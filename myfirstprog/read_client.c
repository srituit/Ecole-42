#include "my_first_prog.h"

t_Client    *read_client(char *client)
{
    t_Client    *Client;
    int     fd;
    char    *buff;
    int     BUFFER_SIZE;
    int     readed;
    int     i;
    int     j;
    int     k;
    char    tmp[5];
    char    *tmp_type;
    char    *tmp_Iban;
    
    Client = malloc(sizeof(Client));
    Client->facture = malloc(sizeof(t_Facture));
    BUFFER_SIZE = 4096;
    buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
    fd = open(client, O_RDONLY);
    readed = read(fd, buff, BUFFER_SIZE);
    buff[readed] = '\0';
    printf("%s\n", buff);
    Client->nom = client;
    printf("%s\n", Client->nom);
    j = 0;
    i = (str_str(buff, "ID : (") + 6);
    while (j < 4)
    {
        tmp[j++] = buff[i++];
    }
    tmp[j] = '\0';
    Client->ID = ft_atoi(tmp);
    printf("%d\n", Client->ID);
    i = (str_str(buff, "type : ") + 7);
    j = 0;
    tmp_type = malloc(sizeof(char) * 25);
    while (buff[i] != ' ')
    {
        tmp_type[j++] = buff[i++];
    }
    tmp_type[j] = '\0';
    Client->facture->type = tmp_type;
    printf("%s\n", Client->facture->type);
    i = (str_str(buff, "I-Ban : ") + 8);
    j = 0;
    tmp_Iban = malloc(sizeof(char) * 25);
    while (buff[i] != '\n')
    {
        tmp_Iban[j++] = buff[i++];
    }
    tmp_Iban[j] = '\0';
    Client->facture->Iban = tmp_Iban;
    printf("%s\n", Client->facture->Iban);
    return (Client);
}

int main(void)
{
    t_Client    *Client;
    int         tot;

    Client = read_client("Bernardo");
    printf("Apres fonction %s\n", Client->nom);
    printf("Apres fonction %s\n", Client->facture->type); 
    printf("Apres fonction %d\n", Client->ID);   
    printf("Apres fonction %s\n", Client->facture->Iban);
    Client->facture->detail = malloc(sizeof(t_Detail));
    Client->facture->detail->next = malloc(sizeof(t_Detail));
    Client->facture->detail->montant = 150;
    tot = Client->facture->detail->montant;
    Client->facture->detail->next->montant = 330;
    tot = Client->facture->detail->montant + Client->facture->detail->next->montant;
    printf("tot is : %d\n", tot);
    printf("Done.\n");
    return (0);
}