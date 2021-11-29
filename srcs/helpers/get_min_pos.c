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
	t_stack_list	*list;

	i = 1;
	pos = 1;
	list = stack->list;
	min = list->item.value;
	while (list != NULL)
	{
		if (min > list->item.value)
		{
			min = list->item.value;
			pos = i;
		}
		i++;
		list = list->next;
	}
	return (pos);
}
