/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 11:53:49 by adimitri      #+#    #+#                 */
/*   Updated: 2019/12/16 16:49:08 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	index;
	size_t	size;

	count = 0;
	index = 0;
	while (dst[count] != '\0' && count < dstsize)
		count++;
	if (dstsize <= count || dstsize == 0)
		return ((int)dstsize + ft_strlen(src));
	size = dstsize - 1;
	while (src[index] != '\0' && count < size)
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
