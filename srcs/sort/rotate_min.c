/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 01:42:27 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/06 01:42:48 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	rotate_min(t_stack *a, t_stack *b, int *hits, t_item bottom_sibbling)
{
	if (bottom_sibbling.index <= (a->size / 2))
	{
		while (b->min.index != 0 && bottom_sibbling.value != a->top.value)
			if (!do_intermediate_push(a, b, hits, PUSH_A))
				*hits += rotate_stacks(a, b, ROTATE_AB);
		while (bottom_sibbling.value != a->top.value)
			if (!do_intermediate_push(a, b, hits, PUSH_A))
				*hits += rotate_stack(a, ROTATE_A);
	}
	else
		while (bottom_sibbling.value != a->top.value)
			if (!do_intermediate_push(a, b, hits, PUSH_A))
				*hits += rev_rotate_stack(a, REV_ROTATE_A);
	while (b->min.index != 0)
		if (!do_intermediate_push(a, b, hits, PUSH_A))
			*hits += rotate_stack(b, ROTATE_B);
}
