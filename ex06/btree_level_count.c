/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:56:24 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/16 00:37:04 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	imax(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int	btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + imax(
			btree_level_count(root->left),
			btree_level_count(root->right)));
}
