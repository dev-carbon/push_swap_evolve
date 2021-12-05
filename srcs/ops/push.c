/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:36:03 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/07 13:36:05 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

t_stack	*push(t_stack *stack, int nbr)
{
	t_stack_list	*new;
	t_stack_list	*head;

	head = stack->list;
	new = (t_stack_list *)malloc(sizeof(t_stack_list));
	if (new == NULL)
		escape(EXIT_FAILURE);
	stack->size += 1;
	new->item.value = nbr;
	new->item.index = 0;
	new->next = head;
	stack->list = new;
	return (stack);
}
