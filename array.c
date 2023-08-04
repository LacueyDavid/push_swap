/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:15:27 by dlacuey           #+#    #+#             */
/*   Updated: 2023/08/04 15:00:12 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "delete.h"

void	ft_arraycpy(int *dest, int *src, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		dest[index] = src[index];
		index++;
	}
}

int	malloc_array_not_sorted_and_sorted_failed(t_arrays *arrays)
{
	arrays->not_sorted = malloc(sizeof(int) * arrays->size);
	if (arrays->not_sorted == NULL)
		return (1);
	arrays->sorted = malloc(sizeof(int) * arrays->size);
	if (arrays->sorted == NULL)
		return (1);
	return (0);
}

int	malloc_arrays_failed(t_arrays **arrays, char **argv)
{
	*arrays = malloc(sizeof(struct arrays));
	if (*arrays == NULL)
		return (1);
	(*arrays)->not_sorted = NULL;
	(*arrays)->sorted = NULL;
	(*arrays)->size = ft_strslen(argv);
	if (malloc_array_not_sorted_and_sorted_failed(*arrays))
		return (1);
	return (0);
}

t_arrays	*init_arrays(char **argv)
{
	t_arrays	*arrays;
	char		**argv_cpy;

	if (is_input_just_one_arg(argv))
	{
		argv_cpy = ft_split(*argv, ' ');
		if (argv_cpy == NULL)
			return (NULL);
		if (malloc_arrays_failed(&arrays, argv_cpy))
			return (clear_arrays(arrays), NULL);
		ft_strs_to_ints(arrays->not_sorted, argv_cpy);
		ft_arraycpy(arrays->sorted, arrays->not_sorted, arrays->size);
		ft_bubble_sort(arrays->sorted, arrays->size);
		free_strs(argv_cpy);
		return (arrays);
	}
	if (malloc_arrays_failed(&arrays, argv))
		return (clear_arrays(arrays), NULL);
	ft_strs_to_ints(arrays->not_sorted, argv);
	ft_arraycpy(arrays->sorted, arrays->not_sorted, arrays->size);
	ft_bubble_sort(arrays->sorted, arrays->size);
	return (arrays);
}
