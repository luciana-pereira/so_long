/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 05:51:19 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/04 23:00:49 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);
size_t ft_strlen(const char *s);
char *ft_strchr(char *s, int c);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char *ft_strjoin(char *s1, char *s2);
char *new_str(char *buffer);
char *read_str(int fd, char *buffer);
char *insert_line(char *buffer);

#endif
