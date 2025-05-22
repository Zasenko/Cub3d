/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:36:37 by yalnaani          #+#    #+#             */
/*   Updated: 2024/09/14 11:40:11 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	ft_div_mod(long a, long b, long *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

void	ft_putnbr_base(int nbr, char *base, int fd)
{
	int		base_result[100];
	int		i;
	long	l;

	l = nbr;
	i = 0;
	if (check_base(base) == 0)
		return ;
	if (nbr == 0)
		i++;
	base_result[0] = 0;
	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		l = -l;
	}
	while (l)
	{
		ft_div_mod(l, ft_strlen(base), &l, &base_result[i]);
		i++;
	}
	while (i > 0)
		ft_putchar_fd(base[base_result[--i]], fd);
}
/*
int	main(void)
{
	char	base[] = "0123456789abcdef";
	int		nbr;

	nbr = 10;
	ft_putnbr_base(nbr, base, 1);
	return (0);
} */
