/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:36:03 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/07 13:36:05 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libs.h"
#include "utils.h"

t_stack	*push(t_stack *stack, int nbr)
{
	t_element	*new;
	t_element	*head;

	head = stack->elements;
	new = (t_element *)malloc(sizeof(t_element));
	if (new == NULL)
		exit_prog(EXIT_FAILURE, NULL, NULL);
	stack->size += 1;
	new->value = nbr;
	new->next = head;
	stack->elements = new;
	return (stack);
}
