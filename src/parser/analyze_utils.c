/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:18:01 by dzasenko          #+#    #+#             */
/*   Updated: 2025/05/28 14:18:06 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared.h"
#include "m_parser.h"

int	skip_empty_lines(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n')
		{
			(*i)++;
			continue ;
		}
		else
		{
			while (str[*i] && str[*i] != '\n')
				(*i)--;
			break ;
		}
	}
	if (!str[*i])
		return (0);
	return (1);
}

int	is_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (!str[i] || str[i] == '\n')
		return (1);
	return (0);
}

int	check_map_empty_lines(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
	{
		if (str[i] == '\n')
		{
			i++;
			if (i == len || !str[i] || str[i] == '\n')
				return (show_err(5), 0);
			else if (is_empty_line(&str[i]))
				return (show_err(5), 0);
		}
		i++;
	}
	return (1);
}

int	check_wrong_char(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (is_empty_line(arr[i]))
		{
			free_str(&arr[i]);
			i++;
			continue ;
		}
		if (!check_map_chars(arr[i], " 10NSEW\n"))
			return (show_err(6), 0);
		i++;
	}
	return (1);
}
