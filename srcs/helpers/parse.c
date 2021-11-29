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

static void	check_duplicates(t_stack_list *list, int nbr)
{
	t_stack_list	*buff;

	buff = list;
	while (buff != NULL)
	{
		if (buff->item.value == nbr)
			escape(EXIT_FAILURE);
		buff = buff->next;
	}
}

static void	add_item(t_stack *stack, int nbr)
{
	int				i;
	t_stack_list	*new;
	t_stack_list	*buff;

	new = (t_stack_list *)malloc(sizeof(t_stack_list));
	if (new == NULL)
		escape(EXIT_FAILURE);
	i = -1;
	new->item.value = nbr;
	new->item.index = ++i;
	new->next = NULL;
	if (stack->list == NULL)
		stack->list = new;
	else
	{
		buff = stack->list;
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
			check_duplicates(stack->list, nbr);
			add_item(stack, nbr);
		}
		destroy_split(split);
	}
	return (stack);
}
