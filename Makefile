SERVER 	:= server
CLIENT 	:= client

OBJS	:= $(SRCS:.c=.o)	

CC		:= cc

CFLAGS	:= -Wall -Wextra -Werror

SRCS = server.c\
	   client.c



all : $(CLIENT) $(SERVER)

$(NAME)		: $(SERVER) $(CLIENT)

$(SERVER)	:
	cc server.c libft/libft.a -o server

$(CLIENT)	:
	cc client.c libft/libft.a -o client
