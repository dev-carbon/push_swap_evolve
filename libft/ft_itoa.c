/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:03:19 by humanfou          #+#    #+#             */
/*   Updated: 2020/09/23 19:57:06 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uintmax_t	init_nbr(int nbr)
{
	uintmax_t	unbr;

	if (nbr < 0)
		unbr = -nbr;
	else
		unbr = nbr;
	return (unbr);
}

char	*ft_itoa(intmax_t nbr)
{
	int			nbr_len;
	int			i;
	char		*ret;
	uintmax_t	unbr;

	unbr = init_nbr(nbr);
	nbr_len = ft_nbrlen(nbr);
	ret = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (unbr > 0)
	{
		ret[++i] = (int)unbr % 10 + '0';
		unbr /= 10;
	}
	if (nbr < 0)
		ret[++i] = '-';
	ret[++i] = '\0';
	ft_strrev(ret);
	return (ret);
}
