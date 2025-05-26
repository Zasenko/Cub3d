/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:07:32 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/26 17:41:26 by yalnaani         ###   ########.fr       */
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
	if (keycode == RIGHT_Key)
		player->rotate_input = 1;
	if (keycode == LEFT_Key)
		player->rotate_input = -1;
	if (keycode == 65307)
		exit_program(vars);
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == W_KEY || keycode == S_KEY)
		vars->player->vertical_input = 0;
	else if (keycode == A_KEY || keycode == D_KEY)
		vars->player->horizontal_input = 0;
	else if (keycode == LEFT_Key || keycode == RIGHT_Key)
		vars->player->rotate_input = 0;
	return (0);
}

void	hook_events(t_vars *vars)
{
	mlx_hook(vars->win, 17, 0, exit_program, vars);
	mlx_hook(vars->win, 2, (1L << 0), key_press, vars);
	mlx_hook(vars->win, 3, (1L << 1), key_release, vars);
}
