# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avornane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 14:42:01 by avornane          #+#    #+#              #
#    Updated: 2019/12/18 16:24:51 by avornane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIB = libft/libft.a 
CFLAGS = -g
SRCS = main.c src/keyinput.c src/draw.c src/print_map.c src/readmap.c src/create_map.c src/color.c src/modifiers.c

OBJ = $(SRCS:.c=.o)

GCC = gcc -Wall -Werror -Wextra -I /usr/X11/include -g -O3 -L /usr/X11/lib -lX11 -lmlx -lXext
LIBXL = libmlx_Linux.a -lm -lX11 -lXext

all: $(NAME)

$(NAME): buildlib
	$(GCC) $(SRCS) $(LIB) -o $(NAME)

linux: buildlib
	@echo "Creating LINUX executable $(NAME) ..."
	@gcc $(CFLAGS) $(SRCS) $(LIB) $(LIBXL) -o $(NAME)  
	

x11: buildlib
	@echo "Creating X11 executable $(NAME)..."
	@gcc $(CFLAGS) -c $(SRCS)
	@gcc -o $(NAME) $(OBJ) $(X11)

buildlib:
	@make -C libft fclean
	@make -C libft

clean:
	/bin/rm -f $(OBJ)
	make -C libft/ clean

fclean : clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean buildlib all

.PHONY: clean fclean all buildlib
