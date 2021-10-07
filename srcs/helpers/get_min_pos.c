/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:01:12 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/10 13:01:14 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int	get_min_pos(t_stack *stack)
{
	int		i;
	int		pos;
	int		min;
	t_items	*items;

	i = 1;
	pos = 1;
	items = stack->items;
	min = items->value;
	while (items != NULL)
	{
		if (min > items->value)
		{
			min = items->value;
			pos = i;
		}
		i++;
		items = items->next;
	}
	return (pos);
}
