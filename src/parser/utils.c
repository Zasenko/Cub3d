/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitryzasenko <dmitryzasenko@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:42:32 by dzasenko          #+#    #+#             */
/*   Updated: 2025/05/27 21:53:46 by dmitryzasen      ###   ########.fr       */
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
//
int len_till_sep(char *str)
{
	int i;

	i = 0;
	if(!str)
		return (0);
	while(str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		i++;
	return (i);
}
