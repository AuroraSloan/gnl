#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (s = NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strchr_len(char *s, int c)
{
	size_t i;

	if (s[0] == (char)c)
		return (1);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*dst;
	int	i;
	int j;

	j = 0;
	i = str == NULL ? 0 : ft_strlen(str);
	if (!(dst = (char*)malloc(sizeof(*dst) * ft_strlen(s1) + 1)))
		return (NULL);
	while (j < i)
	{
		dst[j] = s1[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	j;
	int	len;
	char	*join;

	if (!s1 || !s2)
		return (s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(join = (char *)malloc(sizeof(*join) * len + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char		*sub_s;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!(sub_s = (char*)malloc(sizeof(*sub_s) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
