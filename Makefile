# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/28 16:17:13 by vvaucoul          #+#    #+#              #
#    Updated: 2020/02/22 15:13:59 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC				= gcc
CFLAGS			= -I $(HEADER)
LIBS			= -lmlx -framework OpenGL -framework AppKit -lm -Wall -Wextra -Werror

### EXECUTABLE ###
NAME			= Cub3D

### INCLUDES ###
HEADER 			= ./include/
LIBFT  			= libft.a
LIBFT_UP  		= libft_upgraded.a
LIB_DIR			= ./libft/
LIB_UP_DIR		= ./libft/libft_upgraded/
ALL_LIB_DIR		= ./libraries/
OBJ_PATH 		= obj
SRC_PATH 		= src


### SOURCES ###
SRCS			=	./srcs/draw/draw_screen.c	\
					./srcs/draw/draw_help.c	\
					./srcs/init/check_args.c	\
					./srcs/camera/init_camera.c	\
					./srcs/input/check_inputs.c	\
					./srcs/input/hitbox_walls.c	\
					./srcs/init/init_game.c	\
					./srcs/init/init_game_next.c	\
					./srcs/input/key_pressed.c	\
					./srcs/input/key_released.c	\
					./srcs/map/apply_texture.c	\
					./srcs/main.c	\
					./libft/get_next_line/get_next_line.c	\
					./libft/get_next_line/get_next_line_utils.c	\
					./srcs/map/assign_map.c	\
					./srcs/input/check_hitbox_walls.c	\
					./srcs/map/parse_color.c	\
					./srcs/map/is_valid_key.c	\
					./srcs/map/parse_file.c	\
					./srcs/map/parse_res.c	\
					./srcs/map/parse_texture.c	\
					./srcs/output/destroy_image.c	\
					./srcs/output/game_errors.c	\
					./srcs/output/game_warning.c	\
					./srcs/input/player_movement.c	\
					./srcs/output/free_game.c	\
					./srcs/output/free_game_next.c	\
					./srcs/pixels/draw_floor.c	\
					./srcs/map/check_map_walls.c	\
					./srcs/pixels/draw_pixel.c	\
					./srcs/pixels/draw_sky.c	\
					./srcs/pixels/draw_text.c	\
					./srcs/map/parse_map.c	\
					./srcs/pixels/init_pixels.c	\
					./srcs/pixels/draw_pixel_sized.c	\
					./srcs/pixels/draw_vertical_line.c	\
					./srcs/raycasting/raycasting_math.c	\
					./srcs/raycasting/raycasting_utils_02.c	\
					./srcs/raycasting/init_raycasting.c	\
					./srcs/raycasting/raycasting.c	\
					./srcs/screenshot/screenshot.c	\
					./srcs/raycasting/raycasting_utils.c	\
					./srcs/screenshot/screenshot_utils.c	\
					./srcs/sprites/delete_sprite.c	\
					./srcs/raycasting/spritecasting.c	\
					./srcs/textures/put_pixel_texture.c	\
					./srcs/raycasting/spritecasting_utils.c	\
					./srcs/utils/game/ft_isdirection.c	\
					./srcs/utils/game/ft_can_be_opened.c	\
					./srcs/sprites/load_sprites.c	\
					./srcs/utils/game/ft_isdirection_map.c	\
					./srcs/utils/math/ft_angles.c	\
					./srcs/utils/math/ft_clamp.c	\
					./srcs/textures/load_textures.c	\
					./srcs/utils/math/ft_clamp_to_value.c	\
					./srcs/utils/game/ft_texture_path.c	\
					./srcs/utils/math/ft_rad.c	\
					./srcs/utils/math/ft_maprange_clamped.c	\
					./srcs/utils/strings/ft_eol.c	\
					./srcs/utils/strings/ft_get_next_char.c	\
					./srcs/utils/strings/ft_strtrunc_to_digit.c	\
					./srcs/utils/strings/ft_getlen_line.c	\
					./srcs/utils/game/ft_rgb.c	\
					./srcs/utils/math/ft_distance.c	\
					./srcs/utils/strings/ft_get_next_digit.c	\
					./srcs/utils/strings/ft_skip_spaces.c	\
					./srcs/utils/vectors/2D/v_initvector2d.c	\
					./srcs/utils/strings/ft_removespaces.c	\
					./srcs/utils/strings/ft_has_format.c	\
					./srcs/utils/vectors/3D/v_combine_vectors.c	\
					./srcs/utils/strings/ft_strtrunc.c	\
					./srcs/utils/vectors/3D/v_get_forward_vector.c	\
					./srcs/utils/vectors/3D/v_init_vector.c	\
					./srcs/utils/vectors/3D/v_clamp_vector_to_size.c

### OBJECTS ###
OBJS			=         $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(FLAGS) -I. -c $< -o ${<:.c=.o}

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### CLEAN ###
RM				= rm -f

### RULES ###

all:			obj_dir comp_libs $(NAME)

comp_libs:
				@echo "$(RED)    --->|Create LIBFT lib|<----$(NOC)"
				@make -C $(LIB_DIR)
				@echo Copying $(LIBFT) to root dir.
				@cp $(LIB_DIR)$(LIBFT) $(ALL_LIB_DIR)
				@echo "$(RED)    --->|Create LIBFT_UP lib|<----$(NOC)"
				@make -C $(LIB_UP_DIR)
				@echo Copying $(LIBFT_UP) to root dir.
				@cp $(LIB_UP_DIR)$(LIBFT_UP) $(ALL_LIB_DIR)

$(NAME):
				@echo "\n\033[33m\t-------------------"
				@echo "\033[33m\t| ! Compilation ! |"
				@echo "\033[33m\t-------------------\033[00m"
				@$(CC) $(SRCS) $(CFLAGS) -L $(ALL_LIB_DIR) -lft -lft_upgraded $(LIBS) -o $(NAME)
				@echo "\033[32m\t----------------------"
				@echo "\033[32m\t|   CUB3D COMPILED   |"
				@echo "\033[32m\t----------------------\033[00m"

obj_dir:
				@echo "$(BLUE)    --->|Create obj folder|<----$(NOC)"
				@mkdir -p $(OBJ_PATH)
				@echo "$(BLUE)    --->|Create libraries folder|<----$(NOC)"
				@mkdir -p $(ALL_LIB_DIR)

clean:
				@echo "$(RED)    --->|Remove all .o files|<----$(NOC)"
				@$(RM) $(OBJS)
				@echo "$(RED)    --->|Remove all libraries|<----$(NOC)\n"
				@cd $(LIB_DIR) && $(MAKE) fclean
				@cd $(LIB_UP_DIR) && $(MAKE) fclean
				@$(RM) -r $(ALL_LIB_DIR)
				@$(RM) -r $(OBJ_PATH)
				@echo "\n"

fclean:			clean
				@echo "$(RED)    --->|Binary file deleted|<----$(NOC)"
				@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
