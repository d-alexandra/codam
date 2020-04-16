/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 15:39:21 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/11 14:45:30 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
	char *copy_src = (char *)src;
	char *copy_dest = (char *)dest;
	char temp_arr[n];
	size_t count;
	
	count = 0;
	while (count < n)
	{
		temp_arr[count] = copy_src[count];
		count++;
	}
	count = 0;
	while(count < n)
	{
		copy_dest[count] = temp_arr[count];
		count++;
	}
	return(copy_dest);
}

int main()
{
	char str1[20]="creactivation";
	//char str2[]="sunset";

	printf("%s", ft_memmove(str1+1, str1, 3));
	return (0);
}
