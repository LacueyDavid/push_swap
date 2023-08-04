/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:05:01 by dlacuey           #+#    #+#             */
/*   Updated: 2023/08/04 18:35:13 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

void	push_top_or_bot(t_stacks *stacks, size_t size_divided,
								size_t begin_size, size_t div)
{
	size_t	top_div;

	top_div = size_divided - ((begin_size / div) / 2);
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

void	push_current_div_to_b(t_stacks *stacks, size_t size_divided,
								size_t begin_size, size_t div)
{
	size_t	index;
	size_t	start_size_a;

	index = 0;
	start_size_a = stacks->size_a;
	while (index < start_size_a && stacks->size_a > 2)
	{
		push_top_or_bot(stacks, size_divided, begin_size, div);
		index++;
	}
}

size_t	get_division(t_stacks *stacks)
{
	if (stacks->size_a <= 5)
		return (1);
	else if (stacks->size_a <= 100)
		return (2);
	else if (stacks->size_a <= 500)
		return (3);
	else if (stacks->size_a <= 1000)
		return (4);
	else
		return (5);
}

void	push_everything_to_b(t_stacks *stacks)
{
	size_t	div;
	size_t	begin_size;
	size_t	size_divided;

	div = get_division(stacks);
	begin_size = stacks->size_a;
	size_divided = begin_size / div;
	while (stacks->size_a > 2)
	{
		push_current_div_to_b(stacks, size_divided, begin_size, div);
		size_divided += begin_size / div;
	}
}

size_t	last_rotate_while_rr(t_stacks *stacks)
{
	size_t	count;
	t_node	*tmp;

	tmp = stacks->a;
	count = 0;
	while (tmp->position != 0)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
