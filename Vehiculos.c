#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "Vehiculos_header.h"

void crear_vehiculo();
void modificar_vehiculo();
void eliminar_vehiculo();

void menu_vehiculos(){
int select;
FILE *vehiculos_file;
char res;
do{
printf("##       ##  ######  ##   ##  ##   #####  ##   ##  ##       ####     ######\n");
printf(" ##     ##   ##      ##   ##  ##  ##      ##   ##  ##     ##    ##  ##\n");
printf("  ##   ##    ######  #######  ##  ##      ##   ##  ##     ##    ##   ######\n");
printf("   ## ##     ##      ##   ##  ##  ##      ##   ##  ##     ##    ##        ##\n");
printf("    ###      ######  ##   ##  ##   #####   #####   #####    ####     ######\n\n");

printf("|| ########################################## ||\n");
printf("|| Seleccione una de las siguientes opciones  ||\n");
printf("||                                            ||\n");
printf("|| 1. Añadir un vehículo                      ||\n");
printf("|| 2. Modificar un vehículo ya existente      ||\n");
printf("|| 3. Eliminar un vehículo                    ||\n");
printf("|| 4. Salir del menú                          ||\n");
printf("||                                            ||\n");
printf("|| ########################################## ||\n\n");
scanf("%d",&select);

while(select<1||select>4){
    printf("\n\n====================================================================\n");
    printf("ERROR: Por favor, seleccione una opción válida (números entre 1 y 4)\n");
    printf("====================================================================\n\n");
    scanf("%d",&select);
}
system("cls");

vehiculos_file = fopen("Vehiculos.txt","a+");

if(vehiculos_file == NULL){
	printf("Ha habido un problema al abrir el fichero. Por favor, inténtelo más tarde.");
	exit(1);
}
	switch(select){
    	case 1:
   	    	crear_vehiculo(vehiculos_file);
   	    	break;
  	    case 2:
   	    	modificar_vehiculo();
  			break;
 	    case 3:
   	    	eliminar_vehiculo();
   	    	break;
   	    case 4:
   	    	exit(1);
   	   	
   	}

fclose(vehiculos_file);

printf("\n¿Desea continuar en el menú de vehículos? (pulse s para continuar)\n");
scanf(" %c",&res);

system("cls");
}while(res=='s'||res=='S');
}

int main(){
    setlocale(LC_ALL, "spanish");
    menu_vehiculos();
    return(0);
}

// ##### FUNCIONES PRINCIPALES #####
void crear_vehiculo(FILE *vehiculos_file){
	estruct_vehiculos vehiculos;																									//Definición de una variable de tipo "estruct_vehiculos" llamada "vehiculos"
do{	
	printf("Introduzca la matrícula del vehículo: ");
	fflush(stdin);
	fgets(vehiculos.Id_mat,8,stdin);																								//Usando fgets, leemos la matrícula que ha introducido el usuario
	
	fflush(stdin);
	if(comprobar_matricula(vehiculos.Id_mat)==0){																					//Error de formato de matrícula
		printf("\nERROR: Vuelva a introducir la matrícula en un formato correcto (4 números seguidos de 3 letras mayúsculas).\n");
		system("pause");
		system("cls");
	}
	if(strlen(vehiculos.Id_mat)>8){ 																								//Error de longitud de matrícula
		printf("\nERROR: La matrícula que debe introducir no puede superar los 7 caracteres en longitud.\n");
		system("pause");
		system("cls");
		//NO FUNCIONA ????
	}
}while(comprobar_matricula(vehiculos.Id_mat)==0||strlen(vehiculos.Id_mat)>8);														//Repetir mientras que se de alguno de los 2 errores

//Lo del ID se lo preguntas al americano

do{
	printf("Introduzca el número de plazas disponibles (No números negativos, entre 1 y 10 plazas):");
	fflush(stdin);
	scanf("%d",&vehiculos.Num_plazas);																								//Ahora usamos scanf, al ser vehiculos.Num_plazas un entero
	if(vehiculos.Num_plazas<0 || vehiculos.Num_plazas>8){																			//Error de número de plazas fuera de rango
		printf("\n\nERROR: Introduzca un número de plazas válido (No puede ser menor que 0 ni mayor que 8).\n");
		system("pause");
		system("cls");
	}
}while(vehiculos.Num_plazas<1 || vehiculos.Num_plazas>10);																			//Repetir mientras que se de el error

do{
	printf("Por último, introduzca una breve descripción del vehículo (No más de 50 caracteres): ");
	fflush(stdin);
	fgets(vehiculos.Desc_veh,sizeof(vehiculos.Desc_veh),stdin);																		//Volvemos a usar fgets para leer la descripción dada por el usuario
	
	if(vehiculos.Desc_veh[0] == '\0'){																								//Error por cadena vacía
		printf("\nERROR: La descripción del vehículo es un campo obligatorio.");
		system("pause");
		system("cls");
	}
	
	if(strlen(vehiculos.Desc_veh)>50){																								//Error por máximo de caracteres superado
		printf("\nERROR: La descripción del vehículo no puede superar los 50 caracteres en longitud.\n");
		system("pause");
		system("cls");
	}
}while(vehiculos.Desc_veh[0] == '\0'||strlen(vehiculos.Desc_veh)>50);

fprintf(vehiculos_file, "%s-%d-%s",vehiculos.Id_mat,vehiculos.Num_plazas,vehiculos.Desc_veh);
}




void modificar_vehiculo(){}

void eliminar_vehiculo(){}


// ##### FUNCIONES SECUNDARIAS #####

int comprobar_matricula(estruct_vehiculos vehiculos){ 																				//Función para comprobar si la matrícula sigue el formato de 4 dígitos y 3 letras			
	int cont;
	for(cont=0;cont<4;cont++){
		if(vehiculos.Id_mat[cont]<48||vehiculos.Id_mat[cont]>57){ 																	//Se comprueba que las 4 primeras posiciones de Id_mat sean caracteres numéricos mediante comparación por su código ASCII respectivo (48='0'...57='9')
			return 0;																												//Usaremos el valor '0' como "incorrecta" y el valor '1' como "válida"
		}
	}
	
	for(cont=4;cont<7;cont++){
		if(vehiculos.Id_mat[cont]<65||vehiculos.Id_mat[cont]>90){ 																	//Hacemos lo mismo que en el bucle anterior, solo que con los códigos de las letras mayúsculas (A hasta Z) 
			return 0;																												//De nuevo, la matrícula sería incorrecta	
		}
	}
	
	return 1;																														//Si al pasar por los dos bucles, la info es correcta, la matrícula es válida
}
