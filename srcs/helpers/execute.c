/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:19:24 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/05 18:19:25 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

static void	swap_ab(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

static void	rotate_ab(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

static void	rev_rotate_ab(t_stack *a, t_stack *b)
{
	rev_rotate(a);
	rev_rotate(b);
}

static void	do_push(t_stack **dst, t_stack **src)
{
	int		top;

	if (!is_empty(*src))
	{
		top = peek(*src);
		*src = pop(*src);
		*dst = push(*dst, top);
	}
}

void	execute(t_stack *a, t_stack *b, t_operation *op)
{
	if (ft_strncmp(op->label, SWAP_A, op->len) == 0)
		swap(a);
	else if (ft_strncmp(op->label, SWAP_B, op->len) == 0)
		swap(b);
	else if (ft_strncmp(op->label, SWAP_AB, op->len) == 0)
		swap_ab(a, b);
	else if (ft_strncmp(op->label, PUSH_A, op->len) == 0)
		do_push(&a, &b);
	else if (ft_strncmp(op->label, PUSH_B, op->len) == 0)
		do_push(&b, &a);
	else if (ft_strncmp(op->label, ROTATE_A, op->len) == 0)
		rotate(a);
	else if (ft_strncmp(op->label, ROTATE_B, op->len) == 0)
		rotate(b);
	else if (ft_strncmp(op->label, ROTATE_AB, op->len) == 0)
		rotate_ab(a, b);
	else if (ft_strncmp(op->label, REV_ROTATE_A, op->len) == 0)
		rev_rotate(a);
	else if (ft_strncmp(op->label, REV_ROTATE_B, op->len) == 0)
		rev_rotate(b);
	else if (ft_strncmp(op->label, REV_ROTATE_AB, op->len) == 0)
		rev_rotate_ab(a, b);
}
