/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:39:35 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/04 17:42:02 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	is_valid_int(char *str, long int nbr)
{
	int			i;

	i = -1;
	if (*str == '-' || *str == '+')
		i++;
	while (str[++i] != '\0')
		if (!ft_isdigit(str[i]))
			return (0);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	return (1);
}
