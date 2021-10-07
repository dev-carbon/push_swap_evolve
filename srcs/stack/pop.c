/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 00:51:35 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/07 00:51:38 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*pop(t_stack *stack)
{
	t_items	*top;

	if (!is_empty(stack))
	{
		top = stack->items;
		stack->items = stack->items->next;
		stack->size -= 1;
		free(top);
		top = NULL;
	}
	return (stack);
}
