/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:49:19 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/27 09:04:13 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "../libft/libft.h"
# include "conf.h"
# include "err.h"
# include "raycast.h"
# include "parser.h"

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_player		*player;
	t_map			*map_s;
	t_vector2_int	map_dimesnion;
	t_texture		textures[4];
}					t_vars;

#endif