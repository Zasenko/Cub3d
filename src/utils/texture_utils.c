/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:02:06 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/28 11:23:48 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

t_texture	load_texture(t_vars *vars, char *path)
{
	t_texture	texture;

	texture.texture = mlx_xpm_file_to_image(vars->mlx, path,
			&texture.dimension.x, &texture.dimension.y);
	if (!texture.texture)
	{
		ft_putstr_fd("Error\nCould not load texture \n", 2);
		return (texture);
	}
	texture.texture_data = mlx_get_data_addr(texture.texture, &texture.bpp,
			&texture.length, &texture.endian);
	return (texture);
}

void	destroy_texture(t_vars *vars, t_texture *tex)
{
	if (tex->texture)
	{
		mlx_destroy_image(vars->mlx, tex->texture);
		tex->texture = NULL;
		tex->texture_data = NULL;
	}
}
