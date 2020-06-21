/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   btree_apply_infix.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/23 11:18:37 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/23 14:19:41 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	btree_apply_infix(root->left, applyf);
	applyf(root->item);
	btree_apply_infix(root->right, applyf);
}
