/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 18:57:04 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/19 20:39:26 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int count;

	count = 0;
	while (s[count] != '\0')
	{
		ft_putchar_fd(s[count], fd);
		count++;
	}
}

int main()
{
	int arg;

	arg = 0;
	//ft_putstr_fd("lorem ipsum do\0lor sit amet", 1);
	ft_putstr_fd("  lorem\nipsum\rdolor\tsit amet  ", 1);
	return (0);
}
