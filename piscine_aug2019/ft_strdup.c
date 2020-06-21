/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/15 17:46:57 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/15 18:49:04 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*duplicate;
	int		src_size;
	int		i;

	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	duplicate = (char*)malloc(sizeof(char) * (src_size + 1));
	if (duplicate == NULL)
		return (char*)NULL;
	i = 0;
	while (i < src_size)
	{
		duplicate[i] = src[i];
		i++;
	}
	duplicate[src_size] = '\0';
	return (duplicate);
}
