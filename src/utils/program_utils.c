/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:29:23 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/26 19:05:58 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_program(t_vars *vars, t_map *map)
{
	vars->textures[0] = load_texture(vars, map->textures.no_path);
	vars->textures[1] = load_texture(vars, map->textures.so_path);
	vars->textures[2] = load_texture(vars, map->textures.we_path);
	vars->textures[3] = load_texture(vars, map->textures.ea_path);
	vars->map_s = map;
	vars->map = map->map;
	vars->map_dimesnion = (t_vector2_int){map->col_l, map->row_l};
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
