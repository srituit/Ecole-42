#include "my_first_prog.h"

void    add_client_info(int ID, char *info)
{
    t_list  *List;
    t_list  *cur;
    char    *tmp;
    int     fd_list;
    char    *buff;
    int     BUFFER_SIZE;
    int     readed = 1;
    int     res;
    char    *nom;
    int     i;
    int     j;

    i = 0;
    j = 0;
    List = malloc(sizeof(List) * 1);
    List->next = NULL;
    cur = List;
    BUFFER_SIZE = 4096;
    buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
    fd_list = open("Liste_client", O_RDWR);
    readed = read(fd_list, buff, BUFFER_SIZE);
    buff[readed] = '\0';
    while (buff[j] != '\0')
    {
        nom = (str_cpy(buff, i));
        cur->nom = nom;
        cur->next = malloc(sizeof(List) * 1);
        cur = cur->next;
        cur->next = NULL;
        j = i + str_len(nom) + 2;
        i = (str_len(nom) + i + 1);
    }
    close(fd_list);
    fd_list = open("Liste_client", O_RDWR);
//    res = str_str(buff, client);

    while (List->next)
    {
        write(fd_list, List->nom, str_len(List->nom));
        write(fd_list, "\n", 1);
//        if (List->ID = ID)
//        {
            write(fd_list, "(", 1);
            write(fd_list, info, str_len(info));
            write(fd_list, ")", 1);
            write(fd_list, "\n", 1);
//        }
        List = List->next;
    }
/*    str_len(info);
    tmp = malloc(sizeof(char) * str_len(buff) - str_len(buff) - res);
    tmp = str_cut(buff, res + info);
    printf("%d", res);
*/
    free(buff);
    close(fd_list);
}