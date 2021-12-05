/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:57:43 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/05 20:57:47 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	push_stack(t_stack *dest, t_stack *src, char *label)
{
	push(dest, src->top.value);
	refresh_stack(dest);
	pop(src);
	refresh_stack(src);
	write(STDOUT_FILENO, label, ft_strlen(label));
	return (1);
}