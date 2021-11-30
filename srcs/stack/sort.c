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
	write(STDOUT_FILENO, label, ft_strlen(label));
	return (1);
}

int	swap_stack(t_stack *stack, char *label)
{
	swap(stack);
	refresh_stack(stack);
	write(STDOUT_FILENO, label, ft_strlen(label));
	return (1);
}

int	rotate_stack(t_stack *stack, char *label)
{
	rotate(stack);
	refresh_stack(stack);
	write(STDOUT_FILENO, label, ft_strlen(label));
	return (1);
}

int	rev_rotate_stack(t_stack *stack, char *label)
{
	rev_rotate(stack);
	refresh_stack(stack);
	write(STDOUT_FILENO, label, ft_strlen(label));
	return (1);
}

t_stack	*sort(t_stack *a, t_stack *b, int *hits)
{
	t_item		pivot;
	
	refresh_stack(a);
	pivot = a->last;
	printf("pivot: %d\nhits: %d\n", pivot.value, *hits);
	while (1)
	{
		if (a->min.value == pivot.value && a->top.value == pivot.value)
		{
			pivot = a->last;
			display_stacks(a, b);
		}
		if (a->top.value > pivot.value)
		{
			*hits += rotate_stack(a, "ra\n");
		}
		else
		{
			*hits += push_stack(b, a, "pb\n");
			
		}
		if (is_sorted(a, ASC) && a->top.value == pivot.value)
			break ;
		// if (b->size > 1 && b->top.value < b->list->next->item.value)
		// 		*hits += swap_stack(b, "sb\n");
		
	}
	display_stacks(a, b);
	while (1)
	{
		break ;
		if (is_sorted(a, ASC) && a->top.value > b->max.value)
			break ;
		if (a->min.index <= a->size / 2)
			while (a->min.value != a->top.value)
				*hits += rotate_stack(a, "ra\n");
		else
			while (a->min.value != a->top.value)
				*hits += rev_rotate_stack(a, "rra\n");
		if (!is_sorted(a, ASC))
			*hits += push_stack(b, a, "pb\n");
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
	printf("\npivot: %d\n", pivot.value);
	return (a);
}
