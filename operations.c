/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 02:57:53 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/17 17:15:04 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "libft.h"

void	delnode_b(t_stacks *stacks)
{
	stacks->head_b = stacks->head_b->next;
	stacks->b->prev->next = stacks->head_b;
	stacks->head_b->prev = stacks->b->prev;
	stacks->b = stacks->head_b;
	stacks->size_b -= 1;
}

void	delnode_a(t_stacks *stacks)
{
	stacks->head_a = stacks->head_a->next;
	stacks->a->prev->next = stacks->head_a;
	stacks->head_a->prev = stacks->a->prev;
	stacks->a = stacks->head_a;
	stacks->size_a -= 1;
}

void	first_push_b(t_stacks *stacks, t_node *node_a)
{
	stacks->head_b = node_a;
	stacks->b = stacks->head_b;
	stacks->tail_b = stacks->head_b;
	stacks->head_b->next = stacks->head_b;
	stacks->head_b->prev = stacks->head_b;
	stacks->size_b = 1;
}

void	push_b(t_stacks *stacks)
{
	t_node	*head_a;

	head_a = stacks->a;
	if (stacks->size_b == 0)
	{
		delnode_a(stacks);
		first_push_b(stacks, head_a);
		print_str("pb\n");
		return ;
	}
	delnode_a(stacks);
	stacks->tail_b->next = head_a;
	stacks->head_b->prev = head_a;
	stacks->b = head_a;
	stacks->b->next = stacks->head_b;
	stacks->b->prev = stacks->tail_b;
	stacks->head_b = head_a;
	stacks->size_b += 1;
	print_str("pb\n");
}

void	push_a(t_stacks *stacks)
{
	t_node	*head_b;

	head_b = stacks->b;
	delnode_b(stacks);
	stacks->tail_a->next = head_b;
	stacks->head_a->prev = head_b;
	stacks->a = head_b;
	stacks->a->next = stacks->head_a;
	stacks->a->prev = stacks->tail_a;
	stacks->head_a = head_b;
	stacks->size_a += 1;
	print_str("pa\n");
}
