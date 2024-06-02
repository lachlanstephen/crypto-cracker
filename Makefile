# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darkwater <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 21:42:29 by darkwater         #+#    #+#              #
#    Updated: 2024/06/02 18:41:33 by darkwater        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= crypto-cracker

SRC			= main.c			\
			vigenere.c			\
			rotate.c			\
			cipher_utils.c		\
			decoding_utils.c	\
			encoding_utils.c	\
			str_utils.c			\

SRC_DIR		= ./src/

SRC_PRE		= $(addprefix $(SRC_DIR), $(SRC))

OBJS		= $(SRC_PRE:.c=.o)

OBJ_OUTPUT	= .output

HEADER		= ./includes/

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -Wpedantic

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Colours  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

RED				= \033[0;31m

GREEN			= \033[0;32m

NC				= \033[0m

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Messages ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

BEGIN_COMP		= echo "\n ~ ~ ~ $(GREEN)Compiling Objects$(NC) ~ ~ ~\n"

PROGRAM_COMP	= echo "\n ~ ~ ~ $(GREEN)Compiling Program$(NC) ~ ~ ~\n"

CLEAN_MSG		= echo "\n ~ ~ ~ $(RED)Cleaning all object files$(NC) ~ ~ ~\n"

FCLEAN_MSG		= echo "\n ~ ~ ~ $(RED)Removing Program$(NC) ~ ~ ~\n"

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Rules ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

all: $(NAME)

$(NAME): $(OBJ_OUTPUT) $(OBJS)
	@$(PROGRAM_COMP)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_OUTPUT):
	@$(BEGIN_COMP)
	@touch $(OBJ_OUTPUT)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(HEADER) $< -o $@

clean:
	@$(CLEAN_MSG)
	@$(RM) $(OBJ_OUTPUT) $(OBJS)

fclean: clean
	@$(FCLEAN_MSG)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
