/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:04:03 by humanfou          #+#    #+#             */
/*   Updated: 2021/11/06 12:15:40 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	destroy_list(t_stack_list *list)
{
	t_stack_list	*curent;

	if (list != NULL)
	{
		while (list != NULL)
		{
			curent = list;
			list = list->next;
			free(curent);
		}
	}
}
