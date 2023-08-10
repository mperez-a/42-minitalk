# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperez-a <mperez-a@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 14:12:33 by mperez-a          #+#    #+#              #
#    Updated: 2023/01/24 18:49:56 by mperez-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#************************************VARIABLES*********************************#

#CC = gcc
CFLAGS = -Werror -Wextra -Wall -c -MMD
NAME = libft.a
HEADER = libft.h
BNAME = .bonus
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	  ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ_BONUS = $(BONUS:.c=.o)
DEP_BONUS = $(OBJ_BONUS:.o=.d)

#*************************************REGLAS**********************************#

%.o: %.c Makefile
	$(CC) $(CFLAGS) -I./ $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

-include $(DEP)

bonus: $(BNAME) 
	
$(BNAME): $(OBJ) $(OBJ_BONUS)
	ar crs $(NAME) $(OBJ) $(OBJ_BONUS)
	touch $@

-include $(DEP_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS) $(DEP) $(DEP_BONUS)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all


.PHONY: all clean fclean re bonus
