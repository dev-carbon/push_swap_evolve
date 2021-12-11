/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 08:51:29 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/06 08:51:55 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_item
{
	int				index;
	int				value;
}	t_item;

typedef struct s_stack_list
{
	t_item				item;
	struct s_stack_list	*next;
}	t_stack_list;

typedef struct s_operation
{
	char				*label;
	int					len;
	struct s_operation	*next;
}	t_operation;

typedef struct s_stack
{
	int				size;
	t_item			top;
	t_item			next;
	t_item			start;
	t_item			end;
	t_item			last;
	t_item			min;
	t_item			max;
	t_stack_list	*list;
}	t_stack;

#endif
