/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_xs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 01:57:10 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/06 01:57:11 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

t_stack	*sort_xs(t_stack *a, int *hits)
{
	while (!is_sorted(a, ASC))
	{
		if (a->top.value == a->max.value)
			*hits += rotate_stack(a, ROTATE_A);
		else if (a->top.value > a->next.value)
			*hits += swap_stack(a, SWAP_A);
		else
			*hits += rev_rotate_stack(a, REV_ROTATE_A);
	}
	return (a);
}
