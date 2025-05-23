/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:38:16 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/22 14:53:44 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared.h"
#include "m_parser.h"

char **analyze(char *str, t_map *map);
t_map *init_map(void);

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

void free_map(t_map *map)
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

int arr_str_count(char **str)
{
	int i;

	i = 0;
	if (!str || !*str)
		return 0;
	while(str[i])
		i++;
	return (i);
}


t_map *check_input(int argc, char **argv)
{
	char	*str;
	t_map *map;

	if (argc != 2)
		return (ft_putstr_fd("Error: Not a valid args count\n", 2), NULL);
	str = read_from_file(argv[1]);//malloc
	if (!str)
		return(NULL);
	map = init_map();//malloc
	if (!map)
		return(free(str), NULL);
	map->map = analyze(str, map);
	free(str);
	if (!map->map)
	{
		free_map(map);
		return(NULL);
	}
	return map;
}

t_map *init_map(void)
{
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return NULL;
	map->map = NULL;
	map->textures.no_path = NULL;
	map->textures.so_path = NULL;
	map->textures.we_path = NULL;
	map->textures.ea_path = NULL;
	map->textures.f = NULL;
	map->textures.c = NULL;
	return (map);
}

int add_texture_path(char **path, char *arg)
{
	char *str;

	if (!path || !*path | !arg)
		return (0);
	str = ft_strdup(arg);
	if (!str)
		return (0);
	*path = str;
	return (1);
}


int set_texture_path(char **ptr, const char *str)
{
	if(!ptr || *ptr != NULL || !str)
		return (0);
	*ptr = ft_strdup(str);
	if (!*ptr)
		return (ft_putstr_fd("Error: malloc\n", 2), 0);
	return (1);
}

int compare_args(char	**args, t_map *map)
{
		if (!ft_strcmp(args[0], "NO"))
		{
			if (!set_texture_path(&map->textures.no_path, args[1]))
				return (0);
        }
        else if(!ft_strcmp(args[0], "SO"))
        {
			if (!set_texture_path(&map->textures.so_path, args[1]))
				return (0);
        }
        else if(!ft_strcmp(args[0], "WE"))
        {
			if (!set_texture_path(&map->textures.we_path, args[1]))
				return (0);
        }
        else if(!ft_strcmp(args[0], "EA"))
        {
			if (!set_texture_path(&map->textures.ea_path, args[1]))
				return (0);
        }
        else if(!ft_strcmp(args[0], "F"))
        {
			char **ints;

			if (map->textures.f != NULL)
				return (0);
			ints = ft_split(args[1], ','); //malloc
			if (!ints)
				return (0);

			if (arr_str_count(ints) != 3)
			{
				free_arr(ints);
				return (0);
			}

			t_color	*color = (t_color *)ft_calloc(sizeof(t_color), 1); //malloc
			if (!color)
			{
				free_arr(ints);
				return (0);
			}

			int i = 0;
			while(ints[i] && i < 3)
			{
				if (ft_strlen(ints[i]) < 0 || ft_strlen(ints[i]) > 3)
				{
					free_arr(ints);
					free(color);
					return (0);
				}
				int f = 0;
				while(ints[i][f])
				{
					if(!ft_isdigit(ints[i][f]))
					{
						free_arr(ints);
						free(color);
						return (0);
					}
					f++;
				}

				if (i == 0)
				{
					color->r = ft_atoi(ints[i]);
					if (color->r < 0 || color->r > 255)
					{
						free_arr(ints);
						free(color);
						return (0);
					}
				}
				else if (i == 1)
				{
					color->g = ft_atoi(ints[i]);
					if (color->g < 0 || color->g > 255)
					{
						free_arr(ints);
						free(color);
						return (0);
					}
				}
				else if (1 == 2)
				{
					color->b = ft_atoi(ints[i]);
					if (color->b < 0 || color->b > 255)
					{
						free_arr(ints);
						free(color);
						return (0);
					}
				}

				i++;
			}
			free_arr(ints);
			map->textures.f = color;
        }
        else if(!ft_strcmp(args[0], "C"))
        {
			char **ints;

			if (map->textures.c != NULL)
				return (0);
			ints = ft_split(args[1], ','); //malloc
			if (!ints)
				return (0);
			if (arr_str_count(ints) != 3)
			{
				free_arr(ints);
				return (0);
			}
			t_color	*color = (t_color *)ft_calloc(sizeof(t_color), 1); //malloc
			if (!color)
			{
				free_arr(ints);
				return (0);
			}
			int i = 0;
			while(ints[i] && i < 3)
			{
				if (ft_strlen(ints[i]) < 0 || ft_strlen(ints[i]) > 3)
				{
					free_arr(ints);
					free(color);
					return (0);
				}
				int f = 0;
				while(ints[i][f])
				{
					if(!ft_isdigit(ints[i][f]))
					{
						free_arr(ints);
						free(color);
						return (0);
					}
					f++;
				}

				if (i == 0)
				{
					color->r = ft_atoi(ints[i]);
					if (color->r < 0 || color->r > 255)
					{
						free_arr(ints);
						free(color);
						return (0);
					}
				}
				else if (i == 1)
				{
					color->g = ft_atoi(ints[i]);
					if (color->g < 0 || color->g > 255)
					{
						free_arr(ints);
						free(color);
						return (0);
					}
				}
				else if (1 == 2)
				{
					color->b = ft_atoi(ints[i]);
					if (color->b < 0 || color->b > 255)
					{
						free_arr(ints);
						free(color);
						return (0);
					}
				}

				i++;
			}
			free_arr(ints);
			map->textures.c = color;
        }
		else
		{
			printf("error: invalid argument in file\n");
			return (0);
		}
		return (1);
}

