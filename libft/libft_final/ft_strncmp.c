/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 13:42:51 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/23 19:37:31 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;
	int		result;

	count = 0;
	while (count < n)
	{
		if (s1[count] == s2[count] && s1[count] == '\0')
			return (0);
		if (s1[count] != s2[count])
		{
			result = ((unsigned char)s1[count] - (unsigned char)s2[count]);
			return (result);
		}
		count++;
	}
	return (0);
}
