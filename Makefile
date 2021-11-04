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

CFLAG = -Wall -Wextra -Werror -g

LIB = -Llibft -lft

SANITIZER = -fsanitize=address

INC = -I./includes/ \
	-I./libft/ \
	-I./srcs/ops/ \
	-I./srcs/stack/ \
	-I./srcs/helpers/ \
	-I./srcs/validate/ \

COMMON_SRCS = srcs/ops/push_stack.c \
	srcs/ops/push_n_swap_a.c \
	srcs/ops/rev_rotate_stack.c \
	srcs/ops/rotate_stack.c \
	srcs/ops/swap_stack.c \
	srcs/stack/is_empty.c \
	srcs/stack/is_sorted.c \
	srcs/stack/new_stack.c \
	srcs/stack/peek.c \
	srcs/stack/pop.c \
	srcs/stack/push.c \
	srcs/stack/rev_rotate.c \
	srcs/stack/rotate.c \
	srcs/stack/sort.c \
	srcs/stack/swap.c \
	srcs/helpers/destroy_items.c \
	srcs/helpers/destroy_ops.c \
	srcs/helpers/destroy_split.c \
	srcs/helpers/destroy_stack.c \
	srcs/helpers/escape.c \
	srcs/helpers/execute.c \
	srcs/helpers/get_max_pos.c \
	srcs/helpers/get_min_pos.c \
	srcs/helpers/parse.c \
	srcs/helpers/display_debug_data.c \
	srcs/helpers/display_result.c \
	srcs/helpers/display_stack.c \
	srcs/helpers/display_stacks.c \
	srcs/validate/is_valid_int.c \

COMMON_OBJS = $(COMMON_SRCS: .c=.o)

PUSH_SWAP_SRCS = srcs/driver/push_swap.c \

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS: .c=.o)

CHECKER_SRCS = srcs/driver/checker.c \
	srcs/validate/is_valid_operation.c \

CHECKER_OBJS = $(CHECKER_SRCS: .c=.o)

all: $(PUSH_SWAP)

bonus: $(CHECKER)

$(PUSH_SWAP): $(COMMON_OBJS) $(PUSH_SWAP_OBJS)
	@echo "$(YELLOW)$(PUSH_SWAP): Creating libft.$(RESET)"
	@$(MAKE) -sC libft
	@echo "$(YELLOW)Compiling $(PUSH_SWAP).$(RESET)"
	@$(CC) $(CFLAG) $(SANITIZER) -o $@ $(INC) $^ $(LIB)
	@echo "$(GREEN)[Ok] $(PUSH_SWAP) ready.$(RESET)"

$(CHECKER): $(COMMON_OBJS) $(CHECKER_OBJS)
	@echo "$(YELLOW)$(CHECKER): Creating libft.$(RESET)"
	@$(MAKE) -sC libft
	@echo "$(YELLOW)Compiling $(CHECKER).$(RESET)"
	@$(CC) $(CFLAG) $(SANITIZER) -o $@ $(INC) $^ $(LIB)
	@echo "$(GREEN)[Ok] $(CHECKER) ready.$(RESET)"

clean:
	@$(MAKE) -sC libft clean
	@rm -f *.o
	@echo "$(RED)$(PUSH_SWAP) and $(CHECKER) object files removed.$(RESET)"

fclean:
	@$(MAKE) -sC libft fclean
	@rm -f *.o $(PUSH_SWAP) $(CHECKER)
	@echo "$(RED)Executables and object files removed.$(RESET)"

re: fclean all

norme:
	norminette libft includes srcs

.PHONY: all clean fclean re