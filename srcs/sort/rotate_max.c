/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 01:46:30 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/06 01:46:31 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	rotate_max(t_stack *a, t_stack *b, int *hits, t_item bs)
{
	if (bs.index <= (a->size / 2))
	{
		while (b->max.index != 0 && bs.value != a->top.value)
			if (!do_intermediate_push(a, b, hits, "pa\n"))
				*hits += rotate_stacks(a, b, "rr\n");
		while (bs.value != a->top.value)
			if (!do_intermediate_push(a, b, hits, "pa\n"))
				*hits += rotate_stack(a, "ra\n");
	}
	else
		while (bs.value != a->top.value)
			if (!do_intermediate_push(a, b, hits, "pa\n"))
				*hits += rev_rotate_stack(a, "rra\n");
	while (b->max.index != 0)
		if (!do_intermediate_push(a, b, hits, "pa\n"))
			*hits += rotate_stack(b, "rb\n");
}
