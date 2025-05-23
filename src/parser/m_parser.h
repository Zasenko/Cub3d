/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_parser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:38:30 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/22 14:02:19 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_PARSER_H
#define M_PARSER_H

# include "../../include/shared.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char    *read_from_file(char *file_name);
void    free_str(char **s);
void	free_arr(char **arr);
int     ft_strstr(char *str, char *to_find);
int	ft_strcmp(char *s1, char *s2);
char    **analyze(char *str, t_map *map);
int     arr_str_count(char **str);
int     compare_args(char	**args, t_map *map);
#endif