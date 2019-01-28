# **************************************************************************** #
#                                                          LE - /              #
#                                                              /               #
#   Makefile                                         .::    .:/ .      .::     #
#                                                 +:+:+   +:    +:  +:+:+      #
#   By: wgaetan <wgaetan@student.42.fr>            +:+   +:    +:    +:+       #
#                                                 #+#   #+    #+    #+#        #
#   Created: 2018/01/12 16:19:37 by wgaetan      #+#   ##    ##    #+#         #
#   Updated: 2018/02/14 17:22:40 by wgaetan     ###    #+. /#+    ###.fr       #
#                                                         /                    #
#                                                        /                     #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft.a

SRCS= ft_atoi.c\
	  ft_bzero.c\
	  ft_gnl.c\
	  ft_memalloc.c\
	  ft_memcpy.c\
	  ft_putchar.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdup.c\
	  ft_strjoin.c\
	  ft_strlen.c\
	  ft_strnew.c\
	  ft_strsplit.c\
	  ft_strsub.c\
	  ft_putstr.c\

OBJ= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

./%.o: ./%.c
	gcc -Wall -Wextra -Werror -o $@ -c $<
	cd libft_matrix/ && make libft_matrix.a

clean:
	rm -f $(OBJ)
	make -C ./libft_matrix clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft_matrix fclean

re: fclean all
	make -C ./libft_matrix re
