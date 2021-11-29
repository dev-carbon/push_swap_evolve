/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:09:37 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/09 22:55:02 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

void	rev_rotate_stack(t_stack *stack, char *label)
{
	if (ft_strncmp(label, REV_ROTATE_A, 2) == 0)
	{
		if (stack->min.value == stack->last.value)
		{
			rev_rotate(stack);
			write(STDOUT_FILENO, label, 4);
		}
	}
}
