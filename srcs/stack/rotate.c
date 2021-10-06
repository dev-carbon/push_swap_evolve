/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:36:21 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/07 13:36:23 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libs.h"
#include "libft.h"

t_stack	*rotate(t_stack *stack)
{
	t_element	*el;

	el = stack->elements;
	while (el->next != NULL)
	{
		ft_swap(&el->value, &el->next->value);
		el = el->next;
	}
	return (stack);
}
