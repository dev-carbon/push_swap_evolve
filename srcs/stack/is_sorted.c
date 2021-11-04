/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:40:13 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/07 12:40:18 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_sorted(t_stack *stack, int order)
{
	t_items	*items;

	items = stack->items;
	if (!is_empty(stack))
	{
		while (items->next != NULL)
		{
			if (items->value > items->next->value && order == ASC)
				return (0);
			if (items->value < items->next->value && order == DESC)
				return (0);
			items = items->next;
		}
	}
	return (1);
}
