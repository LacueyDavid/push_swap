/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:59:46 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/17 19:24:19 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "linked_list.h"

typedef struct stacks
{
	t_node			*a;
	t_node			*head_a;
	t_node			*tail_a;
	size_t			size_a;
	t_node			*b;
	t_node			*head_b;
	t_node			*tail_b;
	size_t			size_b;
}					t_stacks;

t_stacks	*init_stacks(char **argv);
t_node		*init_stack(void);

#endif
