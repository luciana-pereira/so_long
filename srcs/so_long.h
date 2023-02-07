/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 03:48:11 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/06 14:17:00 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#define IMG_FLOOR "assets/img/floor.xpm"
#define IMG_WALL "assets/img/wall.xpm"
#define IMG_COLLECT "assets/img/collect.xpm"
#define IMG_EXIT "assets/img/exit.xpm"
#define IMG_PLAYER "assets/img/player.xpm"

#define ESC 65307
#define W 119
#define A 97
#define S 115
#define D 100

#include "../libs/libft/libft.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_img
{
    void *player;
    void *floor;
    void *wall;
    void *collect;
    void *exit;
} t_img;

typedef struct s_ptr
{
    int height;
    int lenght;
    int x;
    int y;
    int player;
    int escape;
    int count;
    int count_ext;
    int step;
    int size;
    char **map;
    void *wall;
    void *mlx;
    void *win;
    char *fn;
    t_img *img;
} t_ptr;

void insert_image(t_ptr *data);
void map_init(t_ptr *data, char *name);
void verify(t_ptr *data);
int new_frame(t_ptr *data);
void move_w(t_ptr *data);
void move_s(t_ptr *data);
void move_a(t_ptr *data);
void move_d(t_ptr *data);
void map_gen(t_ptr *data);
void read_map(t_ptr *data);
int key_input(int keycode, t_ptr *data);
void verify_content(t_ptr *data);
void verify_character(t_ptr *data);
void verify_format(t_ptr *data);
void verify_wall(t_ptr *data);
void insert_player_image(t_ptr *data, int *j, int *i);
void insert_wall_image(t_ptr *data, int *j, int *i);
void insert_space_image(t_ptr *data, int *j, int *i);
void insert_collect_image(t_ptr *data, int *j, int *i);
void create_map(t_ptr *data);
int new_exit(t_ptr *data);
void end_game(t_ptr *data);

#endif