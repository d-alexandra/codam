/**************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 15:39:21 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/17 15:15:41 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*copy_src;
	unsigned char	*copy_dst;
	size_t			count;

	copy_src = (unsigned char *)src;
	copy_dst = (unsigned char *)dst;
	count = 0;
	if (dst == 0 && src == 0)
		return (dst);
	if (len == 0)
		return (dst);
	if (dst < src)
		while (count < len)
		{
			copy_dst[count] = copy_src[count];
			count++;
		}
	else
		while (len != 0)
		{
			copy_dst[len - 1] = copy_src[len - 1];
			len--;
		}
	return (dst);
}
