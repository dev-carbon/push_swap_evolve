/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_intermediate_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:16:05 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/05 21:16:30 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	do_intermediate_push(t_stack *a, t_stack *b, int *hits, char *label)
{
	if (a->top.value > b->top.value && is_sorted(a, ASC))
	{
		*hits += push_stack(a, b, "alt pa 1\n");
		display_stacks(a, b);
		return (1);
	}
	else if (a->top.value > b->top.value && b->top.value > a->last.value)
	{
		*hits += push_stack(a, b, "alt pa 2\n");
		display_stacks(a, b);
		return(1);
	}
	return (0);
}

