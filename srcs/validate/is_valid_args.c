/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:25:03 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/02 13:25:05 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"
#include "struct.h"
#include "validate.h"
#include "utils.h"
#include "libft.h"

int	is_valid_args(int ac, char **av, t_vars *vars)
{
	int	i;
	int	j;

	if (ac > 2)
		return (0);
	i = -1;
	vars->split = ft_split(av[1], 32);
	while (vars->split[++i])
	{
		if (!is_valid_int(vars->split[i]))
			return (0);
		j = i;
		while (vars->split[++j])
			if (ft_atoi(vars->split[j]) == ft_atoi(vars->split[i]))
				return (0);
	}
	return (1);
}
