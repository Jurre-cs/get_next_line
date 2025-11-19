/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_over.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/05 10:36:45 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/18 11:54:36 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_stroin(char const *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	len1;
// 	char	*joined;

// 	len1 = ft_len(s1);
// 	i = 0;
// 	joined = malloc(len1 + ft_len(s2) + 1);
// 	if (!joined)
// 		return (NULL);
// 	if (s1)
// 		while (s1[i] != '\0')
// 		{
// 			joined[i] = s1[i];
// 			i++;
// 		}
// 	i = 0;
// 	while (s2[i] != '\0' && i <= BUFFER_SIZE)
// 	{
// 		joined[len1 + i] = s2[i];
// 		i++;
// 	}
// 	joined[len1 + i] = '\0';
// 	free((char *)s1);
// 	return (joined);
// }

// size_t	ft_len(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 	{
// 		if (str[i] == '\0')
// 			return (i);
// 		else if (str[i] == '\n')
// 			return (i);
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_sustr(char const *strnext, unsigned int start, size_t len)
// {
// 	char	*subs;
// 	size_t	i;

// 	i = 0;
// 	while (strnext && strnext[i] != '\0')
// 		i++;
// 	subs = malloc((len + 1) * sizeof(char));
// 	if (!subs)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		subs[i] = strnext[start];
// 		start++;
// 		i++;
// 	}
// 	return (subs);
// }

// void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char	*x;

// 	x = s;
// 	while (n > 0)
// 	{
// 		*x = '\0';
// 		x++;
// 		n--;
// 	}
// 	s = x;
// }
// remember strjoin might need to be freed if it runs more than ones
// buffer_size 1 werkt nog niet
// null terminator aan het einde plaatsen
