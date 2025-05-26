/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:34:24 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/26 18:44:15 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	rgb_to_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	render_buffer(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

void	put_my_pixel(t_vars *vars, int x, int y, int color)
{
	char	*t_pixel;

	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{
		t_pixel = vars->addr + (y * vars->line_length + x
				* (vars->bits_per_pixel) / 8);
		*(unsigned int *)t_pixel = color;
	}
}

void	clear_buffer(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_my_pixel(vars, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
