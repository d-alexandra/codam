/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/27 17:22:30 by adimitri      #+#    #+#                 */
/*   Updated: 2020/01/05 13:52:57 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#include <stdlib.h>

int		ft_strlen(const char *s);
char		*ft_strdup(char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);

#endif
