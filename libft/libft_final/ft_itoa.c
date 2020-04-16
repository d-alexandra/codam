/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 18:28:11 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/30 18:29:26 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int		count;

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
