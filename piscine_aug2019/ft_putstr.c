/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 17:28:21 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/21 20:54:09 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(const char *str)
{
	int 	count;
	count = 0;

	while (str[count] != '\0')
		count++;
	return (count);	
}

void	ft_putstr(char *str)
{
	if (*str != '\0')
	{
		write(1, str, ft_strlen(str));
	}
}

int main (void)
{
	char *s = "Hello world\n";
	ft_putstr(s);
	return (0);
}
