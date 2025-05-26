/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:46:27 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/26 14:00:46 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "m_core.h"
#include "stdio.h"

void draw_floor_and_ceiling(t_vars *data)
{
    t_color *floor = data->map_s->textures.f;
    t_color *ceiling = data->map_s->textures.c;

    // Draw ceiling (top half of screen)
    for (int y = 0; y < HEIGHT / 2; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            put_my_pixel(data, x, y, rgb_to_color(ceiling->r, ceiling->g, ceiling->b));
        }
    }
    
    // Draw floor (bottom half of screen)
    for (int y = HEIGHT / 2; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            put_my_pixel(data, x, y, rgb_to_color(floor->r, floor->g, floor->b)); // Gray floor
        }
    }
}


int render_frame(t_vars *vars)
{
    draw_floor_and_ceiling(vars);
    render_walls(vars);
    render_buffer(vars);
    return 0;
}


