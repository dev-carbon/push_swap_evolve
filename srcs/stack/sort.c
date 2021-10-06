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
#include "libs.h"
#include "utils.h"
#include "libft.h"
#include "ops.h"

t_stack	*sort(t_stack *sa)
{
	t_stack	*sb;

	sb = new_stack();
	while (!is_empty(sa))
	{
		if (is_empty(sb) && is_sorted(sa))
			break ;
		if (sa->size == 3 && !is_sorted(sa))
		{
			rotate_a(sa);
			rev_rotate_a(sa);
		}
		swap_a(sa);
		push_n_swap_a(sa, sb);
		if (!is_sorted(sa))
			push_b(sb, sa);
		else
			break ;
	}
	while (!is_empty(sb))
		push_a(sa, sb);
	destroy_stack(sb);
	return (sa);
}
