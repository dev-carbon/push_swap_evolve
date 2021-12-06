/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:09:55 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/05 21:10:22 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	rev_rotate_stack(t_stack *stack, char *label)
{
	rev_rotate(stack);
	refresh_stack(stack);
	write(STDOUT_FILENO, label, ft_strlen(label));
	return (1);
}
