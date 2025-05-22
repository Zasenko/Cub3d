/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yamennaani6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:25:00 by yalnaani          #+#    #+#             */
/*   Updated: 2024/09/07 11:12:39 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	l = n;
	if (l < 0)
	{
		l = -l;
		ft_putchar_fd('-', fd);
	}
	if (l > 9)
	{
		ft_putnbr_fd(l / 10, fd);
		l = l % 10;
	}
	if (l <= 9)
	{
		ft_putchar_fd(l + 48, fd);
	}
}
/*int main()
{
	int nb = -2147483648;
	ft_putnbr_fd(nb, 4);
	return (0);
}*/