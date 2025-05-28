/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitryzasenko <dmitryzasenko@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:36:29 by dzasenko          #+#    #+#             */
/*   Updated: 2025/05/27 21:05:23 by dmitryzasen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared.h"
#include "m_parser.h"

int check_map_chars(char *str, char *set)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(!check_char(str[i], set))
            return (0);
        i++;
    }
    return (1);
}
/// set the dir
int fill(t_map *map, int row, int col)
{
	if (row < 0 || col < 0
        || arr_str_count(map->map) <= row || (int)ft_strlen(map->map[row]) <= col)
		return (0);
    if (map->map[row][col] == ' ')
		return (0);
	if (map->map[row][col] == '1' || map->map[row][col] == 'Z')
		return (1);
	if (check_char(map->map[row][col], "NSEW"))
    {
        if (map->direction != DIR_NONE)
            return (0);
        if (map->map[row][col] == 'N')
            map->direction = DIR_NORTH;
        else if (map->map[row][col] == 'S')
            map->direction = DIR_SOUTH;
        else if (map->map[row][col] == 'E')
            map->direction = DIR_EAST;
        else if (map->map[row][col] == 'W')
            map->direction = DIR_WEST;
        map->start.x = col;
        map->start.y = row;
    }
	map->map[row][col] = 'Z';
	if (!fill(map, row -1, col) || !fill(map, row +1, col)
        || !fill(map, row, col - 1) || !fill(map, row, col + 1))
        return (0);
    return (1);
}

void fill_back(t_map *map)
{
    int i;
    int f;

    i = 0;
    f = 0;
    while(map->map[i])
    {
        f = 0;
        while(map->map[i][f])
        {
            if (check_char(map->map[i][f], "Z"))
                map->map[i][f] = '0';
            f++;
        }
        i++;
    }
}

int check_walls(t_map *map)
{
    int i;
    int f;

    i = 0;
    f = 0;
    while(map->map[i])
    {
        f = 0;
        while(map->map[i][f])
        {
            if (check_char(map->map[i][f], "0NSEW"))
            {
                if (!fill(map, i, f))
                    return (0);
            }
            f++;
        }
        i++;
    }
    if(map->direction == DIR_NONE)
        return (0);
    fill_back(map);
    return (1);
}
//
int check_map(t_map *map)
{
    int i;
    int len;

    i = 0;
    while(map->map[i])
    {
        len = ft_strlen(map->map[i]);
        if(len > map->row_l)
        {
            map->row_l = len;
            if (map->row_l > 300)
                return (ft_putstr_fd("Error\nMap too big\n", 2), 0);  
        }
        i++;
    }
    map->col_l = i;
    if (map->col_l > 300)
        return (ft_putstr_fd("Error\nMap too big\n", 2), 0);
    if(!check_walls(map))
        return (ft_putstr_fd("Error: Incrorrect Map", 2), 0);
    return (1);
}
