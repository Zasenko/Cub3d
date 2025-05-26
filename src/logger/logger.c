/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:56:25 by yalnaani          #+#    #+#             */
/*   Updated: 2025/05/26 18:43:06 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger.h"

char	*get_error_msg(int code)
{
	if (code == MALLOC_ERROR)
		return ("Allocation failed\n");
	else if (code == MAP_ERROR)
		return ("MAP ERROR\n");
	else if (INITIAL_ERROR)
		return ("Initial Error");
	return ("Unknown Error");
}

void	log_error(int error)
{
	ft_putendl_fd(get_error_msg(error), 2);
}
