/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:42:15 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/12 20:09:24 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "../include/libft.h"

size_t	ft_strslen(char **strs)
{
	size_t	i;

	if (strs == NULL)
		return (0);
	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	is_input_just_one_arg(char **argv)
{
	if (argv[1] == NULL)
		return (1);
	return (0);
}

void	ft_bubble_sort(int *array, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size - 1)
	{
		if (array[index] > array[index + 1])
		{
			ft_swap(&array[index], &array[index + 1]);
			index = 0;
		}
		else
			index++;
	}
}

void	ft_strs_to_ints(int *array, char **argv)
{
	size_t	index;

	index = 0;
	while (argv[index])
	{
		array[index] = ft_atoi(argv[index]);
		index++;
	}
}
