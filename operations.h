/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 02:53:15 by dlacuey           #+#    #+#             */
/*   Updated: 2023/08/04 16:57:42 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stacks.h"

void	push_b(t_stacks *stacks);
void	push_a(t_stacks *stacks);
void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	rotate_a_and_b(t_stacks *stacks);
void	reverse_rotate_a(t_stacks *stacks);
void	reverse_rotate_b(t_stacks *stacks);
void	reverse_rotate_a_and_b(t_stacks *stacks);
void	swap_with_next(t_node *node);
void	last_swap_a(t_stacks *stacks);

#endif
