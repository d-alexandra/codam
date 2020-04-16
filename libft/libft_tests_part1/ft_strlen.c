/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 12:51:13 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/16 14:23:42 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t count;
	count = 0;
	
	while (str[count] != '\0')
	{		
		count++;
	}
	return (count);
}

int		main(void)
{
	char day[10] = "Tomorrow";
	
	printf("Lenght of day is %ld\n", ft_strlen(day));
	return (0);
}
