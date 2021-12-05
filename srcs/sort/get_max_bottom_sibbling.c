/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_bottom_sibbling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:14:24 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/05 21:14:45 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

t_item	get_max_bottom_sibling(t_stack *s, int val)
{
	int				n;
	t_item			max;
	t_stack_list	*l;

	max = s->max;
	l = s->list;
	while (l)
	{
		if (l->item.value > val)
			if (max.value > l->item.value)
				max = l->item;
		l = l->next;
	}
	return(max);
}

