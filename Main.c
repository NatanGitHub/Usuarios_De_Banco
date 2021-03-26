#include <stdio.h>
#include <string.h>
#include "CrearUsuario.h"
#include "PedirValidar.h"
#include "Menus.h"

void crea_usuario();
int valida_nombre(char*);
int valida_correo(char*);
int valida_identificacion(char*);
int valida_clave(char*);
char valida_usuario(char*, int);
void menu_admin();
void menu_usuario(int);

int main(){
	
	int i, opcion, j, indice = -1, tipo;
	char nombre[30 + 1];
	char correo[30 + 1];
	char clave[30 + 1];
	
	strcpy(usuario[0].correo, "admin@wposs.com");
	strcpy(usuario[0].clave, "Admin123*");
	usuario[0].rol = 1;
		
	// Damos valores al usuario admin

	for(i=0; opcion != 27; i++){

		printf("   MENU PRINCIPAL - SISTEMA BANCARIO\n\n   ESCAPE PARA SALIR\n 1 CREAR USUARIO \n 2 LOGIN DE USUARIO\n\n DIGITE LA OPCION ");
		opcion = getch();
		
		switch(opcion){
			case '1':
				system("cls");
				crea_usuario();
				break;
			case '2':
				system("cls");

				system("cls");
				printf(" LOGIN DE USUARIO\n\n CORREO: ");
				tipo = 1;
				correo[30+1] = valida_usuario(correo, 1);
				tipo = 2;
				printf("\n CLAVE: ");
				clave[30+1] = valida_usuario(clave, 2);
				
				for(j=0; j < numero_usuarios; j++){
					if(strcmp(correo, usuario[j].correo) == 0)
						indice = j;
				}
					
				if(indice == 0){
					system("cls");
					if(strcmp(clave, usuario[indice].clave) == 0)
						menu_admin();
					else{
						system("cls");
						printf(" Usuario o Clave Incorrectos!!!\n\n Presione tecla para Continuar.... ");
						getch();
						system("cls");
					}					
									
				}else if(indice > 0){
					system("cls");
					if(strcmp(clave, usuario[indice].clave) == 0){
					
						if(usuario[indice].estado == 0){
							system("cls");
							printf(" La Cuenta se encuentra Deshabilitada!!! Comuniquese con su Asesor.\n\n Presione cualquier tecla para Continuar.... ");
							getch();
							system("cls");							
						}else
							menu_usuario(indice);
						
					}
					else{
						system("cls");
						printf(" Usuario o Clave Incorrectos!!!\n\n Presione cualquier tecla para Continuar.... ");
						getch();
						system("cls");
					}
						
				}else{
					system("cls");
					printf(" El Usuario no Existe!!!\n\n Presione cualquier tecla para Continuar.... ");
					getch();
					system("cls");
				}
				indice = -1;
				break;
			case 27:
				system("cls");
				printf(" Sesion Finalizada\n\n Presione cualquier tecla para Cerrar.... ");
				getch();
				return 0;
				break;
			default:
				system("cls");
				printf(" La opcion no Existe!!!\n\n Presione cualquier tecla para Continuar.... ");
				getch();
				system("cls");
				break;
		}
	}
	
	return 0;
}
