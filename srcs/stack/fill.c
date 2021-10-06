/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:55:09 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/06 21:55:29 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libs.h"
#include "libft.h"

t_stack	*fill(t_stack *stack, char **list)
{
	int	i;

	i = ft_split_len(list);
	while (--i >= 0)
		stack = push(stack, ft_atoi(list[i]));
	return (stack);
}
