/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:21:52 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/02 13:22:11 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack)
{
	sort(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc > 1)
	{
		a = new_stack();
		parse(argv + 1, a);
		push_swap(a);
		destroy_stack(a);
	}
	return (0);
}
