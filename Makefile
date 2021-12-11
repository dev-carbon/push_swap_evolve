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

RED = \33[31m
GREEN = \33[32m
YELLOW = \33[33m
BLUE = \33[34m
RESET = \33[0m

PUSH_SWAP = push_swap

CHECKER = checker

CC = clang

CFLAG = -Wall -Wextra -Werror

LIB = -Llibft -lft

SANITIZER = -fsanitize=address  -g

INC = -I./includes/ \
	-I./libft/ \
	-I./srcs/stack/ \
	-I./srcs/helpers/ \
	-I./srcs/ops/ \
	-I./srcs/sort/ \
	-I./srcs/validate/ \

COMMON_SRCS = srcs/helpers/is_empty.c \
	srcs/helpers/is_sorted.c \
	srcs/helpers/new_stack.c \
	srcs/helpers/peek.c \
	srcs/helpers/destroy_list.c \
	srcs/helpers/destroy_ops.c \
	srcs/helpers/destroy_split.c \
	srcs/helpers/destroy_stack.c \
	srcs/helpers/escape.c \
	srcs/helpers/execute.c \
	srcs/helpers/parse.c \
	srcs/helpers/display_debug_data.c \
	srcs/helpers/display_result.c \
	srcs/helpers/display_stack.c \
	srcs/helpers/display_stacks.c \
	srcs/ops/pop.c \
	srcs/ops/push.c \
	srcs/ops/rev_rotate.c \
	srcs/ops/rotate.c \
	srcs/ops/swap.c \
	srcs/sort/bring_min_up.c \
	srcs/sort/create_partition.c \
	srcs/sort/do_intermediate_push.c \
	srcs/sort/get_max_bottom_sibbling.c \
	srcs/sort/get_min_bottom_sibbling.c \
	srcs/sort/get_pivot.c \
	srcs/sort/is_rotate_min.c \
	srcs/sort/push_stack.c \
	srcs/sort/refresh_stack.c \
	srcs/sort/rev_rotate_min.c \
	srcs/sort/rev_rotate_max.c \
	srcs/sort/rev_rotate_stack.c \
	srcs/sort/rev_rotate_stacks.c \
	srcs/sort/rotate_min.c \
	srcs/sort/rotate_max.c \
	srcs/sort/rotate_stack.c \
	srcs/sort/rotate_stacks.c \
	srcs/sort/sort_xs.c \
	srcs/sort/sort_sm.c \
	srcs/sort/sort_md.c \
	srcs/sort/sort.c \
	srcs/sort/swap_stack.c \
	srcs/validate/is_valid_int.c \

COMMON_OBJS = $(COMMON_SRCS:.c=.o)

PUSH_SWAP_SRCS = srcs/driver/push_swap.c \

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

CHECKER_SRCS = srcs/driver/checker.c \
	srcs/validate/is_valid_operation.c \

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

$(PUSH_SWAP): $(COMMON_OBJS) $(PUSH_SWAP_OBJS)
	@echo "$(YELLOW)$(PUSH_SWAP) Creating libft ...$(RESET)"
	@$(MAKE) -sC libft
	@echo "$(YELLOW)Compiling $(PUSH_SWAP).$(RESET)"
	@$(CC) $(CFLAG) $(SANITIZER) $^ $(LIB) -o $@
	@echo "$(GREEN)$(PUSH_SWAP) ready.$(RESET)"

$(CHECKER): $(COMMON_OBJS) $(CHECKER_OBJS)
	@echo "$(YELLOW)$(CHECKER) Creating libft ...$(RESET)"
	@$(MAKE) -sC libft
	@echo "$(YELLOW)Compiling $(CHECKER).$(RESET)"
	@$(CC) $(CFLAG) $(SANITIZER) $^ $(LIB) -o $@
	@echo "$(GREEN)$(CHECKER) ready.$(RESET)"

all: $(PUSH_SWAP)

bonus: $(CHECKER)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $^ -o $@

clean:
	@$(MAKE) -sC libft clean
	@rm -f $(COMMON_OBJS) $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)

fclean:
	@$(MAKE) -sC libft fclean
	@rm -f $(CHECKER) $(COMMON_OBJS) $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)
	@rm -f $(PUSH_SWAP) $(CHECKER)

re: fclean all

norme:
	norminette libft includes srcs

.PHONY: all clean fclean re