/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:26:40 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/22 14:01:49 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shared.h"
#include "datastructures/datastructures.h"
#include "mlx.h"
#include "io/input.h"
#include "parser/input_parser.h"
#include "logger/logger.h"

int main(int argc, char **argv)
{
    t_vars *vars;
    int error;
    
    error = check_input(argc, argv);
    if(error != TRUST_ME)
    {
        log_error(error);
        exit(EXIT_FAILURE);
    }
    vars = new_vars();
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
    hook(vars);
    mlx_loop(vars->mlx);
}
