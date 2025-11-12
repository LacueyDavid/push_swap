/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:02:06 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/12 20:08:18 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strdup(const char *s)
{
	size_t	index;
	char	*sdup;

	sdup = malloc(ft_strlen(s) + 1);
	if (!sdup)
		return (NULL);
	index = 0;
	while (s && s[index])
	{
		sdup[index] = s[index];
		index++;
	}
	sdup[index] = '\0';
	return (sdup);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 > *s2)
		return (1);
	if (*s1 < *s2)
		return (-1);
	return (0);
}

void	print_str(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	write(1, str, index);
}

int	ft_strcmp_without_sign_plus(char *s1, char *s2)
{
	if (s1[0] == '-' && s1[1] == '0' && s1[2] == '\0')
	{
		s1[0] = '0';
		(s1[1]) = '\0';
	}
	if (s2[0] == '-' && s2[1] == '0' && s2[2] == '\0')
	{
		s2[0] = '0';
		(s2[1]) = '\0';
	}
	if (*s1 == '+')
		s1++;
	if (*s2 == '+')
		s2++;
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 > *s2)
		return (1);
	if (*s1 < *s2)
		return (-1);
	return (0);
}
