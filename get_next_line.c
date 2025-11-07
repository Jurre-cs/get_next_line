/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/05 10:36:49 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/07 15:45:48 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

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

#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("random.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
