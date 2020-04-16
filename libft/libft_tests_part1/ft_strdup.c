/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:10:52 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/04 17:41:55 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *ft_strdup(const char *str)
{
	int src_size;
	int count;
	char *duplicate;

	src_size = 0;
	count = 0;
	while (str[src_size] != '\0')
		src_size++;
	duplicate = (char*)malloc (sizeof(char) * (src_size + 1));
	while (duplicate == '\0')
		return (NULL);
	while (count < src_size)
	{
		duplicate[count] = str[count];
		count++;
	}
	duplicate[src_size] = '\0';
	return (duplicate);
}

int main()
{
	char *str1="";
	char *str2="day";

	str1=ft_strdup(str2);
	printf("%s", str1);
	return (0);
}
