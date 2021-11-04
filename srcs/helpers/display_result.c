/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 04:55:25 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/07 04:55:26 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	display_result(t_stack *a, t_stack *b)
{
	if (is_empty(b) && is_sorted(a, ASC))
		ft_putendl_fd("\33[32mOK\33[0m\n", STDOUT_FILENO);
	else
		ft_putendl_fd("\33[31mKO\33[0m\n", STDOUT_FILENO);
}
