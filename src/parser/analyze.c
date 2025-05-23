/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:14:51 by dzasenko          #+#    #+#             */
/*   Updated: 2025/05/23 13:14:53 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared.h"
#include "m_parser.h"

int	is_empty_line(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_textures_set(t_map *map)
{
	t_textures	textures;

	textures = map->textures;
	if (textures.no_path && textures.so_path && textures.we_path
		&& textures.ea_path && textures.f && textures.c)
	{
		return (1);
	}
	return (0);
}

int	analyze_line(char *str, t_map *map)
{
	char	**args;
	int		i;

	i = 0;
	if(!str || !map)
		return (-1);
	while(str[i])
	{
		if(ft_isalpha(str[i]))
		{
			args = ft_split(str, ' ');//malloc
			if (!args)
				return (ft_putstr_fd("Error: malloc\n", 2), -1);
			if (arr_str_count(args) != 2)
				return (free_arr(args),ft_putstr_fd("Error: parse\n", 2), -1);
			if (!compare_args(args, map))
				return (free_arr(args), -1);
			free_arr(args);
			return (1);
		}
		i++;
	}
	return (0);
}

int get_info_from_file(char **arr, int *i, t_map *map)
{
	int res;

	if(!arr || !i || !map)
		return (ft_putstr_fd("Error\n", 2), 0);
	while (arr[(*i)])
	{
		if(!is_textures_set(map))
		{
			res = analyze_line(arr[(*i)], map);
			if(res == 0)
			{
				(*i)++;
				continue;
			}
			else if (res == -1)
				return (0);
			(*i)++;
		}
		else
			break;
	}
	return (1);
}

char	**create_map(char **arr)
{
	int count;
	char	**map_arr;
	int i;
	char *str;

	count = arr_str_count(arr);
	map_arr = ft_calloc(count + 1, sizeof(char *));
	if (!map_arr)
		return (ft_putstr_fd("Error: calloc\n", 2), NULL);
	i = 0;
	while(arr[i])
	{
		str = NULL;
		str = ft_strdup(arr[i]);
		if (!str)
			return (free_arr(map_arr), NULL);
		map_arr[i] = str;
		i++;
	}
	return (map_arr);
}

char **analyze(char *str, t_map *map)
{
	char	**arr;
	char	**map_arr;
	int i;

	map_arr = NULL;
	i = 0;
	arr = ft_split(str, '\n');
	if (!arr)
		return (ft_putstr_fd("Error: malloc\n", 2), NULL);
	if (!get_info_from_file(arr, &i, map))
		return (free_arr(arr), NULL);
	while(arr[i])
	{
		if(is_empty_line(arr[i]))
			i++;
		else
			break;
	}
	if (!arr[i])
		return (free_arr(arr), NULL);
	map_arr = create_map(&arr[i]);
	free_arr(arr);
	return(map_arr);
}
