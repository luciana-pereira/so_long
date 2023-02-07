/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:48:54 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/06 01:56:27 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void verify_wall(t_ptr *data)
{
    int index;
    int err;

    err = 0;
    index = 0;
    while (index < data->height)
    {
        if (data->map[index][0] != '1' || data->map[index][data->lenght - 1] != '1')
            err++;
        index++;
    }
    index = 0;
    while (index < data->lenght)
    {
        if (data->map[0][index] != '1' || data->map[data->height - 1][index] != '1')
            err++;
        index++;
    }
    if (err > 0)
    {
        printf("Error.\nVerify walls\n");
        exit(1);
    }
}

void verify_format(t_ptr *data)
{
    char *ber;
    int i;
    int j;
    int len;

    i = 0;
    j = 0;
    ber = "ber";
    len = ft_strlen(data->fn);
    if (len < 3)
    {
        printf("Error.\nVerify file extansion\n");
        exit(1);
    }
    i = len - 3;
    while (data->fn[i] != '\0' && ber[j] != '\0')
    {
        if (data->fn[i] != ber[j])
        {
            printf("Error.\nVerify file extansion\n");
            exit(1);
        }
        i++;
        j++;
    }
}

void verify_character(t_ptr *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->map[j])
    {
        while (data->map[j][i])
        {
            if (data->map[j][i] == 'P' || data->map[j][i] == 'E' || data->map[j][i] == '1' || data->map[j][i] == 'C' || data->map[j][i] == '0')
                i++;
            else
            {
                printf("Error.\nInvalid char at map\n");
                exit(1);
            }
        }
        i = 0;
        j++;
    }
}

void verify_content(t_ptr *data)
{
    int i;
    int j;

    j = 0;
    while (data->map[j])
    {
        i = 0;
        while (data->map[j][i])
        {
            if (data->map[j][i] == 'P')
                data->player += 1;
            else if (data->map[j][i] == 'E')
                data->count_ext += 1;
            else if (data->map[j][i] == 'C')
                data->count += 1;
            i++;
        }
        j++;
    }
    if (data->count == 0 || data->player == 0 || data->count_ext == 0 || data->player > 1 || data->count_ext > 1)
    {
        printf("Error.\nMap invalid\n");
        exit(1);
    }
}
