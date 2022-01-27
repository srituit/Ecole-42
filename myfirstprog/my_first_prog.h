#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_detail
{
    int     montant;
    char    com[60];
    char    iban[45];
    char    ref[45];
    char    date[9];
    char    type[45];
    char    *statut;

}t_detail;

typedef struct s_client
{
    char        nom[15];
    char        info[100];
    int         ID;
    t_detail    detail;
}t_client;

typedef struct s_list
{
    char           *nom;
    int             ID;
    t_client        client_info;
    struct s_list  *next;
}t_list;

typedef struct s_Detail
{
    char            ref[35];
    char            date[9];
    char            statut[10];
    char            com[88];
    int             montant;
    struct s_Detail *next;

}t_Detail;

typedef struct s_Facture
{
    char                *type;
    char                *Iban;
    t_Detail            *detail;
    struct s_Facture    *next;
}t_Facture;

typedef struct s_Client
{
    char                *nom;
    int                 ID;
    t_Facture           *facture;
    struct s_Client     *next;
}t_Client;

void    ft_printnbr(long int n, int fd);
void    ft_putnbr(int n, int fd);
int     add_ID(void);
int     ft_atoi(char *s);
int     str_len(char *str);
int     str_str(char *str, char *to_find);
char    *str_cpy(char *str, int i);
