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

void	bring_min_up(t_stack *stack, int *hits);
void	rev_rotate_min(t_stack *a, t_stack *b, int *hits,
			t_item bottom_sibbling);
void	rotate_min(t_stack *a, t_stack *b, int *hits, t_item bottom_sibbling);
void	rev_rotate_max(t_stack *a, t_stack *b, int *hits,
			t_item bottom_sibbling);
void	rotate_max(t_stack *a, t_stack *b, int *hits, t_item bottom_sibbling);
void	create_partition(t_stack *a, t_stack *b, int *hits);
int		get_pivot(t_stack *a, t_stack *b);
int		push_stack(t_stack *dest, t_stack *src, char *label);
int		swap_stack(t_stack *stack, char *label);
int		do_intermediate_push(t_stack *a, t_stack *b, int *hits, char *label);
int		get_pivot(t_stack *a, t_stack *b);
int		rev_rotate_stack(t_stack *stack, char *label);
int		rev_rotate_stacks(t_stack *a, t_stack *b, char *label);
int		is_rotate_min(t_stack *stack);
int		rotate_stack(t_stack *stack, char *label);
int		rotate_stacks(t_stack *a, t_stack *b, char *label);
int		swap_stack(t_stack *stack, char *label);
t_item	get_min_bottom_sibbling(t_stack *s, int val);
t_item	get_max_bottom_sibling(t_stack *s, int val);
t_stack	*refresh_stack(t_stack *stack);
t_stack	*sort_xs(t_stack *a, int *hits);
t_stack	*sort_sm(t_stack *a, t_stack *b, int *hits);
t_stack	*sort_md(t_stack *a, t_stack *b, int *hits);
t_stack	*sort(t_stack *a, t_stack *b, int *hits);

#endif
