/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:17:17 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/12 21:56:18 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strcmp(const char *s1, const char *s2);
void	print_str(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
size_t	ft_strslen(char **strs);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
int		ft_strcmp_without_sign_plus(char *s1, char *s2);
int		ft_atoi(const char *nptr);
void	ft_swap(int *a, int *b);
int		is_input_just_one_string(char **argv);
void	ft_bubble_sort(int *array, size_t size);
void	ft_strs_to_ints(int *array, char **argv);
void	free_strs(char **strs);
int		is_input_just_one_arg(char **argv);

#endif
