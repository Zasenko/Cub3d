/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:38:16 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/26 13:47:18 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared.h"
#include "m_parser.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (ft_putstr_fd("Error: malloc\n", 2), NULL);
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

int len_till_sep(char *str)
{
	int i;

	i = 0;
	if(!str)
		return (0);
	while(str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	return (i);
}

void set_textures(int texture, char *arg, t_map *map)
{
	if(texture == 1)
		map->textures.no_path = arg;
	else if(texture == 2)
		map->textures.so_path = arg;
	else if(texture == 3)
		map->textures.we_path = arg;
	else if(texture == 4)
		map->textures.ea_path = arg;
}

int get_texture_path(int texture, char *str, int *i, t_map *map)
{
	int		len;
	char	*value;
	int f;

	if = 0;
	if (str[*i] != ' ' || str[*i] != '\t')
		return (ft_putstr_fd("Error\n Invalid arguments in file\n", 2), 0);
	while (str[*i] == ' ' || str[*i] == '\t')
		*i++;
	len = len_till_sep(str[*i]);
	if (len < 1)
		return (ft_putstr_fd("Error\n Invalid arguments in file\n", 2) ,0);
	value = calloc(sizeof(char *), len + 1);
	if (!value)
		return (ft_putstr_fd("Error\nMalloc\n", 2), 0);
	while(f < len)
	{
		value[f] = str[*i];
		*i = *i + 1;
		f++;
	}
	map->textures.
}

int get_textures(char *str, int *i, t_map *map)
{
	int texture;

	texture = 0;
	if (!ft_strncmp(str[*i], "NO", 2))
		texture = 1;
    else if(!ft_strncmp(str[*i], "SO", 2))
		texture = 2;
    else if(!ft_strncmp(str[*i], "WE", 2))
		texture = 3;
    else if(!ft_strncmp(str[*i], "EA", 2))
		texture = 4;
	*i = *i + 2;
	return (get_texture_path(texture, str, i, map));
}

int get_colors(char **str, int *i, t_map *map)
{

}

int compare_args(char *str, int *i, t_map *map)
{


	if(!ft_strcmp(str[*i], "NO") || !ft_strcmp(str[*i], "SO")
		|| !ft_strcmp(str[*i], "WE") || !ft_strcmp(str[*i], "EA"))
		return (get_textures(str, i, map));
	else if(!ft_strcmp(str[*i], "F") || !ft_strcmp(str[*i], "C"))
		return (get_textures(str, i, map));
	else
	{
		ft_putstr_fd("Error\n Invalid arguments in file\n", 2);
		return (0);
	}
}

void get_args(char *str, t_map *map)
{
	int i;
	// int len;
	int res = 0;

	i = 0;
	while(str[i])
	{
		if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		
		
		
		res = compare_args(str, &i, map);
		if (!res)
		{

		}
		else
		{
			
		}
		
		i++;
	}

}

t_map *check_input(int argc, char **argv)
{
	char	*str;
	t_map *map;

	if (argc != 2)
		return (ft_putstr_fd("Error: Not a valid args count\n", 2), NULL);
	str = read_from_file(argv[1]);
	if (!str)
		return(NULL);
	map = init_map();
	if (!map)
		return(free(str), NULL);




	map->map = analyze(str, map);
	free(str);
	if (!map->map)
	{
		free_map(map);
		return(NULL);
	}
	if(!check_map(map))
		return(free_map(map), NULL);
	return map;
}

// int set_texture_path(char **path, const char *str)
// {
// 	if(!path || *path != NULL || !str)
// 		return (ft_putstr_fd("Error\n", 2), 0);
// 	*path = ft_strdup(str);
// 	if (!*path)
// 		return (ft_putstr_fd("Error: malloc\n", 2), 0);
// 	return (1);
// }

int check_color_value(int arg)
{
    if (arg >= 0 && arg <= 255)
		return (1);
	return (0);
}

int	check_all_digits(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr_fd("Error\n", 2), 0);
	i = 0;
	while(str[i])
	{
		if(!ft_isdigit(str[i]))
			return (ft_putstr_fd("Error: wrong color arg\n", 2), 0);
		i++;
	}
	return (1);
}

int set_color_value(t_color *color, char *str, int i)
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

int check_color_args(char **ints, t_color *color)
{
	int i;

	i = 0;
	while(ints[i])
	{
		if (ft_strlen(ints[i]) < 1 || ft_strlen(ints[i]) > 3)
			return (ft_putstr_fd("Error: wrong color arg\n", 2), 0);
		if (!check_all_digits(ints[i]))
			return (0);
		if (!set_color_value(color, ints[i], i))
			return (0);
		if (i == 2)
			return (1);
		i++;
	}
	return (0);
}

int set_colore(t_color **path, char *str)
{
	char **ints;
	t_color	*color;

	if (!path || *path != NULL || !str)
		return (0);
	ints = ft_split(str, ',');
	if (!ints)
		return (ft_putstr_fd("Error: malloc\n", 2), 0);
	if (arr_str_count(ints) != 3)
		return (free_arr(ints), ft_putstr_fd("Error: wrong color arg\n", 2), 0);
	color = (t_color *)ft_calloc(sizeof(t_color), 1);
	if (!color)
		return (free_arr(ints), ft_putstr_fd("Error: malloc\n", 2), 0);

	if(!check_color_args(ints, color))
		return (free_arr(ints), free(color), 0);
	free_arr(ints);
	*path = color;
	return (1);
}

// int compare_args(char	**args, t_map *map)
// {
// 		if (!ft_strcmp(args[0], "NO"))
// 		{
// 			if (!set_texture_path(&map->textures.no_path, args[1]))
// 				return (0);
//         }
//         else if(!ft_strcmp(args[0], "SO"))
//         {
// 			if (!set_texture_path(&map->textures.so_path, args[1]))
// 				return (0);
//         }
//         else if(!ft_strcmp(args[0], "WE"))
//         {
// 			if (!set_texture_path(&map->textures.we_path, args[1]))
// 				return (0);
//         }
//         else if(!ft_strcmp(args[0], "EA"))
//         {
// 			if (!set_texture_path(&map->textures.ea_path, args[1]))
// 				return (0);
//         }
//         else if(!ft_strcmp(args[0], "F"))
//         {
// 			if (!set_colore(&map->textures.f, args[1]))
// 				return (0);
//         }
//         else if(!ft_strcmp(args[0], "C"))
//         {
// 			if (!set_colore(&map->textures.c, args[1]))
// 				return (0);
//         }
// 		else
// 		{
// 			printf("error: invalid argument in file\n");
// 			return (0);
// 		}
// 		return (1);
// }

