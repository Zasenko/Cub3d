/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:57:31 by yalnaani          #+#    #+#             */
/*   Updated: 2025/01/08 13:27:04 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_index;
	size_t	end_index;

	start_index = 0;
	end_index = ft_strlen(s1) - 1;
	while (s1[start_index] && ft_strchr(set, s1[start_index]) != 0)
		start_index++;
	while (s1[end_index] && ft_strchr(set, s1[end_index]) != 0)
		end_index--;
	if (start_index > end_index)
		return (ft_strdup(""));
	else
		return (ft_substr(s1, start_index, (end_index - start_index + 1)));
}
