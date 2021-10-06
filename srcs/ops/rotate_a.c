/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:07:09 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/11 11:07:12 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "libft.h"
#include "stack.h"
#include "utils.h"

void	rotate_a(t_stack *stack)
{
	if (get_max_pos(stack) == 1)
	{
		ft_putstrnl("ra");
		rotate(stack);
	}
}