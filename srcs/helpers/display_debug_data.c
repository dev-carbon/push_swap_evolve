/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_debug_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 02:15:15 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/07 02:15:24 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	display_debug_data(t_stack *a, t_stack *b, int count)
{
	display_stacks(a, b);
	ft_putstr("\33[4mcount:\33[0m ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	ft_putstr("\33[4mExec:\33[0m ");
}
