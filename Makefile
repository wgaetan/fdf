# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/05 18:53:52 by wgaetan      #+#   ##    ##    #+#        #
#    Updated: 2019/01/28 21:18:31 by wgaetan     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

#COMPILATION

NAME = fdf
HEADERS = includes/fdf.h
FLAGS = -Wall -Wextra -Werror -g
INC = -I minilibx_macos -I libft
LIBS = minilibx_macos/libmlx.a libft/libft.a libft/libft_matrix/libft_matrix.a
EXT_LIBS = -framework OpenGl -framework AppKit


#PATH

SRCS = srcs/main.c\
	   srcs/parse.c\
	   srcs/get_pt_grid.c\
	   srcs/pt_grid_compute.c\
	   srcs/display.c\
	   srcs/image_manage.c\
	   srcs/bresenham.c\
	   srcs/color_init.c\
	   srcs/color_manage.c\
	   srcs/display_0.c\
	   srcs/display_1.c\
	   srcs/display_2.c\
	   srcs/display_3.c\
	   srcs/key_manage.c\

OBJS = $(SRCS:.c=.o)


#RULES

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	@$(CC) -ggdb $(FLAGS) $(LIBS) $(EXT_LIBS) $(OBJS) -o $(NAME)

$(LIBS):
	@make -C ./libft
	@make -C ./minilibx_macos

./%.o: ./%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@make -C ./libft clean
	@make -C ./minilibx_macos clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean
	@make -C ./minilibx_macos fclean

re: fclean all
	@make -C ./libft re
	@make -C ./minilibx_macos re
