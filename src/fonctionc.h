#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct capteurs
{
    char nom[40];
    char type[20];
    char localisation[40];
    int valmin;
    int valmax;
    int etat;
}Capts;

void caajouter(Capts C);
void caafficher ();
void carechercher(int name);
void cadefectueux();
void casupprimer(char b[]);
void camodifier(Capts C1);
void caajouter_nom();
void cacheck();
void caafficher_detail(GtkWidget *liste, Capts C);
void caafficher_securite(GtkWidget *liste);
void caafficher_capts(GtkWidget *liste);
int verif(char log[], char Pw[],char fah[]);
