/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:29:23 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/28 14:34:25 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	check_resolution(void)
{
	if ((WIDTH < 100 || WIDTH > 1920) && (HEIGHT < 100 || HEIGHT > 1080))
	{
		ft_putstr_fd("Error:\nScreen Resolution error\n", 2);
		exit(1);
	}
}

static void	set_textures(t_vars *vars, t_map *map)
{
	vars->textures[0] = load_texture(vars, map->textures.no_path);
	if (!vars->textures[0].texture)
	{
		delete_vars(vars);
		exit(1);
	}
	vars->textures[1] = load_texture(vars, map->textures.so_path);
	if (!vars->textures[1].texture)
	{
		delete_vars(vars);
		exit(1);
	}
	vars->textures[2] = load_texture(vars, map->textures.we_path);
	if (!vars->textures[2].texture)
	{
		delete_vars(vars);
		exit(1);
	}
	vars->textures[3] = load_texture(vars, map->textures.ea_path);
	if (!vars->textures[3].texture)
	{
		delete_vars(vars);
		exit(1);
	}
}

void	init_program(t_vars *vars, t_map *map)
{
	vars->map_s = map;
	vars->map_dimesnion = (t_vector2_int){map->col_l, map->row_l};
	set_textures(vars, map);
	vars->player->horizontal_input = 0;
	vars->player->vertical_input = 0;
	vars->player->rotate_input = 0;
	spawn_at_index(vars, map->start.y, map->start.x);
	set_facing_direction(vars, vars->map_s->direction);
}

int	exit_program(t_vars *vars)
{
	delete_vars(vars);
	exit(0);
	return (0);
}
