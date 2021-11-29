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

void	push_n_swap_a(t_stack *sa, t_stack *sb)
{
	while (!is_empty(sb) && sa->top.value < sb->top.value)
	{
		write(STDOUT_FILENO, PUSH_A, 3);
		push(sa, peek(sb).value);
		pop(sb);
		write(STDOUT_FILENO, "sa\n", 3);
		swap(sa);
	}
}
