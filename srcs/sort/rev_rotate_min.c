/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 01:36:57 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/06 01:36:59 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	rev_rotate_min(t_stack *a, t_stack *b, int *hits, t_item bs)
{
	if (bs.index > (a->size / 2))
	{
		while (b->min.index != 0 && bs.value != a->top.value)
			if (!do_intermediate_push(a, b, hits, PUSH_A))
				*hits += rev_rotate_stacks(a, b, REV_ROTATE_AB);
		while (bs.value != a->top.value)
			if (!do_intermediate_push(a, b, hits, PUSH_A))
				*hits += rev_rotate_stack(a, REV_ROTATE_A);
	}
	else
		while (bs.value != a->top.value)
			if (!do_intermediate_push(a, b, hits, PUSH_A))
				*hits += rotate_stack(a, ROTATE_A);
	while (b->min.index != 0)
		if (!do_intermediate_push(a, b, hits, PUSH_A))
			*hits += rev_rotate_stack(b, REV_ROTATE_B);
}
