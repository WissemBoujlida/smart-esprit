


#include <gtk/gtk.h>



typedef struct menu{
    char id[10];
    char date[10];
    char nom[25];
    char type[20];
    char entree[30];
    char suite[30];
    char dessert[30];
}menu;
void foajouter(menu m);
void fomodifier(char identif[],char nouveau[],int choix);
void fosupprimer(char iden[] );
void fochercher(char ident[]);
void foafficher (char fichier[],GtkWidget *liste);
void meilleur();
