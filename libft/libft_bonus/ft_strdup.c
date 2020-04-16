/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:10:52 by adimitri      #+#    #+#                 */
/*   Updated: 2019/12/06 18:34:35 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		src_size;
	int		count;
	char	*duplicate;

	src_size = 0;
	count = 0;
	while (s1[src_size] != '\0')
		src_size++;
	duplicate = (char*)malloc(sizeof(char) * (src_size + 1));
	if (!duplicate)
		return (NULL);
	while (count < src_size)
	{
		duplicate[count] = s1[count];
		count++;
	}
	duplicate[src_size] = '\0';
	return (duplicate);
}
