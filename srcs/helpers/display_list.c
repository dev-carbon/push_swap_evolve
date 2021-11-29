/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:27:15 by humanfou          #+#    #+#             */
/*   Updated: 2021/11/29 17:27:17 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	display_list(t_stack *stack)
{
	t_stack_list *list;

	list = stack->list;
	while (list != NULL)
	{
		printf("[%d] => %d\n",list->item.index, list->item.value);
		list = list->next;
	}
}
