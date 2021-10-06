/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:55:22 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/11 13:55:25 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "libft.h"
#include "stack.h"

void	push_b(t_stack *stack_b, t_stack *stack_a)
{
	ft_putstrnl("pb");
	push(stack_b, peek(stack_a));
	pop(stack_a);
}
