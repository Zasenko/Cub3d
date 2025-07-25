/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:26:40 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/28 15:26:34 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shared.h"
#include "core/core.h"
#include "datastructures/datastructures.h"
#include "io/input.h"
#include "mlx.h"
#include "parser/input_parser.h"
#include "utils/utils.h"

int	main(int argc, char **argv)
{
	t_vars		*vars;
	t_map		*map;
	t_player	player;

	check_resolution();
	map = check_input(argc, argv);
	if (!map)
	{
		exit(EXIT_FAILURE);
	}
	vars = new_vars();
	if (!vars)
	{
		free_map(map);
		exit(1);
	}
	vars->player = &player;
	init_program(vars, map);
	hook_events(vars);
	mlx_loop_hook(vars->mlx, (void *)render_frame, vars);
	mlx_loop(vars->mlx);
	return (0);
}
