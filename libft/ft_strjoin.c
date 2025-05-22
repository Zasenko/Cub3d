/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yamennaani6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:19:14 by yalnaani          #+#    #+#             */
/*   Updated: 2024/09/11 10:42:44 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*ptr;
	size_t	i;

	size = ft_strlen(s2) + ft_strlen(s1);
	ptr = (char *)ft_calloc(size + 1, 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	while (i < size)
	{
		ptr[i] = s2[i - (ft_strlen(s1))];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

/*int main()
{
	char s1[] = "Hello";
	char s2[] = "World";
	printf("%s",ft_strjoin(s1,s2));
	return (0);
}*/