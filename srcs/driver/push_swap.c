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

int	main(int argc, char **argv)
{
	int		hits;
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		hits = 0;
		a = new_stack();
		b = new_stack();
		parse(argv + 1, a);
		if (!is_sorted(a, ASC))
		{
			refresh_stack(a);
			refresh_stack(b);
			sort(a, b, &hits);
		}
		display_result(a, b);
		// write(STDOUT_FILENO, "Total hits: ", 12);
		// ft_putnbr(hits);
		// write(STDOUT_FILENO, "\n", 1);
		destroy_stack(a);
		destroy_stack(b);
	}
	return (0);
}
