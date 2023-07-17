/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:53:49 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/17 06:44:14 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "linked_list.h"
# include "stacks.h"

# ifndef DIVISION
#  define DIVISION 3
# endif

typedef struct rotate_infos
{
	size_t		ra;
	size_t		rb;
	size_t		rra;
	size_t		rrb;
	size_t		rr;
	size_t		rrr;
	size_t		nb_of_moves;
	size_t		position;
	size_t		value;
}				t_rotate_infos;

void	push_swap(t_stacks *stacks);
void	find_number_to_push_in_a(t_stacks *stacks);

#endif
