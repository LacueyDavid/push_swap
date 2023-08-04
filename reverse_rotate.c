/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:02:45 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/17 18:08:03 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "libft.h"

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
