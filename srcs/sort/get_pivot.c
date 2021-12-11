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
	int				pivot;
	long int		tmp;
	t_stack_list	*l;

	tmp = (a->min.value / 2) + (a->max.value / 2);
	pivot = tmp;
	l = a->list;
	while (l != NULL)
	{
		if (pivot <= l->item.value && l->item.value <= tmp)
			pivot = l->item.value;
		l = l->next;
	}
	return (pivot);
}
