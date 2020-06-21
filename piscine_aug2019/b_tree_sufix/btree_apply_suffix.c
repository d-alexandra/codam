/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   btree_apply_sufffix.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/23 11:18:37 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/23 14:26:28 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	applyf(root->item);
}
