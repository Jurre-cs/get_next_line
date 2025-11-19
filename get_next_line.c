/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/17 15:01:07 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/19 19:35:37 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	*tmp;
	char	*buffer;
	char	*result;
	int		i;

	if (fd < 0 && BUFFER_SIZE < 0)
		return (NULL);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	result = get_next_line_extra(fd, buffer, tmp, i);
	return (result);
}

char	*get_next_line_extra(int fd, char *buffer, char *tmp, int i)
{
	static char	*str = NULL;

	if (new_line(str) == -1)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i < 0)
			return (free(tmp), NULL);
	}
	buffer = ft_strchr(tmp, '\n');
	str = ft_strjoin(str, tmp);
	while (buffer == NULL)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i < 0)
			return (free(tmp), NULL);
		if (i == 0)
			break;
		buffer = ft_strchr(tmp, '\n');
		str = ft_strjoin(str, tmp);
	}
	buffer = ft_substr(str, 0, new_line(str));
	str = ft_strchr(str, '\n');
	free(tmp);
	tmp = NULL;
	return (buffer);
}

int	new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (*str != '\0')
	{
		if (*str == '\n')
			return (i + 1);
		str++;
		i++;
	}
	return (-1);
}

char	*ft_strdup(const char *s)
{
	char	*srtn;
	size_t	size;
	size_t	j;

	j = 0;
	size = ft_strlen(s);
	srtn = malloc((size + 1) * sizeof(char));
	if (!srtn)
		return (NULL);
	while (size > 0)
	{
		srtn[j] = s[j];
		j++;
		size--;
	}
	srtn[j] = '\0';
	return (srtn);
}

#include <stdio.h>

int	main(void)
{
	int fd;
	char *line;
	fd = open("random.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line); // note: line already includes '\n' if there is one
		free(line);
	}
	close(fd);
	return (0);
}