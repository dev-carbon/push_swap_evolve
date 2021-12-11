/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 01:57:18 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/06 01:57:21 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

t_stack	*sort_sm(t_stack *a, t_stack *b, int *hits)
{
	while (1)
	{
		if (is_sorted(a, ASC) || a->size == 3)
			break ;
		if (a->min.index <= a->size / 2)
			while (a->top.value != a->min.value)
				*hits += rotate_stack(a, ROTATE_A);
		else
			while (a->top.value != a->min.value)
				*hits += rev_rotate_stack(a, REV_ROTATE_A);
		if (!is_sorted(a, ASC))
			*hits += push_stack(b, a, PUSH_B);
	}
	sort_xs(a, hits);
	while (!is_empty(b))
		*hits += push_stack(a, b, PUSH_A);
	return (a);
}
