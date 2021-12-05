/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:11:14 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/05 21:11:16 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	get_pivot(t_stack *a, t_stack *b)
{
	int				tmp;
	int				pivot;
	t_stack_list	*l;

	tmp = (a->min.value + a->max.value) / 2;
	pivot = INT_MIN;
	l = a->list;
	while (l != NULL)
	{
		if (pivot <= l->item.value && l->item.value <= tmp)
			pivot = l->item.value;
		l = l->next;
	}
	return (pivot);
}
