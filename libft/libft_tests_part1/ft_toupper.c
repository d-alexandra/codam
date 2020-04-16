/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:15:05 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/16 17:16:28 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_toupper(int ch)
{
	char c;

	c = (char)ch;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	if (c > 127 || c < 0)
		return (0);
	else 
		return (c);
}

int main()
{
	char arg = 'j';

	printf("Your character to upper case = %c\n", ft_toupper(arg));
	return (0);
}
