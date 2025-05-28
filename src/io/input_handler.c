/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:07:32 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/28 08:52:50 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_input.h"
#include "mlx.h"

int	key_press(int keycode, t_vars *vars)
{
	t_player	*player;

	player = vars->player;
	if (keycode == 'w')
		vars->player->vertical_input = 1;
	if (keycode == 's')
		vars->player->vertical_input = -1;
	if (keycode == 'd')
		player->horizontal_input = 1;
	if (keycode == 'a')
		player->horizontal_input = -1;
	if (keycode == RIGHT_KEY)
		player->rotate_input = 1;
	if (keycode == LEFT_KEY)
		player->rotate_input = -1;
	if (keycode == 65307)
		exit_program(vars);
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == 'w' || keycode == 's')
		vars->player->vertical_input = 0;
	else if (keycode == 'a' || keycode == 'd')
		vars->player->horizontal_input = 0;
	else if (keycode == LEFT_KEY || keycode == RIGHT_KEY)
		vars->player->rotate_input = 0;
	return (0);
}

void	hook_events(t_vars *vars)
{
	mlx_hook(vars->win, 17, 0, exit_program, vars);
	mlx_hook(vars->win, 2, (1L << 0), key_press, vars);
	mlx_hook(vars->win, 3, (1L << 1), key_release, vars);
}
