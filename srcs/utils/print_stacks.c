/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:25:44 by humanfou          #+#    #+#             */
/*   Updated: 2021/06/10 16:25:47 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libs.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	t_element	*ela;
	t_element	*elb;

	ela = a->elements;
	elb = b->elements;
	printf("\n");
	if (a->size > b->size)
	{
		while (elb)
		{
			printf("%d %d\n", ela->value, elb->value);
			ela = ela->next;
			elb = elb->next;
		}
		while (ela)
		{
			printf("%d\n", ela->value);
			ela = ela->next;
		}
	}
	else
	{
		while (ela)
		{
			printf("%d %d\n", ela->value, elb->value);
			elb = elb->next;
			ela = ela->next;
		}
		while (elb)
		{
			printf("  %d\n", elb->value);
			elb = elb->next;
		}
	}
	printf("_ _\n");
	printf("a b\n\n");
}

