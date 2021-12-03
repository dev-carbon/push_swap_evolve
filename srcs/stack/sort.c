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

t_item	get_min_sibling(t_stack *s, int val)
{
	t_item			min;
	t_stack_list	*l;

	min = s->max;
	l = s->list;
	while (l)
	{
		if (l->item.value < min.value && l->item.value > val)
		{
			min = l->item;
			// break ;
		}
		l = l->next;
	}
	// printf("min sibbling: %d\n", min.value);
	return(min);
}

t_item	get_max_sibling(t_stack *s, int val)
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

t_stack	*sort_md(t_stack *a, t_stack *b, int *hits)
{
	int	min_gap;
	int	max_gap;
	t_item	near;
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
	while (1)
	{
		if (is_sorted(a, ASC))
			break ;
		if (a->top.value > a->last.value)
			*hits += rotate_stack(a, "ra\n");
		else
		{
			*hits += push_stack(b, a, "pb\n");
			count_pb++;
		}
	}
	printf("********* END PARTITION *******\n");
	display_stacks(a, b);
	// exit(0);
	while (1)
	{
		// break ;
		if (is_empty(b))
			break ;

		if (b->min.index < b->size / 2)
			min_gap = b->min.index;
		else
			min_gap = b->size - (b->min.index);
		if (b->max.index < b->size / 2)
			max_gap = b->max.index;
		else
			max_gap = b->size - (b->max.index);
		// printf("min| gap: %d, [%d] => %d\n", min_gap, b->min.index, b->min.value);
		// printf("max| gap: %d, [%d] => %d\n", max_gap, b->max.index, b->max.value);
		
		// move the minimun of B at the correct position in A
		if (min_gap < max_gap)
		{
			near = get_min_sibling(a, b->min.value);
			printf("move min %d above %d\n", b->min.value, near.value);
			
			// preform rrr
			if (b->min.index > (b->size / 2))
			{
				// preform rra ?
				if (near.index > (a->size / 2))
				{
					// printf("performing min rrr\n");
					while (b->min.index != 0 && near.value != a->top.value)
					{
						*hits += rev_rotate_stacks(a, b, "rrr\n");
						display_stacks(a, b);
						count_rrr++;
					}

					// do the rest of rra if possible
					while (near.value != a->top.value)
					{
						// printf("performing min rra\n");
						*hits += rev_rotate_stack(a, "rra\n");
						display_stacks(a, b);
						count_rra++;
					}
				}
				else
				{
					// printf("performing min ra\n");
					// perform ra
					while (near.value != a->top.value)
					{
						// printf("ok\n");
						*hits += rotate_stack(a, "ra\n");
						if (a->top.value > b->top.value && b->top.value > b->min.value)
						{
							*hits += push_stack(a, b, "pa\n");
							break ;
						}
						display_stacks(a, b);
						count_ra++;
					}
				}

				// do the rest of rrb if possible
				while (b->min.index != 0)
				{
					// printf("performing min rrb\n");
					*hits += rev_rotate_stack(b, "rrb\n");
					display_stacks(a, b);
					count_rrb++;
				}
			}
			// perform rr
			else
			{
				if (near.index <= (a->size / 2))
				{
					while (b->min.index != 0 && near.value != a->top.value)
					{
						// printf("ok\n");
						*hits += rotate_stacks(a, b, "rr\n");
						display_stacks(a, b);
						count_rr++;
					}
					// perform the rest of ra
					while (near.value != a->top.value)
					{
						// printf("ok\n");
						*hits += rotate_stack(a, "ra\n");
						display_stacks(a, b);
						count_ra++;
					}
					
				}
				else
				{
					// perform rra
					while (near.value != a->top.value)
					{
						*hits += rev_rotate_stack(a, "rra\n");
						display_stacks(a, b);
						count_rra++;
					}
				}

				while (b->min.index != 0)
				{
					// printf("performing min rb\n");
					*hits += rotate_stack(b, "rb\n");
					display_stacks(a, b);
					count_rb++;
				}
			}
		}
		// move the maximum of B at the right position in A
		else
		{
			// printf("min| gap: %d, [%d] => %d\n", min_gap, b->min.index, b->min.value);
			// printf("max| gap: %d, [%d] => %d\n", max_gap, b->max.index, b->max.value);

			near = get_max_sibling(a, b->max.value);
			// printf("move max %d above %d\n", b->max.value, near.value);
			
			// preform rrr
			if (b->max.index > (b->size / 2))
			{
				// preform rra ?
				if (near.index > (a->size / 2))
				{
					// printf("performinf max rrr\n");
					while (b->max.index != 0 && near.value != a->top.value)
					{
						*hits += rev_rotate_stacks(a, b, "rrr\n");
						display_stacks(a, b);
						count_rrr++;
					}

					// do the rest of rra if possible
					while (near.value != a->top.value)
					{
						// printf("performing max rra\n");
						*hits += rev_rotate_stack(a, "rra\n");
						display_stacks(a, b);
						count_rra++;
					}
				}
				else
				{
					// perform ra
					while (near.value != a->top.value)
					{
						*hits += rotate_stack(a, "ra\n");
						display_stacks(a, b);
						count_ra++;
					}
				}

				// do the rest of rrb if possible
				while (b->max.index != 0)
				{
					*hits += rev_rotate_stack(b, "rrb\n");
					display_stacks(a, b);
					count_rrb++;
				}
			}
			// perform rr
			else
			{
				if (near.index <= (a->size / 2))
				{
					while (b->max.index != 0 && near.value != a->top.value)
					{
						*hits += rotate_stacks(a, b, "rr\n");
						display_stacks(a, b);
						count_rr++;
					}
					// perform the rest of ra
					while (near.value != a->top.value)
					{
						*hits += rotate_stack(a, "ra\n");
						display_stacks(a, b);
						count_ra++;
					}
					
				}
				else
				{
					// perform rra
					while (near.value != a->top.value)
					{
						*hits += rev_rotate_stack(a, "rra\n");
						display_stacks(a, b);
						count_rra++;
					}
				}

				// do the rest of rb if possible
				while (b->max.index != 0)
				{
					*hits += rotate_stack(b, "rb\n");
					display_stacks(a, b);
					count_rb++;
				}
			}
		}
	}
	// printf("total hits: %d\n", *hits);
	while (1)
	{
		if (is_sorted(a, ASC))
			break ;
		// break;
		if (a->min.index > a->size / 2)
		{
			while (a->min.index != 0)
			{
				*hits += rev_rotate_stack(a, "rra\n");
				display_stacks(a, b);
				count_rra++;
			}
		}
		else
		{
			while (a->min.index != 0)
			{
				*hits += rotate_stack(a, "ra\n");
				display_stacks(a, b);
				count_ra++;
			}
		}
	}

	// display_stacks(a, b);

	// printf("coun_pa : %d\n", count_pa);
	// printf("coun_pb: %d\n", count_pb);
	// printf("coun_ra: %d\n", count_ra);
	// printf("coun_rra: %d\n", count_rra);
	// printf("coun_rb: %d\n", count_rb);
	// printf("coun_rrb: %d\n", count_rrb);
	// printf("coun_rr: %d\n", count_rr);
	// printf("coun_rrr: %d\n", count_rrr);
	printf("total hits: %d\n", *hits);

	return (a);
}

t_stack	*sort_lg(t_stack *a, t_stack *b, int *hits)
{
	int			pivot;
	int			count_pa;
	int			count_pb;
	int			count_ra;
	int			count_rb;
	int			count_rra;
	int			count_rrb;

	count_pa = 0;
	count_pb = 0;
	count_ra = 0;
	count_rb = 0;
	count_rra = 0;
	count_rrb = 0;
	pivot = get_pivot(a, b);
	// printf("\n*** PARTITION BEGIN *****\n\n");
	while (1)
	{
		if (a->top.value < pivot)
		{
			display_stacks(a, b);
			*hits += push_stack(b, a, "pb\n");
			count_pb++;
		}
		else if (is_rev_rotate(a, pivot))
		{
			*hits += rotate_stack(a, "rra\n");
			count_rra++;
		}
		else
		{
			display_stacks(a, b);
			*hits += rotate_stack(a, "ra\n");
			count_ra++;
		}
		if (is_sorted(a, ASC) && a->top.value > b->max.value)
			break ;
		if (is_empty(a))
			break ;
		if (a->min.value == pivot)
			pivot = get_pivot(a, b);
	}
	// printf("\n*** PARTITION END *****\n\n");
	while (!is_empty(b))
	{
		if (b->max.index <= b->size / 2)
		{
			while (b->max.value != b->top.value)
			{
				*hits += rotate_stack(b, "rb\n");
				count_rb++;
			}
		}
		else
		{
			while (b->max.value != b->top.value)
			{
				*hits += rev_rotate_stack(b, "rrb\n");
				count_rrb++;
			}
		}
		*hits += push_stack(a, b, "pa\n");
		count_pa++;
	}
	return (a);
}

t_stack	*sort(t_stack *a, t_stack *b, int *hits)
{
	if (a->size <= 3)
		return (sort_xs(a, hits));
	if (a->size <= 5)
		return (sort_sm(a, b, hits));
	if (a->size <= 100)
		return (sort_md(a, b, hits));
	return (sort_md(a, b, hits));

}
