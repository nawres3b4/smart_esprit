#ifndef AF_H_INCLUDED
#define AF_H_INCLUDED

#include <gtk/gtk.h>
typedef struct
{
  int jour;
  int mois;
  int annee;
}date;
typedef struct
{
  char spec[20];
  int niv;
}classe;
typedef struct
{
  char nom[30];
  char prenom[30];
  date naissance;
  classe niveau;
  char chambre[20];
  int CIN;
  char tel[20];
}Etudiant;

/************************************************\PROTOTYPE\************************************************/
void ajouter(Etudiant E,char txt[]);
void rechercher(char entry [],int rechoix);
void modifier(int choix,Etudiant E,char carte[]);
void supprimer(char ch[]);
void afficher(GtkWidget *liste,char txt[]);
int niveau(int calcul[],char txt[]);


#endif // AGF_H_INCLUDED
