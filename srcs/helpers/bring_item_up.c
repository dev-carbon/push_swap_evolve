/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_item_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:28:13 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/08 15:31:59 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	bring_item_up(t_stack *stack, int *hits, t_item item)
{
	if (item.index > stack->size / 2)
		while (stack->top.value != item.value)
			*hits += rev_rotate_stack(stack, REV_ROTATE_A);
	else
		while (stack->top.value != item.value)
			*hits += rotate_stack(stack, ROTATE_A);
}
