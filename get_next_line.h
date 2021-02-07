#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

int	get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
size_t	ft_strchr_len(const char *s, int c);
char	*ft_strjoin(char const *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
