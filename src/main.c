/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitryzasenko <dmitryzasenko@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:26:40 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/28 07:36:18 by dmitryzasen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shared.h"
#include "core/core.h"
#include "datastructures/datastructures.h"
#include "io/input.h"
#include "logger/logger.h"
#include "mlx.h"
#include "parser/input_parser.h"
#include "utils/utils.h"
#include <math.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	// t_vars		*vars;
	t_map		*map;
	// t_player	player;

	map = check_input(argc, argv);
	if (!map)
	{
		exit(EXIT_FAILURE);
	}
printf("TEXTURES\n");
printf("no: [%s]\n", map->textures.no_path);
printf("so: [%s]\n", map->textures.so_path);
printf("ea: [%s]\n", map->textures.ea_path);
printf("we: [%s]\n", map->textures.we_path);
printf("COLORS\n");
printf("f: [%d,%d,%d]\n", map->textures.f->r, map->textures.f->g, map->textures.f->b);
printf("c: [%d,%d,%d]\n", map->textures.c->r, map->textures.c->g, map->textures.c->b);
printf("START\n");
printf("[%d][%d] [%d]\n", map->start.x, map->start.y, map->direction);
	printf("MAP\n");
	int i = 0;
	while(map->map[i])
	{
		printf("[%d][%s]\n", i, map->map[i]);
		i++;
	}

	printf("SIZE\n");
printf("col_l: %d\n", map->col_l);
printf("row_l: %d\n", map->row_l);
	free_map(map);
	// vars = new_vars();
	// if(!vars)
	// {
	// 	free_map(map);
	// 	exit(1);
	// }
	// vars->player = &player;
	// init_program(vars, map);
	// hook_events(vars);
	// mlx_loop_hook(vars->mlx, (void *)render_frame, vars);
	// mlx_loop(vars->mlx);
	return (0);
}
