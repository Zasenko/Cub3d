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

//
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
//
int skip_empty_lines(char *str, int *i)
{
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'))
		*i++;
	if (!str[*i])
		return (0);
	return (1);
}
//
int	is_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' '))
		i++;
	if (!str[i] || str[i] == '\n')
		return (1);
	return (0);
}
//
int	get_map(char *str, t_map *map)
{
	char	**arr;
	int		len;
	int		i;

	if(!str || !map)
		return (0);
	if(!check_map_chars(str, " 10NSEW\n"))
        return (ft_putstr_fd("Error\nWrong simbol on map\n", 2), 0);
	len = ft_strlen(str);
	while(len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t' || str[len - 1] == '\n'))
		len--;
	if (len == 0)
		return (ft_putstr_fd("Error\nNo map in file\n", 2), 0);
	while(str[len] && str[len] != '\n')
		len++;
	i = 0;
	while (str[i] && i < len)
	{
		if(str[i] == '\n')
		{
			i++;
			if(i == len || !str[i] || str[i] == '\n')
				return (ft_putstr_fd("Error\nInvalid map\n", 2), 0);
			else if(is_empty_line(str[i]))
				return (ft_putstr_fd("Error\nInvalid map\n", 2), 0);
		}
		i++;
	}
	arr = ft_split(str, '\n');
	if(!arr)
		return (ft_putstr_fd("Error\nMalloc\n", 2), 0);
	i = 0;
	while(arr[i])
	{
		if(is_empty_line(arr[i]))
			free_str(&arr[i]);
		i++;
	}
	map->map = arr;
	return (1);
}
//
int compare_keys(char *str, int *i, t_map *map)
{
	if(!ft_strcmp(str[*i], "NO") || !ft_strcmp(str[*i], "SO")
		|| !ft_strcmp(str[*i], "WE") || !ft_strcmp(str[*i], "EA"))
		return (get_textures(str, i, map));
	else if(!ft_strcmp(str[*i], "F") || !ft_strcmp(str[*i], "C"))
		return (get_colors(str, i, map));
	else
	{
		ft_putstr_fd("Error\n Invalid arguments in file\n", 2);
		return (0);
	}
}
//
int get_args(char *str, t_map *map)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (is_textures_set(map))
			break ;
		if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			i++;
			continue ;
		}
		if (!compare_keys(str, &i, map))
			return (0);
		while(str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if(!str[i] || str[i] != '\n')
				return (ft_putstr_fd("Error\nInvalid arguments in file\n", 2), 0);
		i++;
	}
	if(!skip_empty_lines(str, &i))
		return (ft_putstr_fd("Error\nNo map in file\n", 2), 0);

	printf("map string:\n[%s]\n", str[i]);// TODO! DELETE
	
	if(!get_map(str[i], map))
		return (0);
}
