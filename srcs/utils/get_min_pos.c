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

#include "utils.h"
#include "libs.h"

int	get_min_pos(t_stack *stack)
{
	int			i;
	int			pos;
	int			min;
	t_element	*el;

	i = 1;
	pos = 1;
	el = stack->elements;
	min = el->value;
	while (el != NULL)
	{
		if (min > el->value)
		{
			min = el->value;
			pos = i;
		}
		i++;
		el = el->next;
	}
	return (pos);
}
