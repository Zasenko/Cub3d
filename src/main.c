/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:26:40 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/22 14:01:49 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shared.h"
#include "datastructures/datastructures.h"
#include "mlx.h"
#include "io/input.h"
#include "parser/input_parser.h"
#include "logger/logger.h"

#include <stdio.h>
int main(int argc, char **argv)
{
    // t_vars *vars;
    t_map *map;
    
    map = NULL;
    map = check_input(argc, argv);
    if(!map)
    {
        exit(EXIT_FAILURE);
    }
    printf("--- TEXTURES ---\n");
    printf("no_path: [%s]\n", map->textures.no_path);
    printf("so_path: [%s]\n", map->textures.so_path);
    printf("we_path: [%s]\n", map->textures.we_path);
    printf("ea_path: [%s]\n\n", map->textures.no_path);
    printf("--- COLORS ---\n");
    printf("f: %d.%d.%d\n", map->textures.f->r, map->textures.f->g, map->textures.f->b);
    printf("f: %d.%d.%d\n\n", map->textures.c->r, map->textures.c->g, map->textures.c->b);
    printf("--- START POSITION ---\n");
    printf("x: %d, y: %d, direction: %d\n", map->start.x, map->start.y, map->direction);
    printf("--- MAP ---\n");
    int i = 0;
    while(map->map[i])
    {
        printf("%d: %s\n", i, map->map[i]);
        i++;
    }
    free_map(map);
    // vars = new_vars();
    // mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
    // hook(vars);
    // mlx_loop(vars->mlx);
}