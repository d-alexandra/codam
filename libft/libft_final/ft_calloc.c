/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:27:07 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/16 14:12:33 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *new_arr;

	new_arr = malloc(count * size);
	if (new_arr == NULL)
		return (NULL);
	else
		ft_bzero(new_arr, (count * size));
	return (new_arr);
}
