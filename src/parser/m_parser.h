/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_parser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitryzasenko <dmitryzasenko@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:38:30 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/27 21:59:16 by dmitryzasen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_PARSER_H
# define M_PARSER_H

# include "../../include/shared.h"
# include <fcntl.h>

char	*read_from_file(char *file_name);
void	free_str(char **s);
void	free_arr(char **arr);
int		arr_str_count(char **str);
void	free_map(t_map *map);
int		ft_strcmp(char *s1, char *s2);
int		check_map(t_map *map);
int		check_char(char c, char *set);
int		get_textures(char *str, int *i, t_map *map);
int		check_map_chars(char *str, char *set);
int		get_args(char *str, t_map *map);
int		len_till_sep(char *str);
int		get_colors(char *str, int *i, t_map *map);
void	show_err(int error);
int		skip_empty_lines(char *str, int *i);
int		check_wrong_char(char **arr);
int		check_map_empty_lines(char *str, int len);
int		check_color_args(char **ints, t_color *color);
int		check_color_value(int arg);
int		set_rgb_value(t_color *color, char *str, int i);
int		len_till_nl(char *str);
int		clean_color_rgb_args(char **ints);

#endif