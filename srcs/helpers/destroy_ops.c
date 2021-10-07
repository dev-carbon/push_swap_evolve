/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 04:13:44 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/07 04:13:48 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	destroy_ops(t_operation **ops)
{
	t_operation	*buff;
	t_operation	*current;

	buff = *ops;
	while (buff != NULL)
	{
		current = buff;
		buff = buff->next;
		free(current->label);
		free(current);
		current = NULL;
	}
	*ops = NULL;
}
