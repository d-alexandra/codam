/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 15:03:19 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 15:06:09 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	int count;

	count = write(1, &c, 1);
	return (count);
}

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int		ft_strlen_const(const char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int		ft_nbrlen(int n)
{
	int	count;

	count = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = n * (-1);
		count++;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int		ft_unbrlen(unsigned int n)
{
	int count;

	count = 1;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
