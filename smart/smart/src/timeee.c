#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "timeee.h"
#include <string.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  heure
//
// time() : La valeur renvoyée correspond au nombre de secondes écoulées depuis le premier janvier 1970.
//
//  Syntaxe : heure
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////// Main /////////////////////////////////////////////////////////////////////
char datetime ()
{
  int i;
char day[200],datime[300];
  time_t secondes;
  struct tm instant;
  //while(1){
  time(&secondes);
  instant=*localtime(&secondes);
  
                sprintf(day,"%d",instant.tm_mday+1);
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
		
//}
return datime;
}
