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

#include "utils.h"
#include "libs.h"

int	get_max_pos(t_stack *stack)
{
	int			i;
	int			pos;
	int			max;
	t_element	*el;

	i = 1;
	pos = 1;
	el = stack->elements;
	max = el->value;
	while (el != NULL)
	{
		if (max < el->value)
		{
			max = el->value;
			pos = i;
		}
		i++;
		el = el->next;
	}
	return (pos);
}
