/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/16 14:27:54 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/18 20:17:08 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*result;
	unsigned char	*new_str;
	unsigned char	ch;

	count = 0;
	new_str = (unsigned char *)s;
	ch = (unsigned char)c;
	result = NULL;
	while (count < n)
	{
		if (new_str[count] == ch)
		{
			result = &new_str[count];
			return ((void *)result);
		}
		count++;
	}
	return (0);
}
