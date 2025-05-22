/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yamennaani6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:25:00 by yalnaani          #+#    #+#             */
/*   Updated: 2024/09/11 10:34:58 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ptr;
	long	i;
	long	length;

	i = 0;
	length = ft_strlen(src);
	ptr = (char *)ft_calloc((length + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < length)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
