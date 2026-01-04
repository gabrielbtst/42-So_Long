# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbatista <gbatista@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 18:57:35 by gbatista          #+#    #+#              #
#    Updated: 2025/09/18 10:28:20 by gbatista         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
BONUS_DIR = src/bonus
OBJ_DIR = obj
OBJ_BONUS_DIR = obj/bonus
INC = include

SRCS = $(SRC_DIR)/ft_isalpha.c \
       $(SRC_DIR)/ft_isdigit.c \
       $(SRC_DIR)/ft_strlen.c \
       $(SRC_DIR)/ft_isalnum.c \
       $(SRC_DIR)/ft_isascii.c \
       $(SRC_DIR)/ft_isprint.c \
       $(SRC_DIR)/ft_memset.c \
       $(SRC_DIR)/ft_bzero.c \
       $(SRC_DIR)/ft_memcpy.c \
       $(SRC_DIR)/ft_memmove.c \
       $(SRC_DIR)/ft_strlcpy.c \
       $(SRC_DIR)/ft_strlcat.c \
       $(SRC_DIR)/ft_toupper.c \
       $(SRC_DIR)/ft_tolower.c \
       $(SRC_DIR)/ft_strchr.c \
       $(SRC_DIR)/ft_strrchr.c \
       $(SRC_DIR)/ft_strncmp.c \
       $(SRC_DIR)/ft_memchr.c \
       $(SRC_DIR)/ft_memcmp.c \
       $(SRC_DIR)/ft_strnstr.c \
       $(SRC_DIR)/ft_atoi.c \
       $(SRC_DIR)/ft_calloc.c \
       $(SRC_DIR)/ft_strdup.c \
       $(SRC_DIR)/ft_substr.c \
       $(SRC_DIR)/ft_strjoin.c \
       $(SRC_DIR)/ft_strtrim.c \
       $(SRC_DIR)/ft_split.c \
       $(SRC_DIR)/ft_itoa.c \
       $(SRC_DIR)/ft_strmapi.c \
       $(SRC_DIR)/ft_striteri.c \
       $(SRC_DIR)/ft_putchar_fd.c \
       $(SRC_DIR)/ft_putstr_fd.c \
       $(SRC_DIR)/ft_putendl_fd.c \
       $(SRC_DIR)/ft_putnbr_fd.c

SRCS_BONUS = $(BONUS_DIR)/ft_lstsize_bonus.c \
             $(BONUS_DIR)/ft_lstnew_bonus.c \
             $(BONUS_DIR)/ft_lstadd_front_bonus.c \
             $(BONUS_DIR)/ft_lstlast_bonus.c \
             $(BONUS_DIR)/ft_lstadd_back_bonus.c \
             $(BONUS_DIR)/ft_lstdelone_bonus.c \
             $(BONUS_DIR)/ft_lstclear_bonus.c \
             $(BONUS_DIR)/ft_lstiter_bonus.c \
             $(BONUS_DIR)/ft_lstmap_bonus.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:$(BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_BONUS_DIR)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

.bonus_build: $(OBJS_BONUS) $(NAME)
	ar rcs $(NAME) $(OBJS_BONUS)
	touch .bonus_build

bonus: .bonus_build

clean:
	rm -rf $(OBJ_DIR) .bonus_build

fclean: clean
	rm -f $(NAME)

re: fclean all
