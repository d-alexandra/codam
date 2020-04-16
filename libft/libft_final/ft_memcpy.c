/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 11:19:05 by adimitri      #+#    #+#                 */
/*   Updated: 2019/12/13 19:05:17 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*copy_dst;
	unsigned char	*copy_src;

	copy_dst = (unsigned char *)dst;
	copy_src = (unsigned char *)src;
	count = 0;
	if (n == 0 || dst == src)
		return (dst);
	while (count < n)
	{
		copy_dst[count] = copy_src[count];
		count++;
	}
	return (copy_dst);
}
