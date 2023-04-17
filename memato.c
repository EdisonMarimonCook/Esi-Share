#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include "PASOS.h"

void menu_pasos(){
    int selector;
    printf("|||||||||||||||||||||||||||||||\n");
    printf("|   Seleccione una opcion:    |\n");
    printf("|       1.CREAR VIAJE         |\n");
    printf("|    2.SELECIONAR VIAJE       |\n");
    printf("|||||||||||||||||||||||||||||||\n");
    scanf("%d",&selector);
    fflush(stdin);
    system("cls");
    while (selector<1 || selector>2){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("|||||||||||||||||||||||||||||||\n");
        printf("|   Seleccione una opcion:    |\n");
        printf("|       1.CREAR VIAJE         |\n");
        printf("|    2.SELECIONAR VIAJE       |\n");
        printf("|||||||||||||||||||||||||||||||\n");
        scanf("%d",&selector);
        system("cls");
    }
    if (selector==1)
        CREAR_VIAJE();
    else
        selector_camino();
}

void CREAR_VIAJE(){
    int selector;
    printf("||||||||||||||||||||||||||||||||||||||\n");
    printf("|       Seleccione una opcion:       |\n");
    printf("|      1.VIAJE DE IDA(A LA ESI)      |\n");
    printf("|    2.VIAJE DE VUELTA(DE LA ESI)    |\n");
    printf("||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&selector);
    fflush(stdin);
    system("cls");
    while (selector<1 || selector>2){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("||||||||||||||||||||||||||||||||||||||\n");
        printf("|       Seleccione una opcion:       |\n");
        printf("|      1.VIAJE DE IDA(A LA ESI)      |\n");
        printf("|    2.VIAJE DE VUELTA(DE LA ESI)    |\n");
        printf("||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&selector);
        system("cls");
    }
    if (selector==1)
        ida_recorrido();
    else
        vuelta_recorrido();
}


int main(){
   menu_pasos();
}
