/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_btree.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/23 10:40:20 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/23 14:08:27 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H
# include <stdlib.h>

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

void				btree_apply_infix(t_btree *root, void (*applyf)(void *));
#endif
