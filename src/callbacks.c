#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctionc.h"
#include "menu.h"
#include "fonction.h"
#include "function.h"
#include "reclamation.h"
#include "user.h"
int sup = 1 ;
char ident1[10] ;
int choix;
int xa;
int r=0;
int rm=0;
Capts ca,cm,cra,Cr;
int x=0,y=0,z=0;

void FJsendmail(char body[])
{
        char cmd[300];
        FILE *fp = fopen("mail.txt","w+"); // open it for writing.
        fprintf(fp,"%s\n",body);        // write body to it.
        fclose(fp);             // close it.

        sprintf(cmd,"curl smtps://smtp.gmail.com:465 -v --mail-from \"stockproduit@gmail.com:Produit12345678\" --mail-rcpt \"mohamedfadhel.jaiet@esprit.tn\" --ssl -u stockproduit@gmail.com:Produit12345678 -T mail.txt -k --anyauth"); // prepare command.
        system(cmd);     // execute it.
}

int s=1;
void
on_rbfemme_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) s=0;
}


void
on_rbhomme_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) s=1;
}


void
on_entrycinaj_grab_focus               (GtkWidget       *widget,
                                        gpointer         user_data)
{
GtkWidget* input0;
GtkWidget* input1;
input0= lookup_widget(widget, "comboboxniveauaj");
input1= lookup_widget(widget, "comboboxblockaj");
gtk_combo_box_set_active(GTK_COMBO_BOX(input0),0);
gtk_combo_box_set_active(GTK_COMBO_BOX(input1),0);
}

void
on_Ajouter_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* input1;
GtkWidget* input2;
GtkWidget* input3;
GtkWidget* input4;
GtkWidget* input5;
GtkWidget* input6;
GtkWidget* input7;
GtkWidget* input8;
GtkWidget* input9;
input1= lookup_widget(objet_graphique, "entrycinaj");
input2= lookup_widget(objet_graphique, "entrynomaj");
input3= lookup_widget(objet_graphique, "entryprenomaj");
input4= lookup_widget(objet_graphique, "comboboxniveauaj");
input5= lookup_widget(objet_graphique, "comboboxblockaj");
input6= lookup_widget(objet_graphique, "entrytelephoneaj");
input7= lookup_widget(objet_graphique, "spinbuttonjouraj");
input8= lookup_widget(objet_graphique, "spinbuttonmoisaj");
input9= lookup_widget(objet_graphique, "spinbuttonanneeaj");
char c [100];
char n [100];
char p  [100];
char sex [100];
char niv [100];
char b [100];
char tel [100];
int j;
int m;
int a;
char sj [100];
char sm [100];
char sa [100];
char dn [100];
int unique;
strcpy(c,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(n,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p,gtk_entry_get_text(GTK_ENTRY(input3)));
if (s==0) strcpy(sex,"femme");
else strcpy(sex,"homme");
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
sprintf(sj,"%d",j);
sprintf(sm,"%d",m);
sprintf(sa,"%d",a);
strcat(sj,"/");
strcat(sm,"/");
strcat(sm,sa);
strcat(sj,sm);
strcpy(dn,sj);
strcpy(niv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
strcpy(b,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
strcpy(tel,gtk_entry_get_text(GTK_ENTRY(input6)));

etudiant_heberge e;
strcpy(e.cin,c);
strcpy(e.nom,n);
strcpy(e.prenom,p);
strcpy(e.sex,sex);
strcpy(e.date_naissance,dn);
strcpy(e.niveau,niv);
strcpy(e.block,b);
strcpy(e.telephone,tel);
if((strlen(e.cin)==0)||(strlen(e.nom)==0)||(strlen(e.prenom)==0)||(strlen(e.telephone)==0))
{
GtkWidget *windowerror1;
windowerror1=create_windowerror1();
gtk_widget_show(windowerror1);
}
else
{
unique=is_unique("etudiants.txt",e.cin);
if((unique==-1))
{
GtkWidget *windowerror2;
windowerror2=create_windowerror2();
gtk_widget_show(windowerror2);
}
else
{
if((unique==1)&&(strlen(e.cin)!=0)&&(strlen(e.nom)!=0)&&(strlen(e.prenom)!=0)&&(strlen(e.telephone)!=0))
{
ajouter("etudiants.txt",e);
GtkWidget *windowok;
windowok=create_windowok();
gtk_widget_show(windowok);
}
}
}
}
void
on_afficheraj_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowgestionetudiant;
GtkWidget *windowafficher;
GtkWidget *treeview1;
windowgestionetudiant=lookup_widget(objet_graphique,"windowgestionetudiant");
gtk_widget_destroy(windowgestionetudiant);
windowafficher=lookup_widget(objet_graphique,"windowafficher");
windowafficher=create_windowafficher();
gtk_widget_show(windowafficher);
treeview1=lookup_widget(windowafficher,"treeview1");
afficher("etudiants.txt",treeview1);
}
int choixxx[5]={0,0};
void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
 choixxx[0]=1;

}
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
choixxx[1]=1;

}
}


void
on_rechercher_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

if ((choixxx[0]==1)&&(choixxx[1]==0))
{
GtkWidget* input10;
char c [100];
input10= lookup_widget(objet_graphique, "entrycinre");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(input10)));
rechercher("etudiants.txt",c);
GtkWidget *windowafficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(objet_graphique,"windowafficher");
windowafficher=create_windowafficher();
gtk_widget_show(windowafficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(windowafficher,"treeview1");
afficher("etudiants_recherchee.txt",treeview1);
choixxx[0]=0;
choixxx[1]=0;
}
else 
{
if ((choixxx[0]==0)&&(choixxx[1]==1))
{
GtkWidget* input11;
char b [100];
input11= lookup_widget(objet_graphique, "entryblockre");
strcpy(b,gtk_entry_get_text(GTK_ENTRY(input11)));
FILE *f, *fw;
char cin[100],nom[100],prenom[100],sex[100],date_naissance[100],niveau[100],block[100],telephone[100];
f=fopen("etudiants.txt","r");
fw=fopen("etudiants_recherchee.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone)!=EOF)
{
if((strcmp(block,b))==0) fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone);
}
fclose(f);
fclose(fw);
GtkWidget *windowafficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(objet_graphique,"windowafficher");
windowafficher=create_windowafficher();
gtk_widget_show(windowafficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(windowafficher,"treeview1");
afficher("etudiants_recherchee.txt",treeview1);
choixxx[0]=0;
choixxx[1]=0;
}
else 
{
if ((choixxx[0]==1)&&(choixxx[1]==1))
{
GtkWidget* input0;
GtkWidget* input1;
char CIN [100];
char BLOCK [100];
input0= lookup_widget(objet_graphique, "entrycinre");
input1= lookup_widget(objet_graphique, "entryblockre");
strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(input0)));
strcpy(BLOCK,gtk_entry_get_text(GTK_ENTRY(input1)));
FILE *f, *fw;
char cin[100],nom[100],prenom[100],sex[100],date_naissance[100],niveau[100],block[100],telephone[100];
f=fopen("etudiants.txt","r");
fw=fopen("etudiants_recherchee.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone)!=EOF)
{
if((strcmp(block,BLOCK)==0)&&(strcmp(cin,CIN)==0)) fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,sex,date_naissance,niveau,block,telephone);
}
fclose(f);
fclose(fw);
GtkWidget *windowafficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(objet_graphique,"windowafficher");
windowafficher=create_windowafficher();
gtk_widget_show(windowafficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(windowafficher,"treeview1");
afficher("etudiants_recherchee.txt",treeview1);
choixxx[0]=0;
choixxx[1]=0;
}
}
}
}


etudiant_heberge e;
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *cin;
gchar *nom;
gchar *prenom;
gchar *sex;
gchar *date_naissance;
gchar *niveau;
gchar *block;
gchar *telephone;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cin,1,&nom,2,&prenom,3,&sex,4,&date_naissance,5,&niveau,6,&block,7,&telephone,-1);
strcpy(e.cin,cin);
strcpy(e.nom,nom);
strcpy(e.prenom,prenom);
strcpy(e.sex,sex);
strcpy(e.date_naissance,date_naissance);
strcpy(e.niveau,niveau);
strcpy(e.block,block);
strcpy(e.telephone,telephone);
}
}

void
on_supprimeraf_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
supprimer("etudiants.txt",e.cin);
}

void
on_entrynommo_grab_focus               (GtkWidget       *widget,
                                        gpointer         user_data)
{
GtkWidget* widget1;
GtkWidget* widget2;
GtkWidget* widget3;
GtkWidget* widget4;
GtkWidget* widget5;
GtkWidget* widget6;
GtkWidget* widget7;
GtkWidget* widget8;
GtkWidget* widget9;
GtkWidget* widgeth;
GtkWidget* widgetf;
widget1=lookup_widget(widget, "entrynommo");
gtk_entry_set_text(GTK_ENTRY(widget1),e.nom);
widget2= lookup_widget(widget, "comboboxniveaumo");
widget3= lookup_widget(widget, "comboboxblockmo");
int n=0,b=0;
n=atoi(e.niveau);
b=atoi(e.block);
gtk_combo_box_set_active(GTK_COMBO_BOX(widget2),n-1);
gtk_combo_box_set_active(GTK_COMBO_BOX(widget3),b-1);
widget4=lookup_widget(widget, "entrytelephonemo");
gtk_entry_set_text(GTK_ENTRY(widget4),e.telephone);
widget5=lookup_widget(widget, "entryprenommo");
gtk_entry_set_text(GTK_ENTRY(widget5),e.prenom);
widgeth=lookup_widget(widget, "rbhommemo");
widgetf=lookup_widget(widget, "rbfemmemo");
if(strcmp(e.sex,"homme")==0) gtk_toggle_button_set_active(GTK_RADIO_BUTTON(widgeth),TRUE);
if(strcmp(e.sex,"femme")==0) gtk_toggle_button_set_active(GTK_RADIO_BUTTON(widgetf),TRUE);
int p_occ=-1,d_occ=0;
pos_car(e.date_naissance,'/',&p_occ,&d_occ);
int i;
char j [3];
for(i=0;i<p_occ;i++) j[i]=e.date_naissance[i];
j[p_occ]='\0';
int ij=0;
ij=atoi(j);
widget7=lookup_widget(widget, "spinbuttonjourmo");
gtk_spin_button_set_value(widget7,ij);
char m [3];
for(i=p_occ+1;i<d_occ;i++) m[i-p_occ-1]=e.date_naissance[i];
m[d_occ-p_occ-1]='\0';
int im=0;
im=atoi(m);
widget8=lookup_widget(widget, "spinbuttonmoismo");
gtk_spin_button_set_value(widget8,im);
char a [5];
for(i=d_occ+1;i<strlen(e.date_naissance);i++) a[i-d_occ-1]=e.date_naissance[i];
a[strlen(e.date_naissance)-d_occ-1]='\0';
int ia=0;
ia=atoi(a);
widget9=lookup_widget(widget, "spinbuttonanneemo");
gtk_spin_button_set_value(widget9,ia);
}

void
on_modifieraf_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *windowmodifier;
windowmodifier=lookup_widget(objet_graphique,"windowmodifier");
windowmodifier=create_windowmodifier();
gtk_widget_show(windowmodifier);
}

int m=1;
void
on_rbhommemo_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) m=1;
}


void
on_rbfemmemo_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) m=0;
}

void
on_enregistrer_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget* input2;
GtkWidget* input3;
GtkWidget* input4;
GtkWidget* input5;
GtkWidget* input6;
GtkWidget* input7;
GtkWidget* input8;
GtkWidget* input9;

input2= lookup_widget(objet_graphique, "entrynommo");
input3= lookup_widget(objet_graphique, "entryprenommo");
input4= lookup_widget(objet_graphique, "comboboxniveaumo");
input5= lookup_widget(objet_graphique, "comboboxblockmo");
input6= lookup_widget(objet_graphique, "entrytelephonemo");
input7= lookup_widget(objet_graphique, "spinbuttonjourmo");
input8= lookup_widget(objet_graphique, "spinbuttonmoismo");
input9= lookup_widget(objet_graphique, "spinbuttonanneemo");
char c [100];
char n [100];
char p  [100];
char sex [100];
char niv [100];
char b [100];
char tel [100];
int j;
int m;
int a;
char sj [100];
char sm [100];
char sa [100];
char dn [100];

strcpy(n,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p,gtk_entry_get_text(GTK_ENTRY(input3)));
if (m==0) strcpy(sex,"femme");
else strcpy(sex,"homme");
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
sprintf(sj,"%d",j);
sprintf(sm,"%d",m);
sprintf(sa,"%d",a);
strcat(sj,"/");
strcat(sm,"/");
strcat(sm,sa);
strcat(sj,sm);
strcpy(dn,sj);
strcpy(niv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
strcpy(b,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
strcpy(tel,gtk_entry_get_text(GTK_ENTRY(input6)));

etudiant_heberge ne;
strcpy(ne.cin,e.cin);
strcpy(ne.nom,n);
strcpy(ne.prenom,p);
strcpy(ne.sex,sex);
strcpy(ne.date_naissance,dn);
strcpy(ne.niveau,niv);
strcpy(ne.block,b);
strcpy(ne.telephone,tel);
modifier("etudiants.txt",ne,e.cin);
}

void
on_actualiser_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowafficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(objet_graphique,"windowafficher");
windowafficher=create_windowafficher();
gtk_widget_show(windowafficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(windowafficher,"treeview1");
afficher("etudiants.txt",treeview1);
}

void
on_retour_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowgestionetudiant,*windowafficher;
windowafficher=lookup_widget(objet_graphique,"windowafficher");
gtk_widget_destroy(windowafficher);
windowgestionetudiant=create_windowgestionetudiant();
gtk_widget_show(windowgestionetudiant);
}




void
on_niveau_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
nbr_etudiant_niveau("etudiants.txt");
GtkWidget *windowafficher;
GtkWidget *windowafficherniveau;
GtkWidget *treeview2;
windowafficher=lookup_widget(objet_graphique,"windowafficher");
gtk_widget_destroy(windowafficher);
windowafficherniveau=lookup_widget(objet_graphique,"windowafficherniveau");
windowafficherniveau=create_windowafficherniveau();
gtk_widget_show(windowafficherniveau);
treeview2=lookup_widget(windowafficherniveau,"treeview2");
afficherniveau("niveau.txt",treeview2);
}


void
on_retourniveau_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowafficher,*windowafficherniveau;
windowafficherniveau=lookup_widget(objet_graphique,"windowafficherniveau");
gtk_widget_destroy(windowafficherniveau);
windowafficher=create_windowafficher();
gtk_widget_show(windowafficher);

}


void
on_fobuttonmeilleur_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{

FILE* f;

FILE* fm;

int a,b,na,nb;

float c,nc=1000.00;

  int l;

    char nom[25];

    char type[20];

    char entree[30];

    char suite[30];

    char dessert[30];

    char str[25];

    char date[10];

    char id[10];

char text[15];

char msg[100];
strcpy(msg,"le meilleur menu est ");

GtkWidget *sortie;

sortie=lookup_widget(button,"folabelme1");

// GtkWidget *fomeilleur;

f=fopen("dechet.txt","r");

while(fscanf(f,"%d %d %f\n",&a,&b,&c)!=EOF){



  if (nc>c){nc=c;

  nb=b;

  na=a;                 }

}

sprintf(text,"%d",na);

fm=fopen("menu.txt","r");



while(fscanf(fm,"%s %s %s %s %s %s %s\n",id,nom,type,entree,suite,dessert,date)!=EOF){

   







if (strcmp(type,"petit_dej")==0){l=1;}

else if (strcmp(type,"repas")==0){l=2;}

else if (strcmp(type,"dinner")==0){l=3;}









if ((strcmp(date,text)==0) && (nb==l)){ 



strcat(msg,nom);

 gtk_label_set_text(GTK_LABEL(sortie),msg);}

}







fclose(fm);

fclose(f);













}
void
on_fobuttoncherche2_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
   GtkWidget *input; 
//*sortie;
   char text[10];
//char msg[100];
input = lookup_widget(button,"foentrycherche");
//sortie=lookup_widget(button,"folabelmescher");
strcpy(text,gtk_entry_get_text(GTK_ENTRY(input)));
fochercher(text);
/*if (chercher(text)==1) {strcpy(msg,"le menu existe");}
else {strcpy(msg,"le menu n'existe pas");}
gtk_label_set_text(GTK_LABEL(sortie),msg);*/
GtkWidget *fowindowchercher,*w1;
GtkWidget *fotreeview2;
w1=lookup_widget(button,"fowindowchercher");
fowindowchercher=create_fowindowchercher();
gtk_widget_show(fowindowchercher);
gtk_widget_hide(w1);
fotreeview2=lookup_widget(fowindowchercher,"fotreeview2");
foafficher("menurecherche.txt",fotreeview2);

}




void
on_fobuttonchercher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *fowindowchercher;
 fowindowchercher = create_fowindowchercher ();
  gtk_widget_show (fowindowchercher);
}



void
on_fobuttonaficher_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fowindowaffiche;
GtkWidget *fotreeview1;

fowindowaffiche=lookup_widget(objet,"fowindowaffiche");
fowindowaffiche=create_fowindowaffiche();


gtk_widget_show(fowindowaffiche);

fotreeview1=lookup_widget(fowindowaffiche,"fotreeview1");
foafficher("menu.txt",fotreeview1);
}


void
on_fotreeview1_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
gchar* id;
gchar* nom;
gchar* type;
gchar* entree;
gchar* suite;
gchar* dessert;
gchar* date;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&type,3,&entree,4,&suite,5,&dessert,6,&date,-1);



strcpy(ident1,id);}
}



void
on_fobuttonajout1_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *fowindowajouter;
 fowindowajouter = create_fowindowajouter ();
  gtk_widget_show (fowindowajouter);

}


void
on_fobuttondelete_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fowindowsupp;
  fowindowsupp = create_fowindowsupp ();
  gtk_widget_show (fowindowsupp);
}




void
on_fobuttonmodifier1_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fowindowmodifier;



 fowindowmodifier = create_fowindowmodifier ();
  
 gtk_widget_show (fowindowmodifier);
}

void
on_fobuttonretour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fowindowaffiche,*fowindowen; 
fowindowaffiche=lookup_widget(button,"fowindowaffiche"); 
gtk_widget_destroy(fowindowaffiche); 
fowindowen=create_fowindowen(); 
gtk_widget_show(fowindowen);

}


void
on_foradiop_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=1;
}


void
on_foradior_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=2;
}


void
on_foradiod_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=3;
}




void
on_fobuttonajoutermenu_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
menu m;
GtkWidget *input1,*input2,*spin,*input4,*input5,*input6,*input7;
GtkWidget *fowindowajouter;
char typea[20],date1[10];
int a;

fowindowajouter=lookup_widget(objet,"fowindowajouter");

input1=lookup_widget(objet,"foentryaid");
input2=lookup_widget(objet,"foentryanom");
if (choix==1){strcpy(typea,"petit_dej");}
if (choix==2){strcpy(typea,"repas");}
if (choix==3){strcpy(typea,"dinner");}


input4=lookup_widget(objet,"foentryaentree");
input5=lookup_widget(objet,"foentryasuite");
input6=lookup_widget(objet,"foentryadessert");

//input7=lookup_widget(objet,"entry2");

spin = lookup_widget(objet,"fospinbutton1");
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin));
sprintf(date1,"%d",a);



strcpy(m.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(m.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(m.type,typea);
strcpy(m.entree,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(m.suite,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(m.dessert,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(m.date,date1);
foajouter(m);
choix=0;

}

gboolean
on_fowindowmodifier_focus_in_event     (GtkWidget       *button,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
FILE* f;
    
    char id[10];
    char date[10];
    char nom[25];
    char type[20];
    char entree[30];
    char suite[30];
    char dessert[30];
    GtkWidget *input, *input1; 
    int a;


GtkWidget *combobox, *spin;
input1 = lookup_widget(button,"focomboboxentrymtype");
input = lookup_widget(button,"foentrymid");
spin = lookup_widget(button,"fospinbuttonmdate");
f=fopen("menu.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s\n",id,nom,type,entree,suite,dessert,date)!=EOF){
if (strcmp(id,ident1)==0){
gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"foentrymid")),ident1);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"foentrymnom")),nom);            
gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"foentrymentree")),entree);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"foentrymsuite")),suite);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"foentrymdessert")),dessert);
if(strcmp(type,"repas")==0) {a=1;}
else if (strcmp(type,"dinner")==0){a=2;}
else {a=0;}
gtk_combo_box_set_active(GTK_COMBO_BOX(input1),a);
gtk_spin_button_set_value(spin,atoi(date));


}
}

fclose(f);
  return FALSE;
}

void
on_fobuttonenregistrer_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
FILE* ft;
FILE* f;
    char id[10];
    char date[10];
    char nom[25];
    char type[20];
    char entree[30];
    char suite[30];
    char dessert[30];
    char id1[10];
    char date1[10];
    char nom1[25];
    char type1[20];
    char entree1[30];
    char suite1[30];
    char dessert1[30];
   int a;
GtkWidget *combobox, *spin;
GtkWidget *input2, *input1, *input3, *input4, *input5;
spin = lookup_widget(button,"fospinbuttonmdate");
combobox = lookup_widget(button,"focomboboxentrymtype");
input1 = lookup_widget(button,"foentrymid");
input2 = lookup_widget(button,"foentrymnom");
input3 = lookup_widget(button,"foentrymentree");
input4 = lookup_widget(button,"foentrymsuite");
input5 = lookup_widget(button,"foentrymdessert");
//
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin));
sprintf(date1,"%d",a);

strcpy(type1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox))) ;

strcpy(id1,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(nom1,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(entree1,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(suite1,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(dessert1,gtk_entry_get_text(GTK_ENTRY(input5)));




f=fopen("menu.txt","r");
ft=fopen("tmp.txt","ab+");
while(fscanf(f,"%s %s %s %s %s %s %s\n",id,nom,type,entree,suite,dessert,date)!=EOF){



if (strcmp(id,id1)==0) {fprintf(ft,"%s %s %s %s %s %s %s\n",id1,nom1,type1,entree1,suite1,dessert1,date1);}

else {fprintf(ft,"%s %s %s %s %s %s %s\n",id,nom,type,entree,suite,dessert,date);}
}

fclose(f);
fclose(ft);
remove("menu.txt");
rename("tmp.txt","menu.txt");
}


void
on_focheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}





gboolean
on_fowindowsupp_focus_in_event         (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_fobuttonsupp_clicked                (GtkWidget       *button,
                                        gpointer         user_data)

{  
char a[10];
strcpy(a,ident1);
fosupprimer(a);}
char fah[50];

void
on_cabuttonlogin_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *username, *password, *windowEspaceAdmin, *dest;
GtkWidget* niggas;
niggas = lookup_widget(button,"calabelerror404");

char user[20];
char pasw[20];
int trouve;
username = lookup_widget (button,"caentryusername");
password = lookup_widget (button,"caentrypassword");

strcpy(user, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw, gtk_entry_get_text(GTK_ENTRY(password)));
trouve=verif(user,pasw,fah);

if(trouve==1)
{
if (strcmp(fah,"adm")==0)
{
dest=create_cawindowlogin();
gtk_widget_destroy (dest);
windowEspaceAdmin=create_bk_welcome();
gtk_widget_show (windowEspaceAdmin);
}
if (strcmp(fah,"tec")==0)
{
dest=create_cawindowlogin();
gtk_widget_destroy (dest);
windowEspaceAdmin=create_cawindowet();
gtk_widget_show (windowEspaceAdmin);
}
else if (strcmp(fah,"nut")==0)
{
dest=create_cawindowlogin();
gtk_widget_destroy (dest);
windowEspaceAdmin=create_fowindowen();
gtk_widget_show (windowEspaceAdmin);
}
else if (strcmp(fah,"adr")==0)
{
dest=create_cawindowlogin();
gtk_widget_destroy (dest);
windowEspaceAdmin=create_FJafficher21();
gtk_widget_show (windowEspaceAdmin);
}
else if (strcmp(fah,"adf")==0)
{
dest=create_cawindowlogin();
gtk_widget_destroy (dest);
windowEspaceAdmin=create_windowafficher();
gtk_widget_show (windowEspaceAdmin);
}
else if (strcmp(fah,"srv")==0)
{
dest=create_cawindowlogin();
gtk_widget_destroy (dest);
windowEspaceAdmin=create_aowindow_consult();
gtk_widget_show (windowEspaceAdmin);
}
}
else if(trouve==2){gtk_label_set_text(GTK_LABEL(niggas),"vous n'avez pas accés à cette tache");}
else if (trouve==0){gtk_label_set_text(GTK_LABEL(niggas),"mot de passe ou nom d'utilisateur incorrecte");}
}


void
on_acbgdcrech_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* windowretourmodifierunapteur;
GtkWidget* closegdcre;
closegdcre= lookup_widget(button,"cawindowgdc");
gtk_widget_destroy(closegdcre);

windowretourmodifierunapteur=create_acwrechercher();
gtk_widget_show (windowretourmodifierunapteur);
}


void
on_cabuttonajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* windowajouterunapteur;
GtkWidget* closegdcaj;
closegdcaj= lookup_widget(button,"cawindowgdc");
gtk_widget_destroy(closegdcaj);

windowajouterunapteur=create_cawindowajouter();
gtk_widget_show (windowajouterunapteur);
}


void
on_cabuttonmodifier_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* windowmoderunapteur;
GtkWidget* closegdcmo;
closegdcmo= lookup_widget(button,"cawindowgdc");
gtk_widget_destroy(closegdcmo);
windowmoderunapteur=create_cawindowmodifier();
gtk_widget_show (windowmoderunapteur);
}


void
on_cabuttonsupprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* windowsupperunapteur;
GtkWidget* closegdcsu;
closegdcsu= lookup_widget(button,"cawindowgdc");
gtk_widget_destroy(closegdcsu);

windowsupperunapteur=create_acwindowsupprimer();
gtk_widget_show (windowsupperunapteur);
}


void
on_cabuttongdcretour_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* windowgdcretour;
GtkWidget* closegdcet;
closegdcet= lookup_widget(button,"cawindowgdc");
gtk_widget_destroy(closegdcet);
windowgdcretour=create_cawindowet();
gtk_widget_show (windowgdcretour);
}


void
on_caatreeviewgdc_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *nom;
gchar *type;
gchar *localisation;
gint *valmin;
gint *valmax;
gint *etat;


GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&type,2,&localisation,3,&valmin,4,&valmax,5,&etat,-1);
	strcpy(cra.nom,nom);
	strcpy(cra.type,type);
	strcpy(cra.localisation,localisation);
	cra.valmin=valmin;
	cra.valmax=valmax;
	cra.etat=etat;

}
}


void
on_treeviewtrax_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_cabuttonsretour_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* windowsretour;
GtkWidget* closeldaet;
closeldaet= lookup_widget(button,"cawindowsecurit__");
gtk_widget_destroy(closeldaet);
windowsretour=create_cawindowet();
gtk_widget_show (windowsretour);
}


void
on_cabuttongdc_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* cawindowgdc;
GtkWidget* treeviewtr;
GtkWidget* cawindowet1;

cawindowet1=lookup_widget(objet_graphique,"cawindowet");
gtk_widget_destroy(cawindowet1);
cawindowgdc=lookup_widget(objet_graphique,"cawindowgdc");
cawindowgdc=create_cawindowgdc();
gtk_widget_show (cawindowgdc);
treeviewtr = lookup_widget(cawindowgdc,"caatreeviewgdc");
caafficher_capts(treeviewtr);
}


void
on_cabuttons__curit___clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* cawindowsecurit__;
GtkWidget* treeviewtrax;
GtkWidget* cawindowet;

cawindowet=lookup_widget(objet_graphique,"cawindowet");
gtk_widget_destroy(cawindowet);
cawindowsecurit__=lookup_widget(objet_graphique,"cawindowsecurit__");
cawindowsecurit__=create_cawindowsecurit__();
gtk_widget_show (cawindowsecurit__);
treeviewtrax = lookup_widget(cawindowsecurit__,"treeviewtrax");
caafficher_securite(treeviewtrax);
}


void
on_cabuttonquitter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* cawindowgdc;
GtkWidget* treeviewtr;
GtkWidget* cawindowet1;

cawindowet1=lookup_widget(button,"cawindowajouter");
gtk_widget_destroy(cawindowet1);
cawindowgdc=lookup_widget(button,"cawindowgdc");
cawindowgdc=create_cawindowgdc();
gtk_widget_show (cawindowgdc);
treeviewtr = lookup_widget(cawindowgdc,"caatreeviewgdc");
caafficher_capts(treeviewtr);
}


void
on_button7_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* input1;
GtkWidget* combobox1;
GtkWidget* input2;
GtkWidget* output3;
GtkWidget* output4;
GtkWidget* Casbavmin;
GtkWidget* Caspinbuttonvmax;
FILE* fg;
int g;
char nom[100];
char localisation[100];
char nomver[100];
char existe1[100]="Cet identifiant existe";
char existe0[100]="  ";
char success[100]="ajout avec succès";

input1 = lookup_widget(objet_graphique,"caentryandc");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(ca.nom,nom);

combobox1 = lookup_widget(objet_graphique,"accbmvald3");
if(strcmp("temperature",gtk_combo_box_get_active_text (GTK_COMBO_BOX(combobox1)))==0){strcpy(ca.type,"temperature");}
else if(strcmp("mouvement",gtk_combo_box_get_active_text (GTK_COMBO_BOX(combobox1)))==0){strcpy(ca.type,"mouvement");}
else if(strcmp("déchet",gtk_combo_box_get_active_text (GTK_COMBO_BOX(combobox1)))==0){strcpy(ca.type,"déchet");}
else if(strcmp("débit",gtk_combo_box_get_active_text (GTK_COMBO_BOX(combobox1)))==0){strcpy(ca.type,"débit");}
else if(strcmp("fumée",gtk_combo_box_get_active_text (GTK_COMBO_BOX(combobox1)))==0){strcpy(ca.type,"fumée");}

input2 = lookup_widget(objet_graphique,"caentryalocalisation");
strcpy(localisation,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(ca.localisation,localisation);

Casbavmin = lookup_widget(objet_graphique,"casbavmin");
ca.valmin=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Casbavmin));
Caspinbuttonvmax = lookup_widget(objet_graphique,"caspinbuttonvmax");
ca.valmax=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Caspinbuttonvmax));
ca.etat=0;
output3 = lookup_widget(objet_graphique,"aclabacne");
output4 = lookup_widget(objet_graphique,"aclaas");


fg=fopen("capteurs.txt","r");
while(fscanf(fg,"%s %s %s %i %i %i ",Cr.nom,Cr.type,Cr.localisation,&Cr.valmin,&Cr.valmax,&Cr.etat)!=(EOF))
	{if(strcmp(Cr.nom,ca.nom)==0)
		{
			gtk_label_set_text(GTK_LABEL(output3),existe1);
			gtk_label_set_text(GTK_LABEL(output4),existe0);
			g=0;
			break;
		}
	else if(strcmp(Cr.nom,nomver)!=0)
		{
			gtk_label_set_text(GTK_LABEL(output3),existe0);
			gtk_label_set_text(GTK_LABEL(output4),success);
			g=1;
		}
	}
fclose(fg);

char trax[300]="un capteur a été  ajouté avec succès";
if(g==1){
		caajouter(ca);
		casendmail(trax);
	}
//cacheck();
}




gboolean
on_cawindowmodifier_focus_in_event     (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
GtkWidget* input1;
input1 = lookup_widget(widget,"caentrymdone");
gtk_entry_set_text(GTK_ENTRY(input1),cra.nom);
  return FALSE;
}


void
on_caentrymdone_changed                (GtkEditable     *editable,
                                        gpointer         user_data)
{
FILE* ft;
Capts C;
char nom[100];
char debit[20]="débit";
char dechet[20]="déchet";
char fumee[20]="fumée";
char temp[20]="temperature";
char mouv[20]="mouvement";
GtkWidget* input1;
GtkWidget* output1 ;
GtkWidget* output2 ;
GtkWidget* output3 ;
GtkWidget* output4 ;
GtkWidget* output5 ;
GtkWidget* output6 ;
GtkWidget* output7 ;
GtkWidget* output8 ;
GtkWidget* output9 ;

ft=fopen("capteurs.txt","r");
input1 = lookup_widget(editable,"caentrymdone");
output1 = lookup_widget(editable, "caentrymnom") ;
output2 = lookup_widget(editable, "caentrymlocalisation") ;
output3 = lookup_widget(editable, "caspinbuttonmvalmin") ;
output4 = lookup_widget(editable, "casbvm") ;
output5 = lookup_widget(editable, "caradiobuttonmdechet") ;
output6 = lookup_widget(editable, "caradiobuttondebit") ;
output7 = lookup_widget(editable, "caradiobuttonmfumee") ;
output8 = lookup_widget(editable, "caradiobuttonmtemp") ;
output9 = lookup_widget(editable, "caradiobuttonmmouv") ;
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
while(fscanf(ft,"%s %s %s %i %i %i ",C.nom,C.type,C.localisation,&C.valmin,&C.valmax,&C.etat)!=(EOF))
     {if(strcmp(C.nom,nom)==0)
			{
			gtk_entry_set_text(GTK_ENTRY(output1),C.nom);
			gtk_entry_set_text(GTK_ENTRY(output2),C.localisation);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output3),C.valmin);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output4),C.valmax);
			if(strcmp(C.type,debit)==0){gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output6),TRUE);}
			else if (strcmp(C.type,dechet)==0){gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output5),TRUE);}
			else if (strcmp(C.type,fumee)==0){gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output7),TRUE);}
			else if (strcmp(C.type,temp)==0){gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output8),TRUE);}
			else if (strcmp(C.type,mouv)==0){gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output9),TRUE);}
		 	}
}
fclose(ft);	
}


void
on_caradiobuttonmdechet_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	strcpy(cm.type,"déchet");
}
}


void
on_caradiobuttondebit_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	strcpy(cm.type,"débit");
}
}


void
on_caradiobuttonmfumee_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	strcpy(cm.type,"fumée");
}
}


void
on_caradiobuttonmtemp_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	strcpy(cm.type,"temperature");
}
}


void
on_caradiobuttonmmouv_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	strcpy(cm.type,"mouvement");
}
}


void
on_accbmvalider_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
{
	rm=1;
}
}


void
on_cabuttonmretour_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* cawindowgdc;
GtkWidget* treeviewtr;
GtkWidget* cawindowet1;

cawindowet1=lookup_widget(button,"cawindowmodifier");
gtk_widget_destroy(cawindowet1);
cawindowgdc=lookup_widget(button,"cawindowgdc");
cawindowgdc=create_cawindowgdc();
gtk_widget_show (cawindowgdc);
treeviewtr = lookup_widget(cawindowgdc,"caatreeviewgdc");
caafficher_capts(treeviewtr);
}


void
on_cabuttonmvalider_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* input1;
GtkWidget* input2;
GtkWidget* Casbavmin;
GtkWidget* Caspinbuttonvmax;

//GtkWidget* combobox;
char success[100]="modification avec succès";
char verif[100]="confirmez la modification svp";
char nom[100];
char localisation[100];
input1 = lookup_widget(objet_graphique,"caentrymnom");
//combobox = lookup_widget(objet_graphique,"accombobox");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(cm.nom,nom);

input2 = lookup_widget(objet_graphique,"caentrymlocalisation");
strcpy(localisation,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(cm.localisation,localisation);

Casbavmin = lookup_widget(objet_graphique,"caspinbuttonmvalmin");
cm.valmin=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Casbavmin));
Caspinbuttonvmax = lookup_widget(objet_graphique,"casbvm");
cm.valmax=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Caspinbuttonvmax));
cm.etat=0;
GtkWidget* output7;
output7 = lookup_widget(objet_graphique,"aclmas");

if(rm==1)
{
gtk_label_set_text(GTK_LABEL(output7),success);
camodifier(cm);
//cacheck();
rm=0;
}
else{gtk_label_set_text(GTK_LABEL(output7),verif);}

}


void
on_cabuttonldtadministrateur_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cawindowtache,*cawindowlogin;
cawindowtache=lookup_widget(button,"cawindowtache");
gtk_widget_destroy(cawindowtache);
cawindowlogin=create_cawindowlogin();
gtk_widget_show(cawindowlogin);
strcpy(fah,"adm");
}


void
on_cabuttonldttechnicien_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cawindowtache,*cawindowlogin;
cawindowtache=lookup_widget(button,"cawindowtache");
gtk_widget_destroy(cawindowtache);
cawindowlogin=create_cawindowlogin();
gtk_widget_show(cawindowlogin);
strcpy(fah,"tec");
}


void
on_cabuttonldtnutritioninste_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cawindowtache,*cawindowlogin;
cawindowtache=lookup_widget(button,"cawindowtache");
gtk_widget_destroy(cawindowtache);
cawindowlogin=create_cawindowlogin();
gtk_widget_show(cawindowlogin);
strcpy(fah,"nut");
}


void
on_cabuttonldtadr_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cawindowtache,*cawindowlogin;
cawindowtache=lookup_widget(button,"cawindowtache");
gtk_widget_destroy(cawindowtache);
cawindowlogin=create_cawindowlogin();
gtk_widget_show(cawindowlogin);
strcpy(fah,"adr");
}


void
on_cabuttonldtadf_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cawindowtache,*cawindowlogin;
cawindowtache=lookup_widget(button,"cawindowtache");
gtk_widget_destroy(cawindowtache);
cawindowlogin=create_cawindowlogin();
gtk_widget_show(cawindowlogin);
strcpy(fah,"adf");
}


void
on_cabuttonldtsrh_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cawindowtache,*cawindowlogin;
cawindowtache=lookup_widget(button,"cawindowtache");
gtk_widget_destroy(cawindowtache);
cawindowlogin=create_cawindowlogin();
gtk_widget_show(cawindowlogin);
strcpy(fah,"srv");
}
void
on_acretour404_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cawindowtache,*cawindowlogin;
cawindowlogin=lookup_widget(button,"cawindowlogin");
gtk_widget_destroy(cawindowlogin);
cawindowtache=create_cawindowtache();
gtk_widget_show(cawindowtache);

}
void
on_acdtree56_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_acrbretour_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* cawindowgdc;
GtkWidget* treeviewtr;
GtkWidget* cawindowet1;

cawindowet1=lookup_widget(button,"acwrechercher");
gtk_widget_destroy(cawindowet1);
cawindowgdc=lookup_widget(button,"cawindowgdc");
cawindowgdc=create_cawindowgdc();
gtk_widget_show (cawindowgdc);
treeviewtr = lookup_widget(cawindowgdc,"caatreeviewgdc");
caafficher_capts(treeviewtr);
}


void
on_acrbrvald12_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE* ft;
Capts Cr;
char nom[100];
char safa1[40];
char safa2[40];
char safa3[40]="defectueux";
char safa4[40]="non defectueux";
GtkWidget* input1;
GtkWidget* output1 ;
GtkWidget* output2 ;
GtkWidget* output3 ;
GtkWidget* output4 ;
GtkWidget* output5 ;
GtkWidget* treedetail;
ft=fopen("capteurs.txt","r");
output1 = lookup_widget(objet_graphique,"acrlrimdonetypeaf");
output2 = lookup_widget(objet_graphique, "acrlrimdoneeopaf") ;
output3 = lookup_widget(objet_graphique, "acrlrimdonevlminaf") ;
output4 = lookup_widget(objet_graphique, "acrlrimdonevlmaxaf") ;
output5 = lookup_widget(objet_graphique, "acrlrimdoneetataf") ;
input1 = lookup_widget(objet_graphique, "acrenom") ;
treedetail = lookup_widget(objet_graphique,"acdtree56");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
while(fscanf(ft,"%s %s %s %i %i %i ",Cr.nom,Cr.type,Cr.localisation,&Cr.valmin,&Cr.valmax,&Cr.etat)!=(EOF))
     {if(strcmp(Cr.nom,nom)==0)
			{
			gtk_label_set_text(GTK_LABEL(output1),Cr.type);
			gtk_label_set_text(GTK_LABEL(output2),Cr.localisation);
			sprintf(safa1,"%i",Cr.valmin);
			gtk_label_set_text(GTK_LABEL(output3),safa1);
			sprintf(safa2,"%i",Cr.valmax);
			gtk_label_set_text(GTK_LABEL(output4),safa2);
			if(Cr.etat==1){gtk_label_set_text(GTK_LABEL(output5),safa3);}
			else if(Cr.etat==0){gtk_label_set_text(GTK_LABEL(output5),safa4);}
			
			caafficher_detail(treedetail,Cr);
		 	}
	}
fclose(ft);
}


gboolean
on_acwindowsupprimer_focus_in_event    (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
GtkWidget* input1;
input1 = lookup_widget(widget,"acsenom");
gtk_entry_set_text(GTK_ENTRY(input1),cra.nom);
  return FALSE;
}


void
on_ouijesuissure12_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
{
	r=1;

}
}


void
on_acsbs_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* input1;
char ID[100];
char success[100]="suppression avec succès";
char verif[100]="confirmez la suppression svp";
input1 = lookup_widget(objet_graphique,"acsenom");
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input1)));
GtkWidget* output7;
output7 = lookup_widget(objet_graphique,"aclsas");


if (r==1)
	{
	casupprimer(ID);
	gtk_label_set_text(GTK_LABEL(output7),success);
	r=0;
	}
else{gtk_label_set_text(GTK_LABEL(output7),verif);}
}


void
on_acsbsretour_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* cawindowgdc;
GtkWidget* treeviewtr;
GtkWidget* cawindowet1;

cawindowet1=lookup_widget(button,"acwindowsupprimer");
gtk_widget_destroy(cawindowet1);
cawindowgdc=lookup_widget(button,"cawindowgdc");

//gtk_widget_destroy(cawindowgdc);

cawindowgdc=create_cawindowgdc();
gtk_widget_show (cawindowgdc);
treeviewtr = lookup_widget(cawindowgdc,"caatreeviewgdc");
caafficher_capts(treeviewtr);
}




void
on_FJcheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	{
		z=1;
	}
}




void
on_FJretour3_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)

{GtkWidget *FJafficher21,*FJmodifier;

FJmodifier=lookup_widget(objet,"FJmodifier");

gtk_widget_destroy(FJmodifier);
FJafficher21=create_FJafficher21();
gtk_widget_show(FJafficher21);


}
void
on_FJradiobuttonnon_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		{y=0;}
}

void
on_FJradiobutton2_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{y=1;}

}



void
on_FJbutton1_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
produit p,p2[100];
int i=0,j,s=1;
char ch[200];
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9, *input10, *input11, *output1; 
GtkWidget *FJajouter;
FILE *fi;

FJajouter=lookup_widget(objet,"FJajouter");
fi=fopen("stock.txt","ab+");
output1 =lookup_widget(objet,"FJlabel73"); 
input1=lookup_widget(objet,"FJentry11");
input2=lookup_widget(objet,"FJcomboboxentry1");
input3=lookup_widget(objet,"FJentry13");
input4=lookup_widget(objet,"FJspinbutton9");
input5=lookup_widget(objet,"FJspinbutton10");
input6=lookup_widget(objet,"FJspinbutton11");
input7=lookup_widget(objet,"FJspinbutton12");
input8=lookup_widget(objet,"FJspinbutton13");
input9=lookup_widget(objet,"FJspinbutton14");
input10=lookup_widget(objet,"FJentry14");
input11=lookup_widget(objet,"FJspinbutton8");

p.id=atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
strcpy(p.marque,gtk_entry_get_text(GTK_ENTRY(input3)));
p.ej=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
p.em=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
p.ea=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
p.fj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
p.fm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
p.fa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
p.cout=atoi(gtk_entry_get_text(GTK_ENTRY(input10)));
p.quantite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input11));
while(fscanf(fi,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",&p2[i].id,p2[i].type,p2[i].marque,&p2[i].ej,&p2[i].em,&p2[i].ea,&p2[i].fj,&p2[i].fm,&p2[i].fa,&p2[i].cout,&p2[i].quantite)!=EOF)
	{
	i++;
	}
fclose(fi);
if (y==1)
	{for(j=0;j<i+1;j++)
	{if (p.id==p2[j].id){
		strcpy(ch,"Ce produit existe déjà");
		gtk_label_set_text(GTK_LABEL(output1),ch);
		s=0;
		}
	}
	if(s==1)
	{strcpy(ch,"le produit a été ajouté avec succés");
	gtk_label_set_text(GTK_LABEL(output1),ch);
	FJAjouter(p);
	//sendmail("le produit a été ajouté avec succés");
}
	

	}
}





void
on_FJbutton2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_FJretour4_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_FJbutton3_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{FILE* ft;
produit p;
int id1,i=0;
char ch[100];
char ej1[40];
char em1[40];
char ea1[40];
char fj1[40];
char fm1[40];
char fa1[40];
char cout1[40];
char quantite1[40];

GtkWidget* input1;
GtkWidget* output1 ;
GtkWidget* output2 ;
GtkWidget* output3 ;
GtkWidget* output4 ;
GtkWidget* output5 ;
GtkWidget* output6 ;
GtkWidget* output7 ;
GtkWidget* output8 ;
GtkWidget* output9 ;
GtkWidget* output10 ;
GtkWidget* output11 ;

ft=fopen("stock.txt","r");
output1 = lookup_widget(objet_graphique,"FJlabel75");
output2 = lookup_widget(objet_graphique,"FJlabel76");
output3 = lookup_widget(objet_graphique,"FJlabel68");
output4 = lookup_widget(objet_graphique,"FJlabel69");
output5 = lookup_widget(objet_graphique,"FJlabel77");
output6 = lookup_widget(objet_graphique,"FJlabel71");
output7 = lookup_widget(objet_graphique,"FJlabel72");
output8 = lookup_widget(objet_graphique,"FJlabel78");
output9 = lookup_widget(objet_graphique,"FJlabel79");
output10 = lookup_widget(objet_graphique,"FJlabel80");
output11 = lookup_widget(objet_graphique,"FJlabel1919");
input1 = lookup_widget(objet_graphique, "FJentry16") ;
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input1)));
id1=atoi(ch);
while(fscanf(ft,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",&p.id,p.type,p.marque,&p.ej,&p.em,&p.ea,&p.fj,&p.fm,&p.fa,&p.cout,&p.quantite)!=EOF){
     	if(p.id==id1)
			{
			i=1;
			gtk_label_set_text(GTK_LABEL(output1),p.type);
			gtk_label_set_text(GTK_LABEL(output2),p.marque);
			sprintf(ej1,"%d",p.ej);
			gtk_label_set_text(GTK_LABEL(output3),ej1);
			sprintf(em1,"%d",p.em);
			gtk_label_set_text(GTK_LABEL(output4),em1);
			sprintf(ea1,"%d",p.ea);
			gtk_label_set_text(GTK_LABEL(output5),ea1);
			sprintf(fj1,"%d",p.fj);
			gtk_label_set_text(GTK_LABEL(output6),fj1);
			sprintf(fm1,"%d",p.fm);
			gtk_label_set_text(GTK_LABEL(output7),fm1);
			sprintf(fa1,"%d",p.fa);
			gtk_label_set_text(GTK_LABEL(output8),fa1);
			sprintf(cout1,"%d",p.cout);
			gtk_label_set_text(GTK_LABEL(output9),cout1);
			sprintf(quantite1,"%d",p.quantite);
			gtk_label_set_text(GTK_LABEL(output10),quantite1);
		
		 	}
	}
if (i==0)
	{gtk_label_set_text(GTK_LABEL(output11),"Ce produit n existe pas");}
fclose(ft);
	
}


void
on_FJretour5_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *FJafficher21,*FJchercher;

FJchercher=lookup_widget(objet,"FJchercher");

gtk_widget_destroy(FJchercher);
FJafficher21=create_FJafficher21();
gtk_widget_show(FJafficher21);

}



void
on_FJretour1_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)

{GtkWidget *FJafficher21,*FJrupturedestock;

FJrupturedestock=lookup_widget(objet,"FJrupturedestock");

gtk_widget_destroy(FJrupturedestock);
FJafficher21=create_FJafficher21();
gtk_widget_show(FJafficher21);

}


void
on_FJtreeview2_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gint id;
	gchar* type;
	gchar* marque;
	gint ej;
	gint em;
	gint ea;
	gint fj;
	gint fm;
	gint fa;
	gint cout;
	gint quantite;
	produit p;


GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model, &iter, path))
{
	gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id, 1, &type, 2, &marque, 3, &ej, 4, &em, 5, &ea, 6, &fj, 7, &fm, 8, &fa, 9, &cout, 10, &quantite, -1);
	p.id=id;
	strcpy(p.type,type);
	strcpy(p.marque,marque);
	p.ej=ej;
	p.em=em;
	p.ea=ea;
	p.fj=fj;
	p.fm=fm;
	p.fa=fa;
	p.cout=cout;
	p.quantite=quantite;
	FJSupprimer(p);
	FJsendmail("le produit a été supprimé avec succés");
	FJafficher(treeview,"stock.txt");
}

}


void
on_FJbuttonafficher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *FJafficher21;
GtkWidget *FJajouter;
GtkWidget *FJtreeview2;

FJajouter=lookup_widget(objet,"FJajouter");

gtk_widget_destroy(FJajouter);
FJafficher21=lookup_widget(objet,"FJafficher21");
FJafficher21=create_FJafficher21();

gtk_widget_show(FJafficher21);

FJtreeview2=lookup_widget(FJafficher21,"FJtreeview2");
FJafficher(FJtreeview2,"stock.txt");
}


void
on_FJActualiser12_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *FJafficher21,*w1;
GtkWidget *FJtreeview2;

w1=lookup_widget(objet,"FJafficher21");
FJafficher21=create_FJafficher21();
gtk_widget_show(FJafficher21);
gtk_widget_hide(w1);
FJtreeview2=lookup_widget(FJafficher21,"FJtreeview2");
//gtk_widget_show_all(FJafficher21);


//vider(FJtreeview2);
FJafficher(FJtreeview2,"stock.txt");

}


void
on_FJmod_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{produit p,p2[100];
int i=0,j,m=1;
char ch[100];
GtkWidget* output1;
GtkWidget* input1;
GtkWidget* input2;
GtkWidget* input3;
GtkWidget* input4;
GtkWidget* input5;
GtkWidget* input6;
GtkWidget* input7;
GtkWidget* input8;
GtkWidget* input9;
GtkWidget* input10;
GtkWidget* input11;
FILE *fi;
   	
fi=fopen("stock.txt","r");
output1 =lookup_widget(objet_graphique,"FJlabel72"); 
input1=lookup_widget(objet_graphique,"FJentry9");
input2=lookup_widget(objet_graphique,"FJcomboboxentry2");
input3=lookup_widget(objet_graphique,"FJentry10");
input4=lookup_widget(objet_graphique,"FJspinbutton2");
input5=lookup_widget(objet_graphique,"FJspinbutton3");
input6=lookup_widget(objet_graphique,"FJspinbutton4");
input7=lookup_widget(objet_graphique,"FJspinbutton5");
input8=lookup_widget(objet_graphique,"FJspinbutton6");
input9=lookup_widget(objet_graphique,"FJspinbutton7");
input10=lookup_widget(objet_graphique,"FJentry8");
input11=lookup_widget(objet_graphique,"FJspinbutton1");

p.id=atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
strcpy(p.marque,gtk_entry_get_text(GTK_ENTRY(input3)));
p.ej=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
p.em=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
p.ea=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
p.fj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
p.fm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
p.fa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
p.cout=atoi(gtk_entry_get_text(GTK_ENTRY(input10)));
p.quantite=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input11));
while(fscanf(fi,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",&p2[i].id,p2[i].type,p2[i].marque,&p2[i].ej,&p2[i].em,&p2[i].ea,&p2[i].fj,&p2[i].fm,&p2[i].fa,&p2[i].cout,&p2[i].quantite)!=EOF)
	{
	i++;
	}
fclose(fi);
if(z==1)
	{for(j=0;j<i+1;j++)
	{if (p.id==p2[j].id){
		strcpy(ch,"Modifié avec succés");
		gtk_label_set_text(GTK_LABEL(output1),ch);
		FJmodifier(p);
		//sendmail("le produit a été modifié avec succés");
		z=0;
		m=0;
		}
	}
	if(m==1)
	{strcpy(ch,"Ce produit n'existe pas verifiez l'id");
	gtk_label_set_text(GTK_LABEL(output1),ch);}
	}
else
	gtk_label_set_text(GTK_LABEL(output1),"Confirmez svp");
	}
void
on_FJboutonmodifier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *FJafficher21,*FJmodifier;

FJafficher21=lookup_widget(objet,"FJafficher21");

gtk_widget_destroy(FJafficher21);
FJmodifier=create_FJmodifier();
gtk_widget_show(FJmodifier);

}


void
on_FJboutonchercher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *FJafficher21,*FJchercher;

FJafficher21=lookup_widget(objet,"FJafficher21");

gtk_widget_destroy(FJafficher21);
FJchercher=create_FJchercher();
gtk_widget_show(FJchercher);
}


void
on_FJruptstock1_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *FJrupturedestock;
GtkWidget *FJafficher21;
GtkWidget *FJtreeview1;

FJafficher21=lookup_widget(objet,"FJafficher21");

gtk_widget_destroy(FJafficher21);
//FJrupturedestock=lookup_widget(objet,"FJrupturedestock");
FJrupturedestock=create_FJrupturedestock();

gtk_widget_show(FJrupturedestock);

FJtreeview1=lookup_widget(FJrupturedestock,"FJtreeview1");
FJafficher1(FJtreeview1,"stock.txt");

}


void
on_FJentry9_changed                    (GtkEditable     *editable,
                                        gpointer         user_data)

{FILE* ft;
produit p;
int id1;
GtkWidget* input1;
GtkWidget* output1 ;
GtkWidget* output2 ;
GtkWidget* output3 ;
GtkWidget* output4 ;
GtkWidget* output5 ;
GtkWidget* output6 ;
GtkWidget* output7 ;
GtkWidget* output8 ;
GtkWidget* output9 ;
GtkWidget* output10 ;
char coutt[20];
char Matrice[4][20]={"Viande","Fruit","Legume","Autre"};
int i=0;

ft=fopen("stock.txt","r");
input1 = lookup_widget(editable,"FJentry9");
output1 = lookup_widget(editable, "FJcomboboxentry2") ;
output2 = lookup_widget(editable, "FJentry10") ;
output3 = lookup_widget(editable, "FJspinbutton2") ;
output4 = lookup_widget(editable, "FJspinbutton3") ;
output5 = lookup_widget(editable, "FJspinbutton4") ;
output6 = lookup_widget(editable, "FJspinbutton5") ;
output7 = lookup_widget(editable, "FJspinbutton6") ;
output8 = lookup_widget(editable, "FJspinbutton7") ;
output9 = lookup_widget(editable, "FJentry8") ;
output10 = lookup_widget(editable, "FJspinbutton1") ;
id1=atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
while(fscanf(ft,"%d %s %s %d /%d /%d %d /%d /%d %d %d \n",&p.id,p.type,p.marque,&p.ej,&p.em,&p.ea,&p.fj,&p.fm,&p.fa,&p.cout,&p.quantite)!=EOF)
     {if(p.id==id1)
		{	while(i<4 && strcmp(Matrice[i],p.type)!=0)
				{
					i++;
				}

			gtk_combo_box_set_active(GTK_COMBO_BOX(output1),i);
			gtk_entry_set_text(GTK_ENTRY(output2),p.marque);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output3),p.ej);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output4),p.em);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output5),p.ea);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output6),p.fj);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output7),p.fm);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output8),p.fa);
			sprintf(coutt,"%d",p.cout);
			gtk_entry_set_text(GTK_ENTRY(output9),coutt);
			gtk_spin_button_set_value (GTK_SPIN_BUTTON(output10),p.quantite);
			
		 }
	}
fclose(ft);	
}




void
on_FJretour69_clicked                  (GtkWidget       *objet,
                                       gpointer         user_data)
{
GtkWidget *FJajouter,*FJafficher21;

FJafficher21=lookup_widget(objet,"FJafficher21");

gtk_widget_destroy(FJafficher21);
FJajouter=create_FJajouter();
gtk_widget_show(FJajouter);
}


void casendmail(char body[])
{
        char cmd[300];
        FILE *fp = fopen("mail.txt","w+"); // open it for writing.
        fprintf(fp,"%s\n",body);        // write body to it.
        fclose(fp);             // close it.

        sprintf(cmd,"curl smtps://smtp.gmail.com:465 -v --mail-from \"stockproduit@gmail.com:Produit12345678\" --mail-rcpt \"mohamedfadhel.jaiet@esprit.tn\" --ssl -u stockproduit@gmail.com:Produit12345678 -T mail.txt -k --anyauth"); // prepare command.
        system(cmd);     // execute it.
}

int c=0;
int E=0;
int obj1=0;
int obj2=0;
int M=1;
rec del;

void
on_aobutton_dep_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *B;
B=create_aowindow_menu();
gtk_widget_show(B);

}


void
on_aobutton_consult_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aowindow_menu ;
GtkWidget *aowindow_consult;
GtkWidget *aotreeview_rec;

aowindow_menu =lookup_widget(objet,"aowindow_menu ");

gtk_widget_destroy(aowindow_menu );
aowindow_consult=lookup_widget(objet,"aowindow_consult");
aowindow_consult=create_aowindow_consult();

gtk_widget_show(aowindow_consult);

aotreeview_rec=lookup_widget(aowindow_consult,"aotreeview_rec");
afficher_rec(aotreeview_rec,"reclm.txt");

}


void
on_aoradiobutton_oui_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
  c=1;
}


void
on_aoradiobutton_non_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
  c=0;
}


void
on_aocheckbutton_ouieq_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
char mail[250]="(  Vous recevrez un e-mail sur l'adresse avec laquelle voue êtes connecté(e)   )";
 GtkWidget*msg ;
 
 if (gtk_toggle_button_get_active(togglebutton))
  {
   msg= lookup_widget(togglebutton, "label_oui") ;
   gtk_label_set_text(GTK_LABEL(msg),mail);
  E=1;
 
  }
}


void
on_aocheckbutton_noneq_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
  E=0;
}


void
on_aocheckbuttonr_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
 obj1=1;
}


void
on_aocheckbuttonh_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
 obj2=1;
}


void
on_aobutton_dep_pl_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{

rec r;
int j,m,a;
char dj[3];
char dm[4];
char da[5];
char ct[10];
char eq[10];
char objj[]="";
GtkWidget *A;
GtkWidget *B;
GtkWidget *aoentrynom;
GtkWidget *aoentrypnom;
GtkWidget *aoentrycin;
GtkWidget *aoentryid;
GtkWidget *aospinbutton_jr;
GtkWidget *aospinbutton_ms;
GtkWidget *aospinbutton_an;
GtkWidget *aoentryprob;

aoentrynom=lookup_widget(button,"aoentrynom");
aoentrypnom=lookup_widget(button,"aoentrypnom");
aoentrycin=lookup_widget(button,"aoentrycin");
aoentryid=lookup_widget(button,"aoentryid");

aospinbutton_jr=lookup_widget(button, "aospinbutton_jr");
aospinbutton_ms=lookup_widget(button, "aospinbutton_ms");
aospinbutton_an=lookup_widget(button, "aospinbutton_an");
aoentryprob=lookup_widget(button,"aoentryprob");
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(aoentrynom)));
strcpy(r.pnom,gtk_entry_get_text(GTK_ENTRY(aoentrypnom)));
strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(aoentrycin)));
strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(aoentryid)));
actv(c,ct);
strcpy(r.contact,ct);
actv(E,eq);
strcpy(r.enquette,eq);
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aospinbutton_jr));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aospinbutton_ms));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aospinbutton_an));
sprintf(dj, "%d",j );
sprintf(dm, "%d",m );
sprintf(da, "%d",a );
strcpy(r.date,dj);
strcat(r.date,dm);
strcat(r.date,da);
objpl(obj1,obj2,objj);
strcpy(r.objet,objj);
strcpy(r.prob,gtk_entry_get_text(GTK_ENTRY(aoentryprob)));
ajouter_pl(r);
B=create_aowindow_dep_succ();
gtk_widget_show(B);
A=lookup_widget(button,"aowindow_formulaire");
gtk_widget_hide(A);

}


void
on_aobutton_annuler_pl_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B;
A=lookup_widget(button,"aowindow_formulaire");
gtk_widget_hide(A);
B=create_aowindow_menu ();
gtk_widget_show(B);
}


void
on_aotreeview_rec_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter   iter;
gchar *nom;
gchar *pnom;
gchar *cin;
gchar *id;
gchar *contact;
gchar *enquette;
gchar *date;
gchar *objet;
gchar *prob;
rec r;


GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&nom,1,&pnom,2,&cin,3,&id,4,&contact,5,&enquette,6,&date,7,&objet,8,&prob,-1);
strcpy(r.nom,nom);
strcpy(r.pnom,pnom);
strcpy(r.cin,cin);
strcpy(r.id,id);
strcpy(r.contact,contact);
strcpy(r.enquette,enquette);
strcpy(r.date,date);
strcpy(r.objet,objet);
strcpy(r.prob,prob);
strcpy(del.nom,nom);
strcpy(del.pnom,pnom);
strcpy(del.cin,cin);
strcpy(del.id,id);
strcpy(del.contact,contact);
strcpy(del.enquette,enquette);
strcpy(del.date,date);
strcpy(del.objet,objet);
strcpy(del.prob,prob);
afficher_rec(treeview,"reclm.txt");
}

}


void
on_aobutton_acc_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aowindow_consult,*wz;
GtkWidget *aotreeview_rec;

wz=lookup_widget(objet,"aowindow_consult");
aowindow_consult=create_aowindow_consult();
gtk_widget_show(aowindow_consult);
gtk_widget_hide(wz);
aotreeview_rec=lookup_widget(aowindow_consult,"aotreeview_rec");

afficher_rec(aotreeview_rec,"reclm.txt");



}


void
on_aobutton_modifier_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *B;
GtkWidget *aowindow_consult;
aowindow_consult=lookup_widget(objet,"aowindow_consult");
gtk_widget_destroy(aowindow_consult);
B=create_aowindow_formulaire();
supprimer_pl(del);
gtk_widget_show(B);
}


void
on_aobutton_supprimer_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *B;
B=create_aowindow_c_supp();
gtk_widget_show(B);
 
}


void
on_aobutton_oui_supp_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *A;
A=lookup_widget(objet,"aowindow_cs");
supprimer_pl(del);
gtk_widget_show(A);
}


void
on_aobutton_non_supp_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *A;
A=lookup_widget(button,"aowindow_c_supp");
gtk_widget_hide(A);
}


void
on_aobutton_rech_pl_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *aotreeview_rec;
GtkWidget *aowindow_consult ,*wz; 
GtkWidget *aoentry_rech_date;
char rech_date[30]; 


wz=lookup_widget(button,"aowindow_consult");
aowindow_consult=create_aowindow_consult();
gtk_widget_show(aowindow_consult);
gtk_widget_hide(wz);
aotreeview_rec=lookup_widget(aowindow_consult,"aotreeview_rec");

aoentry_rech_date=lookup_widget(button,"aoentry_rech_date");
strcpy(rech_date,gtk_entry_get_text(GTK_ENTRY(aoentry_rech_date)));
recherche_pl(rech_date);
afficher_rec(aotreeview_rec,"drec.txt");

}





void
on_aobutton_retour_pl_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_aobutton_service_rec_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{   
int result=0;    
char srv[50]="hello";
GtkWidget*service_rr ;    
GtkWidget *B;
B=create_aowindow_service();
gtk_widget_show(B);
result=service_rec();
if (result==1)
{
strcpy(srv,"Hebergement");
service_rr= lookup_widget(objet, "aolabel_service_rrcc") ;
 gtk_label_set_text(GTK_LABEL(service_rr),srv);
}
if (result==2)
{
strcpy(srv,"Restauration");
service_rr= lookup_widget(objet, "aolabel_service_rrcc") ;
 gtk_label_set_text(GTK_LABEL(service_rr),srv);

}
}



void
on_aobutton_retour_menu_p_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}

void
on_aobutton_retour00_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}




int sexe,sexem,x;
void
on_bk_auth_insc_btn_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{

}


void
on_bk_auth_connecter_btn_clicked        (GtkWidget      *objet,
                                        gpointer         user_data)
{

}


void
on_bk_quitter_btn_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcawindowlogin, *window_destroy;
window_destroy=lookup_widget(objet,"bk_welcome");
gtk_widget_destroy(window_destroy);
windowcawindowlogin=create_cawindowlogin();
gtk_widget_show (windowcawindowlogin);
}


void
on_bk_treeview_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *nom;
gchar *prenom;
gchar *sexe;
gint *age;
gint *num;
gchar *email;
gchar *cin;
gchar *poste;
user p;
GtkTreeModel *model =gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&cin,3,&age,4,&sexe,5,&num,6,&email,7,&poste,-1);
strcpy(p.nom,nom);
strcpy(p.prenom,prenom);
strcpy(p.cin,cin);
strcpy(p.sexe,sexe);
strcpy(p.email,email);
strcpy(p.poste,poste);
p.age=age;
p.num=num;
//supp(p);
aff_user(treeview);
}
}

void
on_bk_aff_retour_btn_clicked            (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *windowbk_welcome, *window_destroy;
window_destroy=lookup_widget(objet,"bk_aff");
gtk_widget_destroy(window_destroy);
windowbk_welcome=create_bk_welcome();
gtk_widget_show (windowbk_welcome);
}


void
on_bk_aff_modif_btn_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *windowbk_modif, *window_destroy;
window_destroy=lookup_widget(objet,"bk_aff");
gtk_widget_destroy(window_destroy);
windowbk_modif=create_bk_modifier();
gtk_widget_show (windowbk_modif);
}


void
on_bk_aff_supp_btn_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar *cin;
        
        p=lookup_widget(objet,"bk_treeview");
	
	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,2,&cin,-1);
	 gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

	
	supp_cin(cin);}

	aff_user(p);

	

}


int
on_bk_supp_supp_btn_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
           
	
	GtkWidget  *window_destroy;
	window_destroy=lookup_widget(objet,"bk_supprimer");
	gtk_widget_destroy(window_destroy);
	

}




void
on_bk_supp_annuler_btn_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget  *window_destroy;
window_destroy=lookup_widget(objet,"bk_supprimer");
gtk_widget_destroy(window_destroy);

GtkWidget *fenetre_afficher,*w1000;
GtkWidget *treeview1000;

w1000=lookup_widget(objet,"bk_aff");
fenetre_afficher=create_bk_aff();
gtk_widget_show(fenetre_afficher);
gtk_widget_hide(w1000);
treeview1000=lookup_widget(fenetre_afficher,"bk_treeview");
aff_user(treeview1000);


}





void
on_bk_aff_rech_btn_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelcin;
GtkWidget *nbResultat;
GtkWidget *message;
char cin[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(objet,"bk_aff_rech_entry");
//labelid=lookup_widget(gestion,"label47");
p1=lookup_widget(objet,"bk_treeview");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(entry)));
nb=chercher_user(p1,"user.txt",cin);
}


void
on_bk_aff_add_btn_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *windowbk_add, *window_destroy;
GtkWidget *fail,*succ;

window_destroy=lookup_widget(objet,"bk_aff");
gtk_widget_destroy(window_destroy);
windowbk_add=create_bk_add();
gtk_widget_show (windowbk_add);
fail=lookup_widget(objet,"label_fail");
succ=lookup_widget(objet,"label_succ");
gtk_widget_hide(fail);
gtk_widget_hide(succ);
}


void
on_bk_add_retour_btn_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowbk_aff, *window_destroy;
window_destroy=lookup_widget(objet,"bk_add");
gtk_widget_destroy(window_destroy);
windowbk_aff=create_bk_aff();
gtk_widget_show (windowbk_aff);
}


void
on_bk_add_add_btn_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{
user c;
int a;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9;
GtkWidget *fenetre_ajout;
GtkWidget *fail,*succ;
fail=lookup_widget(objet,"label_fail");
succ=lookup_widget(objet,"label_succ");



fenetre_ajout=lookup_widget(objet,"bk_add");
input1=lookup_widget(objet,"bk_add_name");
input2=lookup_widget(objet,"bk_add_prename");
input3=lookup_widget(objet,"bk_add_cin");
input4=lookup_widget(objet,"bk_add_num");
input5=lookup_widget(objet,"bk_add_email");

input6=lookup_widget(objet,"bk_add_combo_poste");
input7=lookup_widget(objet,"bk_add_spin_age");
input8=lookup_widget(objet,"bk_add_homme");
input9=lookup_widget(objet,"bk_add_femme");

if(sexe==1)
{
//gtk_toggle_button_set_active(GTK_RADIO_BUTTON(input8),TRUE);
strcpy(c.sexe,"Homme");
}
else
{
//gtk_toggle_button_set_active(GTK_RADIO_BUTTON(input9),TRUE);
strcpy(c.sexe,"Femme");
}

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
c.num=atoi(gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(c.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));

a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
c.age=a;
if(x==1)
{
if(strcmp(c.nom,"")!=0&&strcmp(c.prenom,"")!=0&&strcmp(c.cin,"")!=0&&strcmp(c.sexe,"")!=0&& (c.age>=18) && (c.num!=0) && strcmp(c.email,"")!=0&&strcmp(c.poste,"")!=0)
{gtk_widget_show(succ);
gtk_widget_hide(fail);
add_user(c);
}
else {
gtk_widget_show(fail);
gtk_widget_hide(succ);}
}
}


void
on_bk_modif_annuler_btn_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowbk_aff, *window_destroy;
window_destroy=lookup_widget(objet,"bk_modifier");
gtk_widget_destroy(window_destroy);
windowbk_aff=create_bk_aff();
gtk_widget_show (windowbk_aff);
}


void
on_bk_modif_modif_btn_clicked           (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *cin,*nom,*prenom,*age,*sexe1,*sexe2,*poste,*email,*numero,*rech;
GtkWidget *fail,*succ;
user p;
char reche[200];
fail=lookup_widget(objet,"label_mod_fail");
succ=lookup_widget(objet,"label_mod_succ");
rech=lookup_widget(objet,"bk_modif_chercher");
strcpy(reche,gtk_entry_get_text(GTK_ENTRY(rech)));
cin=lookup_widget(objet,"bk_modif_cin");
nom=lookup_widget(objet,"bk_modif_nom");
prenom=lookup_widget(objet,"bk_modif_prenom");
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

age=lookup_widget(objet,"bk_modif_spin_age");
p.age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(age));

sexe1=lookup_widget(objet,"bk_modif_homme");
sexe2=lookup_widget(objet,"bk_modif_femme");
if(sexem==1)
{
strcpy(p.sexe,"Homme");
}
else
{
strcpy(p.sexe,"Femme");
}
poste=lookup_widget(objet,"bk_modif_combo_poste");
strcpy(p.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(poste)));

email=lookup_widget(objet,"bk_modif_email");
strcpy(p.email,gtk_entry_get_text(GTK_ENTRY(email)));

numero=lookup_widget(objet,"bk_modif_num");
p.num=atoi(gtk_entry_get_text(GTK_ENTRY(numero)));


if(strcmp(p.nom,"")!=0&&strcmp(p.prenom,"")!=0&&strcmp(p.cin,"")!=0&&strcmp(p.sexe,"")!=0&& (p.age>=18) && (p.num!=0) && strcmp(p.email,"")!=0&&strcmp(p.poste,"")!=0)
{gtk_widget_show(succ);
gtk_widget_hide(fail);
supp_cin(reche);
add_user(p);
}
else {
gtk_widget_show(fail);
gtk_widget_hide(succ);}


/*gtk_widget_show (message);
gtk_label_set_text(GTK_LABEL(message),"la modification est validée");*/
}



void
on_bk_modif_chercher_btn_clicked        (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *cin,*nom,*prenom,*age,*genre,*email,*numero,*rech,*poste,*se1,*se2,*message;
user c;
user p;
char nmch[30];
char reche[200];
int i=0;
char matrice[6][30]={"Administrateur","Technicien","Nutritionniste","Agent_de_foyer","Agent_de_restaurant","Etudiant"};
cin=lookup_widget(objet,"bk_modif_cin");
nom=lookup_widget(objet,"bk_modif_nom");
prenom=lookup_widget(objet,"bk_modif_prenom");
email=lookup_widget(objet,"bk_modif_email");
numero=lookup_widget(objet,"bk_modif_num");

age=lookup_widget(objet,"bk_modif_spin_age");

se1=lookup_widget(objet,"bk_modif_homme");
se2=lookup_widget(objet,"bk_modif_femme");

poste=lookup_widget(objet,"bk_modif_combo_poste");

rech=lookup_widget(objet,"bk_modif_chercher");


strcpy(reche,gtk_entry_get_text(GTK_ENTRY(rech)));
//printf("hello world");
FILE *f=NULL;
int v=1;
f=fopen("user.txt","r");
while(fscanf(f,"%s %s %s %s %d %d %s %s \n",c.nom,c.prenom,c.cin,c.sexe,&c.age,&c.num,c.email,c.poste)!=EOF)
        {
	if( strcmp(reche,c.cin)==0){
			gtk_widget_hide (message);
			v=0;
			strcpy(p.cin,c.cin);
			strcpy(p.nom,c.nom);
			strcpy(p.prenom,c.prenom);
			strcpy(p.email,c.email);
			p.num=c.num;
			p.age=c.age;
			strcpy(p.poste,c.poste);
			strcpy(p.sexe,c.sexe);
			
			
			
	}
	else 
		{gtk_widget_show (message);
		gtk_label_set_text(GTK_LABEL(message),"ce cin n'existe pas");
		gtk_entry_set_text (cin,"");
		gtk_entry_set_text (nom,"");
		gtk_entry_set_text (prenom,"");
		gtk_entry_set_text (numero,"");
		gtk_entry_set_text (age,"");
		gtk_entry_set_text (sexe,"");
		gtk_entry_set_text (email,"");
		gtk_entry_set_text (poste,"");

}
}
if(v==0)
{
	gtk_entry_set_text (cin,p.cin);
	gtk_entry_set_text (nom,p.nom);
	gtk_entry_set_text (prenom,p.prenom);
	if(strcmp(p.sexe,"Homme")==0)
	{
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (se1),TRUE);
	}
	else if(strcmp(p.sexe,"Femme")==0) {
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (se2),TRUE);
	}
	i=0;
	while(i<6 && strcmp(matrice[i],p.poste)!=0)
	{
	i++;}
	gtk_combo_box_set_active(GTK_COMBO_BOX(poste),i);
	
	gtk_spin_button_set_value(age,p.age);
	sprintf(nmch,"%d",p.num);
	gtk_entry_set_text(numero,nmch);
	gtk_entry_set_text (email,p.email);
	gtk_widget_hide (message);
}
}


void
on_bk_aff_users_btn_clicked            (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *windowbk_show, *window_destroy;
GtkWidget *treeview1;
window_destroy=lookup_widget(objet,"bk_welcome");
gtk_widget_destroy(window_destroy);
windowbk_show=create_bk_aff();
gtk_widget_show (windowbk_show);

treeview1=lookup_widget(windowbk_show,"bk_treeview");
aff_user(treeview1);
}


void
on_bk_inscrit_admin_incrit_btn_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_bk_inscrit_admin_retour_btn_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_bk_confirmer_check_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
x=1;
}


void
on_bk_add_homme_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
sexe=1;
}


void
on_bk_add_femme_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
sexe=2;
}


void
on_bk_accualiser_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview1;

w1=lookup_widget(objet,"bk_aff");
fenetre_afficher=create_bk_aff();
gtk_widget_show(fenetre_afficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(fenetre_afficher,"bk_treeview");
aff_user(treeview1);
}


void
on_bk_modif_homme_activate             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
sexem=1;
}


void
on_bk_modif_femme_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
sexem=2;
}



void
on_bk_treemvt_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_bk_refresh_mvt_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview1;

w1=lookup_widget(objet,"bk_liste");
fenetre_afficher=create_bk_liste();
gtk_widget_show(fenetre_afficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(fenetre_afficher,"bk_treemvt");
afficher_mvt(treeview1);
}







void
on_fobuttonactualiser_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fowindowaffiche,*w1;
GtkWidget *fotreeview1;
w1=lookup_widget(button,"fowindowaffiche");
fowindowaffiche=create_fowindowaffiche();
gtk_widget_show(fowindowaffiche);
gtk_widget_hide(w1);
fotreeview1=lookup_widget(fowindowaffiche,"fotreeview1");
foafficher("menu.txt",fotreeview1);

}


void
on_bk_dashboard_btn_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowbk_liste, *window_destroy;
window_destroy=lookup_widget(button,"bk_welcome");
gtk_widget_destroy(window_destroy);
windowbk_liste=create_bk_liste();
gtk_widget_show (windowbk_liste);
}

