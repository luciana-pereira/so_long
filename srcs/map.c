/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:53:01 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/03 06:10:27 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_gen(t_ptr *data)
{
    char *line;
    int fd;

    fd = open(data->fn, O_RDONLY);
    line = get_next_line(fd);
    if (!line)
    {
        printf("Error\nNo map specified!\n");
        exit(1);
    }
    while (line[data->lenght] != '\0')
        data->lenght++;
    while (line)
    {
        if ((int)ft_strlen(line) != data->lenght)
        {
            printf("Error\nInvalid map!\n");
            exit(1);
        }
        data->height++;
        free(line);
        line = get_next_line(fd);
    }
    line = NULL;
    close(fd);
}

void read_map(t_ptr *data)
{
    int fd;
    int index;
    char *line;

    fd = open(data->fn, O_RDONLY);
    line = get_next_line(fd);
    data->map = (char **)malloc(sizeof(char *) * (data->height + 1));
    index = 0;
    while (line)
    {
        data->map[index] = line;
        line = get_next_line(fd);
        index++;
    }
    data->map[index] = NULL;
    free(line);
    line = NULL;
    close(fd);
}
