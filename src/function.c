#include "function.h"
enum
{
	CIN,
	NOM,
	PRENOM,
	SEX,
	DATE_NAISSANCE,
	NIVEAU,
	BLOCK,
	TELEPHONE,
	COLUMNS
};

void ajouter(char fname [],etudiant_heberge e)
{
FILE *f;
f=fopen(fname,"a+");
fprintf(f,"%s %s %s %s %s %s %s %s\n",e.cin,e.nom,e.prenom,e.sex,e.date_naissance,e.niveau,e.block,e.telephone);
fclose(f);
}

void rechercher(char fname [],char identifiant [])
{
FILE *f, *fw;
char cin[100],nom[100],prenom[100],sex[100],date_naissance[100],niveau[100],block[100],telephone[100];
f=fopen(fname,"r");
fw=fopen("etudiants_recherchee.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone)!=EOF)
{
if((strcmp(cin,identifiant))==0) fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone);
}
fclose(f);
fclose(fw);
}

void afficher(char fname [],GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char cin [100];
char nom [100];
char prenom [100];
char sex [100];
char date_naissance [100];
char niveau [100];
char block [100];
char telephone [100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Sex",renderer,"text",SEX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Date de naissance",renderer,"text",DATE_NAISSANCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Niveau",renderer,"text",NIVEAU,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Block",renderer,"text",BLOCK,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Telephone",renderer,"text",TELEPHONE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen(fname,"r");
if (f==NULL)
{
return;
}
else
{f=fopen(fname,"a+");
	while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone)!=EOF)
{
gtk_list_store_append(store,&iter);	 		     gtk_list_store_set(store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,SEX,sex,DATE_NAISSANCE,date_naissance,NIVEAU,niveau,BLOCK,block,TELEPHONE,telephone,-1); 
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}
void supprimer(char fname [],char identifiant[])
{
char cin[100],nom[100],prenom[100],sex[100],date_naissance[100],niveau[100],block[100],telephone[100];
FILE *f,*fw;
f=fopen(fname,"r");
fw=fopen("dump.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone)!=EOF)
{
if(strcmp(cin,identifiant)!=0)
{
fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone);
}
}
fclose(f);
fclose(fw);
remove("etudiants.txt");
rename("dump.txt","etudiants.txt");
}

void modifier(char fname [],etudiant_heberge ne,char identifiant [])
{
char cin[100],nom[100],prenom[100],sex[100],date_naissance[100],niveau[100],block[100],telephone[100];
FILE *f,*fw;
f=fopen(fname,"r");
fw=fopen("dump.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone)!=EOF)
{
if(strcmp(cin,identifiant)!=0)
{
fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone);
}
else
{
fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,ne.nom,ne.prenom,ne.sex,ne.date_naissance,ne.niveau,ne.block,ne.telephone);
}
}
fclose(f);
fclose(fw);
remove("etudiants.txt");
rename("dump.txt","etudiants.txt");
}

void pos_car(char T[], char c, int *p_occ, int *d_occ)
{

int i;
    for(i=0;i<strlen(T);i++)
    {
        if (T[i]==c)
        {
            if (*p_occ==-1)
            {
                *p_occ=i;

            }
            else
            {
                *d_occ=i;
            }

        }

    }

}
void nbr_etudiant_niveau(char fname [])
{
int c1=0,c2=0,c3=0,c4=0,c5=0,n;
char cin[100],nom[100],prenom[100],sex[100],date_naissance[100],niveau[100],block[100],telephone[100],s1[100],s2[100],s3[100],s4[100],s5[100];
FILE *f,*fw;
f=fopen(fname,"r");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone)!=EOF)
{
n=atoi(niveau);
switch (n)
{

case 1 : c1+=1;
            break;

case 2 : c2+=1;
            break;

case 3 : c3+=1;
            break;

case 4 : c4+=1;
            break;

default : c5+=1;
            break;
}

}
fclose(f);
sprintf(s1,"%d",c1);
sprintf(s2,"%d",c2);
sprintf(s3,"%d",c3);
sprintf(s4,"%d",c4);
sprintf(s5,"%d",c5);
fw=fopen("niveau.txt","w");
fprintf(fw,"%s %s %s %s %s\n",s1,s2,s3,s4,s5);
fclose(fw);
}

enum
{
	col1,
	col2,
	col3,
	col4,
	col5,
	COL,
};
void afficherniveau(char fname [],GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char c1 [100];
char c2 [100];
char c3 [100];
char c4 [100];
char c5 [100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("1ere annee",renderer,"text",col1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("2eme annee",renderer,"text",col2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("3eme annee",renderer,"text",col3,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("4eme annee",renderer,"text",col4,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("5eme annee",renderer,"text",col5,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COL,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen(fname,"r");
if (f==NULL)
{
return;
}
else
{f=fopen(fname,"a+");
	while(fscanf(f,"%s %s %s %s %s\n",c1,c2,c3,c4,c5)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,col1,c1,col2,c2,col3,c3,col4,c4,col5,c5,-1);	 		      
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}
int is_unique(char fname[], char identifiant [])
{
FILE *f;
int x=1;
char cin[100],nom[100],prenom[100],sex[100],date_naissance[100],niveau[100],block[100],telephone[100];
f=fopen(fname,"r");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone)!=EOF)
{
if((strcmp(cin,identifiant))==0) x=-1;
}
return x;
}

