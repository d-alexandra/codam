/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_btree.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/23 10:40:20 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/23 11:37:43 by adimitri      ########   odam.nl         */
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

t_btree				*btree_create_node(void *item);
#endif
