/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:55:22 by dzasenko          #+#    #+#             */
/*   Updated: 2025/05/28 12:55:25 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared.h"
#include "m_parser.h"

int	set_sn(int texture, t_map *map, char *value)
{
	if (texture == 1)
	{
		if (map->textures.no_path != NULL)
			return (free(value), show_err(4), 0);
		map->textures.no_path = value;
	}
	else if (texture == 2)
	{
		if (map->textures.so_path != NULL)
			return (free(value), show_err(4), 0);
		map->textures.so_path = value;
	}
	return (1);
}

int	set_textures(int texture, char *value, t_map *map)
{
	if (texture == 1 || texture == 2)
	{
		if (!set_sn(texture, map, value))
			return (free(value), show_err(4), 0);
	}
	else if (texture == 3)
	{
		if (map->textures.we_path != NULL)
			return (free(value), show_err(4), 0);
		map->textures.we_path = value;
	}
	else if (texture == 4)
	{
		if (map->textures.ea_path != NULL)
			return (free(value), show_err(4), 0);
		map->textures.ea_path = value;
	}
	else
		return (free(value), 0);
	return (1);
}

int	get_texture_path(int texture, char *str, int *i, t_map *map)
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
	return (set_textures(texture, value, map));
}

int	get_textures(char *str, int *i, t_map *map)
{
	int	texture;

	texture = 0;
	if (!ft_strncmp(&str[*i], "NO", 2))
		texture = 1;
	else if (!ft_strncmp(&str[*i], "SO", 2))
		texture = 2;
	else if (!ft_strncmp(&str[*i], "WE", 2))
		texture = 3;
	else if (!ft_strncmp(&str[*i], "EA", 2))
		texture = 4;
	else
		return (0);
	*i = *i + 2;
	return (get_texture_path(texture, str, i, map));
}
