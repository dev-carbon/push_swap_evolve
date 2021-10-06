/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 00:57:50 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/07 00:57:51 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"
#include "utils.h"
#include "stack.h"

int	peek(t_stack *stack)
{
	if (!is_empty(stack))
		return (stack->elements->value);
	return (INT_MIN);
}
