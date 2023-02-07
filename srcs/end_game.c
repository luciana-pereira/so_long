/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:22:02 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/07 04:53:47 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int new_exit(t_ptr *data)
{
    (void)*data;
    exit(0);
}

void end_game(t_ptr *data)
{
    mlx_destroy_image(data->mlx, data->img->player);
    mlx_destroy_image(data->mlx, data->img->floor);
    mlx_destroy_image(data->mlx, data->img->wall);
    mlx_destroy_image(data->mlx, data->img->collect);
    mlx_destroy_image(data->mlx, data->img->exit);
    mlx_destroy_window(data->mlx, data->win);
    mlx_loop_end(data->mlx);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
}
