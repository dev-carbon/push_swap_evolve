/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:21:52 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/11 11:21:54 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "libft.h"
#include "stack.h"

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstrnl("pa");
	push(stack_a, peek(stack_b));
	pop(stack_b);
}
