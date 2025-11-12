/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:52:06 by dlacuey           #+#    #+#             */
/*   Updated: 2023/08/04 18:31:27 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/operations.h"
#include <limits.h>

t_rotate_infos	*init_rotate_infos(void)
{
	t_rotate_infos	*infos;

	infos = malloc(sizeof(t_rotate_infos));
	if (infos == NULL)
		return (NULL);
	infos->ra = 0;
	infos->rb = 0;
	infos->rr = 0;
	infos->rra = 0;
	infos->rrb = 0;
	infos->rrr = 0;
	infos->nb_of_moves = 0;
	infos->value = 0;
	infos->position = 0;
	return (infos);
}

void	choose_best_position_infos(t_rotate_infos **infos,
								t_rotate_infos **best_position_infos)
{
	if ((*infos)->nb_of_moves == (*best_position_infos)->nb_of_moves)
	{
		if ((*infos)->value > (*best_position_infos)->value)
		{
			if (*best_position_infos != NULL)
				free(*best_position_infos);
			*best_position_infos = *infos;
			*infos = NULL;
		}
	}
	else
	{
		if (*best_position_infos != NULL)
			free(*best_position_infos);
		*best_position_infos = *infos;
		*infos = NULL;
	}
}

void	malloc_infos_fail(t_stacks *stacks, t_rotate_infos *infos,
					t_rotate_infos *best_position_infos)
{
	clear_linked_list(stacks->head_a, stacks->size_a);
	clear_linked_list(stacks->head_b, stacks->size_b);
	free(infos);
	free(best_position_infos);
	stacks->size_b = 0;
	stacks->size_a = 0;
	infos = NULL;
	best_position_infos = NULL;
	stacks->head_a = NULL;
	stacks->head_b = NULL;
	stacks->a = NULL;
	stacks->b = NULL;
	return ;
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
	best_position_infos = init_rotate_infos();
	while (index < stacks->size_b)
	{
		infos = find_fewest_moves(stacks);
		if (best_position_infos == NULL || infos == NULL)
			return (malloc_infos_fail(stacks, infos, best_position_infos));
		if (first_pass == 0
			|| infos->nb_of_moves <= best_position_infos->nb_of_moves)
			choose_best_position_infos(&infos, &best_position_infos);
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
