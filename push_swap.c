/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:11:00 by dlacuey           #+#    #+#             */
/*   Updated: 2023/08/04 18:34:42 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

size_t	last_rotate_while_rrr(t_stacks *stacks)
{
	size_t	count;
	t_node	*tmp;

	tmp = stacks->a;
	count = 0;
	while (tmp->position != 0)
	{
		tmp = tmp->prev;
		count++;
	}
	return (count);
}

void	choose_last_rotate(t_stacks *stacks)
{
	size_t	count;
	size_t	count2;

	if (is_stacks_sorted(stacks->head_a, stacks->size_a))
		return ;
	count = last_rotate_while_rr(stacks);
	count2 = last_rotate_while_rrr(stacks);
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

int	check_if_sorted(t_stacks *stacks)
{
	t_node	*tmp;
	size_t	index;

	tmp = stacks->a;
	index = 0;
	if (tmp->position == stacks->size_a - 1
		&& tmp->next->position == stacks->size_a - 2)
	{
		swap_with_next(stacks->a);
		stacks->a = stacks->a->prev;
		stacks->head_a = stacks->a;
	}
	while (index < stacks->size_a)
	{
		if (is_stacks_sorted(tmp, stacks->size_a))
			return (1);
		tmp = tmp->next;
		index++;
	}
	return (0);
}

void	push_swap(t_stacks *stacks)
{
	if (check_if_sorted(stacks))
		return (choose_last_rotate(stacks));
	push_everything_to_b(stacks);
	if (stacks->a->position > stacks->a->next->position)
		last_swap_a(stacks);
	find_number_to_push_in_a(stacks);
	if (stacks->size_a == 0)
		return ;
	choose_last_rotate(stacks);
}
