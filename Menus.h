/*******************************************************************************
 Function:	  	menu_admin
 Description:   Muestra el menu de las opciones propias del usuario Admin
 Input:		  	Nada
 Return:	  	Nada
*******************************************************************************/

void menu_admin(){
	
	int opcion = 1, i, indice = 0;
	char cuenta[10 + 1];
	char caracter;

	while(opcion != 0){

		printf("     ADMINISTRACION\n\n 1 VER USUARIOS REGISTRADOS\n 2 HABILITAR / DESHABILITAR USUARIOS\n 3 MENU PRINCIPAL\n\n DIGITE LA OPCION ");
		scanf("%d", &opcion);

		if(opcion == 1 && numero_usuarios < 2){
			system("cls");
			printf(" No hay Usuarios para mostrar!!!\n\n Presione tecla para Continuar..... ");
			getch();
			system("cls");
		}else if(opcion == 1){
			
			system("cls");
			printf("\n  CUENTA         USUARIO               IDENTIFICACION    SALDO      ESTADO CUENTA\n\n");

			for(i=0; i < (numero_usuarios - 1); i++){
				//printf("  %s    %.*s...    %s         %d   ", usuario[i+1].cuenta, 10, usuario[i+1].nombre, usuario[i+1].identificacion, usuario[i+1].monto);
				printf("  %-13.13s  %-20.20s  %-13.13s     %d    ", usuario[i+1].cuenta, usuario[i+1].nombre, usuario[i+1].identificacion, usuario[i+1].monto);
				
				if(usuario[i+1].estado == 1)
					printf("Habilitada\n");
				else
					printf("Deshabilitada\n");
			}
			
			printf("\n Pulse tecla para regresar.....");
			getch();
			system("cls");
		}else if(opcion == 2){// Si la opcion seleccionada es la 2.....
			
			indice = 0;
			system("cls");
			printf("\n  CUENTA         USUARIO               IDENTIFICACION    SALDO      ESTADO CUENTA\n\n");

			for(i=0; i < (numero_usuarios - 1); i++){// Mostrare todas las cuentas excepto la de admin, que esta en la posicion 0 del array
				printf("  %-13.13s  %-20.20s  %-13.13s     %d    ", usuario[i+1].cuenta, usuario[i+1].nombre, usuario[i+1].identificacion, usuario[i+1].monto);

				if(usuario[i+1].estado == 1)// Si el campo estado vale 1, la cuenta esta habilitada. De lo contrario esta deshabilitada
					printf("Habilitada\n");
				else
					printf("Deshabilitada\n");
			}
			printf(" -------------------------------------------------------------------------------------\n\n");//Mostramos nuevamente el menu.....
			printf(" HABILITAR / DESHABILITAR CUENTA\n ESCAPE PARA CANCELAR\n\n Ingrese el Numero de Cuenta que Quiere Modificar\n ");
			
			for(i=0; i < 12; i++){// Guardamos caracter por caracter el numero de cuenta que se ingresara por teclado
				
				if(i == 11)
					i = 15;
				else{
					
					caracter = getch();
					
					if(isalpha(caracter))
						i--;
					else{
						
						switch(caracter){
							case '\b':
								if(i > 0){
									i--;
									cuenta[i] = '\0';
									i--;
									putchar('\b');
									putchar(' ');
									putchar('\b');
								}
								break;
							case 27:
								system("cls");
								printf(" Proceso cancelado!!!\n\n Presione cualquier tecla para Continuar.... ");
								getch();
								system("cls");
								menu_admin();
								break;
							case 13:
								if(i == 10)									
									i = 15;									
								else
									i--;
								break;
							default:
								putchar(caracter);
								cuenta[i] = caracter;
								cuenta[i+1] = '\0';
								break;	
						}
					}
				}
			}
			
			for(i=0; i < numero_usuarios; i++){
				
				if(strcmp(cuenta, usuario[i].cuenta) == 0)
					indice = i;
					
			}
			
			if(indice == 0){
				system("cls");
				printf(" La Cuenta %s no Existe!!!\n\n Presione tecla para Continuar.... ", cuenta);
				getch();
				system("cls");
				
			}
			else{
				
				system("cls");
				printf(" CUENTA SELECCIONADA\n\n ----------------------------\n CUENTA: %s\n NOMBRE: %s\n CORREO: %s\n SALDO:  %d", usuario[indice].cuenta, usuario[indice].nombre, usuario[indice].correo, usuario[indice].monto);
				printf("\n ----------------------------\n\n");
				printf(" OPCIONES\n\n 1 HABILITAR\n 2 DESHABILITAR\n\n DIGITE LA OPCION: ");
				scanf("%d", &opcion);
				
				if(opcion == 1){
					
					if(usuario[indice].estado == 1){
						system("cls");
						printf(" La Cuenta ya esta Habilitada!!!\n\n Presione tecla para Continuar.... ");
						getch();
						system("cls");
					}
					else{
						system("cls");
						usuario[indice].estado = 1;
						printf(" La Cuenta %s ha sido Habilitada!!!\n\n Presione tecla para Continuar.... ", cuenta);
						getch();
						system("cls");
					}
					
				}else{
					
					if(usuario[indice].estado == 0){
						system("cls");
						printf(" La Cuenta ya esta Deshabilitada!!!\n\n Presione tecla para Continuar.... ");
						getch();
						system("cls");
					}
					else{
						system("cls");
						usuario[indice].estado = 0;
						printf(" La Cuenta %s ha sido Deshabilitada!!!\n\n Presione tecla para Continuar.... ", cuenta);
						getch();
						system("cls");
					}
				}
			}
			
			
		}else{
			system("cls");
			return;			
		}
	}
}

/****************************************************************************************************************************************
 Function:	  	menu_usuario
 Description:   Muestra el menu de las opciones propias del usuario comun
 Input:		  	Indice = Indice del usuario que ha ingresado. Dentro del menu el usuario podra realizar ciertas acciones propias de su cuenta
 Return:	  	Nada
******************************************************************************************************************************************/

void menu_usuario(int indice){
	
	int opcion = 1, i, j, valida_cuenta = 0;
	long monto;
	char caracter;
	char cuenta[10 + 1];

	printf(" INGRESO EXITOSO!!!!\n --------------------------------------");

	while(opcion != 4){

		printf("\n CUENTA: %s\n USUARIO: %s\n SALDO: $ %d\n --------------------------------------", usuario[indice].cuenta, usuario[indice].nombre, usuario[indice].monto);
		printf("\n MENU\n\n 1 DEPOSITAR SALDO\n 2 RETIRAR SALDO\n 3 TRANSACCION\n 4 MENU PRINCIPAL\n\n DIGITE LA OPCION ");
		scanf("%d", &opcion);
		
		if(opcion == 1){
			
			system("cls");
			printf("\n --------------------------------------");
			printf("\n CUENTA: %s\n USUARIO: %s\n SALDO: $ %d\n --------------------------------------", usuario[indice].cuenta, usuario[indice].nombre, usuario[indice].monto);
			printf("\n INGRESE LA CANTIDAD QUE DESEA DEPOSITAR: ");
			scanf("%d", &monto);
			usuario[indice].monto = usuario[indice].monto + monto;
			system("cls");
			printf(" Deposito Exitoso!!!!\n\n Presione Tecla para continuar.... ");
			getch();
			system("cls");
		}
		else if(opcion == 2){
			
			system("cls");
			printf("\n --------------------------------------");
			printf("\n CUENTA: %s\n USUARIO: %s\n SALDO: $ %d\n --------------------------------------", usuario[indice].cuenta, usuario[indice].nombre, usuario[indice].monto);
			printf("\n INGRESE LA CANTIDAD QUE DESEA RETIRAR: ");
			scanf("%d", &monto);

			if(monto > usuario[indice].monto){
				system("cls");
				printf(" No hay suficiente Saldo en la Cuenta!!!!\n\n Presione tecla para Continuar...... ");
				getch();
				system("cls");
			}else{
				usuario[indice].monto = usuario[indice].monto - monto;
				system("cls");
				printf(" Retiro Exitoso!!!!\n\n Presione tecla para Continuar...... ");
				getch();
				system("cls");
			}
			
		}else if(opcion == 3){
			
			system("cls");
			printf("\n --------------------------------------");
			printf("\n CUENTA: %s\n USUARIO: %s\n SALDO: $ %d\n --------------------------------------", usuario[indice].cuenta, usuario[indice].nombre, usuario[indice].monto);
			
			printf("\n INGRESE EL NUMERO DE CUENTA AL QUE DESEA DEPOSITAR o ESCAPE PARA CANCELAR: ");
			
			for(i=0; i < 15; i++){
				
				caracter = getch();
				
				if(isalpha(caracter)){
					i--;
				}else{

					switch(caracter){
						case '\b':
							if(i > 0){
								i--;
								cuenta[i] = '\0';
								i--;
								putchar('\b');
								putchar(' ');
								putchar('\b');
							}
							break;
						case 27:
							system("cls");
							i = 30;
							break;
						case 13:
							if(i < 10)
								i--;
							else{
								
								for(j=0; j < numero_usuarios; j++){
									if(strcmp(cuenta, usuario[j].cuenta) == 0 && j != indice)
										valida_cuenta = j;
								}

								if(valida_cuenta == 0){
									system("cls");
									printf(" La Cuenta %s no Existe!!!\n\n Presione tecla para Continuar.... ", cuenta);
									getch();
									system("cls");
									i = 30;
									valida_cuenta = 0;
								}else{

									printf("\n Ingrese la Cantidad de saldo que desea Depositar en la cuenta %s: ", cuenta);
									scanf("%d", &monto);

									if(usuario[indice].monto < monto){
										system("cls");
										printf(" Saldo insuficiente!!!!\n\n Presione tecla para Continuar.... ");
										getch();
										system("cls");
										i = 30;
										valida_cuenta = 0;
										break;

									}else{
										
										usuario[indice].monto = usuario[indice].monto - monto;
										usuario[valida_cuenta].monto = usuario[valida_cuenta].monto + monto;
										valida_cuenta = 0;
										system("cls");
										i = 30;
										printf(" Transaccion Exitosa!!\n\n Presione tecla para Continuar.... ");	
										getch();
										system("cls");
										break;
									}
								}
							}
							break;
						default:
							putchar(caracter);
							cuenta[i] = caracter;
							cuenta[i+1] = '\0';
							break;
					}
				}
			}
		}
	}
	
	system("cls");
	
}
