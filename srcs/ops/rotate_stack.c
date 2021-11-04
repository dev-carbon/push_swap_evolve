/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:07:09 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/09 23:14:34 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

void	rotate_stack(t_stack *stack, char *label)
{
	if (ft_strncmp(label, ROTATE_A, 2) == 0)
	{
		if (stack->max == stack->top)
		{
			rotate(stack);
			write(STDOUT_FILENO, label, 3);
		}
	}
	else if (ft_strncmp(label, ROTATE_B, 2) == 0)
	{
		if (stack->min == stack->top)
		{
			rotate(stack);
			write(STDOUT_FILENO, label, 3);
		}
	}
}
