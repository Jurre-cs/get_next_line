/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/17 15:01:04 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/19 16:50:36 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	if (c < 0)
		return (NULL);
	while (s1[i] != (char)c)
	{
		if (!s1[i])
			return (NULL);
		i++;
	}
	i++;
	return ((char *)&s1[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*joined;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	joined = malloc((len1 + len2 + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	if(s1)
		while (s1[i])
		{
			joined[i] = s1[i];
			i++;
		}
	i = 0;
	while (s2[i] != '\0')
	{
		joined[len1 + i] = s2[i];
		i++;
	}
	joined[len1 + i] = '\0';
	return (joined);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	if (len > i + start)
		len = i + start;
	if (start > i)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		(len = ft_strlen(s) - start);
	subs = ft_calloc(len + 1, sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start];
		start++;
		i++;
	}
	return (subs);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	product;
	char	*mem;

	if (nmemb > SIZE_MAX / size)
		return(NULL);
	product = nmemb * size;
	mem = malloc(product);
	if (!mem)
		return (NULL);
	while (product > 0)
	{
		mem[product - 1] = '\0';
		product--;
	}
	return (mem);
}