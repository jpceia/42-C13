/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:56:24 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 17:56:22 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/**
 * @brief	Returns the maximum of two integers.
 * 
 * @param	a 
 * @param	b 
 * @return	int 
 */
int	imax(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

/**
 * @brief	Returns the size of the largest branch passed as argument.
 * @param	root	the root of the tree.
 * @return	int		the size of the largest branch.
 */
int	btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + imax(
			btree_level_count(root->left),
			btree_level_count(root->right)));
}
