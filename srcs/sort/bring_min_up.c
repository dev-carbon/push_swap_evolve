/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_min_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 01:14:28 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/06 01:14:30 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	bring_min_up(t_stack *stack, int *hits)
{
	while (!is_sorted(stack, ASC))
	{
		if (stack->min.index > stack->size / 2)
			while (stack->min.index != 0)
				*hits += rev_rotate_stack(stack, REV_ROTATE_A);
		else
			while (stack->min.index != 0)
				*hits += rotate_stack(stack, ROTATE_A);
	}
}
