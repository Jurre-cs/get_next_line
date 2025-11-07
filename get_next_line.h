/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/05 10:34:53 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/07 15:45:00 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_len(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_linelen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_totalstrlen(const char *s);

#endif