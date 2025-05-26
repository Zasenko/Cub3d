/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:02:06 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/26 19:05:55 by yalnaani         ###   ########.fr       */
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
		printf("Error: Could not load texture %s\n", path);
		exit(1);
	}
	texture.texture_data = mlx_get_data_addr(texture.texture, &texture.bpp,
			&texture.length, &texture.endian);
	return (texture);
}
