/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:36:31 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/07 13:36:33 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libs.h"
#include "libft.h"

t_stack	*rev_rotate(t_stack *stack)
{
	t_element	*head;
	t_element	*next;

	head = stack->elements;
	next = head->next;
	while (next)
	{
		ft_swap(&head->value, &next->value);
		next = next->next;
	}
	return (stack);
}
