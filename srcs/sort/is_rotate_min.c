/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rotate_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:17:30 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/06 01:38:27 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	is_rotate_min(t_stack *stack)
{
	int	min_gap;
	int	max_gap;

	min_gap = stack->min.index;
	max_gap = stack->max.index;
	if (stack->min.index >= stack->size / 2)
		min_gap = stack->size - (stack->min.index);
	if (stack->max.index >= stack->size / 2)
		max_gap = stack->size - (stack->max.index);
	if (min_gap < max_gap)
		return (1);
	return (0);
}
