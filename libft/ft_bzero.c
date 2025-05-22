/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yamennaani6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:22:38 by yalnaani          #+#    #+#             */
/*   Updated: 2024/09/08 15:18:14 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (n--)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
#include <string.h>
#include <strings.h>

int	main(void)
{
	char str[] = "Hi there";
   bzero(str,strlen(str));
   printf("%lu",strlen(str));
	puts(str);
	return (0);
}*/