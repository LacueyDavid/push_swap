/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:10:46 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/12 22:48:21 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"

static	int	is_empty(char *str)
{
	if (ft_strlen(str) == 0)
		return (1);
	return (0);
}

static	int	is_the_first_string_empty(char **argv)
{
	if (*argv == NULL)
		return (1);
	return (0);
}

static	int	is_input_incorrect_multiple_strings(char **argv)
{
	int	error;

	error = 0;
	error += is_the_first_string_empty(argv);
	while (*argv)
	{
		error += is_empty(*argv);
		error += is_alphabetical(*argv);
		error += is_duplicate(*argv, argv);
		error += is_an_int(*argv);
		argv++;
	}
	return (error);
}

int	is_input_incorrect(char **argv)
{
	char	**argv_cpy;
	int		error;

	if (is_input_just_one_arg(argv))
	{
		argv_cpy = ft_split(*argv, ' ');
		if (argv_cpy == NULL)
			return (1);
		error = is_input_incorrect_multiple_strings(argv_cpy);
		free_strs(argv_cpy);
		return (error);
	}
	return (is_input_incorrect_multiple_strings(argv));
}
