/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:36:29 by dzasenko          #+#    #+#             */
/*   Updated: 2025/05/26 10:37:19 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared.h"
#include "m_parser.h"

int check_char(char c, char *set)
{
    int i;

    i = 0;
    while(set[i])
    {
        if (set[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int check_chars(char *str, char *set)
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
        if (map->direction != 0)
            return (0);
        if (map->map[row][col] == 'N')
            map->direction = 1;
        else if (map->map[row][col] == 'S')
            map->direction = 2;
        else if (map->map[row][col] == 'E')
            map->direction = 3;
        else if (map->map[row][col] == 'W')
            map->direction = 4;
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
    if(map->direction == 0)
        return (0);
    fill_back(map);
    return (1);
}

int check_map(t_map *map)
{
    int i;

    i = 0;
    while(map->map[i])
    {
        if(!check_chars(map->map[i], " 10NSEW"))
            return (ft_putstr_fd("Error: Wrong simbol on Map", 2), 0);
        i++;
    }
    if(!check_walls(map))
        return (ft_putstr_fd("Error: Incrorrect Map", 2), 0);
    return (1);
}
