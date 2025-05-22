/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:07:32 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/22 13:32:53 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "m_input.h"

int	key_press(int keycode, t_vars *vars)
{
    if(keycode == ESCAPE_KEY)
		return (exit_program(vars));
    return 0;
}

void hook(t_vars *vars)
{
    mlx_hook(vars->win, 17, 0, exit_program, vars);
    mlx_key_hook(vars->win, key_press, vars);
}
