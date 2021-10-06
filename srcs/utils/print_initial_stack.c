/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_initial_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:48:33 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/11 14:48:34 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libs.h"
#include "libft.h"

void	print_initial_stack(t_stack *stack)
{
	t_element	*el;

	el = stack->elements;
	ft_putstrnl("\e[4mInitial stack\e[m:");
	while (el)
	{
		ft_putnbr(el->value);
		write(1, "\n", 1);
		el = el->next;
	}
	write(1, "\n", 1);
}
