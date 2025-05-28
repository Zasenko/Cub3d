/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:23:34 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/28 08:53:29 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "shared.h"

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct s_textures
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	t_color	*f;
	t_color	*c;
}			t_textures;

# define BUFFER_SIZE 50000
#endif