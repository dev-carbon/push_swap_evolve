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

#include "stack.h"
#include "libs.h"

void	destroy_stack(t_stack *stack)
{
	t_element	*el;
	t_element	*current;

	if (stack != NULL)
	{
		el = stack->elements;
		while (el)
		{
			current = el;
			el = el->next;
			free(current);
			current = NULL;
		}
		free(stack);
		stack = NULL;
	}
}
