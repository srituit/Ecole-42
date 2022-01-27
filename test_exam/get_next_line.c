#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#include <stdlib.h>
#include <unistd.h>

char    *get_new_left(char *left)
{
    char    *new;
    int     i;
    int     j;

    if (!left[0])
    {
        free(left);
        return (NULL);
    }
    i = 0;
    while (left[i] && left[i] != '\n')
        i++;
    new = malloc(sizeof(char) * (str_len(left) - i + 1));
    if (!new)
        return (NULL);
    i++;
    j = 0;
    while (left[i])
    {
        new[j] = left[i];
        i++;
        j++;
    }
    new[j] = '\0';
    free(left);
    return (new);
}

char    *get_line(char *left)
{
    int     i;
    char    *line;

    if (!left)
        return(NULL);
    i = 0;
    while (left[i] && left[i] != '\n')
        i++;
    line = malloc(sizeof(char) * i + 2);
    if (!line)
        return (NULL);
    i = 0;
    while (left[i] && left[i] != '\n')
    {
        line[i] = left[i];
        i++;
    }
    if (left[i] == '\n')
    {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return (line);
}
char    *get_left(char *left, int fd)
{
    char *buff;
    int readed;

    if (!left)
        reurn (NULL);
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    readed = 1;
    while (readed != 0 && !is_new_line(left))
    {
        readed = read(fd, buff, BUFFER_SIZE);
        if (readed == -1)
        {
            free(buff);
            return (NULL);
        }
        buff[BUFFER_SIZE] = '\0';
        str_join(left, buff);
    }
    free(buff);
    return (left);
}

char    *get_next_line(int fd)
{
    char           *line;
    static char    *left;

    if (fd < 0 || BUFFER_SIZE < 1)
        reurn (NULL);
    left = get_left(left, fd);
    if (!left)
        return (NULL);
    line = get_line(left);
    left = get_new_left(left);
    return (line);
}