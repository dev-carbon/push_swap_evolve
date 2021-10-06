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

#include "libs.h"
#include "libft.h"
#include "struct.h"
#include "stack.h"
#include "validate.h"
#include "utils.h"

int	main(int ac, char **av)
{
	t_vars	*vars;
	t_stack	*stack;

	if (ac > 1)
	{
		vars = (t_vars *)malloc(sizeof(t_vars));
		if (vars == NULL)
			exit_prog(EXIT_FAILURE, NULL, NULL);
		if (!is_valid_args(ac, av, vars))
			exit_prog(EXIT_FAILURE, vars, NULL);
		stack = new_stack();
		fill(stack, vars->split);
		print_initial_stack(stack);
		ft_putstrnl("\n\e[4mOperations\e[m:");
		sort(stack);
		ft_putstrnl("\n\e[4mFinal stack\e[m:");
		print_stack(stack);
		exit_prog(EXIT_SUCCESS, vars, stack);
	}
	return (0);
}
