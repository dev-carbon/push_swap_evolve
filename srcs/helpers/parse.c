/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:15:21 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/06 23:15:23 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

static void	check_duplicates(t_items *items, int nbr)
{
	t_items	*buff;

	buff = items;
	while (buff != NULL)
	{
		if (buff->value == nbr)
			escape(EXIT_FAILURE);
		buff = buff->next;
	}
}

static void	add_item(t_stack *stack, int nbr)
{
	t_items	*new;
	t_items	*buff;

	new = (t_items *)malloc(sizeof(t_items));
	if (new == NULL)
		escape(EXIT_FAILURE);
	new->value = nbr;
	new->next = NULL;
	if (stack->items == NULL)
		stack->items = new;
	else
	{
		buff = stack->items;
		while (buff->next != NULL)
			buff = buff->next;
		buff->next = new;
	}
	stack->size++;
}

t_stack	*parse(char **argv, t_stack *stack)
{
	int			i;
	long int	nbr;
	char		**split;

	while (*argv != NULL)
	{
		i = -1;
		split = ft_split(*argv++, 0x20);
		while (split[++i])
		{
			nbr = ft_atoi(split[i]);
			if (!is_valid_int(split[i], nbr))
				escape(EXIT_FAILURE);
			check_duplicates(stack->items, nbr);
			add_item(stack, nbr);
		}
		destroy_split(split);
	}
	return (stack);
}
