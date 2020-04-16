/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 14:40:29 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/25 17:15:47 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char 	*str;
	int		count;
	size_t	index;

	index = 0;
	count = start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	//if (start > strlen(str))
	//	return (strdup(""));
	while(s[count] != '\0' && index < len)
	{
		str[index] = s[count];
		count++;
		index++;
	}
	str[index] = '\0';
	if (start > strlen(str))
		return (strdup(""));
	else 
		return (str);
}

int main()
{
	char s[10] = "allocation";
	printf("%s\n", ft_substr(s, 2, 8));

	return (0);
}
