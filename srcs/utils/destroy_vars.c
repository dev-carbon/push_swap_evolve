/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:10:41 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/08 18:10:42 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"
#include "utils.h"

void	destroy_vars(t_vars *vars)
{
	int	i;

	if (vars != NULL)
	{
		if (vars->split != NULL)
		{
			i = 0;
			while (vars->split[i] != NULL)
			{
				free(vars->split[i]);
				vars->split[i] = NULL;
				i++;
			}
			free(vars->split);
			vars->split = NULL;
		}
		free(vars);
		vars = NULL;
	}
}
