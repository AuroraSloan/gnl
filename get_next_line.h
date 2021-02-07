#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

int	get_next_line(int fd, char **line);
size_t	ft_strlen(char *s);
size_t	ft_strchr_len(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
