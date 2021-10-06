/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_n_swap_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:26:56 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/11 15:27:33 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "stack.h"
#include "libft.h"

void	push_n_swap_a(t_stack *stack_a, t_stack *stack_b)
{
	while (!is_empty(stack_a) && peek(stack_a) < peek(stack_b))
	{
		ft_putstrnl("pa");
		push(stack_a, peek(stack_b));
		pop(stack_b);
		ft_putstrnl("sa");
		swap(stack_a);
	}
}
