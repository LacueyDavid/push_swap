/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:30:24 by dlacuey           #+#    #+#             */
/*   Updated: 2023/08/04 17:17:27 by dlacuey          ###   ########.fr       */
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

void	last_swap_a(t_stacks *stacks)
{
	t_node	*tmp;

	tmp = stacks->head_a;
	stacks->head_a = stacks->tail_a;
	stacks->tail_a = tmp;
	print_str("sa\n");
}

void	swap_with_next(t_node *node)
{
	t_node	*tmp;
	t_node	*node_next;
	t_node	*node_prev;

	node_prev = node->prev;
	node_next = node->next->next;
	tmp = node->next;
	node_prev->next = tmp;
	tmp->next = node;
	node->next = node_next;
	node_next->prev = node;
	node->prev = tmp;
	tmp->prev = node_prev;
	print_str("sa\n");
}
