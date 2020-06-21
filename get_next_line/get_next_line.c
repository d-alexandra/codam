/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/27 14:34:56 by adimitri      #+#    #+#                 */
/*   Updated: 2020/01/05 18:09:22 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static int		ft_eof(char *str) 
{
	int		str_size;

	str_size = 0;
	while (str[str_size] != '\n' && str[str_size] != '\0')
		str_size++;
	if (str[str_size] == '\0')
		return (0);
	else 
		return (1);
}

static char		*ft_putline(char *str, char **line)
{
	int		str_size;
	char		*tmp;

	str_size = 0;
	while (str[str_size] != '\n' && str[str_size] != '\0')
		str_size++;
	*line = ft_substr(str, 0, str_size);
	if (ft_strlen(str) > str_size)
		tmp = ft_strdup(&(str[str_size + 1]));
	else
		tmp = ft_strdup("");
	free(str);
	return (tmp);
}

static int		ft_read_line(int fd, char *str, char **line)
{
	static char buffer[BUFFER_SIZE + 1];
	int 		read_size;
	
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
			return (-1);
		buffer[read_size] = '\0';
		str = ft_strjoin(str, buffer);
		if (str == NULL)
		{
			free(str);
			return (-1);
		}
		if (ft_strchr(str, '\n'))
			break ;
	}
	*line = str;
	return (read_size > 0 ? 1 : 0);
}

int		get_next_line(int fd, char **line)
{
	static char *str; 
	int	returnvalue;
		
	if (fd < 0 || line == NULL)
		return (-1);
	if (str == NULL)
		str = ft_strdup("");
	returnvalue = ft_read_line(fd, str, line);	
	if (returnvalue < 0)
		return (-1);
	str = *line;
	returnvalue = ft_eof(str);
   	str = ft_putline(str, line);
	if (returnvalue > 0)
		return (1);
	else
	{
		free(str);
		str = NULL;
		return (0);
	}
}

#include <fcntl.h>
 #include <stdio.h>


int main(void)
{
	char *line;
	int fd;
	int i;
	int returnvalue;

	returnvalue = 1;
	i = 0;
	fd = open("amsterdam.txt", O_RDONLY);
	while (i < 10)
	{
		returnvalue = get_next_line(fd, &line);
		printf("%d | %s\n", returnvalue, line);
		free(line);
		line = NULL;
		i++;
	}
	close(fd);
	return (0);
}
