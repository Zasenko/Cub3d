/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yamennaani6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:52:57 by yalnaani          #+#    #+#             */
/*   Updated: 2024/09/11 10:10:30 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src = (const unsigned char *)src;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptr_dest = (unsigned char *)dest;
	if (ptr_dest < ptr_src)
	{
		while (n--)
		{
			*ptr_dest++ = *ptr_src++;
		}
	}
	else
	{
		ptr_dest += n;
		ptr_src += n;
		while (n--)
		{
			*(--ptr_dest) = *(--ptr_src);
		}
	}
	return (dest);
}

/*#include <string.h>

int main ()
{
   char dest_str[] = "oldstring";
   const char src_str[]  = "newstring";
   printf("Before memmove dest = %s, src = %s\n", dest_str, src_str);
   ft_memmove(dest_str, src_str, 9);
   printf("After memmove dest = %s, src = %s\n", dest_str, src_str);
   return(0);
}*/