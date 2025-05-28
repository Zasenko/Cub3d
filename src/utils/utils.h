/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:28:57 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/28 09:34:21 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../datastructures/datastructures.h"

void		render_buffer(t_vars *vars);

void		init_program(t_vars *vars, t_map *map);

int			exit_program(t_vars *vars);

void		clear_buffer(t_vars *vars);

void		put_my_pixel(t_vars *vars, int x, int y, int color);

int			rgb_to_color(int r, int g, int b);

t_texture	load_texture(t_vars *vars, char *path);

void		spawn_at_index(t_vars *data, int spawn_x, int spawn_y);

void		set_facing_direction(t_vars *data, t_direction dir);

t_texture	load_texture(t_vars *vars, char *path);

void		destroy_texture(t_vars *vars, t_texture *tex);

void		check_resolution(void);

#endif
