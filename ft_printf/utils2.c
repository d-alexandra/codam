/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 15:10:12 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 15:14:52 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_putnbr(long n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			ft_putnbr((-1) * n);
		}
		else
		{
			if (n >= 10)
			{
				ft_putnbr(n / 10);
				ft_putchar(n % 10 + '0');
			}
			else
				ft_putchar(n + '0');
		}
	}
}

void	ft_putnbr_unsign(unsigned int n)
{
	if (n >= 10)
	{
		ft_putnbr_unsign(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

char	*ft_strdup(const char *s1)
{
	int		src_size;
	int		count;
	char	*duplicate;

	src_size = 0;
	count = 0;
	while (s1[src_size] != '\0')
		src_size++;
	duplicate = (char*)malloc(sizeof(char) * (src_size + 1));
	if (!duplicate)
		return (NULL);
	while (count < src_size)
	{
		duplicate[count] = s1[count];
		count++;
	}
	duplicate[src_size] = '\0';
	return (duplicate);
}

char	*ft_itoa_base(unsigned long num, unsigned long base, char c)
{
	const char	*str;
	static char	hexstr[1000];
	char		*ptr;

	if (c == 'x' || c == 'p')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	ptr = &hexstr[999];
	*ptr = '\0';
	if (num == 0)
		*ptr = str[num % base];
	while (num != 0)
	{
		ptr--;
		*ptr = str[num % base];
		num /= base;
	}
	return (ptr);
}
