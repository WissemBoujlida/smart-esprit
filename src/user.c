#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"

enum
{
	NOM,
	PRENOM,
	CIN,
	AGE,
	SEXE,
	NUMERO,
	EMAIL,
	POSTE,
	
	COLUMNS
};

enum
{
	BLOCK,
	ETAGE,
	NUM_CAPTEUR,
	DEBIT,
	COLUMNS1
};

void add_user(user c)
{
FILE *f;
user p;
int k=0;

        f=fopen("../src/user.txt","r");
while(fscanf(f,"%s %s %s %s %d %d %s %s \n",p.nom,p.prenom,p.cin,p.sexe,&p.age,&p.num,p.email,p.poste)!=EOF)
        {
if( strcmp(c.cin,p.cin)==0){
k++;
}
}
        fclose(f);
if(k==0)
{f=fopen("user.txt","a+");
if(f!=NULL)
{fprintf(f,"%s %s %s %s %d %d %s %s\n",c.nom,c.prenom,c.cin,c.sexe,c.age,c.num,c.email,c.poste);
fclose(f);
}
}}

void aff_user(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;

GtkListStore *store;
	char nom[20];
	char prenom[20];
	char cin[20];
	char sexe[20];
	char age[30];
	char num[30];
	char email[50];
	char poste[50];
store =NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("age",renderer,"text",AGE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("numero",renderer,"text",NUMERO,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("email",renderer,"text",EMAIL,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("poste",renderer,"text",POSTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("user.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("user.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %s %s\n",nom,prenom,cin,sexe,age,num,email,poste)!=EOF)
{gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,CIN,cin,AGE,age,SEXE,sexe,NUMERO,num,EMAIL,email,POSTE,poste, -1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}



void supp(user c)
{
	char nom[20];
	char prenom[20];
	char cin[20];
	char sexe[20];
	int age;
	int num;
	char email[50];
	char poste[50];

FILE *f,*g;
f=fopen("user.txt","r");
g=fopen("dump.txt","w");
if(f==NULL || g==NULL)
{
return;
}
else
{
while(fscanf(f,"%s %s %s %s %d %d %s %s\n",nom,prenom,cin,sexe,&age,&num,email,poste)!=EOF)
{
if(strcmp(c.cin,cin)!=0)
	fprintf(g,"%s %s %s %s %d %d %s %s\n",nom,prenom,cin,sexe,age,num,email,poste);
}
fclose(f);
fclose(g);
remove("user.txt");
rename("dump.txt","user.txt");
}
}


void supp_cin(char cin[])
{
FILE *f;
    FILE *f1=NULL;
    user c;
    f=fopen("user.txt","r");
    f1=fopen("tmp.txt","w");
    if(f!=NULL)
    {
        
        while(fscanf(f,"%s %s %s %s %d %d %s %s\n ",c.nom,c.prenom,c.cin,c.sexe,&c.age,&c.num,c.email,c.poste)!=EOF)
        {
            if(strcmp(c.cin,cin)!=0)
		   
	    {

                fprintf(f1,"%s %s %s %s %d %d %s %s\n ",c.nom,c.prenom,c.cin,c.sexe,c.age,c.num,c.email,c.poste);
            }
                

            }
        fclose(f);
        fclose(f1);

        }

    remove ("user.txt");
    rename ("tmp.txt","user.txt");
}




int chercher_user(GtkWidget* treeview1,char*l,char*type)
{
GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;
user p;
int nb=0, j;

        /* Creation du modele */
        adstore = gtk_list_store_new(7,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_INT,
				     G_TYPE_STRING,
                                     G_TYPE_INT,
				     G_TYPE_STRING,
			             G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %d %d %s %s \n",p.nom,p.prenom,p.cin,p.sexe,&p.age,&p.num,p.email,p.poste)!=EOF)
        {
if( strcmp(type,p.cin)==0){ nb++;
GtkTreeIter pIter;
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,p.nom,
                            1,p.prenom,
                            2,p.cin,
                            3,p.age,
                            4,p.sexe,
		            5,p.num,
			    6,p.email,
			    7,p.poste,
                            -1);}
}
        fclose(f);

/* Creation de la 1ere colonne */
if(j==0)
{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("nom",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("prenom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
/* Ajouter la 2emme colonne à la vue */
//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("cin",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
/* Ajouter la 3emme colonne à la vue */
//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("age",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
/* Ajouter la 4emme colonne à la vue */
//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("sexe",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
/* Ajouter la 5emme colonne à la vue */
//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("numero",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
/* Ajouter la 6emme colonne à la vue */
//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("email",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("poste",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);

j++;}

  gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
return nb;
}


void afficher_mvt(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;

GtkListStore *store;
	int j;
	int h;
	int cap;
	float val;
alarme c;
store =NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Block",renderer,"text",BLOCK,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Etage",renderer,"text",ETAGE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Capteur",renderer,"text",NUM_CAPTEUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Débit",renderer,"text",DEBIT,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


}

store=gtk_list_store_new(COLUMNS1,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_FLOAT);
f=fopen("../src/debit.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("../src/debit.txt","r");
	while(fscanf(f,"%d %d %d %f\n",&c.j,&c.h,&c.cap,&c.val)!=EOF)
	{
	//if(c.val==1)
	//{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,BLOCK,c.j,ETAGE,c.h,NUM_CAPTEUR,c.cap,DEBIT,c.val, -1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
//}



