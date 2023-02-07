/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 03:47:50 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/06 14:16:53 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void insert_image(t_ptr *data)
{
    int x;
    int y;

    data->img = malloc(sizeof(t_img));
    data->img->player = mlx_xpm_file_to_image(data->mlx, IMG_PLAYER, &x, &y);
    data->img->floor = mlx_xpm_file_to_image(data->mlx, IMG_FLOOR, &x, &y);
    data->img->wall = mlx_xpm_file_to_image(data->mlx, IMG_WALL, &x, &y);
    data->img->exit = mlx_xpm_file_to_image(data->mlx, IMG_EXIT, &x, &y);
    data->img->collect = mlx_xpm_file_to_image(data->mlx, IMG_COLLECT, &x, &y);
}

void map_init(t_ptr *data, char *name)
{
    data->height = 0;
    data->lenght = 0;
    data->escape = 0;
    data->count = 0;
    data->count_ext = 0;
    data->step = 0;
    data->x = 0;
    data->y = 0;
    data->player = 0;
    data->fn = name;
    insert_image(data);
}

void verify(t_ptr *data)
{
    verify_wall(data);
    verify_format(data);
    verify_character(data);
    verify_content(data);
}

int new_frame(t_ptr *data)
{
    mlx_clear_window(data->mlx, data->win);
    create_map(data);
    if (data->count == 0 && data->player == 1 && data->escape == 1)
    {
        new_exit(data);
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_ptr data;

    if (argc == 2)
    {
        data.mlx = mlx_init();
        map_init(&data, argv[1]);
        map_gen(&data);
        read_map(&data);
        verify(&data);
        data.win = mlx_new_window(data.mlx, data.lenght * 32,
                                  data.height * 32, "so_long");
        mlx_hook(data.win, 17, 0, new_exit, &data);
        mlx_key_hook(data.win, key_input, &data);
        mlx_loop_hook(data.mlx, new_frame, &data);
        mlx_loop(data.mlx);
    }
}
