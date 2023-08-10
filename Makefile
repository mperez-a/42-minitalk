# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 13:31:16 by mperez-a          #+#    #+#              #
#    Updated: 2023/08/09 16:59:48 by mperez-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server
PRINTF_PATH = ft_printf/
PRINTF_LIB = $(PRINTF_PATH)libftprintf.a
LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc

SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
DEP_CLIENT = $(SRC_CLIENT:.c=.d)

SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
DEP_SERVER = $(SRC_SERVER:.c=.d)

RM = rm -f

# **************************************************************************** #

%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: subsystems
	@$(MAKE) $(CLIENT)
	@$(MAKE) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(PRINTF_LIB) $(LIBFT_LIB) $(OBJ_CLIENT) -o $@
	@echo "\033[32m[COMPILED]\033[0m \033[33m$@\033[0m"

subsystems:
	@$(MAKE) -C $(PRINTF_PATH) all
	@$(MAKE) -C $(LIBFT_PATH) all

$(SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(PRINTF_LIB) $(OBJ_SERVER) -o $@
	@echo "\033[32m[COMPILED]\033[0m \033[33m$@\033[0m"

clean:
	@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(DEP_CLIENT) $(DEP_SERVER)
	@$(MAKE) -C $(PRINTF_PATH) clean
	@$(MAKE) -C $(LIBFT_PATH) clean
	@echo "\033[31m[CLEANED]\033[0m \033[33m$(NAME)\033[0m"

fclean: clean
	@$(RM) $(CLIENT) $(SERVER)
	@$(MAKE) -C $(PRINTF_PATH) fclean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "\033[31m[FCLEANED]\033[0m \033[33m$(NAME)\033[0m"

re: fclean all

.PHONY: all clean fclean re

-include $(DEP_CLIENT)
-include $(DEP_SERVER)