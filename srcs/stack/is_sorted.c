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
	t_stack_list	*list;

	list = stack->list;
	if (!is_empty(stack))
	{
		while (list->next != NULL)
		{
			if (list->item.value > list->next->item.value && order == ASC)
				return (0);
			if (list->item.value < list->next->item.value && order == DESC)
				return (0);
			list = list->next;
		}
	}
	return (1);
}
