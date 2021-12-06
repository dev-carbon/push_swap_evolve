/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_bottom_sibbling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:13:38 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/05 21:14:10 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

t_item	get_min_bottom_sibbling(t_stack *s, int val)
{
	t_item			min;
	t_stack_list	*l;

	min = s->max;
	l = s->list;
	while (l)
	{
		if (l->item.value < min.value && l->item.value > val)
			min = l->item;
		l = l->next;
	}
	return (min);
}
