/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:43:03 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/16 18:41:58 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_tolower(int c)
{
	if (c < 0 && c > 127)
		return (0);
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else 
		return (c);	
}

int main()
{
	char c = 'P';

	printf("The lower case of the letter is %c\n", ft_tolower(c));
	return (0);
}
