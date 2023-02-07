/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:05:31 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/04 04:47:45 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(char *s, int c)
{
    int index;

    index = 0;
    if (!s)
    {
        return (0);
    }
    if (c == '\0')
    {
        return ((char *)&s[ft_strlen(s)]);
    }
    while (s[index] != '\0')
    {
        if (s[index] == (char)c)
            return ((char *)&s[index]);
        index++;
    }
    return (0);
}
