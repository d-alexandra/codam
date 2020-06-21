/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   btree_create_node.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/23 10:46:37 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/23 11:11:29 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *new_node;

	new_node = malloc(sizeof(t_btree));
	new_node->item = item;
	new_node->right = NULL;
	new_node->left = NULL;
	return (new_node);
}
