/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 20:22:16 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/24 15:56:44 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *new_str;
	int len;
	int count;
	int index;

	count = 0;
	len = strlen(s1) + strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[count] != '\0')
	{
		new_str[count] = s1[count];
		count++;
	}
	index = 0;
	while (s2[index] != '\0')
	{
		new_str[count] = s2[index];
		index++;
		count++;
	}
	new_str[count] = '\0';
	return (new_str);
}

int main()
{
	char str1[6] = "hello";
	char str2[6] = "world";

	printf("%s", ft_strjoin(str1, str2));
	return (0);
}
