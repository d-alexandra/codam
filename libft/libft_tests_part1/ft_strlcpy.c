/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:27:56 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/19 16:14:13 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	size;
	int		len;

	count = 0;
	size = dstsize - 1;
	if (dst == 0 || src == 0)
		return (0);
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (count < size && src[count] != '\0')
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (len);
}
