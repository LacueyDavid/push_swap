/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:01:00 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/12 21:21:09 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/libft.h"

int	is_bigger_than_int_max(char *str)
{
	int	sum_limit;
	int	sum_str;

	sum_limit = '2' + '1' + '4' + '7' + '4' + '8' + '3' + '6' + '4' + '7';
	sum_str = 0;
	while (*str)
	{
		sum_str += *str;
		str++;
	}
	if (sum_str > sum_limit)
		return (1);
	return (0);
}

int	is_smaller_than_int_min(char *str)
{
	int	sum_limit;
	int	sum_str;

	sum_limit = '2' + '1' + '4' + '7' + '4' + '8' + '3' + '6' + '4' + '8';
	sum_str = 0;
	str++;
	while (*str)
	{
		sum_str += *str;
		str++;
	}
	if (sum_str > sum_limit)
		return (1);
	return (0);
}

int	is_alphabetical(char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
		if (*str == '\0')
			return (1);
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int	is_duplicate(char *str, char **argv)
{
	int	error;

	error = 0;
	while (*argv)
	{
		if (ft_strcmp_without_sign_plus(str, *argv) == 0)
			error++;
		argv++;
	}
	if (error != 1)
		return (1);
	return (0);
}

int	is_an_int(char *str)
{
	int	error;

	error = 0;
	if (*str == '-')
		error += is_smaller_than_int_min(str);
	else
		error += is_bigger_than_int_max(str);
	return (error);
}
