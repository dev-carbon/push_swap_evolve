/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:35:25 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/07 06:27:05 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include "push_swap.h"

int		get_max_pos(t_stack *stack);
int		get_min_pos(t_stack *stack);
void	execute(t_stack *a, t_stack *b, t_operation *op);
void	escape(int status);
void	destroy_stack(t_stack *stack);
void	destroy_items(t_items *items);
void	destroy_split(char **split);
void	destroy_ops(t_operation **ops);
void	display_debug_data(t_stack *a, t_stack *b, int count);
void	display_result(t_stack *a, t_stack *b);
void	display_stack(t_stack *stack);
void	display_stacks(t_stack *a, t_stack *b);

t_stack	*parse(char **argv, t_stack *stack);

#endif
