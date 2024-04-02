#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>
typedef struct
{
    char cin [100] ;
    char nom [100];
    char prenom [100];
    char sex [100];
    char date_naissance [100];
    char niveau [100];
    char block [100];
    char telephone [100];
}etudiant_heberge;

void ajouter(char fname [],etudiant_heberge e);
void rechercher(char fname [],char identifiant[]);
void afficher(char fname [],GtkWidget *liste);
void supprimer(char fname [],char identifiant[]);
void modifier(char fname [],etudiant_heberge ne,char identifiant []);
void nbr_etudiant_niveau(char fname []);
void pos_car(char T[], char c, int *p_occ, int *d_occ);
void afficherniveau(char fname [],GtkWidget *liste);
