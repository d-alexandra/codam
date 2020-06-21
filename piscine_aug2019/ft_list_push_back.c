/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_push_back.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 17:31:58 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/21 21:02:07 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *new_node;
	t_list *last;

	new_node = ft_create_elem(data);
	last = *begin_list;
	if (begin_list)
	{
		*begin_list = new_node;
	}
	else
	{
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new_node;
	}
}
