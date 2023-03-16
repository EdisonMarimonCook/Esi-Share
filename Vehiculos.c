
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "Vehiculos_header.h"

void crear_vehiculo(){}
void eliminar_vehiculo(){}
void modificar_vehiculo(){}

void menu_vehiculos(){
int select;
FILE *vehiculos_file;
char res;
do{
printf("##       ##  ######  ##   ##  ##   #####  ##   ##  ##       ####    ######\n");
printf(" ##     ##   ##      ##   ##  ##  ##      ##   ##  ##     ##    ##  ##\n");
printf("  ##   ##    ######  #######  ##  ##      ##   ##  ##     ##    ##   ######\n");
printf("   ## ##     ##      ##   ##  ##  ##      ##   ##  ##     ##    ##        ##\n");
printf("    ###      ######  ##   ##  ##   #####   #####   #####    ####    ######\n\n");

printf("|| ########################################## ||\n");
printf("|| Selecciona una de las siguientes opciones  ||\n");
printf("||                                            ||\n");
printf("|| 1. Añadir un vehículo                      ||\n");
printf("|| 2. Modificar un vehículo ya existente      ||\n");
printf("|| 3. Eliminar un vehículo                    ||\n");
printf("||                                            ||\n");
printf("|| ########################################## ||\n\n");
scanf("%d",&select);

while(select<1||select>3){
    printf("\n\n====================================================================\n");
    printf("ERROR: Por favor, seleccione una opción válida (números entre 1 y 3)\n");
    printf("====================================================================\n\n");
    scanf("%d",&select);
}
system("cls");

switch(select){
    case 1:
        crear_vehiculo();
    case 2:
        modificar_vehiculo();
    case 3:
        eliminar_vehiculo();
    }
printf("\n¿Desea continuar en el menú de vehículos? (pulse s para continuar)");
scanf(" %c",&res);

system("cls");
}while(res=='s'||res=='S');
}

int main(){
    setlocale(LC_ALL, "spanish");
    menu_vehiculos();
    return(0);
}
