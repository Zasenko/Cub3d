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

#include "../../../include/shared.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

#include "m_parser.h"

static char   *read_from_file(char *file_name);
static int	check_file_name(char *file_name);
static char	*read_file(int fd);
char **analyze(char *str, t_map *map);
t_map *init_map(void);

void free_str(char **buf)
{

}

int	allocate_buf_str(char **buf, char **str)
{
	if (!buf || !str)
		return (0);
	*buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (*buf == NULL)
		return (0);
	*str = (char *)malloc(sizeof(char));
	if (*str == NULL)
		return (free_str(buf), 0);
	(*str)[0] = '\0';
	return (1);
}

int check_input(int argc, char **argv)
{
	int		fd;
	char	*str;
	t_map *map;

	if (argc != 2)
		return (ft_putstr_fd("Error: Not a valid args count\n", 2), NULL);
	str = read_from_file(argv[1]);//malloc
	if (!str)
		return(NULL);
	map = init_map();//malloc
	if (!map)
	{
		free(str);
		return(NULL);
	}
	map->map = analyze(str, map);
	free(str);
	if (!map->map)
	{
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
	map->textures.no = NULL;
	map->textures.so = NULL;
	map->textures.we = NULL;
	map->textures.ea = NULL;
	map->textures.f = NULL;
	map->textures.c = NULL;
	return (map);
}

int compare_args(char *str)
{
		if (ft_strnstr("NO", str, 2))
		{
			//text
        }
        else if(ft_strnstr("SO", str, 2))
        {
			//text
        }
        else if(ft_strnstr("WE", str, 2))
        {
			//text
        }
        else if(ft_strnstr("EA", str, 2))
        {
			//text
        }
        else if(ft_strnstr("F", str, 2))
        {
			//color
        }
        else if(ft_strnstr("C", str, 2))
        {
			//color
        }
		else
		{
			//error
		}
}

int is_textures_set(t_map *map)
{
	t_textures textures;

	textures = map->textures;
	if (textures.no && textures.so && textures.we && textures.ea
		&& textures.f && textures.c)
	{
		printf("Textures not full fill\n");// todo: delete line
		return (0);
	}
	return (1);
}

int	analyze_line(char *str, t_map *map)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(ft_isprint(str[i]))
		{
			char *trimmed = ft_strtrim(str[0], " \t");//malloc
			if (!trimmed)
			{
				//error
				return -1;
			}

			char	**arr = ft_split(trimmed, ' \t');//malloc
			free(trimmed);
			if (!arr)
			{
				//error
				return -1;
			}

			// if arg == 2: good/bad
			//	int compare_args(char *str);
			//arg[0] compare
			//-- arg[1] path;
			//-- arg[1] color
			return (1);
		}
		i++;
	}
	return (0);
}

char **analyze(char *str, t_map *map)
{
	char	**arr;
	char	**map_arr;

	map_arr = NULL;
	arr = ft_split(str, '\n');//malloc
	if (!arr)
		return (NULL);

	int i = 0;
	while (arr[i])
	{
		if(is_textures_set(map) == 0)
			if(!analyze_line(arr[i++], map))
				continue;
		else
		{
			//make map from arr[i]!
			// free arr
			return(map_arr);
		}
	}
	// free arr
	return(map_arr);
}

int	check_file_name(char *file_name)
{
	size_t	len;

	if (!file_name)
		return (0);
	len = ft_strlen(file_name);
	if (len < 4)
	{
		ft_putstr_fd("Error: incorrect file name (expected fileName.cub)\n", 2);
		return (0);
	}
	if (ft_strstr(&file_name[len - 4], ".cub", 4) != 0)
	{
		ft_putstr_fd("Error: invalid file extension (expected .cub)\n", 2);
		return (0);
	}
	return (1);
}

char	*read_file(int fd)
{
	char	*str;
	char	*buf;
	char	*temp;
	int		buf_count;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!allocate_buf_str(&buf, &str))
		return (NULL);
	buf_count = read(fd, buf, sizeof(char) * BUFFER_SIZE);
	while (buf_count > 0)
	{
		buf[buf_count] = '\0';
		temp = ft_strjoin(str, buf);
		if (!temp)
			return (free_str(&buf), free_str(&str), NULL);
		free_str(&str);
		str = temp;
		buf_count = read(fd, buf, sizeof(char) * BUFFER_SIZE);
	}
	if (buf_count < 0)
		return (free_str(&buf), free_str(&str), NULL);
	return (free_str(&buf), str);
}

char   *read_from_file(char *file_name)
{
	int		fd;
	char	*str;

	if (!check_file_name(file_name))
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: Can't open the file.\n", 2);
		return (NULL);
	}
	str = read_file(fd);//malloc
	close(fd);
	if (!str)
		return (NULL);
	return (str);
}
