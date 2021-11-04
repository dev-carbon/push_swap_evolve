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

# include "push_swap.h"

void	swap_stack(t_stack *stack, char *label);
void	push_stack(t_stack *dst, t_stack *src, char *label);
void	rev_rotate_stack(t_stack *stack, char *label);
void	rotate_stack(t_stack *stack, char *label);
void	push_n_swap_stack(t_stack *dst, t_stack *src);

#endif