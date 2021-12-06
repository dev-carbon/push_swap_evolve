/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:10:33 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/05 21:11:00 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	rev_rotate_stacks(t_stack *a, t_stack *b, char *label)
{
	rev_rotate(a);
	rev_rotate(b);
	refresh_stack(a);
	refresh_stack(b);
	write(STDOUT_FILENO, label, ft_strlen(label));
	return (1);
}
