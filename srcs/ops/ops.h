/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:56:24 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/06 21:56:26 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

# include "push_swap.h"

t_stack	*push(t_stack *stack, int nbr);
t_stack	*swap(t_stack *stack);
t_stack	*pop(t_stack *stack);
t_stack	*rotate(t_stack *stack);
t_stack	*rev_rotate(t_stack *stack);

#endif
