/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:56:24 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/06 21:56:26 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "push_swap.h"

t_stack	*new_stack(void);
t_stack	*push(t_stack *stack, int nbr);
t_stack	*pop(t_stack *stack);
t_stack	*swap(t_stack *stack);
t_stack	*rotate(t_stack *stack);
t_stack	*rev_rotate(t_stack *stack);
t_stack	*sort(t_stack *a, t_stack *b, int *hits);
t_item	peek(t_stack *stack);

int		is_empty(t_stack *stack);
int		is_sorted(t_stack *stack, int order);

#endif
