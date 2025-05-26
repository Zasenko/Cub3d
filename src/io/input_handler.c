/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:07:32 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/26 11:56:39 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_input.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>

double move_speed = 0.1;
double rot_speed = 0.1;

int	key_press(int keycode, t_vars *vars)
{
	t_player *player = vars->player;
	// Move forward if no wall in front of you
    if (keycode == 'w') // W key
    {
       /* if (vars->map[(int)(player->pos.x + player->dir.x * move_speed)][(int)player->pos.y] == '0')
            player->pos.x += player->dir.x * move_speed;
        if (vars->map[(int)player->pos.x ][(int)(player->pos.y + player->dir.y * move_speed)] == '0')
            player->pos.y += player->dir.y * move_speed;*/
         if (vars->map[(int)(player->pos.x + player->dir.x * move_speed)][(int)player->pos.y] == '0'
            && vars->map[(int)player->pos.x ][(int)(player->pos.y + player->dir.y * move_speed)] == '0')
            {
                player->pos.x += player->dir.x * move_speed;
                player->pos.y += player->dir.y * move_speed;
            }  
    }
    // Move backwards if no wall behind you
    if (keycode == 's') // S key
    {
        if (vars->map[(int)(player->pos.x  - player->dir.x * move_speed)][(int)player->pos.y] == '0')
             player->pos.x -= player->dir.x  * move_speed;
       if (vars->map[(int)player->pos.x ][(int)(player->pos.y + player->dir.y * move_speed)] == '0')
            player->pos.y -= player->dir.y * move_speed;
    }

	if(keycode == 'd')
	{
		double perp_dir_x = player->dir.y;
        double perp_dir_y = -player->dir.x;
        if (vars->map[(int)(player->pos.x + perp_dir_x * move_speed)][(int)player->pos.y] == '0')
            player->pos.x += perp_dir_x * move_speed;
        if (vars->map[(int)player->pos.x][(int)(player->pos.y + perp_dir_y * move_speed)] == '0')
            player->pos.y += perp_dir_y * move_speed;
	}

	if(keycode == 'a')
	{
		// Move left (strafe perpendicular to direction)
        double perp_dir_x = -player->dir.y;
        double perp_dir_y = player->dir.x;
        if (vars->map[(int)(player->pos.x + perp_dir_x * move_speed)][(int)player->pos.y] == '0')
            player->pos.x += perp_dir_x * move_speed;
        if (vars->map[(int)player->pos.x][(int)(player->pos.y + perp_dir_y * move_speed)] == '0')
            player->pos.y += perp_dir_y * move_speed;
	}
	
    // Rotate to the right
    if (keycode == RIGHT_Key) // D key
    {
        // Both camera direction and camera plane must be rotated
        double old_dir_x = player->dir.x;
        player->dir.x = player->dir.x * cos(-rot_speed) - player->dir.y * sin(-rot_speed);
        player->dir.y = old_dir_x * sin(-rot_speed) + player->dir.y * cos(-rot_speed);
        double old_plane_x = player->cam_plane.x;
        player->cam_plane.x = player->cam_plane.x * cos(-rot_speed) - player->cam_plane.y * sin(-rot_speed);
        player->cam_plane.y = old_plane_x * sin(-rot_speed) + player->cam_plane.y * cos(-rot_speed);
    }
	
	
    // Rotate to the left
    if (keycode == LEFT_Key) // A key
    {
        // Both camera direction and camera plane must be rotated
        double old_dir_x = player->dir.x;
        player->dir.x = player->dir.x * cos(rot_speed) - player->dir.y * sin(rot_speed);
        player->dir.y = old_dir_x * sin(rot_speed) + player->dir.y * cos(rot_speed);
        double old_plane_x = player->cam_plane.x;
        player->cam_plane.x = player->cam_plane.x * cos(rot_speed) - player->cam_plane.y * sin(rot_speed);
        player->cam_plane.y = old_plane_x * sin(rot_speed) + player->cam_plane.y * cos(rot_speed);
    }
    // Exit on ESC
    if (keycode == 65307) // ESC key
    {
        exit_program(vars);
    }
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == W_KEY || keycode == S_KEY)
		vars->player->vertical_input = 0;
	else if (keycode == A_KEY || keycode == D_KEY)
		vars->player->horizontal_input = 0;
	return (0);
}

void	hook_events(t_vars *vars)
{
	mlx_hook(vars->win, 17, 0, exit_program, vars);
	mlx_hook(vars->win, 2, (1L << 0), key_press, vars);
	mlx_hook(vars->win, 3, (1L << 1), key_release, vars);
}
