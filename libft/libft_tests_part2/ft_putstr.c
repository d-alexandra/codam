/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 19:13:43 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/23 19:26:34 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int count;
	
	count = 0;
	while (s[count] != '\0')
	ft_putchar(s[count]);
	count++;
}

int main()
{
	char str[10] = "today";
	printf("%s", str);
	return (0);
}
