# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 13:08:34 by tgibier           #+#    #+#              #
#    Updated: 2023/06/14 15:10:18 by tgibier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Das Progamm
NAME			=	fractol

# Compiler
CC				=	cc
CFLAGS			=	-g3 -Wall -Werror -Wextra -MMD
LDFLAGS			=	-L $(LIBFT_PATH) -lft
MLXFLAGS		=	-lX11 -lXext -L $(MLX_PATH) -lmlx -lm

# Libft
LIBFT_PATH		=	libft/
LIBFT_NAME		=	libft.a
LIBFT			=	$(LIBFT_PATH)$(LIBFT_NAME)

# Minilibx
MLX_PATH		=	minilibx-linux/
MLX_NAME		=	libmlx.a
MLX				=	$(MLX_PATH)$(MLX_NAME)

HEAD			=	-I ./includes/ \
					-I ./libft/ \
					-I ./minilibx-linux/ 

DEPS			=	${OBJS:.o=.d}

# Sources
SRCS_PATH		=	srcs
SRCS_NAMES		=	fractol.c \
					scanner.c \
					transfer.c \
					virtualization.c \
					dematerialization.c \
					help.c \
					palette.c \
					handle_keys.c \
					handle_more_keys.c \
					handle_mouse.c \
					fractal/julia.c \
					fractal/mandelbrot.c \
					fractal/the_box.c \
					fractal/burning_ship.c 

SRCS			=	$(addprefix $(SRCS_PATH)/, $(SRCS_NAMES))
					
# Objects
OBJS_PATH		=	objs
OBJS_NAMES		=	$(SRCS_NAMES:.c=.o)
OBJS			=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAMES))

# -fsanitize=address

MAKEFLAGS		=	--no-print-directory

all	:	$(MLX) $(LIBFT) ${NAME}

$(OBJS_PATH)/%.o	: $(SRCS_PATH)/%.c
		@mkdir -p $(OBJS_PATH)
		@mkdir -p $(OBJS_PATH)/fractal/
		@$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(LIBFT)	:
		@echo "Crafting Libft"
		@make -sC $(LIBFT_PATH)

$(MLX)		: 
		@echo "Crafting MiniLibX"
		@make -sC $(MLX_PATH)

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
		@echo "Finally, compiling fractol"
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX) $(LDFLAGS) $(MLXFLAGS)
		@echo "Fractol ready, WOOP WOOP"

clean:
	@echo "Cleaning the mess"
	@rm -rf $(OBJS_PATH)
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)
	

fclean:	clean
	@echo "bye fractol"
	@rm -rf $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re:	fclean all

-include $(DEPS)

.PHONY:	all clean fclean re