/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:18:09 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/07 12:18:11 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	push_stack(t_stack *dest, t_stack *src, char *label)
{
	push(dest, src->top.value);
	refresh_stack(dest);
	pop(src);
	refresh_stack(src);
	// write(STDOUT_FILENO, label, ft_strlen(label));
	return (1);
}

int	swap_stack(t_stack *stack, char *label)
{
	swap(stack);
	refresh_stack(stack);
	// write(STDOUT_FILENO, label, ft_strlen(label));
	return (1);
}

int	rotate_stack(t_stack *stack, char *label)
{
	rotate(stack);
	refresh_stack(stack);
	// write(STDOUT_FILENO, label, ft_strlen(label));
	return (1);
}

int	rev_rotate_stack(t_stack *stack, char *label)
{
	rev_rotate(stack);
	refresh_stack(stack);
	// write(STDOUT_FILENO, label, ft_strlen(label));
	return (1);
}

t_stack	*sort(t_stack *a, t_stack *b, int *hits)
{
	t_item		pivot;
	
	refresh_stack(a);
	pivot = a->middle;
	// display_stacks(a, b);
	while (!is_empty(a))
	{
		if (is_sorted(a, ASC) && a->top.value > b->max.value)
			break ;
		if (a->size > 1 && a->top.value > a->list->next->item.value)
			*hits += rotate_stack(a, "ra\n");
		*hits += push_stack(b, a, "pb\n");
		if (b->top.value > pivot.value)
			*hits += rotate_stack(b, "rb\n");
	}
	// display_stacks(a, b);
	while (!is_empty(b))
	{
		// break ;
		if (b->max.index <= b->size / 2)
			while (b->max.value != b->top.value)
				*hits += rotate_stack(b, "rb\n");
		else
			while (b->max.value != b->top.value)
				*hits += rev_rotate_stack(b, "rrb\n");
		*hits += push_stack(a, b, "pa\n");
	}
	printf("pivot: %d\n", pivot.value);
	return (a);
}
