/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_md.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 01:57:28 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/06 01:57:30 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

t_stack	*sort_md(t_stack *a, t_stack *b, int *hits)
{
	t_item	bottom_sibbling;

	while (!is_empty(b))
	{
		if (is_rotate_min(b))
		{
			bottom_sibbling = get_min_bottom_sibbling(a, b->min.value);
			if (b->min.index > (b->size / 2))
				rev_rotate_min(a, b, hits, bottom_sibbling);
			else
				rotate_min(a, b, hits, bottom_sibbling);
		}
		else
		{
			bottom_sibbling = get_max_bottom_sibling(a, b->max.value);
			if (b->max.index > (b->size / 2))
				rev_rotate_max(a, b, hits, bottom_sibbling);
			else
				rotate_max(a, b, hits, bottom_sibbling);
		}
		if (bottom_sibbling.value == a->top.value)
			if (b->min.index == 0 || b->max.index == 0)
				*hits += push_stack(a, b, PUSH_A);
	}
	return (a);
}
