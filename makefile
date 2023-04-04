# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 15:30:29 by gguidone          #+#    #+#              #
#    Updated: 2023/03/22 15:30:29 by gguidone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRC	=	ft_server.c

CLIENT_SRC	=	ft_client.c

LIBFT		=	libft/libft.a

SERVER_OBJ	=	$(SERVER_SRC:.c=.o)

CLIENT_OBJ	=	$(CLIENT_SRC:.c=.o)

OBJ			=	$(SERVER_OBJ) $(CLIENT_OBJ)

SERVER_NAME	= server

CLIENT_NAME	= client

CC			=	gcc 

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

all:		$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME):	$(SERVER_OBJ)
			make -C ./libft
			$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJ) $(LIBFT)

$(CLIENT_NAME):	$(CLIENT_OBJ)
			make -C ./libft
			$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJ) $(LIBFT)

clean:
			make clean -C libft
			${RM} $(OBJ)

fclean: 	clean
			make fclean -C libft
			${RM} $(NAME) ${OBJ}

re:			fclean all

.PHONY:		all clean fclean re