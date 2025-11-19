/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_over.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/05 10:36:49 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/18 11:58:46 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
// #include <fcntl.h>

// char	*get_next_line(int fd)
// {
// 	static char	*strnext = NULL;
// 	char		*str;
// 	char		*tmp;
// 	int			len;
// 	char		*buffer;

// 	if (fd < 0 && BUFFER_SIZE < 0)
// 		return (NULL);
// 	tmp = malloc(BUFFER_SIZE + 1);
// 	strnext = get_next_line_extra(fd, tmp, strnext);
// 	if (!strnext || strnext[0] == '\0')
// 	{
// 		strnext = NULL;
// 		return (free(strnext), NULL);
// 	}
// 	len = ft_len(strnext);
// 	str = ft_substr(strnext, 0, len + 1);
// 	buffer = strnext;
// 	strnext = ft_substr(strnext, len + 1, ft_strlen(buffer + len));
// 	free(buffer);
// 	buffer = NULL;
// 	free(tmp);
// 	tmp = NULL;
// 	return (str);
// }

// char	*get_next_line_extra(int fd, char *tmp, char *strnext)
// {
// 	int		i;

// 	i = read(fd, tmp, BUFFER_SIZE);
// 	if (i <= 0)
// 		return (free(tmp), NULL);
// 	tmp[i] = '\0';
// 	strnext = ft_strjoin(strnext, tmp);
// 	i = ft_len(strnext);
// 	while (strnext[i] != '\n')
// 	{
// 		i = read(fd, tmp, BUFFER_SIZE);
// 		if (i < 0)
// 			return (free(tmp), NULL);
// 		if (i == 0)
// 			break ;
// 		tmp[i] = '\0';
// 		strnext = ft_strjoin(strnext, tmp);
// 		i = ft_len(strnext);
// 	}
// 	return (strnext);
// }

// #include <stdio.h>

// int main(void)
// {
// 	int		fd;
// 	char	*line;
// 	fd = open("random.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line); // note: line already includes '\n' if there is one
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
