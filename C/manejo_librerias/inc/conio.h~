#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>


#ifndef consola
#define consola system
#endif

#ifndef retorna
#define retorna return
#endif


#define estru struct

typedef int ent;
typedef char car;
typedef float flo;
typedef FILE ARCH;
*/

char *gris="\033[0;37m";
char *rojo="\033[1;31m";
char *blanco="\033[1;37m";
char *verde="\033[1;32m";
char *cyan="\033[1;36m";
char *amarillo="\033[1;33m";
char *azul="\033[1;34m";

void clrscr(void)
    {
	system("clear");
    }
void textcolor(int i){
	if (i==1)
	  printf("%s",gris);
	if (i==2)
	  printf("%s",rojo);
	if(i==3)
	  printf("%s",blanco);
	if(i==4)
	  printf("%s",verde);
	if(i==5)
	  printf("%s",cyan);
	if(i==6)
	  printf("%s",amarillo);
	if(i==7)
	  printf("%s",azul);
}
