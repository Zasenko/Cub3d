/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitryzasenko <dmitryzasenko@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:38:16 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/27 21:53:30 by dmitryzasen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared.h"
#include "m_parser.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (ft_putstr_fd("Error\nMalloc\n", 2), NULL);
	map->map = NULL;
	map->textures.no_path = NULL;
	map->textures.so_path = NULL;
	map->textures.we_path = NULL;
	map->textures.ea_path = NULL;
	map->textures.f = NULL;
	map->textures.c = NULL;
	map->direction = DIR_NONE;
	map->row_l = 0;
    map->col_l = 0;
	return (map);
}

t_map *check_input(int argc, char **argv)
{
	char	*str;
	t_map *map;

	if (argc != 2)
		return (ft_putstr_fd("Error\nNot a valid args count\n", 2), NULL);
	str = read_from_file(argv[1]);
	if (!str)
		return(NULL);
	map = init_map();
	if (!map)
		return(free(str), NULL);
	if (!get_args(str, map))
	{
		free(str);
		free_map(map);
		return	(NULL);
	}
	free(str);
	if(!check_map(map))
		return(free_map(map), NULL);
	return map;
}
