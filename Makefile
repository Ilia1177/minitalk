# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npolack <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 13:38:08 by npolack           #+#    #+#              #
#    Updated: 2024/11/22 12:09:57 by npolack          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER 	:= server
CLIENT 	:= client
NAME	:= $(SERVER) $(CLIENT) 

LIBFT 	:= libft/libft.a
CC		:= cc
RM		:= rm -f
CFLAGS	:= -Wall -Wextra -Werror 

S_SRC 	:= 	server.c
C_SRC	:=	client.c

C_OBJ	:= $(C_SRC:.c=.o)
S_OBJ	:= $(S_SRC:.c=.o)
OBJS	:= $(C_OBJ) $(S_OBJ)

all 		: $(NAME)

clean 		:
	make clean -C libft
	$(RM) $(OBJS)
	
fclean		:	clean
	make fclean -C libft
	$(RM) $(NAME)
	
re			:	fclean all

%.o			: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)	:
	make -C libft

$(SERVER)	:	$(S_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(SERVER)

$(CLIENT)	:	$(C_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(CLIENT)

.PHONY	:	all clean fclean re
