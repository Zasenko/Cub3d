/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:23:08 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/26 13:46:27 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
#define RAYCAST_H

#include <stdbool.h>

typedef struct s_vector2_int
{
    int x;
    int y;
}t_vector2_int;

typedef struct  s_vector2
{
    float x;
    float y;    
}t_vector2;


typedef struct s_ray_info
{
    double camera_x;
    t_vector2 ray_dir;
    t_vector2_int map_pos;
    t_vector2_int step;
    t_vector2 side_dist;
    t_vector2 delta_dist;
    double perp_wall_dist;
    bool hit;
    int side;
    int wall_dir;
}t_ray_info;


typedef struct s_player
{
    t_vector2 pos;
    t_vector2 dir;
    t_vector2 cam_plane;
    int horizontal_input;
    int vertical_input;
} t_player;

typedef struct s_texture
{
    void *texture;
    char *texture_data;
    t_vector2_int dimension;
    int bpp;
    int length;
    int endian;
} t_texture;

typedef enum e_direction {
    DIR_NONE,
    DIR_NORTH,
    DIR_EAST,
    DIR_SOUTH,
    DIR_WEST
} t_direction;

/*typedef struct s_map
{
    t_vector2 dimension;
    
} t_map;*/



#endif