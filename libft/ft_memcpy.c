/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yamennaani6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:43:30 by yalnaani          #+#    #+#             */
/*   Updated: 2024/09/11 10:10:11 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n--)
	{
		*ptr_dest++ = *ptr_src++;
	}
	return (dest);
}

/*#include <string.h>
#define MAX_CHAR 100

int	main(void)
{
	char first_str[MAX_CHAR] = "Hello World!";
	char second_str[MAX_CHAR] = "Welcome to Tutorialspoint";

	printf("The Actual Statements:-\n");
	printf("first_str: %s\n", first_str);
	printf("second_str: %s\n", second_str);

	//copying all bytes of second_str to first_str
	ft_memcpy(first_str, second_str, strlen(second_str));

	printf("After executing the function memcpy()\n");
	printf("first_str: %s\n", first_str);
	printf("second_str: %s\n", second_str);
	return (0);
}*/