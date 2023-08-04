/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:53:49 by dlacuey           #+#    #+#             */
/*   Updated: 2023/08/04 18:18:20 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "linked_list.h"
# include "stacks.h"

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

void			push_swap(t_stacks *stacks);
void			find_number_to_push_in_a(t_stacks *stacks);
size_t			sum_of_rra(t_stacks *stacks, size_t good_a_position);
size_t			sum_of_ra(t_stacks *stacks, size_t good_a_position);
size_t			sum_of_rrb(t_stacks *stacks);
size_t			sum_of_rb(t_stacks *stacks);
size_t			find_position_a(t_stacks *stacks, size_t position);
size_t			find_the_smallest(size_t sum[4], size_t size);
void			find_nb_of_moves(t_rotate_infos *infos);
t_rotate_infos	*find_fewest_moves(t_stacks *stacks);
void			exec_best_position(t_stacks *stacks, t_rotate_infos *infos);
void			exec_reverse_rotates(t_rotate_infos *infos, t_stacks *stacks);
void			exec_rotates(t_rotate_infos *infos, t_stacks *stacks);
void			exec_ra_rrb(t_rotate_infos *infos, t_stacks *stacks);
void			exec_rra_rb(t_rotate_infos *infos, t_stacks *stacks);
t_rotate_infos	*init_rotate_infos(void);
void			sort_two_left_a(t_stacks *stacks);
void			push_top_or_bot(t_stacks *stacks, size_t size_divided,
					size_t begin_size, size_t div);
void			push_current_div_to_b(t_stacks *stacks, size_t size_divided,
					size_t begin_size, size_t div);
void			push_everything_to_b(t_stacks *stacks);
size_t			last_rotate_while_rr(t_stacks *stacks);
int				is_stacks_sorted(t_node *head, size_t size);
void			malloc_infos_fail(t_stacks *stacks, t_rotate_infos *infos,
					t_rotate_infos *best_position_infos);

#endif
