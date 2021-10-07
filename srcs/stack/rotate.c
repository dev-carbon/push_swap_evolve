/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:36:21 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/07 13:36:23 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*rotate(t_stack *stack)
{
	t_items	*items;

	items = stack->items;
	if (items != NULL)
	{
		while (items->next != NULL)
		{
			ft_swap(&items->value, &items->next->value);
			items = items->next;
		}
	}
	return (stack);
}
