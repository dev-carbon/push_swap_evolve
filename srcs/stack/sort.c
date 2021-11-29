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

t_stack	*refresh_stack(t_stack *stack)
{
	int				index;
	t_stack_list	*list;

	index = -1;
	list = stack->list;
	stack->top = peek(stack);
	stack->max = stack->top;
	stack->min = stack->top;
	while (list != NULL)
	{
		list->item.index = ++index;
		if (stack->max.value < list->item.value)
			stack->max = list->item;
		if (stack->min.value > list->item.value)
			stack->min = list->item;
		list = list->next;
	}
	return (stack);
}

void	display_prop(t_stack stack)
{
	printf("size : %d\n\n", stack.size);
	printf("TOP\nindex : %d\nvalue : %d\n_____\n", stack.top.index, stack.top.value);
	printf("MIN\nindex : %d\nvalue : %d\n_____\n", stack.min.index, stack.min.value);
	printf("MAX\nindex : %d\nvalue : %d\n_____\n", stack.max.index, stack.max.value);
}

t_stack	*sort(t_stack *sa)
{
	t_stack		*sb;
	int			count;
	int			count_sa;
	int			count_sb;
	int			count_pa;
	int			count_pb;
	int			count_ra;
	int			count_rb;
	int			count_rra;
	int			count_rrb;

	count =  0;
	count_sa =  0;
	count_sb =  0;
	count_pa =  0;
	count_pb =  0;
	count_ra =  0;
	count_rb =  0;
	count_rra =  0;
	count_rrb =  0;
	sb = new_stack();
	refresh_stack(sa);
	refresh_stack(sb);
	display_stacks(sa, sb);
	while (1)
	{
		// partition.
		while (sa->size > sb->size + 1)
		{
			// if (sa->top.value > sa->list->next->item.value)
			// {
			// 	rotate(sa);
			// 	// swap(sa);
			// 	refresh_stack(sa);
			// 	// ft_putstr("sa\n");
			// 	ft_putstr("ra\n");
			// 	count++;
			// 	count_ra++;
			// }
			push(sb, sa->top.value);
			pop(sa);
			refresh_stack(sa);
			refresh_stack(sb);
			ft_putstr("pb\n");
			if (sb->top.value == sb->max.value && sb->size > 1)
			{
				rotate(sb);
				refresh_stack(sb);
				ft_putstr("rb\n");
				count++;
				count_rb++;
			}
			// display_stacks(sa, sb);
			count++;
			count_pb++;
		}
		if (is_sorted(sa, ASC) && sa->top.value > sb->max.value)
			break ;
		if (sa->min.value != sa->top.value)
		{
			if (sa->min.index <= sa->size / 2)
			{
				if (1)
				{
					if (sa->min.value == sa->top.value)
						break ;
					rotate(sa);
					refresh_stack(sa);
					ft_putstr("ra\n");
					// display_stacks(sa, sb);
					count++;
					count_ra++;
				}
			}
			else
			{
				while (1)
				{
					if (sa->min.value == sa->top.value)
						break ;
					rev_rotate(sa);
					refresh_stack(sa);
					ft_putstr("rra\n");
					// display_stacks(sa, sb);
					count++;
					count_rra++;
				}
			}
		}
		if (!is_sorted(sa, ASC) || sa->top.value < sb->max.value)
		{
			// printf("hello\n");
			// break ;
			push(sb, sa->top.value);
			pop(sa);
			refresh_stack(sa);
			refresh_stack(sb);
			ft_putstr("pb\n");
			// display_stacks(sa, sb);
			count++;
			count_pb++;
		}
		if (is_empty(sa))
			break ;
	}
	while (1)
	{
		// break;
		if (is_empty(sb))
			break ;
		if (sb->max.value != sb->top.value)
		{
			if (sb->max.index <= sb->size / 2)
			{
				while (1)
				{
					if (sb->max.value == sb->top.value)
						break ;
					rotate(sb);
					refresh_stack(sb);
					ft_putstr("rb\n");
					// display_stacks(sa, sb);
					count++;
					count_rb++;
				}
			}
			else
			{
				while (1)
				{
					if (sb->max.value == sb->top.value)
						break ;
					rev_rotate(sb);
					refresh_stack(sb);
					ft_putstr("rrb\n");
					// display_stacks(sa, sb);
					count++;
					count_rrb++;
				}
			}
		}
		push(sa, sb->top.value);
		pop(sb);
		refresh_stack(sa);
		refresh_stack(sb);
		ft_putstr("pa\n");
		// display_stacks(sa, sb);
		count++;
		count_pa++;
	}
	display_result(sa, sb);
	printf("\ntotal sa: %d\n", count_sa);
	printf("total sb: %d\n", count_sb);
	printf("total pa: %d\n", count_pa);
	printf("total pb: %d\n", count_pb);
	printf("total ra: %d\n", count_ra);
	printf("total rb: %d\n", count_rb);
	printf("total rra: %d\n", count_rra);
	printf("total rrb: %d\n", count_rrb);
	printf("\ntotal hits: %d\n\n", count);
	return (sa);
}
