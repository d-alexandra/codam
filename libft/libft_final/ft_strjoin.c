/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 20:22:16 by adimitri      #+#    #+#                 */
/*   Updated: 2019/12/03 16:58:13 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	int		index;
	int		count;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	count = 0;
	if (!new_str)
		return (NULL);
	while (s1[count] != '\0')
	{
		new_str[count] = s1[count];
		count++;
	}
	index = 0;
	while (s2[index] != '\0')
	{
		new_str[count] = s2[index];
		count++;
		index++;
	}
	new_str[count] = '\0';
	return (new_str);
}
