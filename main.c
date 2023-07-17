/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:05:01 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/13 17:44:45 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"
#include "linked_list.h"
#include "array.h"
#include "libft.h"
#include "delete.h"
#include "stacks.h"

#include <stdio.h>

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
	push_swap(stacks);
	clear_linked_list(stacks->head_a, stacks->size_a);
	clear_linked_list(stacks->head_b, stacks->size_b);
	free(stacks);
	return (EXIT_SUCCESS);
}
