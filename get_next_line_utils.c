/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_tmp.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/05 10:36:45 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/07 15:50:33 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_linelen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i + 1);
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*joined;
	int		n1;
	int		n2;

	n1 = ft_linelen(s1);
	n2 = ft_linelen(s2);
	i = 0;
	joined = malloc((n1 + (n2 + 1)) * sizeof(char));
	if (!joined)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			joined[i] = s1[i];
			i++;
		}
	}
	i = 0;
	while (s2[i] != '\0' && s2)
	{
		joined[n1 + i] = s2[i];
		i++;
	}
	return (joined);
}

size_t	ft_len(const char *str)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\0')
			return (0);
		else if (str[i] == '\n')
			return (1);
		i++;
	}
	return (-1);
}

char	*ft_substr(char const *strnext, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	while (strnext && strnext[i] != '\0')
		i++;
	// else
	subs = malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = strnext[start];
		start++;
		i++;
	}
	return (subs);
}

size_t	ft_totalstrlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// remember strjoin might need to be freed if it runs more than ones
// buffer_size 1 werkt nog niet
// null terminator aan het einde plaatsen
