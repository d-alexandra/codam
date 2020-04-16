/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 14:33:32 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/03 12:44:58 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_isascii(int ch)
{
	if (ch >= 32 && ch <= 127)
		return 1;
	else 
		return (0);
}

int main()
{
	char letter;

	letter = ft_isascii('-');
	printf("%d", letter);
	return (0);
}
