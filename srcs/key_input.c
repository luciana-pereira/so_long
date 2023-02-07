/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:21:07 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/04 16:51:35 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_input(int keycode, t_ptr *data)
{
    if (keycode == ESC)
        end_game(data);
    else if (keycode == W)
        move_w(data);
    else if (keycode == A)
        move_a(data);
    else if (keycode == S)
        move_s(data);
    else if (keycode == D)
        move_d(data);
    return (0);
}
