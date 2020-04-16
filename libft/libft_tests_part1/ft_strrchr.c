/* ************************************************************************* */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 18:53:26 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/18 16:18:32 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char *ft_strrchr(const char *s, int c)
{
	char *result;
	char ch;
	int count;
	int len;

	result = 0;
	count = 0;
	ch = (char)c;
	len = strlen(s) + 1;
	while(len > 0)
	{
		if(s[count] == ch)
		{
			result = (char *)&s[count];
		}
		count++;
		len--;
	}
   	return (result);
}

int main()
{
	char str[50] = "the cake is a lie !uuu\0I'm hidden lol\r\n";
	char *test;
	char letter;

	letter = '\0';
	test = ft_strrchr(str, '\0');
	printf("The last occurence of %c in %s is %s",letter, str,test);
	return (0);
}
