/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:58:34 by humanfou          #+#    #+#             */
/*   Updated: 2021/12/05 20:58:37 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"

void	create_partition(t_stack *a, t_stack *b, int *hits);

int	push_stack(t_stack *dest, t_stack *src, char *label);
int	swap_stack(t_stack *stack, char *label);
int	do_intermediate_push(t_stack *a, t_stack *b, int *hits, char *label);
int	get_pivot(t_stack *a, t_stack *b);

t_item	get_min_bottom_sibbling(t_stack *s, int val);
t_item	get_max_bottom_sibling(t_stack *s, int val);

t_stack	*refresh_stack(t_stack *stack);
t_stack	*sort(t_stack *a, t_stack *b, int *hits);


#endif

