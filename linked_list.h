/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 04:23:35 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/17 19:24:19 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdlib.h>
# include "array.h"

typedef struct node
{
	struct node			*next;
	struct node			*prev;
	int					value;
	size_t				position;
}						t_node;

void	create_linked_list(t_node *stack_a, t_arrays *arrays);
void	clear_linked_list(t_node *stack, size_t size);

#endif
