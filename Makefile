SERVER 	:= server
CLIENT 	:= client

NAME	:= $(CLIENT) $(SERVEUR)

OBJS	:= $(SRCS:.c=.o)	

CC		:= cc

CFLAGS	:= -Wall -Wextra -Werror

SRCS = server.c\
	   client.c



all : $(NAME) 

$(SERVER)	:
	cc server.c libft/libft.a -o server

$(CLIENT)	:
	cc client.c libft/libft.a -o client
