/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:26:40 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/26 14:18:43 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shared.h"
#include "datastructures/datastructures.h"
#include "mlx.h"
#include "io/input.h"
#include "parser/input_parser.h"
#include "logger/logger.h"
#include "core/core.h"
#include "utils/utils.h"
#include <stdio.h>
#include <math.h>

/*
static char *map_data[24] = {
        "111111111111111111111111",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000100000000000100001",
        "100000100000100000100001",
        "100000100000000000100001",
        "100000000000000000100001",
        "100000111111111111100001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000010000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000001000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "111111111111111111111111"
    };*/


void spawn_at_index(t_vars *data, int spawn_x, int spawn_y)
{
    if (spawn_x >= 0 && spawn_x < MAP_WIDTH && 
        spawn_y >= 0 && spawn_y < MAP_HEIGHT && 
        data->map[spawn_x][spawn_y] == '0') 
    {
        
        data->player->pos.x = spawn_x + 0.5;
        data->player->pos.y = spawn_y + 0.5;
    }
}

void set_facing_direction(t_vars *data, t_direction dir)
{
    switch (dir) 
    {
        case DIR_NONE:
            break;
        case DIR_NORTH: // Facing north
            data->player->dir = (t_vector2){-1.0, 0.0};
            data->player->cam_plane = (t_vector2){0.0, 0.66};
            /*data->player->dir.x = -1.0;
            data->player->dir.y = 0.0;
            data->player->cam_plane.x = 0.0;
            data->player->cam_plane.y = 0.66;*/
            break;
            
        case DIR_EAST: // Facing east
            data->player->dir = (t_vector2){0.0, 1.0};
            data->player->cam_plane = (t_vector2){0.66, 0.0};
           /*data->player->dir.x = 0.0;
            data->player->dir.y = 1.0;
            data->player->cam_plane.x = 0.66;
            data->player->cam_plane.y = 0.0;*/
            break;
            
        case DIR_SOUTH: // Facing south
            data->player->dir = (t_vector2){1.0, 0.0};
            data->player->cam_plane = (t_vector2){0.0, -0.66};
            /*data->player->dir.x  = 1.0;
            data->player->dir.y= 0.0;
            data->player->cam_plane.x= 0.0;
            data->player->cam_plane.y = -0.66;*/
            break;
            
        case DIR_WEST: // Facing west
            data->player->dir = (t_vector2){0.0, -1.0};
            data->player->cam_plane = (t_vector2){-0.66, 0.0};
            /*data->player->dir.x  = 0.0;
            data->player->dir.y= -1.0;
            data->player->cam_plane.x = -0.66;
            data->player->cam_plane.y= 0.0;*/
            break;
    }
}
/// s -> w
// w -> n
// n -> e
// e -> s



void init_player(t_vars *vars)
{
   // vars->player->pos.x = 1.5f;
   // vars->player->pos.y = 1.5f;
  spawn_at_index(vars, 1, 1);
    set_facing_direction(vars, DIR_WEST);
}

t_texture load_texture(t_vars *vars,char *path)
{
    t_texture texture;
    texture.texture = mlx_xpm_file_to_image(vars->mlx, path, 
        &texture.dimension.x, &texture.dimension.y);
    if(!texture.texture)
    {
        printf("Error: Could not load texture %s\n", path);
        exit(1);
    }
    texture.texture_data = mlx_get_data_addr(texture.texture,
        &texture.bpp, &texture.length, &texture.endian);   
    return texture; 
}
/*
 static char *map_data[5] = {
        "11111",
        "10001",
        "10001"
    };    
vars->map_dimesnion = (t_vector2_int){3, 5};  // Fixed typo in "dimension"
*/
void set_map_texture(t_vars *vars, t_map *map)
{
    vars->textures[0] = load_texture(vars, "textures/North.xpm");
    vars->textures[1] = load_texture(vars, "textures/South.xpm");
    vars->textures[2] = load_texture(vars, "textures/West.xpm");
    vars->textures[3] = load_texture(vars, "textures/East.xpm");

    vars->map_s = map;
    vars->map = map->map;
    vars->map_dimesnion = (t_vector2_int){map->col_l, map->row_l};

    
    spawn_at_index(vars, 1, 1);
    //vars->player->pos.x = 1.5f;
    //vars->player->pos.y = 1.5f;
    set_facing_direction(vars, DIR_WEST);
}

int main(int argc, char **argv)
{
    t_vars *vars;
    t_map* map;
    
    map = check_input(argc, argv);
    if(!map)
    {
        exit(EXIT_FAILURE);
    }
    vars = new_vars();
    t_player player;
    vars->player = &player;
    set_map_texture(vars, map);
    
    spawn_at_index(vars, map->start.y, map->start.x);
    set_facing_direction(vars, DIR_EAST);
    hook_events(vars);
    mlx_loop_hook(vars->mlx, (void *)render_frame, vars);
    mlx_loop(vars->mlx);
    return 0;
}
