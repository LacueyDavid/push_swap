/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:11:00 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/17 16:36:58 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

static void	sort_two_left_a(t_stacks *stacks)
{
	if (stacks->a->position > stacks->a->next->position)
		swap_a(stacks);
}

static void	push_top_or_bot(t_stacks *stacks, size_t size_divided,
								size_t begin_size)
{
	size_t	top_div;

	top_div = size_divided - ((begin_size / DIVISION) / 2);
	if (top_div == 0)
		top_div = 1;
	if (stacks->head_a->position < size_divided
		&& stacks->head_a->position != begin_size - 1
		&& stacks->head_a->position != begin_size - 2)
	{
		if (stacks->a->position >= top_div)
		{
			push_b(stacks);
			if (stacks->a->position >= size_divided)
				rotate_a_and_b(stacks);
			else
				rotate_b(stacks);
		}
		else
			push_b(stacks);
	}
	else
		rotate_a(stacks);
}

static void	push_current_div_to_b(t_stacks *stacks, size_t size_divided,
								size_t begin_size)
{
	size_t	index;
	size_t	start_size_a;

	index = 0;
	start_size_a = stacks->size_a;
	while (index < start_size_a && stacks->size_a > 2)
	{
		push_top_or_bot(stacks, size_divided, begin_size);
		index++;
	}
}

#include <stdio.h>
static void	push_everything_to_b(t_stacks *stacks)
{
	size_t	div;
	size_t	begin_size;
	size_t	size_divided;

	div = DIVISION;
	begin_size = stacks->size_a;
	size_divided = begin_size / div;
	if (size_divided == 0)
		size_divided = 1;
	while (stacks->size_a > 2)
	{
		push_current_div_to_b(stacks, size_divided, begin_size);
		size_divided += begin_size / div;
	}
}

#include <stdio.h>
void	push_swap(t_stacks *stacks)
{
	push_everything_to_b(stacks);
	sort_two_left_a(stacks);
	find_number_to_push_in_a(stacks);
	t_node *tmp = stacks->a;
	t_node *tmp2 = stacks->a;
	size_t count = 0;
	size_t count2 = 0;
	while (tmp->position != 0)
	{
		tmp = tmp->next;
		count++;
	}
	while (tmp2->position != 0)
	{
		tmp2 = tmp2->prev;
		count2++;
	}
	if (count < count2)
	{
		while (stacks->a->position != 0)
			rotate_a(stacks);
	}
	else
	{
		while (stacks->a->position != 0)
			reverse_rotate_a(stacks);
	}
}
