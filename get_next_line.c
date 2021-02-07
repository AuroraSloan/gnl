#include <limits.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int	err_free1(char *s1)
{
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (-1);
}

int	err_free2(char *s1, char *s2)
{
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
	return (-1);
}

int	buffer_flow(int fd, char **s_arr)
{
	ssize_t	ret;
	char	*buf;
	char	*tmp;

	if (!(buf = malloc((size_t)BUFFER_SIZE + 1)))
		return (err_free1(s_arr[fd]));
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (ret == -1)
			return (err_free2(s_arr[fd], buf));
		buf[ret] = '\0';
		if (!(tmp = ft_strdup(s_arr[fd])))
			return (err_free2(s_arr[fd], buf));
		free(s_arr[fd]);
		if (!(s_arr[fd] = ft_strjoin(tmp, buf)))
			return (err_free2(buf, tmp));
		free(tmp);
		if (ft_strchr_len(s_arr[fd], '\n') > 0)
		{
			ret = 1;
			break ;
		}
	}
	free(buf);
	return (ret);
}

int	make_new_line(int fd, char **line, char **s_arr, int ret)
{
	char	*tmp;
	size_t	len;
	int	flag;

	flag = 1;
	len = ft_strchr_len(s_arr[fd], '\n');
	if (len == 0)
	{
		len = ft_strlen(s_arr[fd]);
		flag--;
	}
	if (s_arr[fd][0] == '\n')
		len = 0;
	if (!(*line = ft_substr(s_arr[fd], 0, len)))
		return (err_free1(s_arr[fd]));
	if (!(tmp = ft_strdup(s_arr[fd] + len + flag)))
		return (err_free1(s_arr[fd]));
	free(s_arr[fd]);
	if (!(s_arr[fd] = ft_strdup(tmp)))
		return (err_free1(tmp));
	free(tmp);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	*s_arr[OPEN_MAX];
	int	ret;

	ret = 1;
	if (!line || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (-1);
	if (!s_arr[fd] || ft_strchr_len(s_arr[fd], '\n') == 0)
		ret = buffer_flow(fd, s_arr);
	if (ret == -1)
		return (-1);
	if (ret == 0 && !s_arr[fd])
	{
		if (!(s_arr[fd] = ft_strdup("")))
		return (-1);
	}
	ret = make_new_line(fd, line, s_arr, ret);
	if (ret == 0)
	{
		free(s_arr[fd]);
		s_arr[fd] = NULL;
	}
	return (ret);
}
