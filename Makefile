# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/05 14:24:31 by ngunthor          #+#    #+#              #
#    Updated: 2019/02/05 14:24:55 by ngunthor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
FILLIT_SRCS = *.c
LIBFT_SRCS = libft/*.c
OBJS = *.o

$(NAME):
	gcc $(FLAGS) -c $(LIBFT_SRCS)
	ar rc libft.a $(OBJS)
	ranlib libft.a
	gcc $(FLAGS) $(FILLIT_SRCS) -L. -lft -o $(NAME)

all: $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME) libft.a

re: fclean all
