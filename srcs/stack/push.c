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

#include "stack.h"

t_stack	*push(t_stack *stack, int nbr)
{
	t_items	*new;
	t_items	*head;

	head = stack->items;
	new = (t_items *)malloc(sizeof(t_items));
	if (new == NULL)
		escape(EXIT_FAILURE);
	stack->size += 1;
	new->value = nbr;
	new->next = head;
	stack->items = new;
	return (stack);
}
