/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:17:20 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/04 06:34:12 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void insert_player_image(t_ptr *data, int *j, int *i)
{
    mlx_put_image_to_window(data->mlx, data->win,
                            data->img->player, (*j) * 32, (*i) * 32);
    data->y = *i;
    data->x = *j;
}

void insert_wall_image(t_ptr *data, int *j, int *i)
{
    mlx_put_image_to_window(data->mlx, data->win,
                            data->img->wall, (*j) * 32, (*i) * 32);
}

void insert_space_image(t_ptr *data, int *j, int *i)
{
    mlx_put_image_to_window(data->mlx, data->win,
                            data->img->floor, (*j) * 32, (*i) * 32);
}

void insert_collect_image(t_ptr *data, int *j, int *i)
{
    mlx_put_image_to_window(data->mlx, data->win,
                            data->img->collect, (*j) * 32, (*i) * 32);
}

void create_map(t_ptr *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->map[i])
    {
        while (data->map[i][j])
        {
            if (data->map[i][j] == '1')
                insert_wall_image(data, &j, &i);
            else if (data->map[i][j] == '0')
                insert_space_image(data, &j, &i);
            else if (data->map[i][j] == 'P')
                insert_player_image(data, &j, &i);
            else if (data->map[i][j] == 'C')
                insert_collect_image(data, &j, &i);
            else if (data->map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx, data->win,
                                        data->img->exit, j * 32, i * 32);
            j++;
        }
        j = 0;
        i++;
    }
}
