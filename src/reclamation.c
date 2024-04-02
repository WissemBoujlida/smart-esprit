#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#include "reclamation.h"

enum
{CNOM,
  CPNOM,
  CCIN,
  CID,
  CCONTACT,
  CENQUETTE,
  CDATE,
  COBJET,
  CPROBLEME,
  COLUMNS
};
void actv(int e,char v[])
{
if (e==1)
  {strcpy(v,"Oui");};
if (e==0)
  {strcpy(v,"Non");};
}

void objpl(int obj1,int obj2,char ob[])
{
 
if (obj1==1)
{strcat(ob,"-Restauration-");};
if (obj2==1)
{strcat(ob,"-hebergement-");};


}

void ajouter_pl(rec r)
{

FILE*f=NULL;
f=fopen("reclm.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s %s %s \n",r.nom,r.pnom,r.cin,r.id,r.contact,r.enquette,r.date,r.objet,r.prob);
fclose(f);
}
else 
printf("\n ERREUR");
}


void afficher_rec(GtkWidget *liste,char fname[])
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter;
	GtkListStore  *store;

   char nom[50];
   char pnom[50];
   char  cin[9];
   char  id[50];
   char contact[10];
   char enquette[10];
   char date[30];
   char objet[50];
   char prob[300];
	FILE *f;
	store=NULL;
	store=gtk_tree_view_get_model(liste);

	if(store==NULL)
	{

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",CNOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("pnom",renderer,"text",CPNOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CCIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",CID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("contact",renderer,"text",CCONTACT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("enquette",renderer,"text",CENQUETTE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",CDATE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("objet",renderer,"text",COBJET,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prob",renderer,"text",CPROBLEME,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen(fname,"r");
 	if (f==NULL)
		{
		return;
		}
	else
		{
		f=fopen(fname,"a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",nom,pnom,cin,id,contact,enquette,date,objet,prob)!=EOF)
		{
		
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store, &iter , CNOM, nom, CPNOM, pnom, CCIN,cin,CID,id,CCONTACT,contact,CENQUETTE,enquette,CDATE,date,COBJET,objet,CPROBLEME,prob, -1);}		}         
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
		}
}

void supprimer_pl(rec x)
{
   char nom[50];
   char pnom[50];
   char  cin[9];
   char  id[50];
   char contact[10];
   char enquette[10];
   char date[30];
   char objet[50];
   char prob[300];

  FILE *f,*g;
  f=fopen("reclm.txt","r");
  g=fopen("dump.txt","a+");

  if ((f==NULL) || (g==NULL))
  {return;}
  else 
  {
      while (fscanf(f,"%s %s %s %s %s %s %s %s %s \n",nom,pnom,cin,id,contact,enquette,date,objet,prob)!=EOF)
     {
       if ( strcmp(x.nom,nom)!=0 || strcmp(x.pnom,pnom)!=0 || strcmp(x.cin,cin)!=0 || strcmp(x.id,id)!=0 || strcmp(x.contact,contact)!=0 || strcmp(x.enquette,enquette)!=0 || strcmp(x.date,date)!=0 || strcmp(x.objet,objet)!=0 || strcmp(x.prob,prob)!=0  )
         fprintf(g,"%s %s %s %s %s %s %s %s %s \n",nom,pnom,cin,id,contact,enquette,date,objet,prob);
     }
     fclose(f);
     fclose(g);
   remove("reclm.txt");
   rename("dump.txt","reclm.txt");
  }

}

void recherche_pl(char rd[30])
{
FILE*f;
FILE*g;
g=fopen("drec.txt","w");
rec r;

f=fopen("reclm.txt","r");
 if ((f==NULL))
  {return;}
  else 
  {

      while (fscanf(f,"%s %s %s %s %s %s %s %s %s \n",r.nom,r.pnom,r.cin,r.id,r.contact,r.enquette,r.date,r.objet,r.prob)!=EOF)
   {
  if (strcmp(r.date,rd)==0)
         fprintf(g,"%s %s %s %s %s %s %s %s %s \n",r.nom,r.pnom,r.cin,r.id,r.contact,r.enquette,r.date,r.objet,r.prob);

   }
   fclose(g);
   fclose(f);
  
  }

}


int service_rec()
{   int h=0;
    int rr=0;
    int recc=0;
    rec r;
    FILE *f=NULL;
 f=fopen("reclm.txt","r");
 if (f==NULL)
  {return;}
  else 
  {

      while (fscanf(f,"%s %s %s %s %s %s %s %s %s \n",r.nom,r.pnom,r.cin,r.id,r.contact,r.enquette,r.date,r.objet,r.prob)!=EOF)
      {
  if (strcmp(r.objet,"-hebergement-")==0);
        {
        h+=1;
        }
  if (strcmp(r.objet,"-Restauration-")==0);
        {
         rr+=1;
         }
      }
     fclose(f);

     if (h>rr)
    {recc=1;}
   if (h<rr)
    {recc=2;}

  }
    return recc;
}



