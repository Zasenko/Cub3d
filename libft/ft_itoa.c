/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:34:26 by yalnaani          #+#    #+#             */
/*   Updated: 2024/11/19 17:51:56 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getdigitcounts(int num)
{
	int	digits_count;

	digits_count = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		digits_count++;
		num /= 10;
	}
	return (digits_count);
}

char	*ft_itoa(int n)
{
	int		digits;
	int		i;
	long	l;
	char	*ptr;

	digits = getdigitcounts(n);
	l = n;
	if (n < 0)
	{
		digits += 1;
		l = -l;
	}
	i = digits - 1;
	ptr = ft_calloc(digits + 1, 1);
	if (!ptr)
		return (NULL);
	ptr[digits] = '\0';
	while (digits--)
	{
		ptr[i--] = ((l % 10) + 48);
		l /= 10;
	}
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}
