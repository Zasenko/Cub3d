/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:47:12 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/27 09:05:15 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	spawn_at_index(t_vars *data, int spawn_x, int spawn_y)
{
	if (spawn_x >= 0 && spawn_x < data->map_dimesnion.x && spawn_y >= 0
		&& spawn_y < data->map_dimesnion.y
		&& data->map_s->map[spawn_x][spawn_y] == '0')
	{
		data->player->pos.x = spawn_x + 0.5;
		data->player->pos.y = spawn_y + 0.5;
	}
}

void	set_facing_direction(t_vars *data, t_direction dir)
{
	if (dir == DIR_WEST)
	{
		data->player->dir = (t_vector2){-1.0, 0.0};
		data->player->cam_plane = (t_vector2){0.0, 0.66};
	}
	else if (dir == DIR_NORTH)
	{
		data->player->dir = (t_vector2){0.0, 1.0};
		data->player->cam_plane = (t_vector2){0.66, 0.0};
	}
	else if (dir == DIR_EAST)
	{
		data->player->dir = (t_vector2){1.0, 0.0};
		data->player->cam_plane = (t_vector2){0.0, -0.66};
	}
	else if (dir == DIR_SOUTH)
	{
		data->player->dir = (t_vector2){0.0, -1.0};
		data->player->cam_plane = (t_vector2){-0.66, 0.0};
	}
}
