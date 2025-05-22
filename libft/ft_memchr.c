/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:11:11 by yalnaani          #+#    #+#             */
/*   Updated: 2024/11/21 13:03:06 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr = s;
	size_t				i;
	unsigned char		_c;

	i = 0;
	while (i < n)
	{
		_c = *ptr;
		if (_c == (unsigned char)c)
		{
			return ((void *)ptr);
		}
		ptr++;
		i++;
	}
	return (NULL);
}
