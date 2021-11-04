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

typedef struct s_items
{
	int				value;
	struct s_items	*next;
}	t_items;

typedef struct s_operation
{
	char				*label;
	int					len;
	struct s_operation	*next;
}	t_operation;

typedef struct s_stack
{
	int		size;
	int		top;
	int		last;
	int		max;
	int		min;
	t_items	*items;
}	t_stack;

#endif
