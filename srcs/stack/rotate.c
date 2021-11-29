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
	t_stack_list	*list;

	list = stack->list;
	if (list != NULL)
	{
		while (list->next != NULL)
		{
			ft_swap(&list->item.value, &list->next->item.value);
			list = list->next;
		}
	}
	return (stack);
}
