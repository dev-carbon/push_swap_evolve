/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:37:46 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/10 12:37:48 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int	get_max_pos(t_stack *stack)
{
	int		i;
	int		pos;
	int		max;
	t_items	*items;

	i = 1;
	pos = 1;
	items = stack->items;
	max = items->value;
	while (items != NULL)
	{
		if (max < items->value)
		{
			max = items->value;
			pos = i;
		}
		i++;
		items = items->next;
	}
	return (pos);
}
