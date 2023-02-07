/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:42:26 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/06 14:19:47 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_w(t_ptr *data)
{
    if (data->map[data->y - 1][data->x] != '1')
    {
        if (data->map[data->y - 1][data->x] == 'C')
        {
            data->map[data->y][data->x] = '0';
            data->map[data->y - 1][data->x] = 'P';
            data->count--;
            data->step++;
            printf("Steps: %d\n", data->step);
        }
        else if (data->map[data->y - 1][data->x] == '0')
        {
            data->map[data->y][data->x] = '0';
            data->map[data->y - 1][data->x] = 'P';
            data->step++;
            printf("Steps: %d\n", data->step);
        }
        else if (data->map[data->y - 1][data->x] == 'E' && data->count == 0)
        {
            data->step++;
            data->escape = 1;
        }
        data->y--;
    }
}

void move_s(t_ptr *data)
{
    if (data->map[data->y + 1][data->x] != '1')
    {
        if (data->map[data->y + 1][data->x] == 'C')
        {
            data->map[data->y][data->x] = '0';
            data->map[data->y + 1][data->x] = 'P';
            data->count--;
            data->step++;
            printf("Steps: %d\n", data->step);
        }
        else if (data->map[data->y + 1][data->x] == '0')
        {
            data->map[data->y][data->x] = '0';
            data->map[data->y + 1][data->x] = 'P';
            data->step++;
            printf("Steps: %d\n", data->step);
        }
        else if (data->map[data->y + 1][data->x] == 'E' && data->count == 0)
        {
            data->step++;
            data->escape = 1;
        }
        data->y++;
    }
}

void move_a(t_ptr *data)
{
    if (data->map[data->y][data->x - 1] != '1')
    {
        if (data->map[data->y][data->x - 1] == 'C')
        {
            data->map[data->y][data->x] = '0';
            data->map[data->y][data->x - 1] = 'P';
            data->count--;
            data->step++;
            printf("Steps: %d\n", data->step);
        }
        else if (data->map[data->y][data->x - 1] == '0')
        {
            data->map[data->y][data->x] = '0';
            data->map[data->y][data->x - 1] = 'P';
            data->step++;
            printf("Steps: %d\n", data->step);
        }
        else if (data->map[data->y][data->x - 1] == 'E' && data->count == 0)
        {
            data->step++;
            data->escape = 1;
        }
        data->x--;
    }
}

void move_d(t_ptr *data)
{
    if (data->map[data->y][data->x + 1] != '1')
    {
        if (data->map[data->y][data->x + 1] == 'C')
        {
            data->map[data->y][data->x] = '0';
            data->map[data->y][data->x + 1] = 'P';
            data->count--;
            data->step++;
            printf("Steps: %d\n", data->step);
        }
        else if (data->map[data->y][data->x + 1] == '0')
        {
            data->map[data->y][data->x] = '0';
            data->map[data->y][data->x + 1] = 'P';
            data->step++;
            printf("Steps: %d\n", data->step);
        }
        else if (data->map[data->y][data->x + 1] == 'E' && data->count == 0)
        {
            data->step++;
            data->escape = 1;
        }
        data->x++;
    }
}
