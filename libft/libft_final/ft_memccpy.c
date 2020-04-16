/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 17:01:53 by adimitri      #+#    #+#                 */
/*   Updated: 2019/12/13 19:04:08 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*copy_dst;
	unsigned char		*copy_src;
	size_t				count;
	unsigned char		ch;

	copy_dst = (unsigned char *)dst;
	copy_src = (unsigned char *)src;
	count = 0;
	ch = (unsigned char)c;
	while (count < n)
	{
		copy_dst[count] = copy_src[count];
		if (copy_src[count] == ch)
		{
			return ((void *)copy_dst + count + 1);
		}
		count++;
	}
	return (NULL);
}
