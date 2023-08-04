/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:05:01 by dlacuey           #+#    #+#             */
/*   Updated: 2023/08/04 16:17:50 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"
#include "linked_list.h"
#include "array.h"
#include "libft.h"
#include "delete.h"
#include "stacks.h"

int	is_stacks_sorted(t_node *head, size_t size)
{
	t_node	*tmp;
	size_t	index;

	tmp = head;
	index = 0;
	while (index < size - 1)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
		index++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	argv++;
	if (is_input_incorrect(argv))
		return (print_str("Error\n"), 1);
	stacks = init_stacks(argv);
	if (stacks == NULL)
		return (print_str("Error\n"), 1);
	if (is_stacks_sorted(stacks->head_a, stacks->size_a))
		return (clear_linked_list(stacks->head_a, stacks->size_a),
			free(stacks),
			0);
	push_swap(stacks);
	clear_linked_list(stacks->head_a, stacks->size_a);
	clear_linked_list(stacks->head_b, stacks->size_b);
	free(stacks);
	return (EXIT_SUCCESS);
}
