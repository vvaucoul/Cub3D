/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:14:52 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/22 15:24:45 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# include "functions.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../libft/libft_upgraded/libft_up.h"

# define RAY_TOTAL_DISTANCE_MAX 320
# define RAY_DISTANCE_MAX 		64
# define RAY_DISTANCE_INC 		1.2

# define FOV 					60
# define ROTATION_SPEED 		0.05

# define P_STRAFE 				1.11
# define HIT_BOX_SIZE 			0.25

/*
** FILE CONFIGURATION
*/

# define MAX_KEYS 				9
# define KEYS_MAX_SIZE 			4096
# define RES_MAX_LEN 			128

# define ALL_CAM_CHAR			"NSWE"
# define ALL_CHAR_IN_MAP_VALID 	"102NSWE\n"

# define MAX_SCREEN_RES_X		2560
# define MAX_SCREEN_RES_Y		1440
# define DEFAULT_SCREEN_RES_X	1280
# define DEFAULT_SCREEN_RES_Y	720
# define MIN_SCREEN_RES_X		360
# define MIN_SCREEN_RES_Y		140

# define NB_KEYS				1024
# define KEY_LEN				512

# define MIN_MAP_SIZE			3

# define GAME_FILE_FORMAT		".cub"
# define GAME_SAVE_ARGUMENT		"--save"

/*
**	ERRORS
*/

# define ERROR_MALLOC					"Malloc error"

# define ERROR_INVALID_MAP				"Map does not exist"
# define ERROR_ARGUMENTS_UNDER			"Not enough arguments"
# define ERROR_ARGUMENTS_SUP			"Too much arguments"
# define ERROR_ARGUMENTS_INVALID		"Invalid argument found"
# define ERROR_MAP_FORMAT				"Invalid map format"
# define ERROR_EMPTY_MAP				"No map found"
# define ERROR_MAP_SMALL				"Map too small. Minimum size : 3*3"

# define ERROR_INVALID_KEY				"Invalid key found in .cub file"
# define ERROR_INVALID_MAP_KEY			"Invalid character found in the map"
# define ERROR_INVALID_CONFIGURATION	"Invalid configuration in .cub file"
# define ERROR_DOUBLON_FOUND			"Doublon found in .cub file"
# define ERROR_DOUBLON_CAM				"Multiple camera found in the map"
# define ERROR_NO_CAM					"No cam found in the map"

# define ERROR_WRONG_TOP_WALL	"Invalid Map : Your top wall is not closed"
# define ERROR_WRONG_LEFT_WALL	"Invalid Map : Your left wall is not closed"
# define ERROR_WRONG_RIGHT_WALL	"Invalid Map : Your right wall is not closed"
# define ERROR_WRONG_BOTTOM_WALL "Invalid Map : Your bottom wall is not closed"

# define ERROR_TEXTURE_PATH				"Wrong texture path"

# define ERROR_MLX_MLX					"Failed to initialize minilibx"
# define ERROR_MLX_WINDOW				"Failed to initialize window minilibx"
# define ERROR_MLX_CLOSE_WINDOW			"Failed to close window minilibx"
# define ERROR_MLX_DATA					"Failed to load image data"

# define ERROR_SCREEENSHOT_CREATE		"Failed to create screenshot.bmp"
# define ERROR_SCREEENSHOT_WRITE		"Failed to write inside screenshot.bmp"

# define ERROR_DEBUG_KEY				"    ---- DEBUG EXIT ----"

/*
**	WARNINGS
*/

# define WARNING_RES_X_SMALL "Res X too small. Game will use default resolution"
# define WARNING_RES_Y_SMALL "Res X too small. Game will use default resolution"
# define WARNING_RES_X_HIGH "Res X too high. Game will use default resolution"
# define WARNING_RES_Y_HIGH "Res X too high. Game will use default resolution"

/*
**	SCREENSHOT
*/

# define SCREEN_HEADER_SIZE 	54

/*
** KEYS
*/

# define KEY_Z					13
# define KEY_S					1
# define KEY_D					2
# define KEY_A					0
# define ARROW_LEFT 			123
# define ARROW_RIGHT 			124

# define KEY_SPRINT 			257

# define KEY_HELP 				4
# define KEY_ESCAPE				53
# define KEY_TEXTURE 			17

/*
** TEXTURES
*/

# define DEFAULT_NB_TEXTURES 	4

# define ID_TEX_NORTH 			0
# define ID_TEX_SOUTH			1
# define ID_TEX_WEST			2
# define ID_TEX_EAST			3

# define COLOR_NORTH 			5992563
# define COLOR_SOUTH 			7955072
# define COLOR_WEST 			10133879
# define COLOR_EAST				8419183

# define DEFAULT_TEXTURE 		"./data/textures/DEFAULT_TEXTURE_64.xpm"

/*
** SPRITES
*/

# define DEFAULT_SPRITE 		"./data/images/Barrel.XPM"

# define SPRITE_DECAL			0.5
# define VMOVE					76
# define UDIV		 			1
# define VDIV		  			1
# define DEFAULT_TEX_WIDTH	  	64
# define DEFAULT_TEX_HEIGHT    	64

/*
** STRUCTURES
*/

typedef struct			s_input
{
	t_bool				move_forward;
	t_bool				move_backward;
	t_bool				move_right;
	t_bool				move_left;
	t_bool				rotate_left;
	t_bool				rotate_right;
	t_bool				rotate_up;
	t_bool				rotate_down;
	t_bool				sprint;
	t_bool				draw_help;
	t_bool				draw_textures;
	float				player_speed;
}						t_input;

typedef struct			s_texture
{
	void				*img;
	char				*data;
	int					bpp;
	int					sizel;
	int					endian;
	t_vector2d			size;
}						t_texture;

typedef struct			s_sprites
{
	void				*img;
	char				*data;
	int					bpp;
	int					sizel;
	int					endian;
	t_vector			pos;
	char				sprite_char;
	float				distance;
	int					order;
	t_vector2d			size;
}						t_sprites;

typedef struct			s_cam
{
	t_vector			projection_center;
	int					hauteur;
	int					fov;
	t_vector			pos;
	float				angle;
	int					dir;
}						t_cam;

typedef struct			s_map
{
	char				**map;
	char				*tmp_map;
	t_vector2d			size_map;
}						t_map;

typedef	struct			s_file
{
	int					fd;
	char				*file;

	char				*no_texture;
	char				*so_texture;
	char				*we_texture;
	char				*ea_texture;

	char				*sprite;

	int					floor_color;
	int					top_color;

	int					n_sprites;
	int					n_tex;

	char				**keyfounds;
	int					actu_key;
	char				**all_keys;

	t_bool				screenshot;
}						t_file;

typedef struct			s_window
{
	t_vector2d			w_res;
	char				*window_name;
}						t_window;

typedef struct			s_pixel
{
	void				*img_ptr;
	char				*img_data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_pixel;

typedef struct			s_mlx
{
	void				*mlx;
	void				*window;
	t_bool				mlx_loaded;
}						t_mlx;

typedef struct			s_game
{
	t_mlx				mlx;
	t_window			window;

	t_file				file;
	t_map				map;

	t_cam				cam;
	t_pixel				pixel;
	t_input				input;

	t_texture			*textures;
	t_sprites			*sprites;

	t_ray				a_ray;
	t_ray_sprite		a_sray;
}						t_game;

/*
**	Init
*/

t_bool					init_game_values(t_game *game);
t_bool					init_game_values_next(t_game *game);

/*
** OUTPUT
*/

int						game_error(t_game *game, char *str, int fileerror,
t_bool freeg);
void					malloc_error();
int						check_args(t_game *game, int argc, char **argv);
void					free_game(t_game *game);
void					free_game_next(t_game *game);
void					destroy_image(void *img, char *data);
void					game_warning(char *str);

/*
** Parsing file
*/

int						parse_file(t_game *game, char *pathfile);
int						parse_sprites(t_game *game, int *i);
t_vector2d				parse_res(char *str);
int						parse_textures(t_game *game, int *i);
char					*get_texture_path(char *str);
int						load_map(t_game *game, char *path);
int						check_map(t_game *game);
int						apply_texture(t_game *game, char *texture, char *sw);
char					*parse_texture(t_game *game, char *str, char *sw);
t_color					parse_color(char *line);
int						parse_map(t_game *game, char *str);
int						assign_map(t_game *game);
t_bool					is_valid_key(t_game *game, char *key);
t_bool					add_key_to_dic(t_game *game, char *key);

/*
** Pixels
*/

int						draw_pixel(t_game *game, t_vector2d coord, int color);
int						draw_pixel_sized(t_game *game, t_vector2d coord,
int size, int color);
int						swap_pixels(int *p1, int *p2);
int						init_pixels(t_game *game);
int						draw_vertical_line(t_game *game, int x, t_vector2d pos,
int color);
int						draw_text(t_game *game, t_vector2d coord, int color,
char *str);
void					draw_floor(t_game *game);
void					draw_sky(t_game *game);

/*
** Images
*/

void					*create_image(t_game *game, t_vector2d size);
int						*get_data_addr(void *img);
int						screenshot(t_game *game);
void					exit_screenshot(t_game *game);
void					set_bmp_value(unsigned char *bmp_header, int value);
unsigned char			set_uchar(int c);

/*
** Textures
*/

int						load_textures(t_game *game);
int						load_spe_textures(t_game *game);
void					put_pixel_texture(t_game *game, int x, int y, int id);
int						draw_vertical_line_textured(t_game *game, int x,
t_vector2d pos, int id);
void					replace_tex(t_game *game, char *tex, int index);

/*
** Sprites
*/

int						load_sprites(t_game *game);
void					delete_sprite(t_game *game, int spriteremove);
int						get_sprite_index(t_game *game, int index);
int						set_sprite_order(t_game *game, int i);
int						set_sprite_size(t_game *game);
int						renew_sprite_order(t_game *game);

/*
** Blocs
*/

int						init_blocs(t_game *game);
int						ft_mapbloc_isfilled(t_game *game, t_vector2d coord);

/*
** Rays
*/

int						raycasting(t_game *game);
int						init_raycasting(t_game *game);
int						floorcasting(t_game *game);
int						spritecasting(t_game *game);
void					interract(t_game *game);
float					get_ray_distance(t_game *game);
int						wall_direction(t_game *game);
void					get_wall_hit(t_game *game);
void					get_line_to_draw(t_game *game);
void					ray_step(t_game *game);
void					ray_dir(t_game *game);
void					start_ray(t_game *game);

/*
** Camera
*/

int						init_camera(t_game *game);

/*
** Inputs
*/

int						key_pressed(int key, t_game *game);
int						key_released(int key, t_game *game);
int						forward_input(t_game *game, t_bool forward);
int						right_input(t_game *game, t_bool right);
int						yaw_input(t_game *game, t_bool input);
int						pitch_input(t_game *game, t_bool input);
int						checkinputs(t_game *game);
int						quit_game(t_game *game);
void					jump(t_game *game, t_bool pressed);
void					crouch(t_game *game, t_bool pressed);
t_bool					hit_box_forward(t_game *game, int dir);
t_bool					hit_box_right(t_game *game, int dir);
t_bool					hit_box_sprites_forward(t_game *game, int dir);
t_bool					hit_box_sprites_right(t_game *game, int dir);
t_bool					check_hit_box_forward_next(t_game *game, int dir);
t_bool					check_hit_box_forward(t_game *game, int dir);
t_bool					check_hit_box_right_next(t_game *game, int dir);
t_bool					check_hit_box_right(t_game *game, int dir);

/*
** Draw
*/

void					draw_screen(t_game *game);
void					ui(t_game *game);
void					minimap(t_game *game);
int						draw_help(t_game *game);
void					draw_floor(t_game *game);

/*
** EVENTS
*/

void					events(t_game *game);
int						anim_open_door(t_game *game);

/*
**	UI
*/

void					draw_image_into_ui(t_game *game, int ui_index);

#endif
