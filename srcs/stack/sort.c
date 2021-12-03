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

int	rotate_stacks(t_stack *a, t_stack *b, char *label)
{
	rotate(a);
	rotate(b);
	refresh_stack(a);
	refresh_stack(b);
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

int	rev_rotate_stacks(t_stack *a, t_stack *b, char *label)
{
	rev_rotate(a);
	rev_rotate(b);
	refresh_stack(a);
	refresh_stack(b);
	write(STDOUT_FILENO, label, ft_strlen(label));
	return (1);
}

int	get_pivot(t_stack *a, t_stack *b)
{
	int				tmp;
	int				pivot;
	t_stack_list	*l;

	tmp = (a->min.value + a->max.value) / 2;
	pivot = INT_MIN;
	l = a->list;
	while (l != NULL)
	{
		if (pivot <= l->item.value && l->item.value <= tmp)
			pivot = l->item.value;
		l = l->next;
	}
	printf("pivot: %d\n", pivot);
	return (pivot);
}

int	is_rev_rotate(t_stack *s, int pivot)
{
	int				count;
	t_item			first;
	t_item			last;
	t_stack_list	*l;

	l = s->list;
	first = s->min;
	last = first;
	count = 0;
	while (l != NULL)
	{
		if (l->item.value < pivot)
		{
			if (count == 0)
			{
				first = l->item;
				count = 1;
			}
			last = l->item;
		}
		l = l->next;
	}
	// printf("pivot: [%d]\n", pivot);
	// printf("size: [%d]\n", s->size);
	// printf("first: [%d] => %d\n", first.index, first.value);
	// printf("last: [%d] => %d\n", last.index, last.value);
	// printf ("first gap = %d\n", first.index);
	// printf ("last gap = %d\n", s->size - last.index);
	if (first.index > (s->size - last.index))
		return (1);
	return (0);
}

t_stack	*sort_xs(t_stack *a, int *hits)
{
	while (1)
	{
		if (is_sorted(a, ASC))
			break ;
		if (a->top.value == a->max.value)
			*hits += rotate_stack(a, "ra\n");
		else if (a->top.value > a->next.value)
			*hits += swap_stack(a, "sa\n");
		else
			*hits += rev_rotate_stack(a, "rra\n");
	}
	return (a);
}

t_stack	*sort_sm(t_stack *a, t_stack *b, int *hits)
{
	while (1)
	{
		if (is_sorted(a, ASC) || a->size == 3)
			break ;
		if (a->min.index <= a->size / 2)
			while (a->top.value != a->min.value)
				*hits += rotate_stack(a, "ra\n");
		else
			while (a->top.value != a->min.value)
				*hits += rev_rotate_stack(a, "rra\n");
		*hits += push_stack(b, a, "pb\n");
	}
	sort_xs(a, hits);
	while (!is_empty(b))
		*hits += push_stack(a, b, "pa\n");
	return (a);
}


void	print_list(t_stack *stack)
{
	t_stack_list	*l;

	l = stack->list;
	while (l != NULL)
	{
		printf("[%d] => %d\n", l->item.index, l->item.value);
		l = l->next;
	}
}

t_item	get_min_bottom_sibbling(t_stack *s, int val)
{
	t_item			min;
	t_stack_list	*l;

	min = s->max;
	l = s->list;
	while (l)
	{
		if (l->item.value < min.value && l->item.value > val)
			min = l->item;
		l = l->next;
	}
	return(min);
}

t_item	get_max_bottom_sibling(t_stack *s, int val)
{
	int				n;
	t_item			max;
	t_stack_list	*l;

	max = s->max;
	l = s->list;
	while (l)
	{
		if (l->item.value > val)
			if (max.value > l->item.value)
				max = l->item;
		l = l->next;
	}
	// printf("max sibbling: %d\n", max.value);
	return(max);
}

void	create_partition(t_stack *a, t_stack *b, int *hits)
{
	int		pivot;

	pivot = get_pivot(a, b);
	while (1)
	{
		if (is_sorted(a, ASC))
			break ;
		if (a->top.value < pivot)
			*hits += push_stack(b, a, "pb\n");
		else
			*hits += rotate_stack(a, "ra\n");
		pivot = get_pivot(a, b);
	}
}

int	is_rotate_min(t_stack *stack)
{
	int	min_gap;
	int	max_gap;

	min_gap = stack->min.index;
	max_gap = stack->max.index;
	if (stack->min.index >= stack->size / 2)
		min_gap = stack->size - (stack->min.index);
	if (stack->max.index >= stack->size / 2)
		max_gap = stack->size - (stack->max.index);
	if (min_gap < max_gap)
		return (1);
	return (0);
}

t_stack	*sort_md(t_stack *a, t_stack *b, int *hits)
{

	t_item	bottom_sibbling;

	int	pivot;
	int count_rra = 0;
	int count_ra = 0;
	int count_rb = 0;
	int count_rrb = 0;
	int count_pb = 0;
	int count_pa = 0;
	int	count_rrr = 0;
	int	count_rr = 0;

	printf("********* PARTITION *******\n");
	create_partition(a, b, hits);
	printf("********* END PARTITION *******\n");
	display_stacks(a, b);
	// exit(0);
	while (1)
	{
		if (is_empty(b))
			break ;				
		
		if (is_rotate_min(b))
		{
			bottom_sibbling = get_min_bottom_sibbling(a, b->min.value);
			printf("move min %d above %d\n", b->min.value, bottom_sibbling.value);
			
			if (b->min.index > (b->size / 2))
			{
				if (bottom_sibbling.index > (a->size / 2))
				{
					while (b->min.index != 0 && bottom_sibbling.value != a->top.value)
					{
						if (a->top.value > b->top.value && b->top.value > a->last.value)
						{
							*hits += push_stack(a, b, "pa => min => rrr\n");
							display_stacks(a, b);
						}
						else if (a->top.value > b->top.value && is_sorted(a, ASC))
						{
							*hits += push_stack(a, b, "pa => min => rrr 2\n");
							display_stacks(a, b);
						}
						else
						{
							*hits += rev_rotate_stacks(a, b, "rrr\n");
							display_stacks(a, b);
						}
					}

					while (bottom_sibbling.value != a->top.value)
					{
						if (a->top.value > b->top.value && b->top.value > a->last.value)
						{
							*hits += push_stack(a, b, "pa => min => rra\n");
							display_stacks(a, b);
						}
						else if (a->top.value > b->top.value && is_sorted(a, ASC))
						{
							*hits += push_stack(a, b, "pa => min => rrr 2\n");
							display_stacks(a, b);
						}
						else
						{
							*hits += rev_rotate_stack(a, "rra\n");
							display_stacks(a, b);
						}
					}
				}
				else
				{
					while (bottom_sibbling.value != a->top.value)
					{
						if (a->top.value > b->top.value && b->top.value > a->last.value)
						{
							*hits += push_stack(a, b, "pa => min => ra\n");
							display_stacks(a, b);
						}
						else if (a->top.value > b->top.value && is_sorted(a, ASC))
						{
							*hits += push_stack(a, b, "pa => min => rrr 2\n");
							display_stacks(a, b);
						}
						else
						{
							*hits += rotate_stack(a, "ra\n");
							display_stacks(a, b);
						}
					}
				}

				while (b->min.index != 0)
				{
					if (a->top.value > b->top.value && b->top.value > a->last.value)
					{
						*hits += push_stack(a, b, "pa => min => rrb\n");
						display_stacks(a, b);
					}
					else if (a->top.value > b->top.value && is_sorted(a, ASC))
					{
						*hits += push_stack(a, b, "pa => min => rrr 2\n");
						display_stacks(a, b);
					}
					else
					{
						*hits += rev_rotate_stack(b, "rrb\n");
						display_stacks(a, b);
					}
				}
			}
			else
			{
				if (bottom_sibbling.index <= (a->size / 2))
				{
					while (b->min.index != 0 && bottom_sibbling.value != a->top.value)
					{
						if (a->top.value > b->top.value && b->top.value > a->last.value)
						{
							*hits += push_stack(a, b, "pa => min => rr");
							display_stacks(a, b);
						}
						else
						{
							*hits += rotate_stacks(a, b, "rr\n");
							display_stacks(a, b);
						}
					}

					while (bottom_sibbling.value != a->top.value)
					{
						if (a->top.value > b->top.value && b->top.value > a->last.value)
						{
							*hits += push_stack(a, b, "pa => min => ra");
							display_stacks(a, b);
						}
						else
						{
							*hits += rotate_stack(a, "ra\n");
							display_stacks(a, b);
						}
					}
				}
				else
				{
					while (bottom_sibbling.value != a->top.value)
					{
						if (a->top.value > b->top.value && b->top.value > a->last.value)
						{
							*hits += push_stack(a, b, "pa => min => rra\n");
							display_stacks(a, b);
						}
						else
						{
							*hits += rev_rotate_stack(a, "rra\n");
							display_stacks(a, b);
						}
					}

				}

				while (b->min.index != 0)
				{
					if (a->top.value > b->top.value && b->top.value > a->last.value)
					{
						*hits += push_stack(a, b, "pa => min => rb\n");
						display_stacks(a, b);
					}
					else
					{
						*hits += rotate_stack(b, "rb\n");
						display_stacks(a, b);
					}
				}
			}
		}
		else
		{
			bottom_sibbling = get_max_bottom_sibling(a, b->max.value);
			printf("move max %d above %d\n", b->max.value, bottom_sibbling.value);
			if (b->max.index > (b->size / 2))
			{
				if (bottom_sibbling.index > (a->size / 2))
				{
					while (b->max.index != 0 && bottom_sibbling.value != a->top.value)
					{
						// to check
						if (a->top.value > b->top.value && b->top.value > a->last.value)
						{
							*hits += push_stack(a, b, "pa => max => rrr\n");
							display_stacks(a, b);
						}
						else
						{
							*hits += rev_rotate_stacks(a, b, "rrr\n");
							display_stacks(a, b);
						}
					}

					while (bottom_sibbling.value != a->top.value)
					{
						// to check
						if (a->top.value > b->top.value && b->top.value > a->last.value)
						{
							*hits += push_stack(a, b, "pa => max => rra\n");
							display_stacks(a, b);
						}
						else
						{
							*hits += rev_rotate_stack(a, "rra\n");
							display_stacks(a, b);
						}
					}
				}
				else
				{
					while (bottom_sibbling.value != a->top.value)
					{
						// to check
						if (a->top.value > b->top.value && b->top.value > a->last.value)
						{
							*hits += push_stack(a, b, "pa => max => ra\n");
							display_stacks(a, b);
						}
						else
						{
							*hits += rotate_stack(a, "ra\n");
							display_stacks(a, b);
						}
					}
				}

				while (b->max.index != 0)
				{
					// to check
					if (a->top.value > b->top.value && b->top.value > a->last.value)
					{
						*hits += push_stack(a, b, "pa => max => rrb\n");
						display_stacks(a, b);
					}
					else
					{
						*hits += rev_rotate_stack(b, "rrb\n");
						display_stacks(a, b);
					}
				}
			}
			else
			{
				if (bottom_sibbling.index <= (a->size / 2))
				{
					while (b->max.index != 0 && bottom_sibbling.value != a->top.value)
					{
						if (a->top.value > b->top.value && b->top.value > a->last.value)
						{
							*hits += push_stack(a, b, "pa => max => rr\n");
							display_stacks(a, b);
						}
						else
						{
							*hits += rotate_stacks(a, b, "rr\n");
							display_stacks(a, b);
						}
					}

					while (bottom_sibbling.value != a->top.value)
					{
						// to check
						if (a->top.value > b->top.value && b->top.value > a->last.value)
						{
							*hits += push_stack(a, b, "pa => max => ra\n");
							display_stacks(a, b);
						}
						else
						{
							*hits += rotate_stack(a, "ra\n");
							display_stacks(a, b);
						}
					}
					
				}
				else
				{
					while (bottom_sibbling.value != a->top.value)
					{
						// to check
						if (a->top.value > b->top.value && b->top.value > a->last.value)
						{
							*hits += push_stack(a, b, "pa => max => rra\n");
							display_stacks(a, b);
						}
						else
						{
							*hits += rev_rotate_stack(a, "rra\n");
							display_stacks(a, b);
						}
					}
				}

				while (b->max.index != 0)
				{
					// to check
					if (a->top.value > b->top.value && b->top.value > a->last.value)
					{
						*hits += push_stack(a, b, "pa => max => rb\n");
						display_stacks(a, b);
					}
					else
					{
						*hits += rotate_stack(b, "rb\n");
						display_stacks(a, b);
					}
				}
			}
		}

		if (bottom_sibbling.value == a->top.value)
		{
			if (b->min.index == 0 || b->max.index == 0)
			{
				*hits += push_stack(a, b, "pa\n");
				display_stacks(a, b);
			}
		}
	}

	while (1)
	{
		if (is_sorted(a, ASC))
			break ;
		if (a->min.index > a->size / 2)
			while (a->min.index != 0)
				*hits += rev_rotate_stack(a, "rra\n");
		else
			while (a->min.index != 0)
				*hits += rotate_stack(a, "ra\n");
	}

	display_stacks(a, b);

	printf("coun_pa : %d\n", count_pa);
	printf("coun_pb: %d\n", count_pb);
	printf("coun_ra: %d\n", count_ra);
	printf("coun_rra: %d\n", count_rra);
	printf("coun_rb: %d\n", count_rb);
	printf("coun_rrb: %d\n", count_rrb);
	printf("coun_rr: %d\n", count_rr);
	printf("coun_rrr: %d\n", count_rrr);
	
	printf("total hits: %d\n", *hits);

	return (a);
}

t_stack	*sort(t_stack *a, t_stack *b, int *hits)
{
	if (a->size <= 3)
		return (sort_xs(a, hits));
	if (a->size <= 5)
		return (sort_sm(a, b, hits));
	return (sort_md(a, b, hits));

}
