/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:30:24 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/17 14:31:08 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "libft.h"

void	rotate_a(t_stacks *stacks)
{
	stacks->tail_a = stacks->a;
	stacks->a = stacks->a->next;
	stacks->head_a = stacks->a;
	print_str("ra\n");
}

void	rotate_b(t_stacks *stacks)
{
	stacks->tail_b = stacks->b;
	stacks->b = stacks->b->next;
	stacks->head_b = stacks->b;
	print_str("rb\n");
}

void	rotate_a_and_b(t_stacks *stacks)
{
	stacks->tail_b = stacks->b;
	stacks->b = stacks->b->next;
	stacks->head_b = stacks->b;
	stacks->tail_a = stacks->a;
	stacks->a = stacks->a->next;
	stacks->head_a = stacks->a;
	print_str("rr\n");
}

void	reverse_rotate_a(t_stacks *stacks)
{
	stacks->head_a = stacks->tail_a;
	stacks->a = stacks->tail_a;
	stacks->tail_a = stacks->tail_a->prev;
	print_str("rra\n");
}

void	reverse_rotate_b(t_stacks *stacks)
{
	stacks->head_b = stacks->tail_b;
	stacks->b = stacks->tail_b;
	stacks->tail_b = stacks->tail_b->prev;
	print_str("rrb\n");
}

void	reverse_rotate_a_and_b(t_stacks *stacks)
{
	stacks->head_a = stacks->tail_a;
	stacks->a = stacks->tail_a;
	stacks->tail_a = stacks->tail_a->prev;
	stacks->head_b = stacks->tail_b;
	stacks->b = stacks->tail_b;
	stacks->tail_b = stacks->tail_b->prev;
	print_str("rrr\n");
}

void	swap_a(t_stacks *stacks)
{
	t_node *tmp;
	tmp = stacks->head_a;
	stacks->head_a = stacks->tail_a;
	stacks->tail_a = tmp;
	// stacks->head_a->next = stacks->head_a->next->next;
	// stacks->head_a->prev = stacks->head_a->next;
	// stacks->head_a->prev->prev = stacks->tail_a;
	// stacks->tail_a->next = stacks->head_a->prev;
	// stacks->head_a->next->prev = stacks->head_a;
	print_str("sa\n");
}

