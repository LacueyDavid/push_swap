/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 04:22:16 by dlacuey           #+#    #+#             */
/*   Updated: 2023/08/04 14:46:58 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include "array.h"

void	clear_linked_list(t_node *stack, size_t size)
{
	t_node	*tmp;
	size_t	index;

	index = 0;
	if (stack == NULL)
		return ;
	while (index < size)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
		index++;
	}
}

t_node	*new_node(void)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->value = 0;
	new->position = -1;
	return (new);
}

int	find_position(int value, t_arrays *arrays)
{
	size_t	index;

	index = 0;
	while (index < arrays->size)
	{
		if (arrays->sorted[index] == value)
			return (index);
		index++;
	}
	return (-1);
}

// test au milieu de la boucle le malloc
void	create_linked_list(t_node *stack_a, t_arrays *arrays)
{
	size_t	index;
	t_node	*head;
	t_node	*tmp;

	index = 0;
	head = stack_a;
	tmp = stack_a;
	while (index < arrays->size)
	{
		index++;
		stack_a->next = new_node();
		if (stack_a->next == NULL)
		{
			head->value = -1;
			return (clear_linked_list(head, index));
		}
		stack_a->value = arrays->not_sorted[index - 1];
		stack_a->position = find_position(stack_a->value, arrays);
		stack_a->next->prev = stack_a;
		tmp = stack_a;
		stack_a = stack_a->next;
	}
	free(tmp->next);
	tmp->next = head;
	head->prev = tmp;
}
