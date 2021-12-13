#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct date
{
    int j;
    int m;
    int a;
}date_capteur;

typedef struct mesure
{
    char id[20];
    int type;
    char marque[20];
    char etage[5];
    float valeur;
    date_capteur d;
    int h;
    int m;
}mesure;


typedef struct capteur
{
    char id[20];
    int type;
    char bloc[2];
    char marque[20];
    date_capteur d;
}capteur;

void ajouter_capteur(capteur u, char *fname);
void supprimer_capteur(capteur u, char *fname);
void modifier_capteur(capteur u, char *fname);
void afficher_capteur(GtkWidget *liste, char *fname);
void defectueux_capteur(GtkWidget *liste, char *fname);
void ajouter_mesure_capteur(mesure u, char *fname);

