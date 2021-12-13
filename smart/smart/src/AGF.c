/************************************************\INCLUDE\************************************************/
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "AGF.h"

/*************************************************\ENUM\*************************************************/
enum
{
	NOM,
	PRENOM,
	DATE,
	NIVEAU,
	CHAMBRE,
	CIN,
	TEL,
	COLUMNS,
};

/*************************************************\AFFICHER\*************************************************/
void afficher(GtkWidget *liste,char txt[])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char ch1[30],h[11],room[20];
	char ch2[30],ech[20],gch[20],hch[20];
	int a,b,c,d,g;
	char ch3[20],nai[100],cat[100];

	FILE *f;
	f=fopen(txt,"r");

	store=gtk_tree_view_get_model(liste);
if(store==NULL)
{    
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Date de naissance",renderer,"text",DATE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Niveau",renderer,"text",NIVEAU,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	column = gtk_tree_view_column_new_with_attributes("Chambre",renderer,"text",CHAMBRE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("N°cin",renderer,"text",CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("N°tel",renderer,"text",TEL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();

	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING);
	while(fscanf(f,"%s %s %d %d %d %d %s %s %d %s \n",ch1,ch2,&a,&b,&c,&d,ch3,room,&g,h)!= EOF)
        {
		sprintf(cat,"%d",a);
		strcpy(nai,strcat(cat,"/"));
		sprintf(cat,"%d",b);
		strcat(nai,strcat(cat,"/"));
		sprintf(cat,"%d",c);
		strcat(nai,cat);
		sprintf(cat,"%d",d);
		strcat(cat,ch3);
		gtk_list_store_append(store,&iter);
		gtk_list_store_set(store,&iter,NOM,ch1,PRENOM,ch2,DATE,nai,NIVEAU,cat,CHAMBRE,room,CIN,g,TEL,h,-1);
        }

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref (store);
}
else
{
	store=NULL;
	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING);
	if(strcmp(txt,"AGF.txt")==0)
	{
		while(fscanf(f,"%s %s %d %d %d %d %s %s %d %s \n",ch1,ch2,&a,&b,&c,&d,ch3,room,&g,h)!= EOF)
		{
			sprintf(cat,"%d",a);
			strcpy(nai,strcat(cat,"/"));
			sprintf(cat,"%d",b);
			strcat(nai,strcat(cat,"/"));
			sprintf(cat,"%d",c);
			strcat(nai,cat);
			sprintf(cat,"%d",d);
			strcat(cat,ch3);
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,NOM,ch1,PRENOM,ch2,DATE,nai,NIVEAU,cat,CHAMBRE,room,CIN,g,TEL,h,-1);
		}
	}
	else 
	{
		while(fscanf(f,"%s %s %s %s %s %d %s\n",ch1,ch2,nai,cat,room,&g,h)!= EOF){
		gtk_list_store_append(store,&iter);
		gtk_list_store_set(store,&iter,NOM,ch1,PRENOM,ch2,DATE,nai,NIVEAU,cat,CHAMBRE,room,CIN,g,TEL,h,-1);}	
	}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref (store);
}
fclose(f);
}

/*************************************************\AJOUTER\*************************************************/
void ajouter(Etudiant E,char txt[])
{
    FILE *f;
    f=fopen(txt,"a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %d %d %d %s %s %d %s\n",E.nom,E.prenom,E.naissance.jour,E.naissance.mois,E.naissance.annee,E.niveau.niv,E.niveau.spec,E.chambre,E.CIN,E.tel);
        fclose(f);
    }
}

/*************************************************\MODIFIER\*************************************************/
void modifier(int choix,Etudiant E,char carte[])
{
    FILE *f,*l;
    char ch1[30],ch2[30],ch3[20];
    char room[20],gch[20],h[11];
    int a,b,c,d,g;
    f=fopen("AGF.txt","r");
    l=fopen("tmp.txt","a+");
    if(f!=NULL)
    {

        while(fscanf(f,"%s %s %d %d %d %d %s %s %d %s \n",ch1,ch2,&a,&b,&c,&d,ch3,room,&g,h)!= EOF)
        {
	    sprintf(gch,"%d",g);
            if ((strcmp(carte,gch)==0)) //&& (strcmp(id,ch2)==0))
            {	
                  strcpy(ch1,E.nom);fscanf(l,"%s %s %d %d %d %d %s %s %d %s \n",ch1,ch2,&a,&b,&c,&d,ch3,room,&g,h);
		  strcpy(ch2,E.prenom);fscanf(l,"%s %s %d %d %d %d %s %s %d %s \n",ch1,ch2,&a,&b,&c,&d,ch3,room,&g,h);
		  d=choix;fscanf(l,"%s %s %d %d %d %d %s %s %d %s \n",ch1,ch2,&a,&b,&c,&d,ch3,room,&g,h);
		  strcpy(room,E.chambre);fscanf(l,"%s %s %d %d %d %d %s %s %d %s \n",ch1,ch2,&a,&b,&c,&d,ch3,room,&g,h);
  		  strcpy(h,E.tel);fscanf(l,"%s %s %d %d %d %d %s %s %d %s \n",ch1,ch2,&a,&b,&c,&d,ch3,room,&g,h);
                  fprintf(l,"%s %s %d %d %d %d %s %s %d %s \n",ch1,ch2,a,b,c,d,ch3,room,g,h);
            }
            else
            {
                fprintf(l,"%s %s %d %d %d %d %s %s %d %s \n",ch1,ch2,a,b,c,d,ch3,room,g,h);
            }
	     
        }
    }
    fclose(f);
    fclose(l);
    remove("AGF.txt");
    rename("tmp.txt","AGF.txt");
}

/*************************************************\CHERCHER\*************************************************/
void rechercher(char entry[]/*char txt[]*/,int rechoix)
{
    FILE *f,*l;
    char ch1[30],nai[20],cat[15],h[11];
    char ch2[30],gch[20];
    int a,b,c,d,g,trouve=0;
    char ch3[20],room[20];
    f=fopen("AGF.txt","r");
    l=fopen("AGFtemp.txt","a");
    if(f!=NULL)
    {
       if (rechoix==1)

      {  while(fscanf(f,"%s %s %d %d %d %d %s %s %d %s \n",ch1,ch2,&a,&b,&c,&d,ch3,room,&g,h)!= EOF)
        {
            if(strcmp(entry,ch1)==0)
            {
		trouve=1;
		sprintf(cat,"%d",a);
		strcpy(nai,strcat(cat,"/"));
		sprintf(cat,"%d",b);
		strcat(nai,strcat(cat,"/"));
		sprintf(cat,"%d",c);
		strcat(nai,cat);
		sprintf(cat,"%d",d);
		strcat(cat,ch3);
		sprintf(gch,"%d",g);
                fprintf(l,"%s %s %s %s %s %s %s\n",ch1,ch2,nai,cat,room,gch,h);
            }
        }
	 if (trouve==0)
	    {
		strcpy(ch1,"invalid");
		strcpy(ch2,"invalid");
		strcpy(nai,"invalid");
		strcpy(cat,"invalid");
		strcpy(room,"invalid");
		g=0;
		strcpy(h,"invalid");
                fprintf(l,"%s %s %s %s %s %d %s\n",ch1,ch2,nai,cat,room,g,h);
	     }
      }
     if (rechoix==2)

      {  while(fscanf(f,"%s %s %d %d %d %d %s %s %d %s \n",ch1,ch2,&a,&b,&c,&d,ch3,room,&g,h)!= EOF)
        { sprintf(gch,"%d",g);
            if(strcmp(entry,gch)==0)
            {
		trouve=1;
		sprintf(cat,"%d",a);
		strcpy(nai,strcat(cat,"/"));
		sprintf(cat,"%d",b);
		strcat(nai,strcat(cat,"/"));
		sprintf(cat,"%d",c);
		strcat(nai,cat);
		sprintf(cat,"%d",d);
		strcat(cat,ch3);
		
                fprintf(l,"%s %s %s %s %s %s %s\n",ch1,ch2,nai,cat,room,gch,h);
            }
        }
	 if (trouve==0)
	    {
		strcpy(ch1,"invalid");
		strcpy(ch2,"invalid");
		strcpy(nai,"invalid");
		strcpy(cat,"invalid");
		strcpy(room,"invalid");
		g=0;
		strcpy(h,"invalid");
                fprintf(l,"%s %s %s %s %s %d %s\n",ch1,ch2,nai,cat,room,g,h);
	     }
      }
      

        if (rechoix==3)

      {  while(fscanf(f,"%s %s %d %d %d %d %s %s %d %s \n",ch1,ch2,&a,&b,&c,&d,ch3,room,&g,h)!= EOF)
        {
            if(strcmp(entry,room)==0)
            {
		trouve=1;
		sprintf(cat,"%d",a);
		strcpy(nai,strcat(cat,"/"));
		sprintf(cat,"%d",b);
		strcat(nai,strcat(cat,"/"));
		sprintf(cat,"%d",c);
		strcat(nai,cat);
		sprintf(cat,"%d",d);
		strcat(cat,ch3);
		sprintf(gch,"%d",g);
                fprintf(l,"%s %s %s %s %s %s %s\n",ch1,ch2,nai,cat,room,gch,h);
            }
        }
	 if (trouve==0)
	    {
		strcpy(ch1,"invalid");
		strcpy(ch2,"invalid");
		strcpy(nai,"invalid");
		strcpy(cat,"invalid");
		strcpy(room,"invalid");
		g=0;
		strcpy(h,"invalid");
                fprintf(l,"%s %s %s %s %s %d %s\n",ch1,ch2,nai,cat,room,g,h);
	     }
      }

     
    }
    fclose(f);
    fclose(l);
}

/*************************************************\SUPPRIMER\*************************************************/
void supprimer(char ch[])
{
    FILE *f,*l;
    char ch1[30];
    char ch2[30],h[11],room[20];
    int a,b,c,d,g;
    char ch3[20],gstr[10],gch[40];
    f=fopen("AGF.txt","r");
    l=fopen("tmp.txt","w");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %d %s %s %d %s \n",ch1,ch2,&a,&b,&c,&d,ch3,room,&g,h)!= EOF)
        {
             sprintf(gch,"%d",g);
            if(strcmp(ch,gch)!=0)
            {
                fprintf(l,"%s %s %d %d %d %d %s %s %d %s \n",ch1,ch2,a,b,c,d,ch3,room,g,h);
            }
        }
    }
    fclose(f);
    fclose(l);
    remove("AGF.txt");
    rename("tmp.txt","AGF.txt");
}



/*************************************************\CALCUL\*************************************************/
int niveau(int calcul[],char txt[])
{


 FILE *f;
    char ch1[30],h[11];
    char ch2[30],room[20];
    int a,b,c,d,g,s1=0,s2=0,s3=0,s4=0,s5=0,s=0;
    char ch3[20];
    f=fopen(txt,"r");
  if(f!=NULL)
  {
        
          
		while(fscanf(f,"%s %s %d %d %d %d %s %s %d %s \n",ch1,ch2,&a,&b,&c,&d,ch3,room,&g,h)!= EOF)
			
        	{ 		if((calcul[0]==1) && (d==1))

                                 {
                                  s1++;

                                 }

  				if((calcul[1]==1) && (d==2))
                                {
                                 s2++;

                                }

 				if((calcul[2]==1) && (d==3))
                                {
              			 s3++;

            			}

 				if((calcul[3]==1) && (d==4))
            			{
              			s4++;

            			}

 				if((calcul[4]==1) && (d==5))
            			{
              			s5++;

            			}
       
    		}
s=s1+s2+s3+s4+s5;
 }
    fclose(f);
return s;
}




