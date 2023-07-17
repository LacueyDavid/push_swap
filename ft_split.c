/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 07:02:56 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/11 07:08:36 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	strcount(char const *s, char c)
{
	size_t	count;
	size_t	index;

	count = 0;
	index = 0;
	while (s && s[index])
	{
		while (s[index] && s[index] == c)
			index++;
		if (s[index] && s[index] != c)
			count += 1;
		while (s[index] && s[index] != c)
			index++;
	}
	return (count);
}

static void	clearsplit(char **strsplit)
{
	size_t	index;

	index = 0;
	while (strsplit[index])
	{
		free(strsplit[index]);
		strsplit[index] = NULL;
		index++;
	}
}

static char	**strspliter(char **strsplit, char const *s, char c)
{
	size_t	start;
	size_t	len;
	size_t	index;

	start = 0;
	len = 0;
	index = 0;
	while (s && index < strcount(s, c))
	{
		len = 0;
		while (s[start] && s[start] == c)
			start++;
		while (s[len + start] && s[len + start] != c)
			len++;
		strsplit[index] = ft_substr(s, start, len);
		if (strsplit[index] == NULL)
		{
			clearsplit(strsplit);
			strsplit = NULL;
			return (NULL);
		}
		start = len + start;
		index++;
	}
	return (strsplit);
}

char	**ft_split(char const *s, char c)
{
	char	**strsplit;

	strsplit = malloc((strcount(s, c) + 1) * sizeof(char *));
	if (strsplit == NULL)
		return (NULL);
	strsplit[strcount(s, c)] = NULL;
	if (strspliter(strsplit, s, c) == NULL)
	{
		free(strsplit);
		return (NULL);
	}
	return (strsplit);
}
