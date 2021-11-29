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
	t_stack_list	*list;

	i = 1;
	pos = 1;
	list = stack->list;
	max = list->item.value;
	while (list != NULL)
	{
		if (max < list->item.value)
		{
			max = list->item.value;
			pos = i;
		}
		i++;
		list = list->next;
	}
	return (pos);
}
