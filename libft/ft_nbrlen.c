/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:50:18 by humanfou          #+#    #+#             */
/*   Updated: 2020/09/23 15:53:17 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(intmax_t number)
{
	size_t		len;
	uintmax_t	unumber;

	len = 0;
	if (number < 0)
	{
		len = 1;
		unumber = -number;
	}
	else
		unumber = number;
	while (unumber > 0)
	{
		unumber /= 10;
		len++;
	}
	return (len);
}
