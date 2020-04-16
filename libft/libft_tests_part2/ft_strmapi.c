/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 17:45:21 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/30 18:06:02 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *str;
	int count;
	int len;

	len = strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	count = 0;
	while (count < len)
	{
		str[count] = f(count, s[count]);
		count++;
	}
	str[count] = '\0';
	return (str);
}

char ft_test(unsigned int a, char b)
{
	return (b + a);
}
int main()
{
	char *arr = "abcde";

	printf("%s", ft_strmapi(arr, &ft_test));
	return (0);
}
