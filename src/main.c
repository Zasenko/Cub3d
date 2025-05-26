/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:26:40 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/26 19:06:17 by yalnaani         ###   ########.fr       */
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
	t_vars		*vars;
	t_map		*map;
	t_player	player;

	map = check_input(argc, argv);
	if (!map)
	{
		exit(EXIT_FAILURE);
	}
	vars = new_vars();
	vars->player = &player;
	set_map_texture(vars, map);
	hook_events(vars);
	mlx_loop_hook(vars->mlx, (void *)render_frame, vars);
	mlx_loop(vars->mlx);
	return (0);
}
