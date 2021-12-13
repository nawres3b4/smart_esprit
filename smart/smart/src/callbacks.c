#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>


#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include  "AGF.h"
#include "timeee.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
//var global

int choix=1,rechoix=1,calcul[5]={0,0,0,0,0};
char sup[100],id[10],nv[200],nat[40],so[200],chambr[20],carte[20];
Etudiant E,ET;


                    ///Afficher///
void
on_treeviewAGF_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* ch1;
gchar* ch2;
gchar* nai;
gchar* cat;
gchar* e;
gchar* g;
gchar* h;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter,path));
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&ch1,1,&ch2,2,&nai,3,&cat,4,&e,5,&g,6,&h,-1);
strcpy(sup,ch1);
strcpy(id,ch2);
strcpy(chambr,e);
sprintf(carte,"%d",g);
strcpy(nat,h);

}
}

void
on_button_afficherAGF_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
char dtagf[300];
GtkWidget *treeviewAGF,*labelAGFtim,* windowAG,*windowAGFcalculer;
treeviewAGF=lookup_widget(button,"treeviewAGF");
afficher(treeviewAGF,"AGF.txt");


}


               ///Ajouter///
void
on_buttonAGFajouter_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *nom,*prenom,*chambre,*cin,*tel,*jour,*mois,*annee,*niveau,*spc,*Carte_in,*valnom;
char x[30];
int validite=0;
nom = lookup_widget(button, "entryAGFnom") ;
strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(nom)));

prenom = lookup_widget(button, "entryAGFprenom") ;
strcpy(E.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

jour= lookup_widget(button, "spinbuttonAGFj");
E.naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

mois= lookup_widget(button, "spinbuttonAGFm");
E.naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));

annee= lookup_widget(button, "spinbuttonAGFa");
E.naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

niveau= lookup_widget(button, "comboboxAGFniv");
strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveau)));
E.niveau.niv=atoi(x);

spc= lookup_widget(button, "comboboxAGFspc");
strcpy(E.niveau.spec,gtk_combo_box_get_active_text(GTK_COMBO_BOX(spc)));

chambre= lookup_widget(button, "entryAGFchambre");
strcpy(E.chambre,gtk_entry_get_text(GTK_ENTRY(chambre)));

cin= lookup_widget(button, "entryAGFcin");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(cin)));
E.CIN=atoi(x);

tel= lookup_widget(button, "entryAGFtelf");
strcpy(E.tel,gtk_entry_get_text(GTK_ENTRY(tel)));





/////////////////


valnom = lookup_widget(button, "labelAGFinva_nom") ; 
if (strlen(E.nom)==0)
{
gtk_label_set_text(GTK_LABEL(valnom),"Champ manquant!!");}
else {
gtk_label_set_text(GTK_LABEL(valnom)," ");
validite++;
}

//////////
valnom = lookup_widget(button, "labelAGFinva_prenom") ; 
if (strlen(E.prenom)==0)
{
gtk_label_set_text(GTK_LABEL(valnom),"Champ manquant!!");}
else {
gtk_label_set_text(GTK_LABEL(valnom)," ");
validite++;
}

////////
valnom = lookup_widget(button, "labelAGFinva_chambre") ; 
if (strlen(E.chambre)==0)
{
gtk_label_set_text(GTK_LABEL(valnom),"Champ manquant!!");}
else {
gtk_label_set_text(GTK_LABEL(valnom)," ");
validite++;
}

/////
Carte_in = lookup_widget(button, "labelAGFinva_cin") ; 
if ((strlen(x)!=8) && (strlen(x)!=7))
{
gtk_label_set_text(GTK_LABEL(Carte_in),"Champ manquant!!");}
else {
gtk_label_set_text(GTK_LABEL(Carte_in)," ");
validite++;
}
//////
valnom = lookup_widget(button, "labelAGFinva_telf") ; 
if (strlen(E.tel)==0)
{
gtk_label_set_text(GTK_LABEL(valnom),"Champ manquant!!");}
else {
gtk_label_set_text(GTK_LABEL(valnom)," ");
validite++;
}
if(validite==5){ajouter(E,"AGF.txt");}


}


                ///Modifier///

void
on_buttonAGFmodif_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *nom,*prenom,*chambre,*tel;
//nom
nom = lookup_widget(button, "entryAGFmodifnom") ;
strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
//prenom
prenom = lookup_widget(button, "entryAGFmodifprenom") ;
strcpy(E.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
//chambre
chambre = lookup_widget(button, "entryAGFmodifchambre") ;
strcpy(E.chambre,gtk_entry_get_text(GTK_ENTRY(chambre)));
//tel
tel = lookup_widget(button, "entryAGFmodiftelf") ;
strcpy(E.tel,gtk_entry_get_text(GTK_ENTRY(tel)));
modifier(choix,E,carte);
}  


void
on_radiobuttonAGFm1_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=1;
}


void
on_radiobuttonAGFm2_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=2;
}


void
on_radiobuttonAGFm3_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=3;
}


void
on_radiobuttonAGFm4_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=4;
}


void
on_radiobuttonAGFm5_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if
(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=5;
}





void
on_buttonAGFinfo_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *nom,*prenom,*chambre,*tel;
//nom
nom = lookup_widget(button, "entryAGFmodifnom") ;
gtk_entry_set_text(GTK_ENTRY(nom),sup);
//prenom
prenom = lookup_widget(button, "entryAGFmodifprenom") ;
gtk_entry_set_text(GTK_ENTRY(prenom),id);
//chambre
chambre = lookup_widget(button, "entryAGFmodifchambre") ;
gtk_entry_set_text(GTK_ENTRY(chambre),chambr);
//tel
tel = lookup_widget(button, "entryAGFmodiftelf") ;
gtk_entry_set_text(GTK_ENTRY(tel),nat);
}



/*************************************************\SUPPRIMER\*************************************************/


void
on_buttonAGFsupprimer_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *WindowAGFsupprimer;
WindowAGFsupprimer = create_WindowAGFsupprimer ();
gtk_widget_show (WindowAGFsupprimer);
}


void
on_buttonAGFsup_annuler_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *WindowAGFsupprimer;
WindowAGFsupprimer=lookup_widget(button,"WindowAGFsupprimer");
gtk_widget_destroy(WindowAGFsupprimer);
}


void
on_buttonAGFsup_valider_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *WindowAGFsupprimer;
supprimer(carte);
WindowAGFsupprimer=lookup_widget(button,"WindowAGFsupprimer");
gtk_widget_destroy(WindowAGFsupprimer);
}

/*************************************************\CALCULER\*************************************************/

void
on_buttonwindocalculer_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAGFcalculer;
windowAGFcalculer = create_windowAGFcalculer ();
gtk_widget_show (windowAGFcalculer);
}


void
on_buttonAGF_back_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAGFcalculer;
windowAGFcalculer=lookup_widget(button,"windowAGFcalculer");
gtk_widget_destroy(windowAGFcalculer);
}

void
on_checkbuttonAGFcalcul_1_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[0]=1;
}
else
{calcul[0]=0;}
}

void
on_checkbuttonAGFcalcul_2_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[1]=1;
}
else
{calcul[1]=0;}
}

void
on_checkbuttonAGFcalcul_3_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[2]=1;
}
else
{calcul[2]=0;}
}



void
on_checkbuttonAGFcalcul_4_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[3]=1;}
else
{calcul[3]=0;}
}


void
on_checkbuttonAGFcalcul_5_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[4]=1;}
else
{calcul[4]=0;}
}









void
on_button2AGFclaculer_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *somme;
int sum;
somme = lookup_widget(button, "labelAGFcalcul_somme") ;
sum=niveau(calcul,"AGF.txt");
sprintf(so,"%d",sum);
gtk_label_set_text(GTK_LABEL(somme),so);
}

/*************************************************\RECHERCHER\*************************************************/
void
on_buttonAGFrechercher_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *carte,*treeviewAGF;
int cn;
char entry[30]; 
//appel rechercher
remove("AGFtemp.txt");
carte= lookup_widget(button, "entryAGFrechercher");
if (rechoix==1)
{
strcpy(entry,gtk_entry_get_text(GTK_ENTRY(carte)));
rechercher(entry,rechoix);
}
if (rechoix==2)
{
strcpy(entry,gtk_entry_get_text(GTK_ENTRY(carte)));
rechercher(entry,rechoix);
}

if (rechoix==3)
{
strcpy(entry,gtk_entry_get_text(GTK_ENTRY(carte)));
rechercher(entry,rechoix);
}

//appel afficher
treeviewAGF=lookup_widget(button,"treeviewAGF");
afficher(treeviewAGF,"AGFtemp.txt");

}


void
on_radiobuttonAGFrechercher_Chambre_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
rechoix=3;
}


void
on_radiobuttonAGFrechercher_nom_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if
(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
rechoix=1;
}


void
on_radiobuttonAGFrechercher_Cin_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
rechoix=2;
}


void
on_calendar1_day_selected_double_click (GtkCalendar     *calendar,
                                        gpointer         user_data)
{
GtkWidget *labelAGFtim;
int i,nbb;
char day[200],datime[300];
  time_t secondes;
  struct tm instant;
  time(&secondes);
  instant=*localtime(&secondes);
  
                sprintf(day,"%d",instant.tm_mday);
		strcpy(datime,strcat(day,"/"));
		sprintf(day,"%d",instant.tm_mon+1);
		strcat(datime,strcat(day,"/"));
		sprintf(day,"%d",instant.tm_year+1900);
		strcat(datime,strcat(day," ; "));
		sprintf(day,"%d",instant.tm_hour);
		strcat(datime,strcat(day,":"));
		sprintf(day,"%d",instant.tm_min);
		strcat(datime,strcat(day,":"));
		sprintf(day,"%d",instant.tm_sec);
		strcat(datime,day);
  //strcpy(dtagf,datetime());
  labelAGFtim = lookup_widget(calendar,"labelAGFtime") ;
  gtk_label_set_text(GTK_LABEL(labelAGFtim),datime);

}

