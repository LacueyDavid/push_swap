/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:57:34 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/12 23:09:44 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

int	is_alphabetical(char *str);
int	is_duplicate(char *str, char **argv);
int	is_bigger_than_int_max(char *str);
int	is_smaller_than_int_min(char *str);
int	is_an_int(char *str);
int	is_input_just_one_arg(char **argv);
int	is_input_incorrect(char **argv);

#endif
