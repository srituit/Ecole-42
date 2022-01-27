#include "my_first_prog.h"

int     add_ID(void)
{
    int ID;
    int fd;
    char    *buff;
    int BUFFER_SIZE;
    int i;
    int j;
    char    tmp[5];

    BUFFER_SIZE = 4096;
    buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
    j = 0;
    fd = open("Liste_client", O_RDONLY);
    read(fd, buff, BUFFER_SIZE);
    i = (str_str(buff, "ID : (") + 6);
    while (j < 4)
    {
        tmp[j] = buff[i];
        j++;
        i++;
    }
    tmp[j] = '\0';
    ID = (ft_atoi(tmp) + 1);
    if (ID == 1)
        ID = 1000;
    free(buff);
    close(fd);
    return (ID);
}