/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:32:23 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/14 03:40:29 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_operation	*store_ops(t_operation **ops, char *label)
{
	t_operation		*new;
	t_operation		*buff;

	new = (t_operation *)malloc(sizeof(t_operation));
	if (!new)
		return (NULL);
	new->label = ft_strdup(label);
	new->len = ft_strlen(label);
	new->next = NULL;
	if (*ops == NULL)
		*ops = new;
	else
	{
		buff = *ops;
		while (buff->next != NULL)
			buff = buff->next;
		buff->next = new;
	}
	return (*ops);
}

static void	do_ops(t_stack *a, t_stack *b, t_operation *operations)
{
	t_operation	*op;

	op = operations;
	while (op != NULL)
	{
		execute(a, b, op);
		op = op->next;
	}
}

// static t_vars	*free_ops(t_vars *vars)
// {
// 	free(vars->ops->action->label);
// 	vars->ops->action->label = NULL;
// 	free(vars->ops->action);
// 	vars->ops->action = NULL;
// 	free(vars->ops);
// 	vars->ops = NULL;
// 	return (vars);
// }

static int	checker(t_stack *a)
{
	int				count;
	char			*label;
	t_operation		*ops;
	t_stack			*b;

	count = 0;
	ops = NULL;
	b = new_stack();
	ft_putstr("\n\33[4mExec\33[0m: ");
	while (get_next_line(STDIN_FILENO, &label) && is_valid_operation(label))
	{
		ops = store_ops(&ops, label);
		free(label);
		do_ops(a, b, ops);
		destroy_ops(&ops);
		display_debug_data(a, b, ++count);
	}
	free(label);
	display_stacks(a, b);
	display_result(a, b);
	destroy_stack(b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc > 1)
	{
		stack = new_stack();
		parse(argv + 1, stack);
		display_stack(stack);
		checker(stack);
		destroy_stack(stack);
	}
	return (0);
}