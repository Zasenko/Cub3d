/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:26:40 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/22 12:30:35 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shared.h"
#include "datastructures/datastructures.h"
#include "mlx.h"

int main(int argc, char **argv)
{
    t_vars *vars;

    if(argc != 2 && *argv)
    {
        //return(1);
    }
    vars = new_vars();
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
    mlx_loop(vars->mlx);
}