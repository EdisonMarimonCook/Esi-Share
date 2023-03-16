#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "viajes_header.h"

void subir_viaje(){
    estruct_viajes v;
    printf("¡Bienvenido al creador de viajes de ESI Share!\n\nIntroduzca la matrícula del coche que vaya a utilizar: ");
    fflush(stdin);
    fgets(v.Id_mat, sizeof(char), stdin);
}

void eliminar_viaje(FILE *viajes_file){
    char c;
    printf("¿Qué viaje desea eliminar?\n\n");
    do{
        c=fgetc(viajes_file);
        printf("%c", c);
    }while(c!=EOF);
    printf("Introduzca el ID del viaje que desea eliminar:");

}

void modificar_viaje(){
    printf("¿Qué viaje desea modificar?");
}

void menu_viajes(){
    int elect, cont_menu=0;
    FILE *viajes_file;
    char res;
    do{
        printf("##       ##   ##      ###       ########  ######   ######\n");
        printf(" ##     ##    ##     ## ##         ##     ##      ##\n");
        printf("  ##   ##     ##    ##   ##        ##     ######   ######\n");
        printf("   ## ##      ##   #########   ##  ##     ##            ##\n");
        printf("    ###       ##  ##       ##   ####      ######   ######\n");
        printf("\n #######################");
        printf("\n |¿Qué desea hacer?    |");
        printf("\n |                     |");
        printf("\n |1. Añadir un viaje   |\n |2. Eliminar un viaje |\n |3. Modificar un viaje|\n");
        printf(" #######################\n\n");
        scanf("%d", &elect);
        while(elect<1||elect>3){
            printf("VALOR INVÁLIDO: Introduzca '1', '2' o '3' para seleccionar la opción deseada\n");
            scanf("%d", &elect);
        }
        system ("cls");
        viajes_file=fopen("viajes_file.txt", "a+");
        if(viajes_file!=NULL){
            switch (elect){
                case 1: subir_viaje();
                break;
                case 2: eliminar_viaje(viajes_file);
                break;
                case 3: modificar_viaje();
            }
        }else{
            printf("######################################################################\n");
            printf("|Ha ocurrido un error a la hora de abrir el fichero <viajes_file.txt>|\n|    Por favor, inténtelo más tarde o consulte con mantenimiento     |\n");
            printf("######################################################################\n\n");
        }
        fclose(viajes_file);
        printf("\n\n¿Desea continuar modificando sus viajes?\n(s/n)\n");
        scanf(" %c", &res);
        while(res!='s'&&res!='n'&&res!='N'&&res!='S'){
            printf("VALOR INVÁLIDO: Responda con 's' para continuar o 'n' para salir del menú viajes\n");
            scanf(" %c", &res);
        }
        system ("cls");
        if(res=='n'||res=='N'){
            cont_menu++;
        }
    }while(cont_menu==0);
}

int main(){
    setlocale(LC_ALL, "spanish");
    menu_viajes();
    return 0;
}
