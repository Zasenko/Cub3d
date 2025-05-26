/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:55:14 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/26 18:37:17 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_core.h"

static void	calc_wall_projection(t_ray_info *ray, t_vector2_int *draw_point,
		int *line_height)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
	*line_height = (int)(HEIGHT / ray->perp_wall_dist);
	if (*line_height < 0)
		*line_height = HEIGHT;
	draw_point->x = -(*line_height) / 2 + HEIGHT / 2;
	if (draw_point->x < 0)
		draw_point->x = 0;
	draw_point->y = (*line_height) / 2 + HEIGHT / 2;
	if (draw_point->y >= HEIGHT)
		draw_point->y = HEIGHT - 1;
}

static void	calc_texture_coords(t_ray_info *ray, t_vars *data,
		t_vector2_int *tex_coord, t_vector2_int y)
{
	double	wall_x;
	int		d;

	if (ray->side == 0)
		wall_x = data->player->pos.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		wall_x = data->player->pos.x + ray->perp_wall_dist * ray->ray_dir.x;
	wall_x -= floor(wall_x);
	tex_coord->x = (int)(wall_x
			* (double)data->textures[ray->wall_dir].dimension.x);
	if ((ray->side == 0 && ray->ray_dir.x > 0) || (ray->side == 1
			&& ray->ray_dir.y < 0))
		tex_coord->x = data->textures[ray->wall_dir].dimension.x - tex_coord->x
			- 1;
	d = y.x * 256 - HEIGHT * 128 + y.y * 128;
	tex_coord->y = ((d * data->textures[ray->wall_dir].dimension.y) / y.y)
		/ 256;
}

static void	draw_texture_stripe(t_vars *data, t_ray_info *ray,
		t_vector2_int coord, t_vector2_int text_coord)
{
	char	*tex_pixel;
	int		color;

	if (text_coord.x >= 0
		&& text_coord.x < data->textures[ray->wall_dir].dimension.x
		&& text_coord.y >= 0
		&& text_coord.y < data->textures[ray->wall_dir].dimension.y)
	{
		tex_pixel = data->textures[ray->wall_dir].texture_data + (text_coord.y
				* data->textures[ray->wall_dir].length + text_coord.x
				* (data->textures[ray->wall_dir].bpp / 8));
		color = *(unsigned int *)tex_pixel;
		if (ray->side == 1)
			color = (color >> 1) & 0x7F7F7F;
		put_my_pixel(data, coord.x, coord.y, color);
	}
}

void	draw(t_vars *data, t_vector2_int draw_points, t_ray_info *ray,
		t_vector2_int coord)
{
	int				y;
	t_vector2_int	tex_coord;

	y = draw_points.x;
	while (y <= draw_points.y)
	{
		tex_coord = (t_vector2_int){0, 0};
		calc_texture_coords(ray, data, &tex_coord, (t_vector2_int){y, coord.y});
		draw_texture_stripe(data, ray, (t_vector2_int){coord.x, y}, tex_coord);
		y++;
	}
}

void	render_walls(t_vars *data)
{
	t_ray_info		ray;
	int				x;
	t_vector2_int	draw_point;
	int				line_height;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(&ray, *data->player, x);
		calc_ray_step(&ray, *data->player);
		perform_dda(&ray, data);
		if (ray.map_pos.x < 0 || ray.map_pos.x >= data->map_dimesnion.x
			|| ray.map_pos.y < 0 || ray.map_pos.y >= data->map_dimesnion.y)
			continue ;
		calc_wall_projection(&ray, &draw_point, &line_height);
		ray.wall_dir = get_wall_direction(ray.ray_dir.x, ray.ray_dir.y,
				ray.side);
		draw(data, draw_point, &ray, (t_vector2_int){x, line_height});
		x++;
	}
}
