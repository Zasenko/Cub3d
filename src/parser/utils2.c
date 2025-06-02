/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:25:33 by dzasenko          #+#    #+#             */
/*   Updated: 2025/05/28 14:25:34 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared.h"
#include "m_parser.h"

int	check_char(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	len_till_sep(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		i++;
	return (i);
}

int	len_till_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || str[i] != '\n')
		return (0);
	return (i);
}

int	check_map_chars(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!check_char(str[i], set))
			return (0);
		i++;
	}
	return (1);
}
