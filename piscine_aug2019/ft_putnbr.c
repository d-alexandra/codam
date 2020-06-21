/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                       :+:    :+:             */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 12:21:41 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/23 16:45:56 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{	if (nb > 10)
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
	ft_putnbr(5);
	return (0);
}
