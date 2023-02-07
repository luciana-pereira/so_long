/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 03:29:31 by lucperei          #+#    #+#             */
/*   Updated: 2023/02/04 17:29:24 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *new_str(char *buffer)
{
    int i;
    int j;
    char *str;

    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (!buffer[i])
    {
        free(buffer);
        return (NULL);
    }
    str = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
    if (!str)
        return (NULL);
    i++;
    j = 0;
    while (buffer[i])
        str[j++] = buffer[i++];
    str[j] = '\0';
    free(buffer);
    return (str);
}

char *read_str(int fd, char *buffer)
{
    char *temp;
    int byte;

    temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!temp)
        return (NULL);
    byte = 1;
    while (!ft_strchr(buffer, '\n') && byte != 0)
    {
        byte = read(fd, temp, BUFFER_SIZE);
        if (byte == -1)
        {
            free(temp);
            return (NULL);
        }
        temp[byte] = '\0';
        buffer = ft_strjoin(buffer, temp);
    }
    free(temp);
    return (buffer);
}

char *insert_line(char *buffer)
{
    int i;
    char *str;

    i = 0;
    if (!buffer[i])
        return (NULL);
    while (buffer[i] && buffer[i] != '\n')
        i++;
    str = (char *)malloc(sizeof(char) * (i + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        str[i] = buffer[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *get_next_line(int fd)
{
    static char *buffer[BUFFER_SIZE + 1];
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    buffer[fd] = read_str(fd, buffer[fd]);
    if (!buffer[fd])
        return (NULL);
    line = insert_line(buffer[fd]);
    buffer[fd] = new_str(buffer[fd]);
    return (line);
}
