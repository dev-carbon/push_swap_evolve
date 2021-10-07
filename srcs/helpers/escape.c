/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:34:40 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/06 08:38:52 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	escape(int status)
{
	if (status == EXIT_FAILURE)
		write(STDERR_FILENO, "Error\n", 6);
	exit(status);
}
