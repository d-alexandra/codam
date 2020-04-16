/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 14:58:59 by adimitri      #+#    #+#                 */
/*   Updated: 2020/02/04 07:53:39 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int			ft_atoi(const char *str)
{
	long long	result;
	int			sign;

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
	return ((int)sign * result);
}
