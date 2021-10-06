/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:12:23 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/11 11:12:27 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "libft.h"
#include "stack.h"

void	swap_a(t_stack *stack)
{
	if (stack->elements->value > stack->elements->next->value)
	{
		ft_putstrnl("sa");
		swap(stack);
	}
}