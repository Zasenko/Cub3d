/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:13:31 by yalnaani          #+#    #+#             */
/*   Updated: 2024/11/21 13:02:56 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (nitems == 0 || size == 0)
		return (malloc(0));
	if (nitems > (size_t)-1 / size)
		return (NULL);
	ptr = malloc((nitems) * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}
