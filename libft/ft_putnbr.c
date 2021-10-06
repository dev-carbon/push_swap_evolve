/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:54:48 by humanfou          #+#    #+#             */
/*   Updated: 2020/08/11 16:55:51 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	uintmax_t	unbr;

	unbr = n;
	if (unbr < 0)
	{
		ft_putchar('-');
		unbr = -unbr;
	}
	if (unbr > 9)
	{
		ft_putnbr(unbr / 10);
		ft_putnbr(unbr % 10);
	}
	else
		ft_putchar((unbr + 48));
}
