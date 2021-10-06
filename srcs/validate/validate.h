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

# include "struct.h"

int	is_valid_args(int ac, char **av, t_vars *vars);
int	is_valid_int(char *str);

#endif
