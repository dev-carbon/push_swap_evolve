/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:55:56 by humanfou          #+#    #+#             */
/*   Updated: 2021/11/30 12:55:58 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

t_stack	*refresh_stack(t_stack *stack)
{
	int				index;
	t_stack_list	*list;

	index = -1;
	list = stack->list;
	stack->top = peek(stack);
	stack->max = stack->top;
	stack->min = stack->top;
	while (list != NULL)
	{
		list->item.index = ++index;
		if (stack->max.value < list->item.value)
			stack->max = list->item;
		if (stack->min.value > list->item.value)
			stack->min = list->item;
		if (list->next == NULL)
			stack->last = list->item;
		if (index <= (stack->size / 2) - 1)
			stack->middle = list->item;
		list = list->next;
	}
	return (stack);
}
