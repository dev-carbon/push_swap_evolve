/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 23:42:55 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/01 23:42:59 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid(char *str, char *base)
{
	int	i;
	int	j;
	int	count;

	if (str == NULL || *str == '\0')
		return (0);
	if (ft_strlen(base) == 1)
		return (0);
	i = -1;
	while (str[++i] != '\0')
	{
		j = -1;
		while (base[++j])
			if (str[i] == base[j])
				count += 1;
		if (count != 1)
			return (0);
	}
}

static int	get_char_position(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i] != '\0')
		if (c == base[i])
			return (i);
	return (0);
}

static int	get_power(int x, int y)
{
	int	pow;

	if (y < 0)
		return (-1);
	pow = 1;
	while (y--)
		pow *= x;
	return (pow);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	pos;
	int	base_len;
	int	nbr_len;
	int	nbr;

	if (is_valid(str, base))
	{
		nbr = 0;
		base_len = ft_strlen(base);
		nbr_len = ft_strlen(str);
		i = -1;
		while (str[++i] != '\0')
		{
			pos = get_char_position(str[i], base);
			if (pos < 0)
				break ;
			nbr = nbr + pos * get_power(base_len, nbr_len - 1);
			nbr_len -= 1;
		}
		return (nbr);
	}
	return (0);
}
