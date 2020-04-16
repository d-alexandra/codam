/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 13:42:51 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/17 17:28:34 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i; 
	
	i = 0;
	while (i < n)
	{
		while (str1[i] != '\0' && str2[i] != '\0')
		{
			if (str1[i] != str2[i])
				return str1[i]-str2[i];
			i++;
		}
	}	
	return (0);
}

int main()
{
	char str1[] = "today";
	char str2[] = "tomorrow";

	printf("%d", strncmp(str1, str2, 0));
	return (0);
}
