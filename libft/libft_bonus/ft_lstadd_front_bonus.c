/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 09:31:58 by adimitri      #+#    #+#                 */
/*   Updated: 2020/02/04 10:37:05 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content, void *content2)
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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	
}

int main(void)
{
	t_list *head;
	
	head = ft_lstnew("hello world", "hello C!");
	printList(head);
	return (0);
}
