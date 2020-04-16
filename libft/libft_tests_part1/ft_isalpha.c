/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 12:37:38 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/02 13:02:33 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_isalpha(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return 1;
	if (ch >= 'A' && ch <= 'Z')
		return 1;
	else
		return (0);
}

int main()
{
	printf("%s%s\n", isalpha('A') ? "A is a": "A is not a", "letter");
	return (0);
}
