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

#include "sort.h"

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



t_stack	*sort_md(t_stack *a, t_stack *b, int *hits)
{

	t_item	bottom_sibbling;

	int	pivot;

	printf("********* PARTITION *******\n");
	create_partition(a, b, hits);
	printf("********* END PARTITION *******\n");
	display_stacks(a, b);
	if (a->size == 3)
		sort_xs(a, hits);
	display_stacks(a, b);
	while (!is_empty(b))
	{
		if (rotate_min(b))
		{
			bottom_sibbling = get_min_bottom_sibbling(a, b->min.value);
			printf("move min %d above %d\n", b->min.value, bottom_sibbling.value);			
			if (b->min.index > (b->size / 2))
			{
				if (bottom_sibbling.index > (a->size / 2))
				{
					while (b->min.index != 0 && bottom_sibbling.value != a->top.value)
						if (!do_intermediate_push(a, b, hits, "alt pa\n"))
							*hits += rev_rotate_stacks(a, b, "rrr\n");

					while (bottom_sibbling.value != a->top.value)
						if (!do_intermediate_push(a, b, hits, "alt pa\n"))
							*hits += rev_rotate_stack(a, "rra\n");
				}
				else
					while (bottom_sibbling.value != a->top.value)
						if (!do_intermediate_push(a, b, hits, "alt pa\n"))
							*hits += rotate_stack(a, "ra\n");

				while (b->min.index != 0)
					if (!do_intermediate_push(a, b, hits, "alt pa\n"))
						*hits += rev_rotate_stack(b, "rrb\n");
			}
			else
			{
				if (bottom_sibbling.index <= (a->size / 2))
				{
					while (b->min.index != 0 && bottom_sibbling.value != a->top.value)
						if (!do_intermediate_push(a, b, hits, "pa\n"))
							*hits += rotate_stacks(a, b, "rr\n");

					while (bottom_sibbling.value != a->top.value)
						if (!do_intermediate_push(a, b, hits, "pa\n"))
							*hits += rotate_stack(a, "ra\n");
				}
				else
					while (bottom_sibbling.value != a->top.value)
						if (!do_intermediate_push(a, b, hits, "pa\n"))
							*hits += rev_rotate_stack(a, "rra\n");

				while (b->min.index != 0)
					if (!do_intermediate_push(a, b, hits, "pa\n"))
						*hits += rotate_stack(b, "rb\n");
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
						if (!do_intermediate_push(a, b, hits, "pa\n"))
							*hits += rev_rotate_stacks(a, b, "rrr\n");

					while (bottom_sibbling.value != a->top.value)
						if (!do_intermediate_push(a, b, hits, "pa\n"))
							*hits += rev_rotate_stack(a, "rra\n");
				}
				else
					while (bottom_sibbling.value != a->top.value)
						if (!do_intermediate_push(a, b, hits, "pa\n"))
							*hits += rotate_stack(a, "ra\n");

				while (b->max.index != 0)
					if (!do_intermediate_push(a, b, hits, "pa\n"))
						*hits += rev_rotate_stack(b, "rrb\n");
			}
			else
			{
				if (bottom_sibbling.index <= (a->size / 2))
				{
					while (b->max.index != 0 && bottom_sibbling.value != a->top.value)
						if (!do_intermediate_push(a, b, hits, "pa\n"))
							*hits += rotate_stacks(a, b, "rr\n");

					while (bottom_sibbling.value != a->top.value)
						if (!do_intermediate_push(a, b, hits, "pa\n"))
							*hits += rotate_stack(a, "ra\n");
					
				}
				else
					while (bottom_sibbling.value != a->top.value)
						if (!do_intermediate_push(a, b, hits, "pa\n"))
							*hits += rev_rotate_stack(a, "rra\n");

				while (b->max.index != 0)
					if (!do_intermediate_push(a, b, hits, "pa\n"))
						*hits += rotate_stack(b, "rb\n");
			}
		}

		if (bottom_sibbling.value == a->top.value)
			if (b->min.index == 0 || b->max.index == 0)
				*hits += push_stack(a, b, "pa\n");
	}

	while (!is_sorted(a, ASC))
	{
		if (a->min.index > a->size / 2)
			while (a->min.index != 0)
				*hits += rev_rotate_stack(a, "rra\n");
		else
			while (a->min.index != 0)
				*hits += rotate_stack(a, "ra\n");
	}
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
