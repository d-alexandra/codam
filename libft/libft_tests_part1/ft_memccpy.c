/**************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 17:01:53 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/17 14:06:27 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *copy_dest;
	unsigned char *copy_src;
	size_t count;
	char ch;
	
	copy_dest = (unsigned char *)dest;
	copy_src = (unsigned char *)src;
	count = 0;
	ch = (char)c;
	while (count < n)
	{
		copy_dest[count] = copy_src[count];
		if (copy_src[count] == ch)
		{
			return (copy_dest);
		}
		count++;
	}
	return(copy_dest);
}

int main()
{
	char str1[20] = "Automatization";
	char str2[20] = "system";

	ft_memccpy(str1, str2, 't', 20);
	printf("%s", str1);
	return (0);
}
