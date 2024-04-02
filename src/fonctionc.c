#include <stdio.h>
#include <stdlib.h>
#include "fonctionc.h"
#include <gtk/gtk.h>
#include <string.h>
enum
{
	ID,
	T,
	L,
	VMIN,
	VMAX,
	ETAT,
	COL
	
};
enum
{
	EJOUR,
	EHEURE,
	ETEMP,
	COLUMNS
	
};
enum
{
	STYPE,
	SJOUR,
	SHEURE,
	SETAGE,
	COLUMNSS
};

void caajouter(Capts C)
{
    FILE* f;
    
    f=fopen("capteurs.txt","a+");
    if (f!=NULL)
    {
        
        
        fprintf(f,"%s %s %s %i %i %i \n",C.nom,C.type,C.localisation,C.valmin,C.valmax,C.etat);
        fclose(f);

    }
    else
    {
      printf("impossible d'ouvrir le fichier");
    }
}

void caajouter_nom()
{
   FILE* fx;
   FILE* f;
    Capts C;
    fx=fopen("nomcapteurs.txt","w");
    f=fopen("capteurs.txt","r");
    while(fscanf(f,"%s %s %s %i %i %i ",C.nom,C.type,C.localisation,&C.valmin,&C.valmax,&C.etat)!=(EOF))
     {
     fprintf(fx,"%s \n",C.nom);
     
     }
     fclose(f);
     fclose(fx);

}

/////////
void camodifier(Capts cm)
{

    FILE* f;
    FILE* ft;
    Capts C;

    
    f=fopen("capteurs.txt","r");
    ft=fopen("tmp.txt","a+");

     while((fscanf(f,"%s %s %s %i %i %i",C.nom,C.type,C.localisation,&C.valmin,&C.valmax,&C.etat))!=(EOF))
        {
        if (strcmp(C.nom,cm.nom)!=0){fprintf(ft,"%s %s %s %i %i %i \n",C.nom,C.type,C.localisation,C.valmin,C.valmax,C.etat);}




        else
        {
            
            fprintf(ft,"%s %s %s %i %i %i \n",cm.nom,cm.type,cm.localisation,cm.valmin,cm.valmax,cm.etat);
        }
    }


fclose(f);
fclose(ft);
remove("capteurs.txt");
rename("tmp.txt","capteurs.txt");
}
/*void rechercher(Capts cr)
{
    FILE* f;
    FILE* ft;
    int reponse,x;
    Capts C;
    int jour;
    int heure;
    int etage;
    float temp;
    f=fopen("capteurs.txt","r");
    ft=fopen("temperature.txt","r");

    while((fscanf(f,"%i %s %i %i %i %i",&C.nom,C.type,&C.localisation,&C.valmin,&C.valmax,&C.etat))!=(EOF))
    {
        if(C.nom==name)
        {
            printf("nom= %i \n type= %s \n localisation=  %i \n valeur minimale=%i \n valeur maximale= %i \n etat=%i [0=non defectueux/1=defectueux] ",C.nom,C.type,C.localisation,C.valmin,C.valmax,C.etat);
            x=C.localisation;
            if(C.etat==0)
            {
                printf("etat=non defectueux");
                printf("voulez vous voir les valeurs de ce fichier? [1=oui/0=non");
                scanf("%i",&reponse);
                if(reponse==1)
                {
                    while((fscanf(ft,"%i %i %i %f",&jour,&heure,&etage,&temp))!=(EOF))
                    {
                        if(etage==x)
                        {
                            printf("jour= %i novembre     heure= %i h    etage= %i    temp= %f C \n",jour,heure,etage,temp);

                        }
                    }
                }
            }
            else if(C.etat==1)
                {
                    printf("etat= defectueux");
                    printf("voulez vous voir les valeurs de ce fichier? [1=oui/0=non");
                    scanf("%i",&reponse);
                    if(reponse==1)
                    {
                        while((fscanf(ft,"%i %i %i %f",&jour,&heure,&etage,&temp))!=(EOF))
                        {
                            if(etage==x)
                            {
                                printf("jour= %i novembre     heure= %i h    etage= %i    temp= %f C \n",jour,heure,etage,temp);

                            }
                        }
                    }
                }
            else {
                    printf("etat= [%i] indefinie",C.etat);
                    printf("voulez vous voir les valeurs de ce fichier? [1=oui/0=non");
                    scanf("%i",&reponse);
                    if(reponse==1)
                    {
                        while((fscanf(ft,"%i %i %i %f",&jour,&heure,&etage,&temp))!=(EOF))
                        {
                            if(etage==x)
                        {
                                printf("jour= %i novembre     heure= %i h    etage= %i    temp= %f C \n",jour,heure,etage,temp);

                            }
                        }
                    }
                  }
        }


    }

    fclose(f);
    fclose(ft);
}
*/
void casupprimer(char b[])
{
    FILE* f;
    FILE* ft;
    Capts C;
    f=fopen("capteurs.txt","r");
    ft=fopen("tmp.txt","a+");

    while((fscanf(f,"%s %s %s %i %i %i",C.nom,C.type,C.localisation,&C.valmin,&C.valmax,&C.etat))!=(EOF))
        {
        if ((strcmp(C.nom,b)!=0)){fprintf(ft,"%s %s %s %i %i %i \n",C.nom,C.type,C.localisation,C.valmin,C.valmax,C.etat);}
	 
        }


fclose(f);
fclose(ft);
remove("capteurs.txt");
rename("tmp.txt","capteurs.txt");
}
void cacheck()
{
FILE* ft;
FILE* fx;
FILE* f;
Capts C,C1,C2,C3,T1[1000],T2[1000];
int jour,a,heure,i,j,k,n,m;
float temp;
char etage[40];
f=fopen("capteurs.txt","r");
j=0;
n=1;
m=1;
while((fscanf(f,"%s %s %s %i %i %i",C.nom,C.type,C.localisation,&C.valmin,&C.valmax,&C.etat))!=(EOF))
{
	ft=fopen("temperature.txt","r");
	while((fscanf(ft,"%i %i %s %f",&jour,&heure,etage,&temp))!=(EOF))
	{
		if(strcmp(C.localisation,etage)==0)
		{
			if(temp<C.valmin||temp>C.valmax)
			{
				fx=fopen("temp.txt","a+");
				C.etat=1;
				fprintf(fx,"%s %s %s %i %i %i \n",C.nom,C.type,C.localisation,C.valmin,C.valmax,C.etat);
				fclose(fx);
			}
		}
	}
	fclose(ft);


}
fclose(f);
i=0;
fx=fopen("temp.txt","r");
while((fscanf(fx,"%s %s %s %i %i %i",C1.nom,C1.type,C1.localisation,&C1.valmin,&C1.valmax,&C1.etat))!=(EOF))
{
	T1[i]=C1;
	i++;
	n++;
}
fclose(fx);
f=fopen("capteurs.txt","r");
while((fscanf(f,"%s %s %s %i %i %i",C2.nom,C2.type,C2.localisation,&C2.valmin,&C2.valmax,&C2.etat))!=(EOF))
{
	T1[j]=C2;
	j++;
	m++;
}
fclose(f);
for (i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
		{
			if(strcmp(T2[i].nom,T1[j].nom)==0)
			{
				T2[i].etat=1;
			}
		}
	}
f=fopen("capteurs.txt","w");
for(k=0;k<m-1;k++)
{
	C3=T2[k];
	fprintf(f,"%s %s %s %i %i %i \n",C3.nom,C3.type,C3.localisation,C3.valmin,C3.valmax,C3.etat);
}
fclose(f);
remove("temp.txt");
}

void caafficher_detail(GtkWidget *liste, Capts C)
{
FILE* f;



GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkListStore *store;
GtkTreeIter iter;

int jour;
int heure;
int etage;
char loc[100];
char temp[20];
store=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Jour", renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Heure",renderer,"text",EHEURE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Temperature",renderer,"text",ETEMP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column); 
}
store=gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING);
f=fopen("temperature.txt","r");
while(fscanf(f,"%i %i %i %s",&jour,&heure,&etage,temp)!=EOF)
{	
	sprintf(loc,"%i",etage);
	if(strcmp(loc,C.localisation)==0)
	{	
		gtk_list_store_append (store, &iter);
		gtk_list_store_set(store, &iter, EJOUR, jour, EHEURE, heure, ETEMP , temp, -1);
		
	}
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);

}


void caafficher_securite(GtkWidget *liste)
{
FILE* fm;
FILE* ff;



GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkListStore *store;
GtkTreeIter iter;
char type1[20]="mouvement";
char type2[20]="fumée";
int jour;
int heure;
int etage;
int temp;
store=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Type", renderer,"text",STYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Jour", renderer,"text",SJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Heure",renderer,"text",SHEURE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Etage",renderer,"text",SETAGE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column); 
}
store=gtk_list_store_new(COLUMNSS,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);

ff=fopen("fumee.txt","r");
while(fscanf(ff,"%i %i %i %i",&jour,&heure,&etage,&temp)!=EOF)
{	
	
	if(temp==1)
	{	
		gtk_list_store_append (store, &iter);
		gtk_list_store_set(store, &iter, STYPE, type2, SJOUR, jour, SHEURE, heure, SETAGE , etage, -1);
		
	}
}
fclose(ff);
fm=fopen("mouvement.txt","r");
while(fscanf(fm,"%i %i %i %i",&jour,&heure,&etage,&temp)!=EOF)
{	
	
	if(temp==1)
	{	
		gtk_list_store_append (store, &iter);
		gtk_list_store_set(store, &iter,STYPE,type1, SJOUR, jour, SHEURE, heure, SETAGE , etage, -1);
		
	}
}
fclose(fm);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);

}
//////////////////

void caafficher_capts(GtkWidget *liste)
{
FILE* f;



GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkListStore *store;
GtkTreeIter iter;

Capts C1;
store=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",T,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Localisation",renderer,"text",L,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column); 

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Valeur minimale", renderer,"text",VMIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Valeur maximale", renderer,"text",VMAX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("etat", renderer,"text",ETAT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COL,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
f=fopen("capteurs.txt","r");
while(fscanf(f,"%s %s %s %i %i %i",C1.nom,C1.type,C1.localisation,&C1.valmin,&C1.valmax,&C1.etat)!=EOF)
{	
	
	gtk_list_store_append (store, &iter);
	gtk_list_store_set(store, &iter, ID, C1.nom, T, C1.type, L, C1.localisation, VMIN , C1.valmin, VMAX, C1.valmax, ETAT, C1.etat, -1);
		
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);

}
int verif(char log[], char Pw[],char fah[])
{
int trouve=0;
FILE *f=NULL;
char ch1[50];
char ch2[50];
char ch3[50];
f=fopen("utilisateur.txt","a+");
if(f!=NULL)
{
while (fscanf(f,"%s %s %s\n",ch1,ch2,ch3)!=EOF)
	{
		if((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0))
		{
			if((strcmp(fah,ch3)==0)) { trouve=1 ; break;} //1 jawek behi bro 
			else trouve=2;
		}//2==>mot de passe et log sont correctes mais l'accès a cette tache est impo
		//else{trouve=0;}	// nom utilisateur ou mot de passe incorrectes
	
	}
fclose(f);
}
return (trouve);
}

