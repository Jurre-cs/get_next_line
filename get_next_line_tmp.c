/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_tmp.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/07 15:16:19 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/07 15:52:40 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*strnext = NULL;
	char		*str;
	char		tmp[BUFFER_SIZE];
	int			i;

	i = 0;
	while (ft_len(strnext) != 1)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		// if (i < BUFFER_SIZE)
		// 	tmp[i] = '\0';
			i = ft_len(strnext);
		strnext = ft_strjoin(strnext, tmp);
		// if (i == 0)
		// 	break ;
	}
	str = ft_substr(strnext, 0, ft_linelen(strnext));
	strnext = ft_substr(strnext, (ft_linelen(strnext)),
			ft_totalstrlen(strnext + ft_linelen(strnext)));
	return (str);
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