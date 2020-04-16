/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 11:53:49 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/19 17:53:05 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

size_t  ft_strlen(const char *s)
 {
	 size_t count;

     count = 0;
 	 while (s[count] != '\0') 
        count++;
     return (count);
 }

void ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t size;
	size_t count;
	size_t index;

	size = dstsize - 1;
	count = 0;
	index = 0;
	while (dst[count] != '\0')
		count++;
	if (dstsize <= count)
		return ((int)dstsize + ft_strlen(src)); 	
	while(src[index] != '\0' && count < size)
	{
		dst[count] = src[index];
		index++;
		count++;
	}
	dst[count] = '\0';
	while (src[index] != '\0')
	{
		index++;
		count++;
	}
	return (count);
}


int main()
{
	char *dest = NULL;
	
	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
		return (0);
	memset(dest, 'r', 15);
	ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
	write(1, "\n",1);
	write(1, dest, 15);
	
	return (0); 
}
