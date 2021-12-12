/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:35:11 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/07 13:35:12 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

t_stack	*swap(t_stack *stack)
{
	t_stack_list	*list;

	list = stack->list;
	if (stack->size > 1)
		ft_swap(&list->item.value, &list->next->item.value);
	return (stack);
}
