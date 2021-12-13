#include <gtk/gtk.h>


void
on_treeviewAGF_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonAGFajouter_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_afficherAGF_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonAGFmodif1_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAGFmodif2_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAGFmodif3_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAGFmodif4_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAGFmodif5_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonAGFmodif_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAGFinfo_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonAGFm1_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAGFm3_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAGFm2_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAGFm4_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAGFm5_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonAGFsupprimer_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAGFsup_annuler_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAGFsup_valider_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonwindocalculer_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAGF_back_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbuttonAGFcalcul_4_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonAGFcalcul_5_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonAGFcalcul_2_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonAGFcalcul_3_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonAGFcalcul_1_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button2AGFclaculer_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAGFrechercher_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonAGFrechercher_Chambre_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAGFrechercher_nom_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAGFrechercher_Cin_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_calendar1_day_selected_double_click (GtkCalendar     *calendar,
                                        gpointer         user_data);
