/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:34:40 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/04 16:46:51 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"
#include "struct.h"
#include "utils.h"
#include "libft.h"

int	exit_prog(int status, t_vars *vars, t_stack *stack)
{
	if (status == EXIT_FAILURE)
		write(STDERR_FILENO, "Error\n", 6);
	if (status == EXIT_SUCCESS)
		write(STDOUT_FILENO, "Bye!\n", 5);
	destroy_vars(vars);
	destroy_stack(stack);
	exit(status);
	return (0);
}
