/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 19:39:34 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/23 20:03:38 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr((-1) * nb);
	}
	else
	{
		if (nb > 10)
		{
			ft_putnbr(nb / 10);
			ft_putchar(nb % 10 + '0');
		}
		else 
			ft_putchar(nb + '0');
	}
}

int main()
{
	int c = -147;

	ft_putnbr(c);
	return (0);
}
