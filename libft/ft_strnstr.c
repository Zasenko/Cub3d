/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:31:46 by yalnaani          #+#    #+#             */
/*   Updated: 2024/11/21 13:03:22 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *)big);
	if (*big == '\0')
		return (NULL);
	while (i < len)
	{
		if (big[i] == little[j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		if (little[j] == '\0')
			return ((char *)&big[i - j + 1]);
		i++;
	}
	return (NULL);
}
