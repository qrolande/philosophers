# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 18:03:25 by qrolande          #+#    #+#              #
#    Updated: 2021/11/28 14:54:11 by qrolande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	philo

SRCS  		=	srcs/main.c \
				srcs/begin.c \
				srcs/thread.c \
				srcs/process.c \
				srcs/time_func.c \
				srcs/modif_atoi.c \
				srcs/check_status.c
						
OBJS		=	${SRCS:.c=.o}

CC			= 	gcc -g

RM			= 	rm -f

CFLAGS		= 	-Wall -Wextra -Werror

INCLUDES	= 	incl/philo.h

%.o : %.c	$(INCLUDES)
			${CC} ${CFLAGS} -c $< -I ${INCLUDES} -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDES)
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			@echo "Make done"

clean:		
			@${RM} ${OBJS}
			@echo "Make clean done" 

fclean:		
			@${RM} ${OBJS}
			@${RM} ${NAME}
			@echo "Make fclean done"

re:			fclean all

.PHONY:		all clean fclean re
