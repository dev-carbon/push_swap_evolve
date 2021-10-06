/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 22:01:20 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/06 22:01:22 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libs.h"
#include "libft.h"

void	print_stack(t_stack *stack)
{
	t_element	*el;

	el = stack->elements;
	while (el)
	{
		ft_putnbr(el->value);
		write(1, "\n", 1);
		el = el->next;
	}
	write(1, "\n", 1);
}
