/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 11:56:14 by adimitri      #+#    #+#                 */
/*   Updated: 2020/02/05 17:00:04 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list *head;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		head = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(head, (*del));
	}
	*lst = NULL;
}
