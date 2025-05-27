/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:51:37 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/27 09:04:48 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_core.h"

int	get_wall_direction(double ray_dir_x, double ray_dir_y, int side)
{
	if (side == 0)
	{
		if (ray_dir_x > 0)
			return (2);
		else
			return (3);
	}
	else
	{
		if (ray_dir_y > 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

void	init_ray(t_ray_info *ray, t_player player, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir.x = player.dir.x + player.cam_plane.x * ray->camera_x;
	ray->ray_dir.y = player.dir.y + player.cam_plane.y * ray->camera_x;
	ray->map_pos.x = (int)player.pos.x;
	ray->map_pos.y = (int)player.pos.y;
	ray->hit = false;
}

void	calc_ray_step(t_ray_info *ray, t_player player)
{
	ray->step = (t_vector2_int){1, 1};
	if (ray->ray_dir.x == 0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	if (ray->ray_dir.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player.pos.x - ray->map_pos.x) * ray->delta_dist.x;
	}
	else
		ray->side_dist.x = (ray->map_pos.x + 1.0 - player.pos.x)
			* ray->delta_dist.x;
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player.pos.y - ray->map_pos.y) * ray->delta_dist.y;
	}
	else
		ray->side_dist.y = (ray->map_pos.y + 1.0 - player.pos.y)
			* ray->delta_dist.y;
}

void	perform_dda(t_ray_info *ray, t_vars *vars)
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
		if (vars->map_s->map[ray->map_pos.x][ray->map_pos.y] != '0')
			ray->hit = true;
	}
}
