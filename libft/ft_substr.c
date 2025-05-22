/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:32:02 by yalnaani          #+#    #+#             */
/*   Updated: 2024/11/21 13:03:35 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;
	size_t	l;

	i = start;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while ((i < ((len) + (size_t)start)) && s[i] != '\0')
		i++;
	ptr = (char *)ft_calloc((i - start) + 1, 1);
	l = i - start;
	i = 0;
	if (!ptr)
		return (NULL);
	while (i < l)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
