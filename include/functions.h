/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:16:45 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/02/21 17:02:49 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>

# define OUTPUT_ERROR 2
# define TOTAL_NB_TEXTURE 256

typedef	int	t_bool;
# define TRUE 1
# define FALSE 0

/*
**	Raycasting structure
*/

typedef struct	s_ray
{
	float		dir_x;
	float		dir_y;

	float		plane_x;
	float		plane_y;

	float		camera_x;

	float		ray_dir_x;
	float		ray_dir_y;

	int			map_x;
	int			map_y;

	float		ray_pos_x;
	float		ray_pos_y;

	float		wall_dist_x;
	float		wall_dist_y;

	float		dist2_mur_x;
	float		dist2_mur_y;

	int			ray_step_x;
	int			ray_step_y;

	int			wall_hit;
	int			wall_side;
	int			wall_height;
	float		wall_len;

	char		wall_char;

	int			draw_start;
	int			draw_end;

	int			tex_x;
	int			tex_y;

	float		wall_x;

	float		distance;
	float		direction;

	float		*sf_dist;

	int			x;

}				t_ray;

/*
**	Spritecasting structure
*/

typedef struct	s_ray_sprite
{
	float		*zbuffer;
	int			*sprite_order;
	float		*sprite_distance;

	float		sprite_x;
	float		sprite_y;

	float		inv_det;

	float		transform_x;
	float		transform_y;

	float		sprite_screen_x;

	int			v_move_screen;

	int			sprite_height;
	int			sprite_width;

	int			draw_start_y;
	int			draw_end_y;

	int			draw_start_x;
	int			draw_end_x;

	int			stripe;
}				t_ray_sprite;

/*
**	Utils structs
*/

typedef struct	s_vector2d
{
	int			x;
	int			y;
}				t_vector2d;

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

/*
** Utils functions
*/

int				get_len_line(char *str, int i);
int				get_next_char(char *str, int *i);
int				ft_strcmp(char *s1, char *s2);
int				ft_has_format(char *str, char *format);
int				is_eol(char c);
char			*ft_get_texture_path(char *line);
char			*ft_strtrunc(char *str, char c);
int				ft_skip_spaces(char *str, int *i);
int				ft_isdirection(char *dir);
char			*ft_removespaces(char *str);
int				ft_isdirection_map(char dir);
int				ft_get_next_digit(char *str, int *i);
int				ft_hash(char *str);
char			*ft_strtrunc_to_digit(int *i, char *str);
t_bool			ft_can_be_opened(char *path);

/*
** COLORS
*/

int				color(int red, int green, int blue);
t_color			subtract_color(t_color color, int sub);
int				deg_color(int r, int g, int b, float distance);
int				color_to_int(t_color color);
int				shade_color(int color, float divide);

/*
** MATH
*/

float			ft_map_range_clamped(float value, t_vector inrange,
t_vector outrange);
float			ft_deg_to_rad(float angle_deg);
float			ft_rad_to_deg(float angle_deg);
t_bool			ft_clamped(t_vector min, t_vector max, float value);
float			ft_dcos(float angle_deg);
float			ft_dsin(float angle_deg);
float			ft_vangle(float v1, float v2);
float			ft_distance(t_vector pos1, t_vector pos2);
int				ft_clamp_to_value(int value, int range);

/*
** Vectors
*/

t_vector		v_init_vector(int x, int y, int z);
t_vector		v_combine_vectors(t_vector base, t_vector add);
t_vector2d		v_init_vector2d(int x, int y);
t_vector		v_get_forward_vector(t_vector actu_pos, float angle,
float distance);
t_vector		v_clamp_vector_to_size(t_vector coord, t_vector bloc_coord,
float bloc_size);

#endif
