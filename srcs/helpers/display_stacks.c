/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:25:44 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/07 06:33:00 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	display_left(t_stack *a, t_stack *b)
{
	t_items	*ia;
	t_items	*ib;

	ia = a->items;
	ib = b->items;
	if (a->size > b->size)
	{
		while (ib)
		{
			printf("% 15d | %-d\n", ia->value, ib->value);
			ia = ia->next;
			ib = ib->next;
		}
		while (ia)
		{
			printf("% 15d |\n", ia->value);
			ia = ia->next;
		}
	}
}

void	display_right(t_stack *a, t_stack *b)
{
	t_items	*ia;
	t_items	*ib;

	ia = a->items;
	ib = b->items;
	if (a->size <= b->size)
	{
		while (ia)
		{
			printf("% 15d | %-d\n", ia->value, ib->value);
			ib = ib->next;
			ia = ia->next;
		}
		while (ib)
		{
			printf("                | %-d\n", ib->value);
			ib = ib->next;
		}
	}
}

void	display_stacks(t_stack *a, t_stack *b)
{
	write(STDOUT_FILENO, "\n", 1);
	display_left(a, b);
	display_right(a, b);
	ft_putstr_fd("________________ _______________\n", STDOUT_FILENO);
	ft_putstr_fd("         stack a stack b\n\n", STDOUT_FILENO);
}
