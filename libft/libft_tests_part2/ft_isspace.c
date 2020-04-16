/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isspace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 21:07:27 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/23 21:17:07 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isspace(int c)
{
	char ch;

	ch = (unsigned char)c;
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || 
			c == '\f' || c == '\r')
		return (1);
	else 
		return (0);
}

int main()
{
	int c = ' ';
	printf("%d", ft_isspace(c));
	return (0);
}
