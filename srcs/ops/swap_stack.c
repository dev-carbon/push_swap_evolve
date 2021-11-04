/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:12:23 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/09 22:58:22 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

void	swap_stack(t_stack *stack, char *label)
{
	if (stack->size > 1)
	{
		if (ft_strncmp(label, SWAP_A, 2) == 0)
		{
			if (stack->items->value > stack->items->next->value)
			{
				swap(stack);
				write(STDOUT_FILENO, label, 3);
			}
		}
		else if (ft_strncmp(label, SWAP_B, 2) == 0)
		{
			if (stack->items->value < stack->items->next->value)
			{
				swap(stack);
				write(STDOUT_FILENO, label, 3);
			}
		}
	}
}
