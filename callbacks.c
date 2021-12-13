#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"


void
on_button1_ach_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *aj, *dashboard;
	dashboard=lookup_widget(objet,"af");
	aj=lookup_widget(objet,"aj");
	aj=create_aj();
	gtk_widget_show(aj);
}


void
on_button2_ach_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod, *dashboard;
dashboard=lookup_widget(objet,"af");
mod=lookup_widget(objet,"mod");
mod=create_mod();
gtk_widget_show(mod);
}



void
on_button4_ach_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *def, *treeview;
def=lookup_widget(objet,"def");
def=create_def();
gtk_widget_show(def);
treeview=lookup_widget(def,"treeview_def_ach");
defectueux_capteur(treeview,"mesures.txt");
}


void
on_button_mod_ach_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *pInfo, *mod4;
capteur u;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(mod1)));
u.type=gtk_combo_box_get_active(GTK_COMBO_BOX(mod2));
strcpy(u.bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mod4)));
strcpy(u.marque,gtk_entry_get_text(GTK_ENTRY(mod3)));
modifier_capteur(u,"capteurs.txt");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Capteur modifié avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}


void
on_check_id_ach_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *pInfo, *mod4;
capteur p;
int a=0;
char id[50];
FILE *f;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(mod1)));
f = fopen("capteurs.txt","r");
if(f!=NULL){
while(fscanf(f,"%s %d %s %s %d %d %d\n",p.id,&(p.type),p.bloc,p.marque,&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
		if(strcmp(p.id,id)==0){
			a=1;
			break;
                 }
	}
fclose(f);
}
if(a==1){
gtk_combo_box_set_active(GTK_COMBO_BOX(mod2),p.type);
gtk_entry_set_text(GTK_ENTRY(mod3),p.marque);
gtk_combo_box_set_active(GTK_COMBO_BOX(mod4),strcmp(p.bloc,"A")==0?0:strcmp(p.bloc,"B")==0?1:2);
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Capteur introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_button_af_ach_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af;
af=lookup_widget(objet,"af");
gtk_widget_destroy(af);
af=lookup_widget(objet,"af");
af=create_af();
gtk_widget_show(af);
treeview=lookup_widget(af,"treeview_ach");
afficher_capteur(treeview,"capteurs.txt");
}


void
on_button_aj_ach_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *check, *pInfo;
check=lookup_widget(objet,"check_ach");
GtkWidget *aj1, *aj2, *aj3, *a, *b, *c;
GtkCalendar *ajc;
capteur u;
guint day, month, year;
aj1=lookup_widget(objet,"aj1");
aj2=lookup_widget(objet,"aj2");
aj3=lookup_widget(objet,"aj3");
ajc=lookup_widget(objet,"ajc");
a=lookup_widget(objet,"aj4");
b=lookup_widget(objet,"aj5");
c=lookup_widget(objet,"aj6");
strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(aj1)));
u.type=gtk_combo_box_get_active(GTK_COMBO_BOX(aj2));
strcpy(u.bloc,gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(a))?"A":gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))?"B":"C");
strcpy(u.marque,gtk_entry_get_text(GTK_ENTRY(aj3)));
gtk_calendar_get_date(GTK_CALENDAR(ajc), &day, &month, &year);
u.d.j=year;
u.d.m=month+1;
u.d.a=day;
if(gtk_toggle_button_get_active(GTK_CHECK_BUTTON(check)))
ajouter_capteur(u,"capteurs.txt");
else{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Confirmation requise");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
}


void
on_treeview_ach_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar *id;
	capteur u;
	GtkWidget *pInfo;
	GtkTreeModel *model ;
	model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
	strcpy(u.id,id);
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer ce capteur?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo);
	supprimer_capteur(u,"capteurs.txt");
	afficher_capteur(treeview,"capteurs.txt");
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo);
	break;
}
}
}

void
on_button_ajm_ach_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj1, *aj2, *aj3, *aj4, *aj5, *h, *m;
GtkCalendar *ajc;
mesure u;
guint day, month, year;// guint??

aj1=lookup_widget(objet,"ajm1");
aj2=lookup_widget(objet,"ajm2");
aj3=lookup_widget(objet,"ajm3");
aj4=lookup_widget(objet,"ajm4");
aj5=lookup_widget(objet,"ajm5");
ajc=lookup_widget(objet,"ajmc");
h=lookup_widget(objet,"h");
m=lookup_widget(objet,"m");
strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(aj1)));
u.type=gtk_combo_box_get_active(GTK_COMBO_BOX(aj2));
strcpy(u.marque,gtk_entry_get_text(GTK_ENTRY(aj3)));
strcpy(u.etage,gtk_entry_get_text(GTK_ENTRY(aj4)));
u.valeur=atof(gtk_entry_get_text(GTK_ENTRY(aj5)));
gtk_calendar_get_date(GTK_CALENDAR(ajc), &day, &month, &year);
u.d.j=year;
u.d.m=month+1;
u.d.a=day;
u.h=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(h));
u.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
ajouter_mesure_capteur(u,"mesures.txt");
}


void
on_afficher_ach_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *def;
def=lookup_widget(objet,"def");
gtk_widget_destroy(def);
def=lookup_widget(objet,"def");
def=create_def();
gtk_widget_show(def);
treeview=lookup_widget(def,"treeview_def_ach");
defectueux_capteur(treeview,"mesures.txt");
}


void
on_ajouter_ach_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj_mesure, *def;
def=lookup_widget(objet,"def");
aj_mesure=lookup_widget(objet,"aj_mesure");
aj_mesure=create_aj_mesure();
gtk_widget_show(aj_mesure);
}
