/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yamennaani6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:07:03 by yalnaani          #+#    #+#             */
/*   Updated: 2024/09/06 15:54:42 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (n--)
	{
		*ptr++ = (unsigned char)c;
	}
	return (str);
}

/*

#include <string.h>

int	main(void)
{
	int arr[10];
   ft_memset(arr, 0, sizeof(arr));

   printf("Array after memset(): ");
   for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
   }
   printf("\n");

	return (0);
}*/