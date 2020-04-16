/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 21:55:01 by adimitri      #+#    #+#                 */
/*   Updated: 2019/12/13 19:03:40 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*char_s1;
	unsigned char	*char_s2;
	size_t			count;

	count = 0;
	char_s1 = (unsigned char *)s1;
	char_s2 = (unsigned char *)s2;
	if (s1 == s2 || n == 0)
		return (0);
	while (count < n)
	{
		if (char_s1[count] != char_s2[count])
			return (char_s1[count] - char_s2[count]);
		count++;
	}
	return (0);
}
