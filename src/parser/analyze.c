/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitryzasenko <dmitryzasenko@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:14:51 by dzasenko          #+#    #+#             */
/*   Updated: 2025/05/27 21:53:00 by dmitryzasen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared.h"
#include "m_parser.h"

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

int	get_map(char *str, t_map *map)
{
	char	**arr;
	int		len;

	if (!str || !map)
		return (0);
	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t'
			|| str[len - 1] == '\n'))
		len--;
	if (len == 0)
		return (show_err(3), 0);
	while (str[len] && str[len] != '\n')
		len++;
	if (!check_map_empty_lines(str, len))
		return (0);
	arr = ft_split(str, '\n');
	if (!arr)
		return (show_err(1), 0);
	if (!check_wrong_char(arr))
		return (free_arr(arr), show_err(6), 0);
	map->map = arr;
	return (1);
}

int	compare_keys(char *str, int *i, t_map *map)
{
	if (!str || !i || !str[*i] || !map)
		return (show_err(0), 0);
	if (!ft_strncmp(&str[*i], "NO", 2) || !ft_strncmp(&str[*i], "SO", 2)
		|| !ft_strncmp(&str[*i], "WE", 2) || !ft_strncmp(&str[*i], "EA", 2))
		return (get_textures(str, i, map));
	else if (!ft_strncmp(&str[*i], "F", 1) || !ft_strncmp(&str[*i], "C", 1))
		return (get_colors(str, i, map));
	else
		return (show_err(4), 0);
}

int	map_prepare(t_map *map, char *str, int *i)
{
	if (!is_textures_set(map))
		return (show_err(4), 0);
	if (!skip_empty_lines(str, i))
		return (show_err(3), 0);
	if (!get_map(&str[*i], map))
		return (0);
	return (1);
}

int	get_args(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_textures_set(map))
			break ;
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			i++;
			continue ;
		}
		if (!compare_keys(str, &i, map))
			return (0);
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (!str[i] || str[i] != '\n')
			return (show_err(4), 0);
		i++;
	}
	return (map_prepare(map, str, &i));
}
