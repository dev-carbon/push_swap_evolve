/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:06:06 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/05 21:06:10 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	swap_stack(t_stack *stack, char *label)
{
	swap(stack);
	refresh_stack(stack);
	write(STDOUT_FILENO, label, ft_strlen(label));
	return (1);
}

