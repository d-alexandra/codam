/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 20:19:18 by adimitri      #+#    #+#                 */
/*   Updated: 2019/12/05 19:37:05 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*bigstr;
	size_t	size_needle;

	size_needle = ft_strlen(needle);
	bigstr = (char *)haystack;
	if (needle == NULL || *needle == '\0')
		return (bigstr);
	if (*haystack == '\0')
		return (NULL);
	while (len > 0 && *bigstr != '\0')
	{
		if (size_needle > len)
			return (0);
		if (ft_strncmp(bigstr, needle, size_needle) == 0)
		{
			return (bigstr);
		}
		len--;
		bigstr++;
	}
	return (0);
}
