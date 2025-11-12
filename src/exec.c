/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:52:58 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/17 17:54:37 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/operations.h"
#include <limits.h>

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
	size_t	sum_of_rotates;
	size_t	sum_of_reverse_rotates;
	size_t	sum_rra_rb;
	size_t	sum_ra_rrb;

	sum_rra_rb = infos->rra + infos->rb;
	sum_ra_rrb = infos->ra + infos->rrb;
	sum_of_rotates = infos->ra + infos->rb + infos->rr;
	sum_of_reverse_rotates = infos->rra + infos->rrb + infos->rrr;
	if (sum_rra_rb == infos->nb_of_moves)
		exec_rra_rb(infos, stacks);
	else if (sum_ra_rrb == infos->nb_of_moves)
		exec_ra_rrb(infos, stacks);
	else if (sum_of_rotates == infos->nb_of_moves)
		exec_rotates(infos, stacks);
	else if (sum_of_reverse_rotates == infos->nb_of_moves)
		exec_reverse_rotates(infos, stacks);
}
