/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:25:40 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/02 13:25:43 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "push_swap.h"

int	is_valid_args(int ac, char **av);
int	is_valid_int(char *str, long int nbr);
int	is_valid_operation(char *label);

#endif
