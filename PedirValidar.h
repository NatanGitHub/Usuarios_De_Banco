/*******************************************************************************
 Function:	  	valida_nombre
 Description:   Pide el nombre y lo valida
 Input:		  	nombre = variable donde se guardaran los datos
 Return:	  	Retorna 1 si se cancela el proceso, de lo contrario retornara 0
*******************************************************************************/

int valida_nombre(char* nombre){
	
	int i, opcion;
	char caracter;
	
	printf(" INGRESE ESCAPE PARA CANCELAR EL PROCESO\n\n NOMBRE DEL USUARIO\n Ingrese el Nombre del Usuario ( Maximo 30 Caracteres )\n ");
	
	for(i=0; i < 35;i++){

		if(i == 30){
			system("cls");
			printf(" Se alcanzo el limite maximo de Caracteres!!!\n\n Nombre del Usuario: %s\n Desea Guardarlo?\n 1 SI\n 2 CAMBIARLO\n\n DIGITE OPCION ", nombre);
			scanf("%d", &opcion);
			if(opcion == 1)
				return 0;
			else{
				nombre[0] = '\0';
				i = -1;// Le digo que valga -1, cuando vuelva arriba, valdra cero y empezara el guardado desde la posicion 0
				system("cls");
				printf(" INGRESE ESCAPE PARA CANCELAR EL PROCESO\n\n NOMBRE DEL USUARIO\n Ingrese el Nombre del Usuario ( Maximo 30 Caracteres )\n ");
			}// Controlamos el limite maximo de caracteres en la variable nombre
		}// Fin de if...

		else{

			if(isdigit(caracter) && caracter != '0'){
					if(i >= 0)
						i--;
			}else{
				caracter = getch();
				
				switch(caracter){
				case 27:
					system("cls");
					printf(" Se ha Cancelado el proceso\n\n Presione cualquier tecla para Continuar.... ");
					getch();
					system("cls");
					return 1;
				case '\b':
					if(i > 0){
						i--;
						nombre[i] = '\0';
						i--;
						putchar(' ');
						putchar('\b');
					}
					break;
				case 13:
					if(i > 0){
						system("cls");
						printf(" Nombre del Usuario: %s\n Desea Guardarlo?\n\n 1 SI\n 2 CAMBIARLO\n\n DIGITE OPCION ", nombre);
						scanf("%d", &opcion);
						if(opcion == 1)
							return 0;
						else{
							nombre[0] = '\0';
							i = -1;// Le digo que valga -1, cuando vuelva arriba, valdra cero y empezara el guardado desde la posicion 0
							system("cls");
							printf(" INGRESE ESCAPE PARA CANCELAR EL PROCESO\n\n NOMBRE DEL USUARIO\n Ingrese el Nombre del Usuario ( Maximo 30 Caracteres )\n ");
						}
					}else{
						i--;
						putchar(' ');
						putchar('\b');
					}
					break;
				default:
					putchar(caracter);
					nombre[i] = caracter;
					nombre[i+1] = '\0';
					break;					
				}
			}
			
		}// Fin de else		
	}
}

/*******************************************************************************
 Function:	  	valida_correo
 Description:   Pide el correo y lo valida
 Input:		  	correo = variable donde se guardaran los datos
 Return:	  	Retorna 1 si se cancela el proceso, de lo contrario retornara 0
*******************************************************************************/

int valida_correo(char* correo){
	
	int i, opcion, j = 0, arroba = 0;
	char direccion_correo[30];
	char caracter;

	printf(" INGRESE ESCAPE PARA CANCELAR EL PROCESO\n\n CORREO DEL USUARIO\n Ingrese el Correo del Usuario ( Maximo 30 Caracteres / Formato: ...@email.com )\n ");

	for(i=0; i < 35; i++){

		caracter = getch();

		if(i == 29)
			caracter = 13;
			
			//caracter = getch();
			
		if(caracter == '@')
			arroba = i;

			switch(caracter){
				case 27:
					system("cls");
					printf(" Se ha Cancelado el proceso\n\n Presione cualquier tecla para Continuar.... ");
					getch();
					system("cls");
					return 1;
				case '\b':
					if(i > 0){
						if(correo[i] == '@')
							arroba = 0;
						i--;
						correo[i] = '\0';
						i--;
						putchar('\b');
						putchar(' ');
						putchar('\b');
					}
					break;
				case 13:
					
					if(i > 0){
						
						if(arroba > 3){
							
							for(j=0; correo[arroba] != '\0'; j++){
								direccion_correo[j+1] = '\0';
								direccion_correo[j] = correo[arroba];
								arroba++;
							}// Tengo el formato @........ Ahora me resta averiguar si en esta cadena hay palabras antes y despues del punto
							
							arroba = 0;
							
							for(j=0; direccion_correo[j] != '\0'; j++){
								if(direccion_correo[j] == '.')
									arroba = j;
							}
							
							j = j-2;// El for me esta votando uno mas.....

							if(arroba > 0 && j > arroba+1 && j < arroba+3){
								system("cls");
								printf(" Correo del Usuario: %s\n Desea Guardarlo?\n\n 1 SI\n 2 CAMBIARLO\n\n DIGITE OPCION ", correo);
								scanf("%d", &opcion);

								if(opcion == 1){
									strcpy(usuario[numero_usuarios].correo, correo);
									return 0;
								}
								else{
									correo[0] = '\0';
									i = -1;// Le digo que valga -1, cuando vuelva arriba, valdra cero y empezara el guardado desde la posicion 0
									system("cls");
									printf(" INGRESE ESCAPE PARA CANCELAR EL PROCESO\n\n CORREO DEL USUARIO\n Ingrese el Correo del Usuario ( Maximo 30 Caracteres / Formato: ejemplo@email.com )\n ");
								}
							}else{
								system("cls");
								printf(" El Correo no cumple con el formato!!!\n\n Presione cualquier tecla para Continuar.... ");
								getch();
								system("cls");
								correo[0] = '\0';
								i = -1;// Le digo que valga -1, cuando vuelva arriba, valdra cero y empezara el guardado desde la posicion 0
								printf(" INGRESE ESCAPE PARA CANCELAR EL PROCESO\n\n CORREO DEL USUARIO\n Ingrese el Correo del Usuario ( Maximo 30 Caracteres / Formato: ejemplo@email.com )\n ");
							}

						}else{
							system("cls");
							printf(" El Correo no cumple con el formato!!!\n\n Presione cualquier tecla para Continuar.... ");
							getch();
							system("cls");
							correo[0] = '\0';
							i = -1;// Le digo que valga -1, cuando vuelva arriba, valdra cero y empezara el guardado desde la posicion 0
							printf(" INGRESE ESCAPE PARA CANCELAR EL PROCESO\n\n CORREO DEL USUARIO\n Ingrese el Correo del Usuario ( Maximo 30 Caracteres / Formato: ejemplo@email.com )\n ");
						}
					}					
					else{
						i--;
						putchar(' ');
						putchar('\b');
					}
					break;
				default:
						putchar(caracter);
						correo[i] = caracter;
						correo[i+1] = '\0';
					break;
			}	
	}

}

/*******************************************************************************
 Function:	  	valida_identificacion
 Description:   Pide el numero de cedula
 Input:		  	identificacion = variable donde se guardaran los datos
 Return:	  	Retorna 1 si se cancela el proceso, de lo contrario retornara 0
*******************************************************************************/

int valida_identificacion(char* identificacion){
	
	int i, opcion;
	char caracter;
	
	printf(" INGRESE ESCAPE PARA CANCELAR EL PROCESO\n\n CEDULA DEL USUARIO\n Ingrese el Numero de Cedula ( Maximo 10 Digitos )\n ");
	
	for(i=0; i < 15; i++){
			
		caracter = getch();
		
		switch(caracter){
			case 27:
				system("cls");
				printf(" Se ha Cancelado el proceso\n\n Presione cualquier tecla para Continuar.... ");
				getch();
				system("cls");
				return 1;
			case '\b':
				if(i > 0){
					i--;
					identificacion[i] = '\0';
					i--;
					putchar('\b');
					putchar(' ');
					putchar('\b');
				}
				break;
			case 13:
				
				if(i > 0){
					
					system("cls");
					printf(" Desea registrar el Numero: %s\n 1 SI\n 2 CAMBIAR EL NUMERO\n\n DIGITE LA OPCION ", identificacion);
					scanf("%d", &opcion);

					if(opcion == 1)
						return 0;
					else{
						identificacion[0] = '\0';
						i = -1;// Le digo que valga -1, cuando vuelva arriba, valdra cero y empezara el guardado desde la posicion 0
						system("cls");
						printf(" INGRESE ESCAPE PARA CANCELAR EL PROCESO\n\n CEDULA DEL USUARIO\n Ingrese el Numero de Cedula ( Maximo 10 Digitos )\n ");
					}
				}else
					i = - 1;
				break;
			default:
				if(i == 10 || !isdigit(caracter))
					i--;								
				else{
					putchar(caracter);
					identificacion[i] = caracter;
					identificacion[i+1] = '\0';
				}
				break;
			}
	}
	
}

/*******************************************************************************
 Function:	  	valida_clave
 Description:   Pide y valida una contraseña
 Input:		  	clave = variable donde se guardaran los datos
 Return:	  	Retorna 1 si se cancela el proceso, de lo contrario retornara 0
*******************************************************************************/

int valida_clave(char* clave){
	
	int i, opcion;
	int numero = 0;
	int letra = 0;
	char caracter;
	
	printf(" INGRESE ESCAPE PARA CANCELAR EL PROCESO\n\n CLAVE DEL USUARIO\n Cree la Clave del Usuario ( Maximo 10 Caracteres / Letras y Numeros* )\n ");
	
	for(i=0; i < 15;i++){
			
			caracter = getch();

			if(isdigit(caracter))
				numero++;
			
			if(isalpha(caracter))
				letra++;	
			
			switch(caracter){
				case 27:
					system("cls");
					printf(" Se ha Cancelado el proceso\n\n Presione tecla para Continuar.... ");
					getch();
					system("cls");
					return 1;
				case '\b':
					if(i > 0){
						i--;
						
						if(isdigit(clave[i]))
							numero--;
						if(isalpha(clave[i]))
							letra--;
						
						clave[i] = '\0';
						i--;
						putchar('\b');
						putchar(' ');
						putchar('\b');
					}
					break;
				case 13:
					if(i > 0){
						
						if(strlen(clave) < 6){
							clave[0] = '\0';
							i = -1;// Le digo que valga -1, cuando vuelva arriba, valdra cero y empezara el guardado desde la posicion 0
							system("cls");
							printf(" La Clave es Demasiado corta!!!!\n\n Presione cualquier tecla para Continuar.... ");
							getch();
							system("cls");
							printf(" INGRESE ESCAPE PARA CANCELAR EL PROCESO\n\n CLAVE DEL USUARIO\n Cree la Clave del Usuario ( Maximo 10 Caracteres / Letras y Numeros* )\n ");
						}else if(numero < 2 || letra < 2){
							numero = 0;
							letra = 0;
							clave[0] = '\0';
							i = -1;// Le digo que valga -1, cuando vuelva arriba, valdra cero y empezara el guardado desde la posicion 0
							system("cls");
							printf(" La Clave no cumple con el formato!!!!\n\n Presione cualquier tecla para Continuar.... ");
							getch();
							system("cls");
							printf(" INGRESE ESCAPE PARA CANCELAR EL PROCESO\n\n CLAVE DEL USUARIO\n Cree la Clave del Usuario ( Maximo 10 Caracteres / Letras y Numeros* )\n ");
						}else{
							system("cls");
							printf(" Desea registrar la Clave: %s\n 1 SI\n 2 CAMBIAR LA CLAVE\n\n DIGITE LA OPCION ", clave);
							scanf("%d", &opcion);
							if(opcion == 1){
								system("cls");
								return 0;
							}
							else{
								clave[0] = '\0';
								i = -1;// Le digo que valga -1, cuando vuelva arriba, valdra cero y empezara el guardado desde la posicion 0
								system("cls");
								printf(" INGRESE ESCAPE PARA CANCELAR EL PROCESO\n\n CLAVE DEL USUARIO\n Cree la Clave del Usuario ( Maximo 10 Caracteres / Letras y Numeros* )\n ");
							}	
						}
						
					}else{
						i = -1;
					}
					break;
				default:
					if(i == 10)
						i--;
					else{
						putchar(caracter);
						clave[i] = caracter;
						clave[i+1] = '\0';
					}					
					break;
				}	
	}
	
}

/*********************************************************************************************************************
 Function:	  	valida_usuario
 Description:   Valida el campo que el campo que se enviara cumpla con los requisitos expuestos dentro de la funcion
 Input:		  	cadena = variable donde se guardaran los datos
 Return:	  	Retorna la cadena validada
********************************************************************************************************************/

char valida_usuario(char* cadena, int tipo){
	
	char caracter;
	int i;
		
	for(i=0; i < 31; i++){
			
		caracter = getch();
			
		if(i == 29){
			
			printf(" Limite Maximo!!");
			return *cadena;
				
		}else{
				
			switch(caracter){
				case 27:
					return 0;
					break;
				case 13:
					if(i < 1){
						i = -1;							
					}else{
						return *cadena;
					}
					break;
				case '\b':
					if(i > 0){
						i--;
						cadena[i] = '\0';
						i--;
						putchar('\b');
						putchar(' ');
						putchar('\b');
					}
					break;
				default:
					if(tipo == 1)
						putchar(caracter);
					else
						putchar('*');
					cadena[i] = caracter;
					cadena[i+1] = '\0';
					break;
				}
			}
		}
		
	return *cadena;
}
