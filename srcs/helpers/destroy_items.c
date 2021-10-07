/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_items.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:04:03 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/06 23:04:05 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	destroy_items(t_items *items)
{
	t_items	*curent;

	if (items != NULL)
	{
		while (items != NULL)
		{
			curent = items;
			items = items->next;
			free(curent);
		}
	}
}
