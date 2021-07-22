#include <stdio.h>
#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	ret = 0, fd = 0, line_num = 1, limit = argc - 1, i = 1, first_fd, last_fd;
	char	*line;

	line = NULL;
	while (argc-- > 1)
	{
		if ((fd = open(argv[i++], O_RDONLY)) == -1) 
		{
			printf("file #%d could not be opened\n", i);
			while (fd-- > 1)
				close(fd);
			return (0);
		}
		fd++;
	}
	first_fd = fd - limit;
	last_fd = (first_fd + limit - 1);
	if (fd == 0)
	{
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("fd: %d Line: %d ret: %d| %s\n", fd, line_num++, ret, line);
			free(line);
			line = NULL;
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
					line = NULL;
				}
			}
			close(fd);
			limit--;
		}
	}
	printf("fd: %d Line: %d ret: %d| %s\n", fd, line_num++, ret, line);
	free(line);
	line = NULL;
	close(fd);
	return (0);
}
