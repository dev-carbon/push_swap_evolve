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

#include "sort.h"

t_stack	*refresh_stack(t_stack *stack)
{
	int				index;
	t_stack_list	*list;

	index = 0;
	list = stack->list;
	if (list)
		list->item.index = index;
	stack->top = peek(stack);
	if (stack->size > 1)
		stack->next = list->next->item;
	stack->max = stack->top;
	stack->min = stack->top;
	while (list != NULL)
	{
		list->item.index = index++;
		if (stack->max.value < list->item.value)
			stack->max = list->item;
		if (stack->min.value > list->item.value)
			stack->min = list->item;
		if (list->next == NULL)
			stack->last = list->item;
		list = list->next;
	}
	return (stack);
}
