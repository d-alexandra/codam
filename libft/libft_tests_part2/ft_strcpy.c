/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/24 15:35:27 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/24 18:07:23 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strcpy(char *dst, const char *src)
{
	int count;
	int index;

	count = 0;
	index = 0;
	while (src[index] != '\0')
	{
		dst[count] = src[index];
		index++;
		count++;
	}
	dst[count] = '\0';
	return (dst);
}

int main()
{
	char dst[3] = "Jan";
	char src[20] = " and February";

	printf("%s", ft_strcpy(dst, src));
	return (0);
}
