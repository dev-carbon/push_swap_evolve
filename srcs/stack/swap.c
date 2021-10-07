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

#include "stack.h"

t_stack	*swap(t_stack *stack)
{
	t_items	*items;

	items = stack->items;
	ft_swap(&items->value, &items->next->value);
	return (stack);
}
