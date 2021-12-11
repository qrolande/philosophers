# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 18:03:25 by qrolande          #+#    #+#              #
#    Updated: 2021/12/07 20:09:34 by qrolande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	philo_bonus

SRCS  		=	srcs/bonus_philo.c \
				srcs/print_error.c \
				srcs/modif_atoi.c \
				srcs/time_func.c \
				srcs/process.c \
				srcs/begin.c
						
OBJS		=	${SRCS:.c=.o}

CC			= 	gcc -g

RM			= 	rm -f

CFLAGS		= 	-Wall -Wextra -Werror

INCLUDES	= 	incl/bonus_philo.h

%.o : %.c	$(INCLUDES)
			${CC} ${CFLAGS} -c $< -I ${INCLUDES} -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDES)
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			@echo "Make done"

bonus:		all

clean:		
			@${RM} ${OBJS}
			@echo "Make clean done" 

fclean:		
			@${RM} ${OBJS}
			@${RM} ${NAME}
			@echo "Make fclean done"

re:			fclean all

.PHONY:		all clean fclean re
