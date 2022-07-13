# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 17:36:14 by gmarzull          #+#    #+#              #
#    Updated: 2022/07/11 18:31:00 by gmarzull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT		= -L./libft -lft

INCLUDE		= -I./libft \
			  -I.

SERVERNAME	= server

CLIENTNAME	= client

SERVERSRC	=	ft_server.c

CLIENTSRC	=	ft_client.c

SERVEROBJS	= ${SERVERSRC:.c=.o}

CLIENTOBJS	= ${CLIENTSRC:.c=.o}

HEADER		= minitalk.h

CC			= gcc 

FLAGS		= -Wall -Wextra -Werror
#FLAGS = -g

.c.o:		${CC} ${FLAGS} -c $< -o ${<:c=o}

all:		$(SERVERNAME) $(CLIENTNAME)

$(SERVERNAME):	${SERVEROBJS}
			make -C ./libft
			$(CC) $(FLAGS) $(INCLUDE) $(LIBFT) ./libft/libft.a $(SERVEROBJS) -o $(SERVERNAME)


$(CLIENTNAME):	${CLIENTOBJS}
			make -C ./libft
			$(CC) $(FLAGS) $(INCLUDE) $(LIBFT) ./libft/libft.a $(CLIENTOBJS) -o $(CLIENTNAME)			

clean:		
			$(MAKE) clean -C ./libft
			rm -f $(SERVEROBJS) $(CLIENTOBJS)

fclean:		clean
			$(MAKE) fclean -C ./libft
			rm -f $(SERVERNAME) $(CLIENTNAME)

re:			fclean all

.PHONY:		all clean fclean re