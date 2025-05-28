/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:54:28 by dzasenko          #+#    #+#             */
/*   Updated: 2025/05/28 12:54:49 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared.h"
#include "m_parser.h"

int	set_rgb_value(t_color *color, char *str, int i)
{
	if (i == 0)
	{
		color->r = ft_atoi(str);
		return (check_color_value(color->r));
	}
	else if (i == 1)
	{
		color->g = ft_atoi(str);
		return (check_color_value(color->g));
	}
	else if (i == 2)
	{
		color->b = ft_atoi(str);
		return (check_color_value(color->b));
	}
	else
		return (0);
}

int	set_color(t_map *map, t_color *color, int c)
{
	if (c == 1)
	{
		if (map->textures.f)
			return (show_err(4), 0);
		map->textures.f = color;
	}
	else if (c == 2)
	{
		if (map->textures.c)
			return (show_err(4), 0);
		map->textures.c = color;
	}
	return (1);
}

int	init_color(char *str, int c, t_map *map)
{
	char	**ints;
	t_color	*color;

	if (!str)
		return (0);
	ints = ft_split(str, ',');
	if (!ints)
		return (show_err(1), 0);
	if (arr_str_count(ints) != 3)
		return (free_arr(ints), show_err(7), 0);
	color = (t_color *)ft_calloc(sizeof(t_color), 1);
	if (!color)
		return (free_arr(ints), show_err(1), 0);
	if (!check_color_args(ints, color))
		return (free_arr(ints), free(color), 0);
	free_arr(ints);
	if (c == 1 || c == 2)
	{
		if (!set_color(map, color, c))
			return (free(color), show_err(4), 0);
	}
	else
		return (free(color), 0);
	return (1);
}

int	get_rgb(char *str, int *i, int c, t_map *map)
{
	int		len;
	char	*value;
	int		f;

	f = 0;
	if (!str[*i] || (str[*i] != ' ' && str[*i] != '\t'))
		return (show_err(4), 0);
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	len = len_till_sep(&str[*i]);
	if (len == 0)
		return (show_err(4), 0);
	value = ft_calloc(sizeof(char *), len + 1);
	if (!value)
		return (show_err(1), 0);
	while (f < len)
	{
		value[f] = str[*i];
		*i = *i + 1;
		f++;
	}
	if (!init_color(value, c, map))
		return (free(value), 0);
	return (free(value), 1);
}

int	get_colors(char *str, int *i, t_map *map)
{
	int	color;

	color = 0;
	if (!ft_strncmp(&str[*i], "F", 1))
		color = 1;
	else if (!ft_strncmp(&str[*i], "C", 1))
		color = 2;
	else
		return (0);
	*i = *i + 1;
	return (get_rgb(str, i, color, map));
}
