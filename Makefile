# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 21:05:04 by dlacuey           #+#    #+#              #
#    Updated: 2023/07/17 18:08:41 by dlacuey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS =												\
													\
				push_swap_bis.o						\
				reverse_rotate.o					\
				sum.o								\
				exec.o								\
				find.o								\
				array.o								\
				delete.o							\
				error.o								\
				errors.o							\
				ft_atoi.o							\
				ft_split.o							\
				ft_substr.o							\
				linked_list.o						\
				libft_2.o							\
				libft_3.o							\
				libft.o								\
				main.o								\
				operations.o						\
				push_swap_2.o						\
				push_swap.o							\
				rotate.o							\
				stacks.o							\
													\

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
