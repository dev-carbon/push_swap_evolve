/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:36:31 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/07 13:36:33 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*rev_rotate(t_stack *stack)
{
	t_items	*head;
	t_items	*next;

	head = stack->items;
	if (head != NULL)
	{
		next = head->next;
		while (next)
		{
			ft_swap(&head->value, &next->value);
			next = next->next;
		}
	}
	return (stack);
}
