/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 09:31:58 by adimitri      #+#    #+#                 */
/*   Updated: 2020/02/04 11:26:17 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = NULL;
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	printList(t_list * head)
{
	t_list * content = head;
	while (content != NULL)
	{
		printf("%s\n", head->content);
		content =  content->next;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_node;
	if (!lst)
		return (NULL);
	last_node = lst;
	while (last_node->next != NULL)
		last_node = last_node->next;
	return (last_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst || !new)
		return ;
	if (!*lst)
		new = ft_lstnew(lst);
	else
		last = ft_lstlast(*lst);
	last->next = new;
}

int main(void)
{
	t_list **head;

	*head = ft_lstnew("hello C!");
	printList(*head);
	ft_lstadd_back(head, *head);
	printList(*head);

	return (0);
}
