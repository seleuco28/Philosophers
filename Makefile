# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 17:34:16 by alvelazq          #+#    #+#              #
#    Updated: 2025/05/08 17:41:34 by alvelazq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

HEADER = philo.h

SRC_SOURCES = main.c utils.c
SRC_DIR		= src/
SRC					= $(addprefix $(SRC_DIR), $(SRC_SOURCES))
SRC_OBJ				= $(SRC:.c=.o)

%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

$(NAME):		$(SRC_OBJ) 
				@$(CC)  $(SRC_OBJ) -o $(NAME)
				@echo "$(NAME) creado!"

all:	$(NAME)

clean:
				@$(RM) $(SRC_OBJ)
				@echo "Archivos *.o borrados"

fclean:			clean
				@$(RM) $(NAME)
				@echo "Todo borrado!"

re:			fclean all

.PHONY:		all clean fclean re