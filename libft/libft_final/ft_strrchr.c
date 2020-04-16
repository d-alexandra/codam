/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 18:53:26 by adimitri      #+#    #+#                 */
/*   Updated: 2019/12/08 18:59:11 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	char	ch;
	int		count;
	int		len;

	result = 0;
	count = 0;
	len = ft_strlen(s) + 1;
	ch = (char)c;
	while (count < len)
	{
		if (s[count] == ch)
		{
			result = (char *)&s[count];
		}
		count++;
	}
	return (result);
}
