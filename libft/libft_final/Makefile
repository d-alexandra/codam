# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: adimitri <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/12 19:03:02 by adimitri      #+#    #+#                  #
#    Updated: 2020/02/05 16:52:10 by adimitri      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_memchr.c ft_memccpy.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c \
ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strjoin.c \
ft_substr.c ft_itoa.c ft_strmapi.c ft_strtrim.c ft_split.c

BONUS = ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstiter_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \

OBJ = $(SRC:.c=.o)

BON = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(BONUS)
	gcc -Wall -Werror -Wextra -I . -c $(SRC) $(BONUS)
	ar rc $(NAME) $(OBJ) $(BON)

clean:
	rm -f $(OBJ) $(BON)

fclean: clean
	rm -f $(NAME)

re: fclean all
