/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 00:57:50 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/07 00:57:51 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

t_item	peek(t_stack *stack)
{
	t_item	item;

	item.index = INT_MIN;
	item.value = INT_MIN;
	if (!is_empty(stack))
		item = stack->list->item;
	return (item);
}
