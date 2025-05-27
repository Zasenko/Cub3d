/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vars.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:52:15 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/27 09:16:51 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VARS_H
# define FT_VARS_H
# include "../../../include/shared.h"
# include "../parser/input_parser.h"
# include "../utils/utils.h"
# include "mlx.h"

t_vars	*new_vars(void);
void	delete_vars(t_vars *vars);
#endif