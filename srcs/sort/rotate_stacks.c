/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:09:15 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/05 21:09:38 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	rotate_stacks(t_stack *a, t_stack *b, char *label)
{
	rotate(a);
	rotate(b);
	refresh_stack(a);
	refresh_stack(b);
	write(STDOUT_FILENO, label, ft_strlen(label));
	return (1);
}
