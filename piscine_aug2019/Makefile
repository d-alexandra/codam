#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: adimitri <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/19 11:23:35 by adimitri      #+#    #+#                  #
#    Updated: 2019/08/19 16:04:24 by adimitri      ########   odam.nl          #
#                                                                              #
#******************************************************************************#
LIB = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
INCLUDES = includes/

all:
	gcc -I $(INCLUDES) -Wall -Wextra -Werror -c $(SRCS)
	ar rc $(LIB) ft_putchar.o ft_putstr.o ft_strlen.o ft_strcmp.o ft_swap.o   

clean:
	/bin/rm -f *.o

fclean:
	/bin/rm -f $(LIB)

re: fclean all