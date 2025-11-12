/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:54:02 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/17 20:15:38 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/operations.h"
#include <limits.h>

size_t	find_position_a(t_stacks *stacks, size_t position)
{
	size_t	index;
	size_t	good_a_position;

	index = 0;
	good_a_position = ULONG_MAX;
	while (index < stacks->size_a)
	{
		if (stacks->a->position > position)
			if (good_a_position == ULONG_MAX
				|| stacks->a->position < good_a_position)
				good_a_position = stacks->a->position;
		index++;
		stacks->a = stacks->a->next;
	}
	stacks->a = stacks->head_a;
	return (good_a_position);
}

size_t	find_the_smallest(size_t sum[4], size_t size)
{
	size_t	index;
	size_t	smallest;

	index = 0;
	smallest = sum[0];
	while (index < size)
	{
		if (sum[index] < smallest)
			smallest = sum[index];
		index++;
	}
	return (smallest);
}

void	find_nb_of_moves(t_rotate_infos *infos)
{
	size_t	sum_of_rotates;
	size_t	sum_of_reverse_rotates;
	size_t	sum_rra_rb;
	size_t	sum_ra_rrb;
	size_t	sum[4];

	sum_of_rotates = infos->ra + infos->rb + infos->rr;
	sum_of_reverse_rotates = infos->rra + infos->rrb + infos->rrr;
	sum_rra_rb = infos->rra + infos->rb;
	sum_ra_rrb = infos->ra + infos->rrb;
	sum[0] = sum_of_rotates;
	sum[1] = sum_of_reverse_rotates;
	sum[2] = sum_rra_rb;
	sum[3] = sum_ra_rrb;
	infos->nb_of_moves = find_the_smallest(sum, 4);
}

//TODO : PROTECT TOUT LES MALLOC DU PROGRAMME!
t_rotate_infos	*find_fewest_moves(t_stacks *stacks)
{
	t_rotate_infos	*infos;
	size_t			good_a_position;

	infos = init_rotate_infos();
	if (infos == NULL)
		return (malloc_infos_fail(stacks, NULL, NULL), NULL);
	stacks->a = stacks->head_a;
	good_a_position = find_position_a(stacks, stacks->b->position);
	infos->position = stacks->b->position;
	infos->value = stacks->b->value;
	infos->ra = sum_of_ra(stacks, good_a_position);
	infos->rra = sum_of_rra(stacks, good_a_position);
	infos->rb = sum_of_rb(stacks);
	infos->rrb = sum_of_rrb(stacks);
	find_nb_of_moves(infos);
	return (infos);
}
