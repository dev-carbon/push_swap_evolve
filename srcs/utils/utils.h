/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:35:25 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/04 16:35:27 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

int		get_max_pos(t_stack *stack);
int		get_min_pos(t_stack *stack);
int		exit_prog(int status, t_vars *vars, t_stack *stack);
void	destroy_vars(t_vars *vars);
void	destroy_stack(t_stack *stack);
void	print_initial_stack(t_stack *stack);
void	print_stack(t_stack *stack);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);

#endif