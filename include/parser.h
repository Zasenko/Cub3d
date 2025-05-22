/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:23:34 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/22 13:23:47 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

typedef struct s_color
{
	int r;
	int g;
	int b;
}	t_color;

typedef struct s_textures
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	t_color	*f;
	t_color	*c;
}	t_textures;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char	**map;
	t_textures	textures;
	int	start[2];
}	t_map;

#endif