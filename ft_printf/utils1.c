/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 15:06:27 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 15:09:53 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putstr(char *str)
{
	if (!str)
		return ;
	if (str)
		write(1, str, ft_strlen(str));
}

char		*ft_itoa(int n)
{
	char	*str;
	int		count;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = ft_nbrlen(n);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
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
	return (str);
}

char		*ft_uitoa(unsigned int n)
{
	char			*str;
	unsigned int	count;

	count = ft_unbrlen(n);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = 0;
	count--;
	while (n >= 10)
	{
		str[count] = (n % 10) + '0';
		count--;
		n = n / 10;
	}
	str[count] = n + '0';
	return (str);
}

static int	ft_isspace(int c)
{
	char	ch;

	ch = (unsigned char)c;
	if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' ||
			ch == '\f' || ch == '\r')
		return (1);
	else
		return (0);
}

long		ft_atoi(char *str)
{
	long long	result;
	long		sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
		if (result > 9223372036854775807 && sign == -1)
			return (0);
		if (result > 9223372036854775807 && sign == 1)
			return (-1);
	}
	return (sign * result);
}
