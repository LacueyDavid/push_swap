/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:50:49 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/17 17:54:37 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/operations.h"
#include <limits.h>

size_t	sum_of_rra(t_stacks *stacks, size_t good_a_position)
{
	size_t	sum;

	sum = 0;
	stacks->a = stacks->head_a;
	while (stacks->a->position != good_a_position)
	{
		sum++;
		stacks->a = stacks->a->prev;
	}
	stacks->a = stacks->head_a;
	return (sum);
}

size_t	sum_of_ra(t_stacks *stacks, size_t good_a_position)
{
	size_t	sum;

	sum = 0;
	stacks->a = stacks->head_a;
	while (stacks->a->position != good_a_position)
	{
		sum++;
		stacks->a = stacks->a->next;
	}
	stacks->a = stacks->head_a;
	return (sum);
}

size_t	sum_of_rrb(t_stacks *stacks)
{
	size_t	sum;
	t_node	*actual_b;

	sum = 0;
	actual_b = stacks->b;
	while (stacks->b != stacks->head_b)
	{
		sum++;
		stacks->b = stacks->b->next;
	}
	stacks->b = actual_b;
	return (sum);
}

size_t	sum_of_rb(t_stacks *stacks)
{
	size_t	sum;
	t_node	*actual_b;

	sum = 0;
	actual_b = stacks->b;
	while (stacks->b != stacks->head_b)
	{
		sum++;
		stacks->b = stacks->b->prev;
	}
	stacks->b = actual_b;
	return (sum);
}
