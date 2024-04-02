#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

/*typedef struct date
{
int j;
int m;
int a;
}date;*/

typedef struct produit
{
int id;
char type[20];
char marque[20];
int ej;
int em;
int ea;
int fj;
int fm;
int fa;
int cout;
int quantite;
}produit;

int FJverif(char log[],char Pw[]);
void FJAjouter(produit p);
void FJSupprimer(produit p);
//void Modifier(int id,char fich[]);
//void chercher(int id);
void FJafficher(GtkWidget *liste,char fname[]);
void FJafficher1(GtkWidget *liste,char fname[]);
void FJmodifier(produit p);
void vider(GtkWidget *liste);
void FJtrouver(char fich[],char rupt[]);
#endif


