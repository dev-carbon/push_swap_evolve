/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 22:01:20 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/07 06:32:53 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	display_stack(t_stack *stack)
{
	t_items	*items;

	items = stack->items;
	while (items)
	{
		printf("% 15d |\n", items->value);
		items = items->next;
	}
	printf("________________ _______________\n");
	printf("         stack a stack b\n\n");
}
