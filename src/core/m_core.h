/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_core.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:46:58 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/26 18:00:35 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_CORE_H
# define M_CORE_H

# include "../../include/shared.h"
# include "../utils/utils.h"
# include "mlx.h"
# include <math.h>

void	render_walls(t_vars *data);

int		get_wall_direction(double ray_dir_x, double ray_dir_y, int side);

void	init_ray(t_ray_info *ray, t_player player, int x);

void	calc_ray_step(t_ray_info *ray, t_player player);

void	perform_dda(t_ray_info *ray, t_vars *vars);
#endif