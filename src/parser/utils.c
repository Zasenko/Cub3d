/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:42:32 by dzasenko          #+#    #+#             */
/*   Updated: 2025/05/23 14:42:33 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared.h"
#include "m_parser.h"

void	free_str(char **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		free(arr);
	}
}

void	free_map(t_map *map)
{
	if (!map)
		return;
	if (map->map)
		free_arr(map->map);
	if (map->textures.no_path)
		free_str(&map->textures.no_path);
	if (map->textures.so_path)
		free_str(&map->textures.so_path);
	if (map->textures.we_path)
		free_str(&map->textures.we_path);
	if (map->textures.ea_path)
		free_str(&map->textures.ea_path);
	if (map->textures.f)
		free(map->textures.f);
	if (map->textures.c)
		free(map->textures.c);
	free(map);
}

int	arr_str_count(char **str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while(str[i])
		i++;
	return (i);
}
