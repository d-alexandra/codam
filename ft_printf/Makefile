# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: adimitri <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/15 16:27:17 by adimitri      #+#    #+#                  #
#    Updated: 2020/03/03 13:25:02 by adimitri      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c ft_parse.c ft_check.c ft_printstr.c ft_printchar.c \
ft_printint.c ft_printuint.c ft_printhex.c ft_printptr.c utils_int.c \
utils_uint.c utils_str.c utils_ptr.c print_size.c utils.c utils1.c utils2.c \
utils3.c utils4.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) -I . -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) *.gch *.swp *.c~ *.h~

fclean: clean
	rm -f $(NAME)

re: fclean all
