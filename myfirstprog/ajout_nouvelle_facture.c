#include "my_first_prog.h"

void    add_client(char *client, int ID)
{
    int     fd_list;
    char    *buff;
    int     BUFFER_SIZE;
    int     z;

    BUFFER_SIZE = 4096;
    buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
    fd_list = open("Liste_client", O_RDWR);
    read(fd_list, buff, BUFFER_SIZE);
    write(fd_list, "ID : (", 6);
    ft_putnbr(ID, fd_list);
    write(fd_list, ")\t", 2);    
    write(fd_list, client, str_len(client));
    write(fd_list, "\n", 1);
    close(fd_list);
    free(buff);
}

int main(void)
{
    t_client    client;
    int         fd;
    int         fd_list;
    char         Q;
    char        *buff;
    char        *buff_list;
    int         BUFFER_SIZE;
    char        Q1;

    BUFFER_SIZE = 4096;
    client.detail.statut = "non";
    Q1 = 'a';
    while (Q1 != 'y' && Q1 != 'n')
    {
        printf("Nouveau client? (y) / (n)\n");
        scanf("%s", &Q1);
    }
    if (Q1 == 'y')
    {
        printf("Nom du client?\n");
        scanf("%s", &client.nom);
        client.nom[str_len(client.nom)] = '\0';
        client.ID = add_ID();
        printf("ID : %d\n", client.ID);
        add_client(client.nom, client.ID);
        open(client.nom, O_CREAT);
        fd = open(client.nom, O_RDWR);
        write(fd, "ID : (", 6);
        ft_putnbr(client.ID, fd);
        write(fd, ")\n", 2);
    }
    if (Q1 == 'n') 
    {
        fd = -1;
        while (fd == -1)
        {
            printf("nom du client?\n");
            scanf("%s", &client.nom);
            client.nom[str_len(client.nom)] = '\0';
            fd = open(client.nom, O_RDWR);
            if (fd != -1)
                read(fd, buff, BUFFER_SIZE);
            if (fd == -1)
                printf("Client inexistant, reessayer\n");
        }
    }
    Q = 'a';
    while (Q != 'y' && Q != 'n')
    {
        printf("Nouvelle facture? (y) / (n)\n");
        scanf("%s", &Q);
    }
    while (Q == 'y')
    {
        printf("type de facture ?\n");
        scanf("%s", &client.detail.type);
        client.detail.type[str_len(client.detail.type)] = '\0';
        printf("Montant de la facture ?\n");
        scanf("%d", &client.detail.montant);
        printf("A payer jusqu'au?\n");
        scanf("%s", &client.detail.date);
        client.detail.date[str_len(client.detail.date)] = '\0';
        printf("Commentaire ?\n");
        scanf("%s", &client.detail.com);
        client.detail.com[str_len(client.detail.com)] = '\0';
        write(fd, &client.detail.type, str_len(client.detail.type));
        write(fd, " : ", 3);
        printf("Iban?\n");
        scanf("%s", &client.detail.iban);
        client.detail.iban[str_len(client.detail.iban)] = '\0';
        printf("ref?\n");
        scanf("%s", &client.detail.ref);
        client.detail.ref[str_len(client.detail.ref)] = '\0';
        write(fd, &client.detail.iban, str_len(client.detail.iban));
        write(fd, "\n", 1);
        write(fd, "(", 1);
        write(fd, &client.detail.com, str_len(client.detail.com));
        write(fd, ")", 1);
        write(fd, "\t\t", 2);
        ft_putnbr(client.detail.montant, fd);
        write(fd, ".-", 2);
        write(fd, "\t\t", 2);
        write(fd, &client.detail.date, str_len(client.detail.date));
        write(fd, "\n", 1);
        write(fd, "ref. : ", 7);
        write(fd, &client.detail.ref, str_len(client.detail.ref));
        write(fd, "\t\t", 2);
        write(fd, "statut : ", 9);
        write(fd, client.detail.statut, str_len(client.detail.statut));
        write(fd, "\n", 1);   
        write(fd, "**************************************************", 50);
        write(fd, "**************************************************", 50);
        write(fd, "\n", 1);
        printf("Nouvelle facture? (y) / (n)\n");
        scanf("%s", &Q);
    }
    close(fd);
    return (0);
}