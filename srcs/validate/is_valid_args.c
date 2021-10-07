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

#include "validate.h"

int	is_valid_args(int ac, char **av)
{
	char	**split;
	int		i;
	int		j;

	if (ac == 1)
		return (0);
	while (*av != NULL)
	{
		i = -1;
		split = ft_split(*av++, 0x20);
		while (split[++i])
		{
			if (!is_valid_int(split[i]))
				return (0);
			j = i;
			while (split[++j])
				if (ft_atoi(split[j]) == ft_atoi(split[i]))
					return (0);
		}
	}
	return (1);
}
