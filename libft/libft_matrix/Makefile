# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/02 10:50:03 by wgaetan      #+#   ##    ##    #+#        #
#    Updated: 2018/03/02 10:50:06 by wgaetan     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft_matrix.a

SRCS = ft_mtx_build.c\
	   ft_mtx_com.c\
	   ft_mtx_det.c\
	   ft_mtx_minor.c\
	   ft_mtx_destroy.c\
	   ft_mtx_times_mtx.c\
	   ft_mtx_times_scal.c\
	   ft_mtx_trans.c\

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

./%.o: ./%.c
	gcc -Wall -Wextra -Werror -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
