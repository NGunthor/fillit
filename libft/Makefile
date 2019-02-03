# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 13:50:07 by ngunthor          #+#    #+#              #
#    Updated: 2018/11/29 20:46:02 by ngunthor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRC=*.c
INC=*.h

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) -I $(INC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	/bin/rm -f *.o
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
