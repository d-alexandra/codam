/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 13:03:58 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/02 13:19:05 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <ctype.h>

int ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return 1;
	else 
		return (0);
}

int main()
{
	printf("%s%s\n", ft_isdigit('5') ? "5 is a " : "5 is not a ",  "digit");
	return (0);
}
