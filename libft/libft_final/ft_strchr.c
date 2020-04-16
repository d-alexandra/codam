/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 13:14:55 by adimitri      #+#    #+#                 */
/*   Updated: 2019/12/10 13:42:38 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		len;
	int		count;
	char	*result;
	char	ch;

	count = 0;
	ch = (char)c;
	len = ft_strlen(s) + 1;
	while (count < len)
	{
		if (s[count] == ch)
		{
			result = (char *)&s[count];
			return (result);
		}
		count++;
	}
	return (0);
}
