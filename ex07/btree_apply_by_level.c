/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:38:32 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 14:02:59 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

typedef struct s_node_info
{
	int	level;
	int	depth;
	int	is_first;
}	t_node_info;

void	btree_apply_to_level(
	t_btree *root, t_node_info *info,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	depth;

	if (root == NULL || info->depth > info->level)
		return ;
	if (info->level == info->depth)
	{
		applyf(root->item, info->level, info->is_first);
		info->is_first = 0;
		return ;
	}
	depth = ++info->depth;
	btree_apply_to_level(root->left, info, applyf);
	info->depth = depth;
	btree_apply_to_level(root->right, info, applyf);
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_node_info	info;

	info.is_first = 0;
	info.level = 0;
	while (info.is_first == 0)
	{
		info.is_first = 1;
		info.depth = 0;
		btree_apply_to_level(root, &info, applyf);
		info.level++;
	}
}
