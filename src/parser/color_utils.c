/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:23:10 by dzasenko          #+#    #+#             */
/*   Updated: 2025/05/28 14:57:34 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared.h"
#include "m_parser.h"

int	check_color_value(int arg)
{
	if (arg >= 0 && arg <= 255)
		return (1);
	return (ft_putstr_fd("Error\nWrong color argument\n", 2), 0);
}

int	check_all_digits(char *str)
{
	int	i;

	if (!str)
		return (show_err(0), 0);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (show_err(7), 0);
		i++;
	}
	return (1);
}

int	check_color_args(char **ints, t_color *color)
{
	int	i;

	i = 0;
	while (ints[i])
	{
		if (ft_strlen(ints[i]) < 1 || ft_strlen(ints[i]) > 3)
			return (show_err(7), 0);
		if (!check_all_digits(ints[i]))
			return (0);
		if (!set_rgb_value(color, ints[i], i))
			return (0);
		if (i == 2)
			return (1);
		i++;
	}
	return (0);
}

int	clean_color_rgb_args(char	**ints)
{
	int		i;
	char	*trimmed;

	i = 0;
	while (ints[i])
	{
		trimmed = ft_strtrim(ints[i], " \t");
		if (!trimmed)
			return (show_err(2), 0);
		free(ints[i]);
		ints[i] = trimmed;
		i++;
	}
	return (1);
}
