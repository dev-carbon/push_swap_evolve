/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:21:52 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/09 23:28:02 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

void	push_stack(t_stack *dst, t_stack *src, char *label)
{
	push(dst, peek(src));
	pop(src);
	write(STDOUT_FILENO, label, 3);
}
