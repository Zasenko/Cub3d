/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:52:19 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/25 15:59:16 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vars.h"

void	delete_vars(t_vars *vars)
{
	if (vars->mlx != NULL)
	{
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		if (vars->img)
			mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		vars->mlx = NULL;
	}
	free(vars);
}

static int	init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (-1);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, TITLE);
	if (!vars->win)
		return (-1);
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img)
		return (-1);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	if (!vars->addr)
		return (-1);
	return (0);
}

t_vars	*new_vars()
{
	t_vars	*ptr;

	ptr = ft_calloc(sizeof(t_vars), 1);
	if (!ptr)
		return (NULL);
	ptr->win = NULL;
	ptr->mlx = NULL;
	ptr->img = NULL;
	ptr->addr = NULL;
	ptr->player = NULL;
	if (init_mlx(ptr) == -1)
	{
		delete_vars(ptr);
		ft_putstr_fd("ERROR FILE NOT VAILD\n", 2);
		exit(EXIT_FAILURE);
		return (NULL);
	}
	return (ptr);
}