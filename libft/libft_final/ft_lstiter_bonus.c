/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 07:55:36 by adimitri      #+#    #+#                 */
/*   Updated: 2020/02/04 07:56:00 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (void *))
{
	while (lst != NULL)
	{
		if (lst->content != NULL)
			f(lst->content);
		lst = lst->next;
	}
}
