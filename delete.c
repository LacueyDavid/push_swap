/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:33:11 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/12 22:49:22 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "array.h"

void	clear_arrays(t_arrays *arrays)
{
	if (arrays == NULL)
		return ;
	free(arrays->not_sorted);
	free(arrays->sorted);
	free(arrays);
}
