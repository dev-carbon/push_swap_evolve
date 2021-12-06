/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:18:09 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/07 12:18:11 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

t_stack	*sort(t_stack *a, t_stack *b, int *hits)
{
	if (a->size <= 3)
		return (sort_xs(a, hits));
	if (a->size <= 5)
		return (sort_sm(a, b, hits));
	create_partition(a, b, hits);
	sort_md(a, b, hits);
	bring_min_up(a, hits);
	return (a);
}
