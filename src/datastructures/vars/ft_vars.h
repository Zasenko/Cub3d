/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vars.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:52:15 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/22 13:30:43 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VARS_H
# define FT_VARS_H
#include "../../../include/shared.h"
#include "mlx.h"
#include <stdlib.h>

t_vars	*new_vars();
void	delete_vars(t_vars *vars);
#endif