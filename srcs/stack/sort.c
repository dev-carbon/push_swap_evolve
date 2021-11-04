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

t_stack	*init_tracker(t_stack *stack)
{
	t_items	*buff;

	buff = stack->items;
	stack->top = peek(stack);
	stack->max = stack->top;
	stack->min = stack->top;
	while (buff != NULL)
	{
		if (stack->max < buff->value)
			stack->max = buff->value;
		if (stack->min > buff->value)
			stack->min = buff->value;
		if (buff->next == NULL)
			stack->last = buff->value;
		buff = buff->next;
	}
	return (stack);
}

void	display_tracker(t_stack stack)
{
	printf("top = %d\nlast = %d\nmin = %d\nmax = %d\n",
		stack.top, stack.last, stack.min, stack.max);
}

t_stack	*sort(t_stack *sa)
{
	t_stack		*sb;
	// int			count = 0;

	sb = new_stack();
	while (!is_empty(sa))
	{
		// STACK A
		// if max = top rotate a
		// if min = last rev_rotate a

		// if top > next swap a then push b
		// else push b

		// STACK B
		// si min = top -> rotate b

		// si top A < top B


		init_tracker(sa);
		if (is_empty(sb) && is_sorted(sa, ASC))
			break ;
		if (sa->max == sa->top)
		{
			rotate(sa);
			write(STDOUT_FILENO, ROTATE_A, 3);
			init_tracker(sa);
		}
		if (sa->min == sa->last)
		{
			rev_rotate(sa);
			write(STDOUT_FILENO, REV_ROTATE_A, 4);
			init_tracker(sa);
		}
		if (sa->size > 1)
		{
			if (sa->top > sa->items->next->value)
			{
				swap(sa);
				write(STDOUT_FILENO, SWAP_A, 3);
				init_tracker(sa);
			}
		}
		if (sb->size > 1)
		{
			if (sb->top == sb->min)
			{
				rotate(sb);
				write(STDOUT_FILENO, ROTATE_B, 3);
				init_tracker(sb);
			}
		}
		if (sa->top > sb->top && !is_sorted(sa, ASC))
		{
			push(sb, sa->top);
			pop(sa);
			write(STDOUT_FILENO, PUSH_B, 3);
			init_tracker(sa);
			init_tracker(sb);
		}
		else if (sa->top > sb->top)
		{
			push(sa, sb->top);
			pop(sb);
			write(STDOUT_FILENO, PUSH_A, 3);
			init_tracker(sa);
			init_tracker(sb);
		}
		else
		{
			while (sa->top < sb->top)
			{
				push(sa, sb->top);
				pop(sb);
				write(STDOUT_FILENO, PUSH_A, 3);
				init_tracker(sa);
				init_tracker(sb);
			}
		}

			
			
		// 	swap_a(sa);
		// push_n_swap_a(sa, sb);
		// if (!is_sorted(sa))
		// 	push_b(sb, sa);
		// else
		// 	break ;



		// init_tracker(sa);
		// rev_rotate_stack(sa, REV_ROTATE_A);
		// init_tracker(sa);
		// rotate_stack(sa, ROTATE_A);
		// while (!is_empty(sb) && (sa->top < sb->top))
		// {
		// 	push_stack(sa, sb, PUSH_A);
		// 	init_tracker(sa);
		// 	swap_stack(sa, SWAP_A);
		// 	init_tracker(sa);
		// }
		// swap_stack(sa, SWAP_A);
		// init_tracker(sa);
		// while (!is_empty(sb) && (sa->top < sb->top))
		// {
		// 	push_stack(sa, sb, PUSH_A);
		// 	init_tracker(sa);
		// 	swap_stack(sa, SWAP_A);
		// 	init_tracker(sa);
		// }
		// while (!is_empty(sa) && is_sorted(sb, DESC))
		// 	push_stack(sb, sa, PUSH_B);
		// init_tracker(sb);
		// rotate_stack(sb, ROTATE_B);
		// init_tracker(sb);
		// swap_stack(sb, SWAP_B);
		// // if (++count == 100)
		// 	// break;
		// if (is_empty(sb) && is_sorted(sa, ASC))
		// 	break ;
		// // ft_putstr("_____________\n");
	}
	// printf("count: %d\n", count);
	while (!is_empty(sb))
		push_stack(sa, sb, PUSH_A);
	destroy_stack(sb);
	// display_stack(sa);
	return (sa);
}
