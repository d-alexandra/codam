/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 18:26:48 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/19 18:45:30 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void  ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int main()
{
	int i;

	i = 58;
	while (i <= 64)
	{
		ft_putchar_fd(i, 2);
		i++;
	}
	return (0);
}
