/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:55:14 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/26 09:56:38 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_core.h"
#include <stdio.h>

// Function to determine wall direction
int	get_wall_direction(double ray_dir_x, double ray_dir_y, int side)
{
	if (side == 0) // X (E/W)
	{
		if (ray_dir_x > 0)
			return (2); // e
		else
			return (3); // w
	}
	else // N/S
	{
		if (ray_dir_y > 0)
			return (1); // s
		else
			return (0); // n
	}
}

// 1. Initialize ray information
static void	init_ray(t_ray_info *ray, t_player player, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir.x = player.dir.x + player.cam_plane.x * ray->camera_x;
	ray->ray_dir.y = player.dir.y + player.cam_plane.y * ray->camera_x;
	ray->map_pos.x = (int)player.pos.x;
	ray->map_pos.y = (int)player.pos.y;
	ray->hit = false;
}

// 2. Calculate ray step and side distances
static void	calc_ray_step(t_ray_info *ray, t_player player)
{
	if(ray->ray_dir.x == 0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x  = fabs(1 / ray->ray_dir.x);
	if(ray->ray_dir.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player.pos.x - ray->map_pos.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map_pos.x + 1.0 - player.pos.x)
			* ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player.pos.y - ray->map_pos.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map_pos.y + 1.0 - player.pos.y)
			* ray->delta_dist.y;
	}
}

// 3. Perform DDA algorithm
static void	perform_dda(t_ray_info *ray, t_vars *vars)
{
	while (!ray->hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_pos.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_pos.y += ray->step.y;
			ray->side = 1;
		}
		if (ray->map_pos.x < 0 || ray->map_pos.x >= vars->map_dimesnion.x
			|| ray->map_pos.y < 0 || ray->map_pos.y >= vars->map_dimesnion.y)
		{
			ray->hit = true;
			break ;
		}
		if (vars->map[ray->map_pos.x][ray->map_pos.y] != '0')
			ray->hit = true;
	}
}

// 4. Calculate wall distance and line height
static void	calc_wall_projection(t_ray_info *ray, int *line_height,
		int *draw_start, int *draw_end)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
	*line_height = (int)(HEIGHT / ray->perp_wall_dist);
	*line_height = (*line_height < 0) ? HEIGHT : *line_height;
	*draw_start = -(*line_height) / 2 + HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = (*line_height) / 2 + HEIGHT / 2;
	if (*draw_end >= HEIGHT)
		*draw_end = HEIGHT - 1;
}

// 5. Calculate texture coordinates
static void	calc_texture_coords(t_ray_info *ray, t_vars *data, int *tex_x,
		int *tex_y, int y, int line_height)
{
	double	wall_x;
	int		d;

	if (ray->side == 0)
		wall_x = data->player->pos.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		wall_x = data->player->pos.x + ray->perp_wall_dist * ray->ray_dir.x;
	wall_x -= floor(wall_x);
	*tex_x = (int)(wall_x * (double)data->textures[ray->wall_dir].dimension.x);
	if ((ray->side == 0 && ray->ray_dir.x > 0) || (ray->side == 1
			&& ray->ray_dir.y < 0))
		*tex_x = data->textures[ray->wall_dir].dimension.x - *tex_x - 1;
	d = y * 256 - HEIGHT * 128 + line_height * 128;
	*tex_y = ((d * data->textures[ray->wall_dir].dimension.y) / line_height)
		/ 256;
}

// 6. Draw vertical texture stripe
static void	draw_texture_stripe(t_vars *data, t_ray_info *ray, int x, int y,
		int tex_x, int tex_y)
{
	char	*tex_pixel;
	int		color;

	if (tex_x >= 0 && tex_x < data->textures[ray->wall_dir].dimension.x
		&& tex_y >= 0 && tex_y < data->textures[ray->wall_dir].dimension.y)
	{
		tex_pixel = data->textures[ray->wall_dir].texture_data + (tex_y
				* data->textures[ray->wall_dir].length + tex_x
				* (data->textures[ray->wall_dir].bpp / 8));
		color = *(unsigned int *)tex_pixel;
		if (ray->side == 1)
			color = (color >> 1) & 0x7F7F7F;
		put_my_pixel(data, x, y, color);
	}
}

// Main render_walls function (now just orchestrates the smaller functions)
void	render_walls(t_vars *data)
{
	t_ray_info	ray;

	for (int x = 0; x < WIDTH; x++)
	{
		init_ray(&ray, *data->player, x);
		calc_ray_step(&ray, *data->player);
		perform_dda(&ray, data);
		if (ray.map_pos.x < 0 || ray.map_pos.x >= data->map_dimesnion.x
			|| ray.map_pos.y < 0 || ray.map_pos.y >= data->map_dimesnion.y)
			continue ;
		int line_height, draw_start, draw_end;
		calc_wall_projection(&ray, &line_height, &draw_start, &draw_end);
		ray.wall_dir = get_wall_direction(ray.ray_dir.x, ray.ray_dir.y,
				ray.side);
		ray.wall_dir = (ray.wall_dir < 0
				|| ray.wall_dir > 3) ? 0 : ray.wall_dir;
		for (int y = draw_start; y <= draw_end; y++)
		{
			int tex_x, tex_y;
			calc_texture_coords(&ray, data, &tex_x, &tex_y, y, line_height);
			draw_texture_stripe(data, &ray, x, y, tex_x, tex_y);
		}
	}
}
