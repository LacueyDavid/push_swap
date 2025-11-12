/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:20:00 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/12 22:49:10 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stdlib.h>

typedef struct arrays
{
	int			*not_sorted;
	int			*sorted;
	size_t		size;
}				t_arrays;

t_arrays	*init_arrays(char **argv);

#endif
