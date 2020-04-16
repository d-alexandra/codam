/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 13:20:25 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/02 14:10:33 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_isalnum(int ch)
{
	if(ch >= 'A' && ch <= 'Z')
		return 1;
	if(ch >= 'a' && ch <= 'z')
		return 1;
	if(ch >= '0' && ch <= '9')
		return 1;
	else 
		return (0);
}

int main()
{
	printf("%s%s\n", ft_isalnum('9') ? "9 is a " : "9 is not a ", "digit or a letter");
	return (0);
}
