#include "fonction.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>


enum
{
	EID,
	ETYPE,
	EMARQUE,
	EEJ,
	EEM,
	EEA,
	EFJ,
	EFM,
	EFA,
	ECOUT,
	EQUANTITE,
	COLUMNS
};


int FJverif(char log[],char Pw[])
{
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("utilisateur.txt","r");
if(f!=NULL)
{while(fscanf(f,"%s %s ",ch1,ch2)!=EOF)
{
if((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw))==0)
trouve=1;
}
fclose(f);
}
return trouve;
}
void FJAjouter(produit p)
{
    FILE *fi;
    fi=fopen("stock.txt","a+");
    if (fi!=NULL){
    
    fprintf(fi,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",p.id,p.type,p.marque,p.ej,p.em,p.ea,p.fj,p.fm,p.fa,p.cout,p.quantite);
    }
    fclose(fi);
}

void FJafficher(GtkWidget *liste,char fname[])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter;
	GtkListStore  *store;

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
	FILE *fi;
	store=NULL;
	store=gtk_tree_view_get_model(liste);

	if(store==NULL)
	{

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Spécification",renderer,"text",EMARQUE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE LIM JOUR",renderer,"text",EEJ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE LIM MOIS",renderer,"text",EEM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE LIM ANNEE",renderer,"text",EEA,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE ARR JOUR",renderer,"text",EFJ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE ARR MOIS",renderer,"text",EFM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE ARR ANNEE",renderer,"text",EFA,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("cout",renderer,"text",ECOUT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",EQUANTITE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	store=gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
	fi=fopen(fname,"r");
 	if (fi==NULL)
		{
		return;
		}
	else
		{
		fi=fopen(fname,"a+");
		while(fscanf(fi,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",&id,type,marque,&ej,&em,&ea,&fj,&fm,&fa,&cout,&quantite)!=EOF)
		{
		
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store, &iter , EID, id, ETYPE, type, EMARQUE,marque,EEJ,ej,EEM,em,EEA,ea,EFJ,fj,EFM,fm,EFA,fa,ECOUT,cout,EQUANTITE,quantite, -1);}		}         
		fclose(fi);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
		}
		}

void FJSupprimer(produit p)
{
	FILE *fi,*g;
	produit p2;
	fi=fopen("stock.txt","r");
	g=fopen("stock2.txt","w");
	if (fi==NULL || g==NULL)
		return;
	else
	{	
		while(fscanf(fi,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",&p2.id,p2.type,p2.marque,&p2.ej,&p2.em,&p2.ea,&p2.fj,&p2.fm,&p2.fa,&p2.cout,&p2.quantite)!=EOF)
		{
			if( p2.id!=p.id || strcmp(p2.type,p.type)!=0 || strcmp(p2.marque,p.marque)!=0 || p2.ej!=p.ej || p2.em!=p.em || p2.ea!=p.ea || p2.fj!=p.fj || p2.fm!=p.fm || p2.fa!=p.fa || p2.cout!=p.cout || p2.quantite!=p.quantite )
				fprintf(g,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",p2.id,p2.type,p2.marque,p2.ej,p2.em,p2.ea,p2.fj,p2.fm,p2.fa,p2.cout,p2.quantite);
	
		}
	fclose(fi);
	fclose(g);
	remove("stock.txt");
	rename("stock2.txt","stock.txt");
	}
}

void vider(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter;
	GtkListStore  *store;

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
	FILE *fi;
	store=NULL;
	store=gtk_tree_view_get_model(liste);

	if(store==NULL)
	{

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE EXP JOUR",renderer,"text",EEJ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE EXP MOIS",renderer,"text",EEM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE EXP ANNEE",renderer,"text",EEA,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE FAB JOUR",renderer,"text",EFJ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE FAB MOIS",renderer,"text",EFM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE FAB ANNEE",renderer,"text",EFA,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("cout",renderer,"text",ECOUT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",EQUANTITE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store=gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
	gtk_list_store_append(store, &iter);
	gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
	g_object_unref(store);
}

/*void chercher(int id)
{FILE *fi=NULL,*f1=NULL;
produit p,p1;
fi=fopen("stock.txt","r");
f1=fopen("foundproduit.txt","w+");
while(fscanf(fi,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",&p.id,p.type,p.marque,&p.ej,&p.em,&p.ea,&p.fj,&p.fm,&p.fa,&p.cout,&p.quantite)!=EOF){
if(id==p.id)
    {fprintf(f1,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",p.id,p.type,p.marque,p.ej,p.em,p.ea,p.fj,p.fm,p.fa,p.cout,p.quantite);}
}
fclose(fi);
fclose(f1);
}*/

void FJafficher1(GtkWidget *liste,char fname[])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter;
	GtkListStore  *store;

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
	FILE *fi;
	store=NULL;
	store=gtk_tree_view_get_model(liste);

	if(store==NULL)
	{

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Spécification",renderer,"text",EMARQUE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE LIM JOUR",renderer,"text",EEJ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE LIM MOIS",renderer,"text",EEM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE LIM ANNEE",renderer,"text",EEA,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE ARR JOUR",renderer,"text",EFJ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE ARR MOIS",renderer,"text",EFM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE ARR ANNEE",renderer,"text",EFA,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("cout",renderer,"text",ECOUT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",EQUANTITE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	store=gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
	fi=fopen(fname,"r");
 	if (fi==NULL)
		{
		return;
		}
	else
		{
		fi=fopen(fname,"a+");
		while(fscanf(fi,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",&id,type,marque,&ej,&em,&ea,&fj,&fm,&fa,&cout,&quantite)!=EOF)
		{if (quantite==0){
		
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store, &iter , EID, id, ETYPE, type, EMARQUE,marque,EEJ,ej,EEM,em,EEA,ea,EFJ,fj,EFM,fm,EFA,fa,ECOUT,cout,EQUANTITE,quantite, -1);}}		}         
		fclose(fi);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
		}
		}

void FJmodifier(produit p)
{

    FILE* fi;
    FILE* ft;
    produit pm;

    
    fi=fopen("stock.txt","r");
    ft=fopen("stock1.txt","a+");

     while(fscanf(fi,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",&pm.id,pm.type,pm.marque,&pm.ej,&pm.em,&pm.ea,&pm.fj,&pm.fm,&pm.fa,&pm.cout,&pm.quantite)!=EOF)
        {
        if (pm.id!=p.id)
{fprintf(ft,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",pm.id,pm.type,pm.marque,pm.ej,pm.em,pm.ea,pm.fj,pm.fm,pm.fa,pm.cout,pm.quantite);}




        else
        {
            
            fprintf(ft,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",p.id,p.type,p.marque,p.ej,p.em,p.ea,p.fj,p.fm,p.fa,p.cout,p.quantite);
        }
    }


fclose(fi);
fclose(ft);
remove("stock.txt");
rename("stock1.txt","stock.txt");
}














