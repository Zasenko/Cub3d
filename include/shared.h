/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:49:19 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/27 09:53:09 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "../libft/libft.h"
# include "conf.h"
# include "err.h"
# include "parser.h"
# include "raycast.h"

typedef struct s_vector2_int
{
	int				x;
	int				y;
}					t_vector2_int;

typedef struct s_vector2
{
	float			x;
	float			y;
}					t_vector2;

typedef enum e_direction
{
	DIR_NONE,
	DIR_NORTH,
	DIR_EAST,
	DIR_SOUTH,
	DIR_WEST
}					t_direction;

typedef struct s_map
{
	char			**map;
	t_textures		textures;
	t_vector2_int	start;
	t_direction		direction;
	int				row_l;
	int				col_l;
}					t_map;


typedef struct s_ray_info
{
	double			camera_x;
	t_vector2		ray_dir;
	t_vector2_int	map_pos;
	t_vector2_int	step;
	t_vector2		side_dist;
	t_vector2		delta_dist;
	double			perp_wall_dist;
	bool			hit;
	int				side;
	int				wall_dir;
}					t_ray_info;

typedef struct s_player
{
	t_vector2		pos;
	t_vector2		dir;
	t_vector2		cam_plane;
	int				horizontal_input;
	int				vertical_input;
	int				rotate_input;
}					t_player;

typedef struct s_texture
{
	void			*texture;
	char			*texture_data;
	t_vector2_int	dimension;
	int				bpp;
	int				length;
	int				endian;
}					t_texture;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_player		*player;
	t_map			*map_s;
	t_vector2_int	map_dimesnion;
	t_texture		textures[4];
}					t_vars;

#endif