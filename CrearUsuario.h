#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

/****************************************************************************************************************/

struct USUARIO{
	
	char nombre[30 + 1];// Cadena para 30 caracteres, y uno para el cierre \0
	char correo[30 + 1];
	char clave[10 + 1];// Clave maxima de 10 caracteres
	char identificacion[10 + 1];
	char cuenta[10 + 1];
	int rol;// ROL: 1 Admin ------- 2 Usuario Normal
	long monto;
	int estado; // Si vale 1 esta habilitada, si vale 0 esta deshabilitada
};

struct USUARIO usuario[MAX];

int numero_usuarios = 1;

/****************************************************************************************************************************************
 Function:	  	crea_usuario
 Description:   Gestiona la creacion de los nuevos usuarios
 Input:		  	Nada
 Return:	  	Nada
******************************************************************************************************************************************/

void crea_usuario(){

	char nombre[30+1];
	char correo[30+1];
	char identificacion[10 + 1];
	char clave[10 + 1];
	int i, respuesta = 0;
	
	respuesta = valida_nombre(nombre);	
	if(respuesta == 1)
		return;
	system("cls");
	respuesta = 0;
	respuesta = valida_identificacion(identificacion);
	if(respuesta == 1)
		return;
	system("cls");
	respuesta = 0;
	respuesta = valida_correo(correo);
	if(respuesta == 1)
		return;
	system("cls");
	respuesta = 0;
	respuesta = valida_clave(clave);
	if(respuesta == 1)
		return;
	
	//printf("El correo debe tener %d caracteres", strlen(clave));
	//printf("%s   %s   %s   %s", nombre, identificacion, correo, clave);
	//getch();
	
	strcpy(usuario[numero_usuarios].nombre, nombre);
	strcpy(usuario[numero_usuarios].identificacion, identificacion);
	strcpy(usuario[numero_usuarios].correo, correo);
	strcpy(usuario[numero_usuarios].clave, clave);

	memset(usuario[numero_usuarios].cuenta, 0x00, sizeof(usuario[numero_usuarios].cuenta));
	for(i=0; i < 10; i++){
		usuario[numero_usuarios].cuenta[i] = (1+rand() % (9-1) + 48 );// Obtiene un numero entre 1 y 9
	}
	usuario[numero_usuarios].rol = 2;
	usuario[numero_usuarios].monto = 1000000;
	usuario[numero_usuarios].estado = 1;
	
	printf(" Usuario Creado exitosamente!!!\n\n Presione tecla para Continuar.... ");
	getch();
	system("cls");	
	numero_usuarios++;
		
	
}
