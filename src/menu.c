
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

enum {
EID, 
EDATE,
ENOM,
ETYPE,
EENTREE,
ESUITE,
EDESSERT,
COLUMNS,
};





///////////////////////////////////////////////////////////////////
void foajouter(menu m)
{
FILE* f;
f=fopen("menu.txt","ab+");
fprintf(f,"%s %s %s %s %s %s %s\n",m.id,m.nom,m.type,m.entree,m.suite,m.dessert,m.date);
fclose(f);
}
/////////////////////////////////////////////////////////
void fosupprimer(char iden[] ){
FILE* f;
FILE* ft;
f=fopen("menu.txt","r");
ft=fopen("tmp.txt","ab+");
    char id[10];
    char date[10];
    char nom[25];
    char type[20];
    char entree[30];
    char suite[30];
    char dessert[30];
    char str[25];
while(fscanf(f,"%s %s %s %s %s %s %s\n",id,nom,type,entree,suite,dessert,date)!=EOF){
if (strcmp(iden,id)!=0){fprintf(ft,"%s %s %s %s %s %s %s\n",id,nom,type,entree,suite,dessert,date);}

}

fclose(f);
fclose(ft);
remove("menu.txt");
rename("tmp.txt","menu.txt");}
/////////////////////////////////////////////////////////////////////////////
void foafficher (char fichier [], GtkWidget *liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

    char id[10];
    char date[10];
    char nom[25];
    char type[20];
    char entree[30];
    char suite[30];
    char dessert[30];
    store=NULL;
	
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL){
 	
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("entree",renderer,"text",EENTREE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("suite",renderer,"text",ESUITE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("dessert",renderer,"text",EDESSERT,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("date",renderer,"text",EDATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);               }


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen(fichier,"r");
while(fscanf(f,"%s %s %s %s %s %s %s\n",id,nom,type,entree,suite,dessert,date)!=EOF){
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EID,id,ENOM,nom,ETYPE,type,EENTREE,entree,ESUITE,suite,EDESSERT,dessert,EDATE,date,-1);}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}
//////////////////////////////////////////////////////////////////////////
void fochercher(char ident[]){
FILE *f;
FILE *fw;
f=fopen("menu.txt","r");
fw=fopen("menurecherche.txt","w");
    int nb=0;
    char id[10];
    char date[10];
    char nom[25];
    char type[20];
    char entree[30];
    char suite[30];
    char dessert[30];
    char str[25];
while(fscanf(f,"%s %s %s %s %s %s %s\n",id,nom,type,entree,suite,dessert,date)!=EOF){
    if (strcmp(ident,id)==0) fprintf(fw,"%s %s %s %s %s %s %s\n",id,nom,type,entree,suite,dessert,date);
}
fclose(f);
fclose(fw);
}	
	











































