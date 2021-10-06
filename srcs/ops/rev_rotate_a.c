/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:09:37 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/11 11:09:39 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "libft.h"
#include "stack.h"
#include "utils.h"

void	rev_rotate_a(t_stack *stack)
{
	if (get_min_pos(stack) == 3)
	{
		ft_putstrnl("rra");
		rev_rotate(stack);
	}
}