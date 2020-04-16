/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 21:55:01 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/09 18:36:46 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_memcmp(const void *str1, const void *str2, size_t n)
{
	char *char_str1;
	char *char_str2;
	size_t count;

	count = 0;
	char_str1 = (char *)str1;
	char_str2 = (char *)str2;
	while(count < n)
	{
		if(char_str1[count] != char_str2[count])
			return (char_str1[count] - char_str2[count]);
		count++;
	}
	return (0);
}

int main()
{ 		
	char str1[10] = "i";
	char str2[10] = "";
	int result;

	result = ft_memcmp(str1, str2, 1);
	if (result > 0)
	{
		printf("str2 is less than str1");
	}
	else if (result < 0)
	{
		printf("str1 is less than str2");
	}
	else 
	{
		printf("str1 is equal to str2");
	}
	return (0);
}
