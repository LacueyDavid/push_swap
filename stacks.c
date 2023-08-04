/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 00:01:31 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/17 19:32:18 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include "stacks.h"
#include "array.h"
#include "delete.h"

t_node	*init_stack(void)
{
	t_node	*stack;

	stack = malloc(sizeof(t_node));
	if (stack == NULL)
		return (NULL);
	stack->next = NULL;
	stack->prev = NULL;
	stack->value = 0;
	stack->position = -1;
	return (stack);
}

t_stacks	*init_stacks(char **argv)
{
	t_stacks	*stacks;
	t_arrays	*arrays;

	arrays = init_arrays(argv);
	if (arrays == NULL)
		return (NULL);
	stacks = malloc(sizeof(struct stacks));
	if (stacks == NULL)
		return (NULL);
	stacks->a = init_stack();
	if (stacks->a == NULL)
		return (NULL);
	stacks->head_a = stacks->a;
	stacks->size_a = arrays->size;
	stacks->size_b = 0;
	create_linked_list(stacks->a, arrays);
	stacks->tail_a = stacks->head_a->prev;
	clear_arrays(arrays);
	if (stacks->a->value == -1)
	{
		free(stacks->a);
		free(stacks);
		return (NULL);
	}
	return (stacks);
}
