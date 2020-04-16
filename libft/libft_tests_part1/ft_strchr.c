/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 13:14:55 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/17 15:46:54 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		len;
	int		count;
	char	*ptr;
	char	ch;

	count = 0;
	len = ft_strlen(s) + 1;
	ch = (char)c;
	while (count < len)
	{
		if (s[count] == ch)
		{
			ptr = (char *)&s[count];
			return (ptr);
		}
		count++;
	}
	return (0);
}
