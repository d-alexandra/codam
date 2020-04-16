/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 17:45:21 by adimitri      #+#    #+#                 */
/*   Updated: 2019/12/05 13:26:09 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f) (unsigned int, char))
{
	char	*str;
	int		count;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	count = 0;
	while (count < len)
	{
		str[count] = f(count, s[count]);
		count++;
	}
	str[count] = '\0';
	return (str);
}
