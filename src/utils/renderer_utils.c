/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:34:24 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/22 13:36:04 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	render_buffer(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
