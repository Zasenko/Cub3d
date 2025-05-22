/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:18:48 by yalnaani          #+#    #+#             */
/*   Updated: 2025/01/08 13:34:55 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	total_len;
	size_t	i;
	size_t	available_space;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dst_len = ft_strlen(dest);
	total_len = dst_len + src_len;
	if (size <= dst_len)
	{
		return (src_len + size);
	}
	available_space = size - dst_len - 1;
	i = 0;
	while (i < available_space && src[i] != '\0')
	{
		dest[dst_len + i] = src[i];
		i++;
	}
	dest[dst_len + i] = '\0';
	return (total_len);
}
