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

#include "ops.h"

t_stack	*pop(t_stack *stack)
{
	t_stack_list	*top;

	if (!is_empty(stack))
	{
		top = stack->list;
		stack->list = stack->list->next;
		stack->size -= 1;
		free(top);
		top = NULL;
	}
	return (stack);
}
