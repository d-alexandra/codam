/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/13 15:32:01 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/13 18:59:36 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n)
{	
	int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{	
		dest[i] = src[i];
		i = i + 1;
	}
	return (dest);
}

int		main(void)
{
	unsigned int n;

	n = 6;
	char dest[16] = "";
	char src[16] = "Hello everybody!";
	ft_strncpy(src, dest, 6);
	printf("%s", dest);
}
