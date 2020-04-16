/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 20:19:18 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/18 19:46:30 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t count;
	size_t index;
	char *bigstr;
	int size_needle;

	count = 0;
	index = 0;
	size_needle = strlen(needle);
	bigstr = (char *)haystack;
		if (*haystack == '\0')
			return (NULL);
		if (*needle == '\0')
	   		return (bigstr);
		while (len > 0 && bigstr != '\0')
		{
			if (strncmp(haystack, needle, len) == 0)
			{
				return (bigstr);
			}
			len--;
			bigstr++;
		}
	 return (0);	
}

int main()
{
	const char *largestring = "FF";
	const char *smallstring = "See FF your FF return FF now FF";
	char *ptr;

	ptr = ft_strnstr(largestring, smallstring, 15);
	printf("%s", ptr);
	return (0);
}
