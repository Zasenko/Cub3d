/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:46:27 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/26 18:52:19 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_core.h"
#include "stdio.h"

void	draw_floor_and_ceiling(t_vars *data)
{
	t_color	*floor;
	t_color	*ceiling;
	int		y;
	int		x;

	floor = data->map_s->textures.f;
	ceiling = data->map_s->textures.c;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				put_my_pixel(data, x, y, rgb_to_color(ceiling->r, ceiling->g,
						ceiling->b));
			else
				put_my_pixel(data, x, y, rgb_to_color(floor->r, floor->g,
						floor->b));
			x++;
		}
		y++;
	}
}

void	handle_rotation(t_vars *vars)
{
	t_player	*player;
	float		rotate_angle;
	double		old_dir_x;
	double		old_plane_x;

	player = vars->player;
	if (player->rotate_input == 0)
		return ;
	rotate_angle = -(player->rotate_input) * ROT_SPEED;
	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(rotate_angle) - player->dir.y
		* sin(rotate_angle);
	player->dir.y = old_dir_x * sin(rotate_angle) + player->dir.y
		* cos(rotate_angle);
	old_plane_x = player->cam_plane.x;
	player->cam_plane.x = player->cam_plane.x * cos(rotate_angle)
		- player->cam_plane.y * sin(rotate_angle);
	player->cam_plane.y = old_plane_x * sin(rotate_angle) + player->cam_plane.y
		* cos(rotate_angle);
}

void	handle_movement(t_player *player, char **map)
{
	t_vector2	next_position;
	t_vector2	perp_dir;

	if (player->vertical_input != 0)
	{
		next_position = (t_vector2){player->dir.x * SPEED
			* player->vertical_input, player->dir.y * SPEED
			* player->vertical_input};
		if (map[(int)(player->pos.x
				+ next_position.x)][(int)player->pos.y] == '0')
			player->pos.x += next_position.x;
		if (map[(int)(player->pos.x)][(int)(player->pos.y
				+ next_position.y)] == '0')
			player->pos.y += next_position.y;
	}
	if (player->horizontal_input != 0)
	{
		perp_dir = (t_vector2){player->dir.y * SPEED * player->horizontal_input,
			player->dir.x * SPEED * -player->horizontal_input};
		if (map[(int)(player->pos.x + perp_dir.x)][(int)player->pos.y] == '0')
			player->pos.x += perp_dir.x;
		if (map[(int)player->pos.x][(int)(player->pos.y + perp_dir.y)] == '0')
			player->pos.y += perp_dir.y;
	}
}

int	render_frame(t_vars *vars)
{
	handle_movement(vars->player, vars->map);
	handle_rotation(vars);
	draw_floor_and_ceiling(vars);
	render_walls(vars);
	render_buffer(vars);
	return (0);
}
