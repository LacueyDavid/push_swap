/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:52:06 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/17 16:29:15 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"
#include <limits.h>

#include <stdio.h>

// void	rra_rb(t_stacks *stacks)
// {
// 	reverse_rotate_a(stacks);
// 	rotate_b(stacks);
// }
//
// void	rrb_ra(t_stacks *stacks)
// {
// 	reverse_rotate_b(stacks);
// 	rotate_a(stacks);
// }
//
/*
		TODO :

		find_position_a
		sum of ra rra rb rrb
		find_rr_or_rrr
		find_nb_of_moves

		Exec best position
*/

size_t	find_position_a(t_stacks *stacks, size_t position)
{
	size_t	index;
	size_t	good_a_position;

	index = 0;
	good_a_position = ULONG_MAX;
	while (index < stacks->size_a)
	{
		if (stacks->a->position > position)
			if (good_a_position == ULONG_MAX || stacks->a->position < good_a_position)
				good_a_position = stacks->a->position;
		index++;
		stacks->a = stacks->a->next;
	}
	stacks->a = stacks->head_a;
	return (good_a_position);
}

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

void	find_rr_or_rrr(t_rotate_infos *infos)
{
	while (infos->ra > 0 && infos->rb > 0)
	{
		infos->ra--;
		infos->rb--;
		infos->rr++;
	}
	while (infos->rra > 0 && infos->rrb > 0)
	{
		infos->rra--;
		infos->rrb--;
		infos->rrr++;
	}
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
	size_t sum_of_rotates;
	size_t sum_of_reverse_rotates;
	size_t sum_rra_rb;
	size_t sum_ra_rrb;
	size_t sum[4];

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

t_rotate_infos	*find_fewest_moves(t_stacks *stacks)
{
	t_rotate_infos	*infos;
	size_t			good_a_position;

	infos = malloc(sizeof(t_rotate_infos));
	infos->ra = 0;
	infos->rra = 0;
	infos->rb = 0;
	infos->rrb = 0;
	infos->rr = 0;
	infos->rrr = 0;

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

void	exec_rra_rb(t_rotate_infos *infos, t_stacks *stacks)
{
	while (infos->rra > 0)
	{
		reverse_rotate_a(stacks);
		infos->rra--;
	}
	while (infos->rb > 0)
	{
		rotate_b(stacks);
		infos->rb--;
	}
	push_a(stacks);
}

void	exec_ra_rrb(t_rotate_infos *infos, t_stacks *stacks)
{
	while (infos->ra > 0)
	{
		rotate_a(stacks);
		infos->ra--;
	}
	while (infos->rrb > 0)
	{
		reverse_rotate_b(stacks);
		infos->rrb--;
	}
	push_a(stacks);
}

void	exec_rotates(t_rotate_infos *infos, t_stacks *stacks)
{
	while (infos->ra > 0 && infos->rb > 0)
	{
		rotate_a_and_b(stacks);
		infos->ra--;
		infos->rb--;
	}
	while (infos->ra > 0)
	{
		rotate_a(stacks);
		infos->ra--;
	}
	while (infos->rb > 0)
	{
		rotate_b(stacks);
		infos->rb--;
	}
	push_a(stacks);
}

void	exec_reverse_rotates(t_rotate_infos *infos, t_stacks *stacks)
{
	while (infos->rra > 0 && infos->rrb > 0)
	{
		reverse_rotate_a_and_b(stacks);
		infos->rra--;
		infos->rrb--;
	}
	while (infos->rra > 0)
	{
		reverse_rotate_a(stacks);
		infos->rra--;
	}
	while (infos->rrb > 0)
	{
		reverse_rotate_b(stacks);
		infos->rrb--;
	}
	push_a(stacks);
}

void	exec_best_position(t_stacks *stacks, t_rotate_infos *infos)
{
	size_t sum_of_rotates;
	size_t sum_of_reverse_rotates;
	size_t sum_rra_rb;
	size_t sum_ra_rrb;

	sum_rra_rb = infos->rra + infos->rb;
	sum_ra_rrb = infos->ra + infos->rrb;
	sum_of_rotates = infos->ra + infos->rb + infos->rr;
	sum_of_reverse_rotates = infos->rra + infos->rrb + infos->rrr;

	if(sum_rra_rb == infos->nb_of_moves)
		exec_rra_rb(infos, stacks);
	else if(sum_ra_rrb == infos->nb_of_moves)
		exec_ra_rrb(infos, stacks);
	else if(sum_of_rotates == infos->nb_of_moves)
		exec_rotates(infos, stacks);
	else if(sum_of_reverse_rotates == infos->nb_of_moves)
		exec_reverse_rotates(infos, stacks);
}

void	push_number_fewest_moves(t_stacks *stacks)
{
	size_t			index;
	t_rotate_infos	*best_position_infos;
	t_rotate_infos	*infos;
	size_t			first_pass;

	index = 0;
	first_pass = 0;
	stacks->b = stacks->head_b;
	best_position_infos = malloc(sizeof(t_rotate_infos));
	best_position_infos->nb_of_moves = 0;
	best_position_infos->value = 0;
	best_position_infos->position = 0;
	while (index < stacks->size_b)
	{
		infos = find_fewest_moves(stacks);
		if (first_pass == 0 || infos->nb_of_moves <= best_position_infos->nb_of_moves)
		{
			if (infos->nb_of_moves == best_position_infos->nb_of_moves)
			{
				if (infos->value > best_position_infos->value)
				{
					if (best_position_infos != NULL)
						free(best_position_infos);
					best_position_infos = infos;
					infos = NULL;
				}
			}
			else
			{
				if (best_position_infos != NULL)
					free(best_position_infos);
				best_position_infos = infos;
				infos = NULL;
			}
		}
		free(infos);
		stacks->b = stacks->b->next;
		index++;
		first_pass++;
	}
	stacks->b = stacks->head_b;
	exec_best_position(stacks, best_position_infos);
	free(best_position_infos);
}

void	find_number_to_push_in_a(t_stacks *stacks)
{
	while (stacks->size_b > 0)
	{
		push_number_fewest_moves(stacks);
	}
}
