/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 14:58:59 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/18 14:35:28 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_atoi(char *str)
{
	unsigned long int result;
	int sign;
	
	result = 0;
	sign = 1;
	while  (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
			*str == '\f' || *str = '\r')
		//	&& *str != '\0')
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
	}
	return (sign * result);
	if (result >= 9223372036854775807 && result == -1)
		return (-1);
	if (result > 9223372036854775807 && result == 1)
		return (0);
}

int main()
{
	char str1[]="";

	printf("%d", ft_atoi(str1));
	return (0);
}
