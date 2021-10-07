/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:59:51 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/08 18:03:32 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	destroy_stack(t_stack *stack)
{
	if (stack != NULL)
	{
		destroy_items(stack->items);
		free(stack);
		stack = NULL;
	}
}
