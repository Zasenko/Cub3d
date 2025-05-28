#include "../../include/shared.h"
#include "m_parser.h"

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
			return (ft_putstr_fd("Error\nWrong color arg\n", 2), 0);
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
			return (ft_putstr_fd("Error\nWrong color arg\n", 2), 0);
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

int	init_color(char *str, int c, t_map *map)
{
	char	**ints;
	t_color	*color;

	if (!str)
		return (0);
	ints = ft_split(str, ',');
	if (!ints)
		return (ft_putstr_fd("Error\nMalloc\n", 2), 0);
	if (arr_str_count(ints) != 3)
		return (free_arr(ints), ft_putstr_fd("Error\nWrong color arg\n", 2), 0);
	color = (t_color *)ft_calloc(sizeof(t_color), 1);
	if (!color)
		return (free_arr(ints), ft_putstr_fd("Error\nMalloc\n", 2), 0);
	if(!check_color_args(ints, color))
		return (free_arr(ints), free(color), 0);
	free_arr(ints);
	if(c == 1)
	{
		if (map->textures.f)
		{
			free(color);
			return (0);
		}
		map->textures.f = color;
	}	
	else if(c == 2)
	{
		if(map->textures.c)
		{
			free(color);
			return (0);
		}
		map->textures.c = color;
	}
	else
		return (free(color), 0);
	return (1);
}

int get_rgb(char *str, int *i, int c, t_map *map)
{
	int		len;
	char	*value;
	int f;

	f = 0;
	if (!str[*i] || (str[*i] != ' ' && str[*i] != '\t'))
		return (ft_putstr_fd("Error\nInvalid arguments in file\n", 2), 0);
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	len = len_till_sep(&str[*i]);
	if (len == 0)
		return (ft_putstr_fd("Error\nInvalid arguments in file\n", 2) ,0);
	value = calloc(sizeof(char *), len + 1);
	if (!value)
		return (ft_putstr_fd("Error\nMalloc\n", 2), 0);
	while(f < len)
	{
		value[f] = str[*i];
		*i = *i + 1;
		f++;
	}
	if(!init_color(value, c, map))
		return (free(value), 0);
	return (free(value), 1);
}

int	get_colors(char *str, int *i, t_map *map)
{
	int	color;

	color = 0;
	if (!ft_strncmp(&str[*i], "F", 1))
		color = 1;
	else if(!ft_strncmp(&str[*i], "C", 1))
		color = 2;
	else
		return (0);
	*i = *i + 1;
	return (get_rgb(str, i, color, map));
}
