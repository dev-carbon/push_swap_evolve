/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:03:10 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/11 11:03:12 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

# include "struct.h"

void	swap_a(t_stack *stack);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_n_swap_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_b, t_stack *stack_a);
void	rotate_a(t_stack *stack);
void	rev_rotate_a(t_stack *stack);

#endif