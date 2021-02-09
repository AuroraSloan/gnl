#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	ret = 0, fd = 0, line_num = 1, limit = argc - 1, i = 1, first_fd, last_fd;
	char	*line;

	line = NULL;
	first_fd = fd - limit;
	last_fd = (first_fd + limit - 1); 
	while (argc-- > 1)
	{
		if ((fd = open(argv[i++], O_RDONLY)) == -1) 
		{
			printf("file #%d could not be opened\n", fd);
			while (fd-- > 1)
				close(fd);
			return (0);
		}
		fd++;
	}
	if (fd == 0)
	{
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("fd: %d Line: %d ret: %d| %s\n", fd, line_num++, ret, line);
			free(line);
		}
	}
	else
	{
		while (limit)
		{
			if (fd >= last_fd)
				fd = first_fd;
			else
				fd++;
			while ((ret = get_next_line(fd, &line)) >= -1)
			{
				if (ret == 0)
					break ;
				else if (ret > 0)
				{
					printf("fd: %d Line: %d ret: %d| %s\n", fd, line_num++, ret, line);
					free(line);
				}
				if (fd >= last_fd)
					fd = first_fd;
				else
					fd++;
			}
			close(fd);
			limit--;
		}
	}
	printf("fd: %d Line: %d ret: %d| %s\n", fd, line_num++, ret, line);
	free(line);
	close(fd);
	return (0);
}
