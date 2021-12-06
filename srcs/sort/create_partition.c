/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_partition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:14:59 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/05 21:15:33 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	create_partition(t_stack *a, t_stack *b, int *hits)
{
	int		pivot;

	pivot = get_pivot(a, b);
	while (!is_sorted(a, ASC) && a->size != 3)
	{
		if (a->top.value < pivot)
			*hits += push_stack(b, a, PUSH_B);
		else
			*hits += rotate_stack(a, ROTATE_A);
		pivot = get_pivot(a, b);
	}
	if (a->size == 3)
		sort_xs(a, hits);
}
