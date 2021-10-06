/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:05:56 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/01 17:06:00 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_element
{
	int					value;
	struct s_element	*next;
}	t_element;

typedef struct s_stack
{
	int			size;
	t_element	*elements;
}	t_stack;

typedef struct s_vars
{
	char	**split;
	char	*str;
	int		flag;
}	t_vars;

typedef struct s_operation
{
	char	*label;
	int		len;
}	t_operation;

#endif
