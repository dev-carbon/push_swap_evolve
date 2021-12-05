/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:08:47 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/05 21:09:05 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	rotate_stack(t_stack *stack, char *label)
{
	rotate(stack);
	refresh_stack(stack);
	write(STDOUT_FILENO, label, ft_strlen(label));
	return (1);
}
