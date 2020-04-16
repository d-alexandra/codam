/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 15:32:17 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/16 18:23:47 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_isprint(int ch)
{
	char c;

	c = (char)ch;
	if (ch >= 0 && ch <= 127)
		return 1;
	else 
		return (0);
}

int main()
{
	char ch;

	ch = ft_isprint(' ');
	printf("%d", ch);
}
