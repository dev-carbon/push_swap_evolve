# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humanfou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 13:28:50 by humanfou          #+#    #+#              #
#    Updated: 2021/06/02 13:28:52 by humanfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = clang

CCFLAG = -Wall -Wextra -Werror -g

LIBFT = -Llibft -lft

# SANITIZE = -fsanitize=address

HEADERS = -I./includes/ \
		-I./libft/ \
		-I./srcs/ops/ \
		-I./srcs/stack/ \
		-I./srcs/utils/ \
		-I./srcs/validate/ \

SRCS_MANDATORY = srcs/driver/push_swap.c \
				srcs/ops/push_a.c \
				srcs/ops/push_n_swap_a.c \
				srcs/ops/push_b.c \
				srcs/ops/rotate_a.c \
				srcs/ops/rev_rotate_a.c \
				srcs/ops/swap_a.c \
				srcs/stack/swap.c \
				srcs/stack/push.c \
				srcs/stack/rotate.c \
				srcs/stack/rev_rotate.c \
				srcs/stack/new_stack.c \
				srcs/stack/fill.c \
				srcs/stack/push.c \
				srcs/stack/pop.c \
				srcs/stack/peek.c \
				srcs/stack/sort.c \
				srcs/stack/is_empty.c \
				srcs/stack/is_sorted.c \
				srcs/utils/print_initial_stack.c \
				srcs/utils/print_stack.c \
				srcs/utils/print_stacks.c \
				srcs/utils/get_min_pos.c \
				srcs/utils/get_max_pos.c \
				srcs/utils/destroy_stack.c \
				srcs/utils/destroy_vars.c \
				srcs/utils/exit_prog.c \
				srcs/validate/is_valid_args.c \
				srcs/validate/is_valid_int.c \

OBJS_MANDATORY = $(SRCS_MANDATORY: %.c=%.o)

all: $(NAME)

$(NAME): 	$(OBJS_MANDATORY)
			@$(MAKE) --directory=libft
			@$(CC) $(CCFLAG) $(HEADERS) $(SANITIZE) -o $@ $^ $(LIBFT)

clean:
	cd libft && $(MAKE) clean
	@$(RM) *.o

fclean: clean
	cd libft && $(MAKE) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re