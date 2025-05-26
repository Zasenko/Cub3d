/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:28:57 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/25 14:01:16 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../datastructures/datastructures.h"

void	render_buffer(t_vars *vars);
int		exit_program(t_vars *vars);
void	draw_square(int x_pos, int y_pos, int size, int color, t_vars *vars);
void	clear_buffer(t_vars *vars);
void	put_my_pixel(t_vars *vars, int x, int y, int color);
int		rgb_to_color(int r, int g, int b);
#endif