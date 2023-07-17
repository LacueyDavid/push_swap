# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 21:05:04 by dlacuey           #+#    #+#              #
#    Updated: 2023/07/14 05:26:53 by dlacuey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS =												\
				main.o								\
				tests_arrays.o						\
				tests_input.o						\
				tests_linked_list.o					\
				tests_operations.o					\
													\

OBJS_PUSH_SWAP =									\
													\
				$(addprefix ../,					\
				array.o								\
				delete.o							\
				error.o								\
				errors.o							\
				ft_atoi.o							\
				ft_split.o							\
				ft_substr.o							\
				libft.o								\
				libft_2.o							\
				libft_3.o							\
				linked_list.o						\
				operations.o						\
				rotate.o							\
				stacks.o							\
												)	\
													\

NAME = test_push_swap

all: $(NAME)

$(NAME): $(OBJS)
	make -C ../ all
	$(CC) -o $(NAME) $(OBJS) $(OBJS_PUSH_SWAP)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make -C ../ fclean

re: fclean all
	make -C ../ re

.PHONY: all clean fclean re bonus
