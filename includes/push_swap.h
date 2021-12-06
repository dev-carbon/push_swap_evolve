/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:09:24 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/01 19:11:23 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# include "libft.h"
# include "struct.h"
# include "helpers.h"
# include "ops.h"
# include "sort.h"
# include "validate.h"

# define SWAP_A "sa\n"
# define SWAP_B "sb\n"
# define SWAP_AB "ss\n"
# define PUSH_A "pa\n"
# define PUSH_B "pb\n"
# define ROTATE_A "ra\n"
# define ROTATE_B "rb\n"
# define ROTATE_AB "rr\n"
# define REV_ROTATE_A "rra\n"
# define REV_ROTATE_B "rrb\n"
# define REV_ROTATE_AB "rrr\n"

# define ASC 0x01
# define DESC 0x02

# define LABEL_MIN_LEN 2
# define LABEL_MAX_LEN 3

#endif
