/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 18:28:11 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/26 16:12:35 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_nbrlen(int n)
{
	int count;

	count = 1;
	while (n < 0)
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

char	*ft_itoa(int n)
{
	char	*str;
	//char	sign;
	int		count;

	//nbr = 1;
	count = ft_nbrlen(n);
	printf("%d", count);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (n == -2147483648)
	{
		ft_putchar(' ');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	if (n < 0)
	{
		n = n * (-1);
		str[0] = '-';
	}
	str[count] = 0;
	count--;
	while (n >= 10)
	{
		str[count] = (n % 10) + '0';
		count--;
		n = n / 10;
	}
	str[count] = n + '0';
//	printf("%s", str);
	//count++;
//	str[count] = '\0';
	return (str);
}

int main()
{
	int i = 12345;

	printf("%s", ft_itoa(i));
	return (0);
}
