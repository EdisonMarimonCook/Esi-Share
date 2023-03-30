#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include "PASOS.h"

int main(){
    menu_pasos();
}

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
        fflush(stdin);
        system("cls");
    }
    if (selector==1)
        CREAR_VIAJE();
    if (selector==2)
        selector_camino();
}

int CREAR_VIAJE(){
    int selector;
    printf("|||||||||||||||||||||||||||||||||||||||||\n");
    printf("|       Seleccione un tipo de viaje:    |\n");
    printf("|         1.VIAJE DE IDA(A LA ESI)      |\n");
    printf("|       2.VIAJE DE VUELTA(DE LA ESI)    |\n");
    printf("|||||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&selector);
    fflush(stdin);
    system("cls");
    while (selector<1 || selector>2){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("|||||||||||||||||||||||||||||||||||||||||\n");
        printf("|       Seleccione un tipo de viaje:    |\n");
        printf("|         1.VIAJE DE IDA(A LA ESI)      |\n");
        printf("|       2.VIAJE DE VUELTA(DE LA ESI)    |\n");
        printf("|||||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&selector);
        system("cls");
    }
    if (selector==1)
        ida_recorrido();
    else
        vuelta_recorrido();

    return (selector);
}

void ida_recorrido(){
    FILE *pasos;
    pasos= fopen("pasos.txt", "a+");
    int a=0;
    char ubi1,ubi2,ubi3,ubi4,ubi5,ubi6;
    printf ("|      Selecione la su lugar de salida:        |\n");
    printf ("|      1.Cadiz                                 |\n");
    printf ("|      2.Puerto Real                           |\n");
    printf ("|      3.Jerez                                 |\n");
    printf ("|      4.Chiclana                              |\n");
    printf ("|      5.Sanlucar de Barrameda                 |\n");
    printf ("|      6.Puerto de Sant Maria                  |\n");
    printf ("|      7.San Fernando                          |\n\n");
    scanf("%i",&a);
    fflush(stdin);

    switch(a){
    case 1:
        system("cls");
        printf("Su lugar de salida es Cadiz\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        do{
            printf("1.Plaza Espana(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='S'||ubi1!='s'){
                fprintf(pasos,"-I-Cadiz PlazaEspana");
                a=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Hotel Victoria(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='S'||ubi2=='s'){
                fprintf(pasos,"-I-Cadiz Hospital");
                a=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Barriada Rio San Pedro(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='S'||ubi3=='s'){
                fprintf(pasos,"-I-Cadiz Estadio");
                a=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Puerta Tierra(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='S'||ubi4=='s'){
                fprintf(pasos,"-I-Cadiz PuertaTierra");
                a=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
        break;


    case 2:
        system("cls");
        printf("Su lugar de salida es Puerto Real\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        do{
            printf("1.Estacion de trenes(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='S'||ubi1!='s'){
                fprintf(pasos,"-I-Puerto Real Estaciontrenes");
                a=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Burger King(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='S'||ubi2=='s'){
                fprintf(pasos,"-I-Puerto Real BK");
                a=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Laguna de la Marroquia(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='S'||ubi3=='s'){
                fprintf(pasos,"-I-Puerto Real LagunaMarroquia");
                a=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Casem(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='S'||ubi4=='s'){
                fprintf(pasos,"-I-Puesto Real Casem");
                a=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
        break;


    case 3:
       system("cls");
        printf("Su lugar de salida es Jerez\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        do{
            printf("1.Minotauro (S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='S'||ubi1!='s'){
                fprintf(pasos,"-I-Jerez Minotauro");
                a=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Rotonda(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='S'||ubi2=='s'){
                fprintf(pasos,"-I-Jerez Roronda");
                a=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Estacion de trenes(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='S'||ubi3=='s'){
                fprintf(pasos,"-I-Jerez EstacionTrenes");
                a=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        break;


    case 4:
        system("cls");
        printf("Su lugar de salida es Chiclana\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        do{
            printf("1.Marquesado(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='S'||ubi1!='s'){
                fprintf(pasos,"-I-Chiclana Marquesado");
                a=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Pinar de los franceses(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='S'||ubi2=='s'){
                fprintf(pasos,"-I-Chiclana Franceses");
                a=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.El Novo(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='S'||ubi3=='s'){
                fprintf(pasos,"-I-Chiclana Novo");
                a=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.La Rana Verde/Los Gallos(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                fprintf(pasos,"-I-Chiclana Gallos");
                a=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
        break;


    case 5:
        system("cls");
        printf("Su lugar de salida es Sanlucar de Barrameda\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        do{
            printf("1.El Palmar(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='S'||ubi1!='s'){
                fprintf(pasos,"-I-SanLucar Palmar");
                a=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Avenida 5º Centenario(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='S'||ubi2=='s'){
                fprintf(pasos,"-I-SanLucar Centenario");
                a=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Rotonda(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='S'||ubi3=='s'){
                fprintf(pasos,"-I-SanLucar Rotonda");
                a=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');
        break;


    case 6:
        system("cls");
        printf("Su lugar de salida es Puerto de Santa Maria\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        do{
            printf("1.Estacion de Trenes(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='S'||ubi1!='s'){
                fprintf(pasos,"-I-Puerto Estaciontrenes");
                a=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Valdelagrana(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='S'||ubi2=='s'){
                fprintf(pasos,"-I-Puerto Valdelagrana");
                a=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Sudamerica(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='S'||ubi3=='s'){
                fprintf(pasos,"-I-Puerto Sudamerica");
                a=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Plaza de toros(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='S'||ubi4=='s'){
                fprintf(pasos,"-I-Puerto PlazaToros");
                a=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
        break;


    case 7:
        system("cls");
        printf("Su lugar de salida es San Fernando\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        do{
            printf("1.Parque de la Huerta(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='S'||ubi1=='s'){
                fprintf(pasos,"-I-Sanfer ParqueHuerta");
                a=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Ardila(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='S'||ubi2=='s'){
                fprintf(pasos,"-I-Sanfer Ardila");
                a=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Hornos Punicos(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='S'||ubi3=='s'){
                fprintf(pasos,"-I-Sanfer HornosPunicos");
                a=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Bahia Sur(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='S'||ubi4=='s'){
                fprintf(pasos,"-I-Sanfer BahiaSur");
                a=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');

        do{
            printf("5.Plaza(S/N)\n");
            scanf("%c",&ubi5);
            fflush(stdin);
            if (ubi5=='S'||ubi5=='s'){
                fprintf(pasos,"-I-Sanfer Plaza");
                a=0;
                break;
        }
        if(ubi5!='N'&&ubi5!='S')
           system("cls");
        }while(ubi5!='N'&&ubi5!='S');
        break;

    }
}

void vuelta_recorrido(){
    FILE *pasos;
    pasos= fopen("pasos.txt", "a+");
    int a=0;
    char ubi1,ubi2,ubi3,ubi4,ubi5,ubi6;
    printf ("|      Selecione la su lugar de llegada:       |\n");
    printf ("|      1.Cadiz                                 |\n");
    printf ("|      2.Puerto Real                           |\n");
    printf ("|      3.Jerez                                 |\n");
    printf ("|      4.Chiclana                              |\n");
    printf ("|      5.Sanlucar de Barrameda                 |\n");
    printf ("|      6.Puerto de Sant Maria                  |\n");
    printf ("|      7.San Fernando                          |\n\n");
    scanf("%i",&a);
    fflush(stdin);

    switch(a){
    case 1:
        system("cls");
        printf("Su lugar de llegada es Cadiz\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        do{
            printf("1.Plaza Espana(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='S'||ubi1!='s'){
                fprintf(pasos,"-V-Cadiz PlazaEspana");
                a=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Hotel Victoria(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='S'||ubi2=='s'){
                fprintf(pasos,"-V-Cadiz Hospital");
                a=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Barriada Rio San Pedro(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='S'||ubi3=='s'){
                fprintf(pasos,"-V-Cadiz Estadio");
                a=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Puerta Tierra(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='S'||ubi4=='s'){
                fprintf(pasos,"-V-Cadiz PuertaTierra");
                a=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
        break;


    case 2:
        system("cls");
        printf("Su lugar de llegada es Puerto Real\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        do{
            printf("1.Estacion de trenes(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='S'||ubi1!='s'){
                fprintf(pasos,"-V-Puerto Real Estaciontrenes");
                a=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Burger King(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='S'||ubi2=='s'){
                fprintf(pasos,"-V-Puerto Real BK");
                a=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Laguna de la Marroquia(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='S'||ubi3=='s'){
                fprintf(pasos,"-V-Puerto Real LagunaMarroquia");
                a=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Casem(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='S'||ubi4=='s'){
                fprintf(pasos,"-V-Puesto Real Casem");
                a=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
        break;


    case 3:
       system("cls");
        printf("Su lugar de llegada es Jerez\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        do{
            printf("1.Minotauro (S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='S'||ubi1!='s'){
                fprintf(pasos,"-V-Jerez Minotauro");
                a=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Rotonda(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='S'||ubi2=='s'){
                fprintf(pasos,"-V-Jerez Roronda");
                a=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Estacion de trenes(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='S'||ubi3=='s'){
                fprintf(pasos,"-V-Jerez EstacionTrenes");
                a=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');
        break;


    case 4:
        system("cls");
        printf("Su lugar de llegada es Chiclana\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        do{
            printf("1.Marquesado(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='S'||ubi1!='s'){
                fprintf(pasos,"-V-Chiclana Marquesado");
                a=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Pinar de los franceses(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='S'||ubi2=='s'){
                fprintf(pasos,"-V-Chiclana Franceses");
                a=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.El Novo(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='S'||ubi3=='s'){
                fprintf(pasos,"-V-Chiclana Novo");
                a=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.La Rana Verde/Los Gallos(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                fprintf(pasos,"-V-Chiclana Gallos");
                a=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
        break;


    case 5:
        system("cls");
        printf("Su lugar de llegada es Sanlucar de Barrameda\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        do{
            printf("1.El Palmar(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='S'||ubi1!='s'){
                fprintf(pasos,"-V-SanLucar Palmar");
                a=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Avenida 5º Centenario(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='S'||ubi2=='s'){
                fprintf(pasos,"-V-SanLucar Centenario");
                a=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Rotonda(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='S'||ubi3=='s'){
                fprintf(pasos,"-V-SanLucar Rotonda");
                a=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');
        break;


    case 6:
        system("cls");
        printf("Su lugar de llegada es Puerto de Santa Maria\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        do{
            printf("1.Estacion de Trenes(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='S'||ubi1!='s'){
                fprintf(pasos,"-V-Puerto Estaciontrenes");
                a=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Valdelagrana(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='S'||ubi2=='s'){
                fprintf(pasos,"-V-Puerto Valdelagrana");
                a=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Sudamerica(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='S'||ubi3=='s'){
                fprintf(pasos,"-V-Puerto Sudamerica");
                a=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Plaza de toros(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='S'||ubi4=='s'){
                fprintf(pasos,"-V-Puerto PlazaToros");
                a=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
        break;


    case 7:
        system("cls");
        printf("Su lugar de llegada es San Fernando\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        do{
            printf("1.Parque de la Huerta(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='S'||ubi1=='s'){
                fprintf(pasos,"-V-Sanfer ParqueHuerta");
                a=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Ardila(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='S'||ubi2=='s'){
                fprintf(pasos,"-V-Sanfer Ardila");
                a=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Hornos Punicos(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='S'||ubi3=='s'){
                fprintf(pasos,"-V-Sanfer HornosPunicos");
                a=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Bahia Sur(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='S'||ubi4=='s'){
                fprintf(pasos,"-V-Sanfer BahiaSur");
                a=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');

        do{
            printf("5.Plaza(S/N)\n");
            scanf("%c",&ubi5);
            fflush(stdin);
            if (ubi5=='S'||ubi5=='s'){
                fprintf(pasos,"-V-Sanfer Plaza");
                a=0;
                break;
        }
        if(ubi5!='N'&&ubi5!='S')
           system("cls");
        }while(ubi5!='N'&&ubi5!='S');
        break;

    }
}

void selector_camino(){
    int selector;
    printf("|||||||||||||||||||||||||||||||||||||\n");
    printf("|   Seleccione el tipo de viaje:    |\n");
    printf("|           1.IDA                   |\n");
    printf("|          2.VUELTA                 |\n");
    printf("|||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&selector);
    fflush(stdin);
    system("cls");
    while (selector<1 || selector>2){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("|||||||||||||||||||||||||||||||||||||\n");
        printf("|   Seleccione el tipo de viaje:    |\n");
        printf("|           1.IDA                   |\n");
        printf("|          2.VUELTA                 |\n");
        printf("|||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&selector);
        system("cls");
    }
    if (selector==1)
        selector_i();
    else
        selector_v();
}

int selector_i(){
    int selectorc;
    printf("|||||||||||||||||||||||||||||||||||||\n");
    printf("|   Seleccione su lugar de SALIDA:  |\n");
    printf("|              1.CADIZ              |\n");
    printf("|           2.PUERTO REAL           |\n");
    printf("|             3.JEREZ               |\n");
    printf("|            4.CHICLANA             |\n");
    printf("|      5.SANLUCAR DE BARRAMEDA      |\n");
    printf("|      6.PUERTO DE SANTA MARIA      |\n");
    printf("|          7.SAN FERNANDO           |\n");
    printf("|||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&selectorc);
    fflush(stdin);
    system("cls");
        while (selectorc<1 || selectorc>7){
            printf("Introduzca una opcion correcta\n\n\n");
            printf("|||||||||||||||||||||||||||||||||||||\n");
            printf("|   Seleccione su lugar de SALIDA:  |\n");
            printf("|              1.CADIZ              |\n");
            printf("|           2.PUERTO REAL           |\n");
            printf("|             3.JEREZ               |\n");
            printf("|            4.CHICLANA             |\n");
            printf("|      5.SANLUCAR DE BARRAMEDA      |\n");
            printf("|      6.PUERTO DE SANTA MARIA      |\n");
            printf("|          7.SAN FERNANDO           |\n");
            printf("|||||||||||||||||||||||||||||||||||||\n");
            scanf("%d",&selectorc);
            fflush(stdin);
            system("cls");
    }
    sel(selectorc);
return (selectorc);
}

int selector_v(){
    int selectorc;
    printf("|||||||||||||||||||||||||||||||||||||\n");
    printf("|   Seleccione su lugar de VUELTA:  |\n");
    printf("|              1.CADIZ              |\n");
    printf("|           2.PUERTO REAL           |\n");
    printf("|             3.JEREZ               |\n");
    printf("|            4.CHICLANA             |\n");
    printf("|      5.SANLUCAR DE BARRAMEDA      |\n");
    printf("|      6.PUERTO DE SANTA MARIA      |\n");
    printf("|          7.SAN FERNANDO           |\n");
    printf("|||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&selectorc);
    fflush(stdin);
    while (selectorc<1 || selectorc>7){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("||||||||||||||||||||||||||||||||||||||\n");
        printf("|    Seleccione su lugar de VUELTA:  |\n");
        printf("|              1.CADIZ               |\n");
        printf("|           2.PUERTO REAL            |\n");
        printf("|             3.JEREZ                |\n");
        printf("|            4.CHICLANA              |\n");
        printf("|      5.SANLUCAR DE BARRAMEDA       |\n");
        printf("|      6.PUERTO DE SANTA MARIA       |\n");
        printf("|          7.SAN FERNANDO            |\n");
        printf("||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&selectorc);
        fflush(stdin);
        system("cls");
    }
    sel(selectorc);
return(selectorc);
}

int cadiz(){
    int parada;
    printf("|||||||||||||||||||||||||||||||||||||||||\n");
    printf("|                 CADIZ                 |\n");
    printf("|     Seleccione la parada deseada:     |\n");
    printf("|            1.PLAZA ESPAÑA             |\n");
    printf("|              2.HOSPITAL               |\n");
    printf("|              3.ESTADIO                |\n");
    printf("|           4.PUERTA TIERRA             |\n");
    printf("|||||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&parada);
    fflush(stdin);
    while (parada<1 || parada>4){
        printf("|||||||||||||||||||||||||||||||||||||||||\n");
        printf("|                 CADIZ                 |\n");
        printf("|     Seleccione la parada deseada:     |\n");
        printf("|            1.PLAZA ESPAÑA             |\n");
        printf("|              2.HOSPITAL               |\n");
        printf("|              3.ESTADIO                |\n");
        printf("|           4.PUERTA TIERRA             |\n");
        printf("|||||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&parada);
        fflush(stdin);
        system("cls");
    }
return (parada);
}

int puertoreal(){
    int parada;
    printf("||||||||||||||||||||||||||||||||||||||||\n");
    printf("|             PUERTO REAL              |\n");
    printf("|     Seleccione la parada deseada:    |\n");
    printf("|         1.ESTACION DE TRENES         |\n");
    printf("|           2.BURGER KING              |\n");
    printf("|        3.LAGUNA DE LA MARROQUIA      |\n");
    printf("|              4.CASEM                 |\n");
    printf("||||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&parada);
    fflush(stdin);
    while (parada<1 || parada>4){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("||||||||||||||||||||||||||||||||||||||||\n");
        printf("|             PUERTO REAL              |\n");
        printf("|     Seleccione la parada deseada:    |\n");
        printf("|         1.ESTACION DE TRENES         |\n");
        printf("|           2.BURGER KING              |\n");
        printf("|        3.LAGUNA DE LA MARROQUIA      |\n");
        printf("|              4.CASEM                 |\n");
        printf("||||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&parada);
        fflush(stdin);
        system("cls");
    }
return(parada);
}

int jerez(){
    int parada;
    printf("|||||||||||||||||||||||||||||||||||||||||\n");
    printf("|                  JEREZ                |\n");
    printf("|     Seleccione la parada deseada:     |\n");
    printf("|              1.MINOTAURO              |\n");
    printf("|               2.ROTONDA               |\n");
    printf("|          3.ESTACION DE TRENES         |\n");
    printf("|         4.PUERTO DE SANTA MARIA       |\n");
    printf("|||||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&parada);
    fflush(stdin);
    while (parada<1 || parada>4){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("|||||||||||||||||||||||||||||||||||||||||\n");
        printf("|                 JEREZ                 |\n");
        printf("|     Seleccione la parada deseada:     |\n");
        printf("|              1.MINOTAURO              |\n");
        printf("|               2.ROTONDA               |\n");
        printf("|          3.ESTACION DE TRENES         |\n");
        printf("|         4.PUERTO DE SANTA MARIA       |\n");
        printf("|||||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&parada);
        fflush(stdin);
        system("cls");
    }
return (parada);
}

int chiclana(){
    int parada;
    printf("||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|               CHICLANA                 |\n");
    printf("|    Seleccione la parada deseada:       |\n");
    printf("|             1.MARQUESADO               |\n");
    printf("|               2.EL NOVO                |\n");
    printf("|              3.FRANCESES               |\n");
    printf("|             4.LOS GALLOS               |\n");
    printf("||||||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&parada);
    fflush(stdin);
    while (parada<1 || parada>4){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|               CHICLANA                 |\n");
        printf("|    Seleccione la parada deseada:       |\n");
        printf("|             1.MARQUESADO               |\n");
        printf("|               2.EL NOVO                |\n");
        printf("|              3.FRANCESES               |\n");
        printf("|             4.LOS GALLOS               |\n");
        printf("||||||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&parada);
        fflush(stdin);
        system("cls");
    }
return (parada);
}

int sanlucar(){
    int parada;
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|              SANLUCAR DE BARRAMEDA              |\n");
    printf("|          Seleccione la parada deseada:          |\n");
    printf("|                   1.EL PALMAR                   |\n");
    printf("|                  2.5ºCENTENARIO                 |\n");
    printf("|                3.ROTONDA DEL TREN               |\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&parada);
    fflush(stdin);
    while (parada<1 || parada>3){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|              SANLUCAR DE BARRAMEDA              |\n");
        printf("|          Seleccione la parada deseada:          |\n");
        printf("|                   1.EL PALMAR                   |\n");
        printf("|              2.AVENIDA 5ºCENTENARIO             |\n");
        printf("|                3.ROTONDA DEL TREN               |\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&parada);
        fflush(stdin);
        system("cls");
    }
    return (parada);
}

int puerto(){
    int parada;
    printf("||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|          PUERTO SANTA MARIA            |\n");
    printf("|     Seleccione la parada deseada:      |\n");
    printf("|         1.ESTACION DE TRENES           |\n");
    printf("|            2.VALDELAGRANA              |\n");
    printf("|             3.SUDAMERICA               |\n");
    printf("|            4.PLAZA DE TOROS            |\n");
    printf("||||||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&parada);
    fflush(stdin);
    while (parada<1 || parada>4){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|          PUERTO SANTA MARIA            |\n");
        printf("|     Seleccione la parada deseada:      |\n");
        printf("|         1.ESTACION DE TRENES           |\n");
        printf("|            2.VALDELAGRANA              |\n");
        printf("|             3.SUDAMERICA               |\n");
        printf("|            4.PLAZA DE TOROS            |\n");
        printf("||||||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&parada);
        fflush(stdin);
        system("cls");
    }
return (parada);
}

int sanfer(){
    int parada;
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|                    SAN FERNANDO                  |\n");
    printf("|          Seleccione la parada deseada:           |\n");
    printf("|                 1.PARQUE LA HUERTA               |\n");
    printf("|                     2.ARDILA                     |\n");
    printf("|                 3.HORNOS PUNICOS                 |\n");
    printf("|                    4.BAHIA SUR                   |\n");
    printf("|                      5.PLAZA                     |\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&parada);
    fflush(stdin);
    while (parada<1 || parada>5){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|                    SAN FERNANDO                  |\n");
        printf("|          Seleccione la parada deseada:           |\n");
        printf("|                 1.PARQUE LA HUERTA               |\n");
        printf("|                     2.ARDILA                     |\n");
        printf("|                 3.HORNOS PUNICOS                 |\n");
        printf("|                    4.BAHIA SUR                   |\n");
        printf("|                      5.PLAZA                     |\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&parada);
        fflush(stdin);
        system("cls");
    }
return (parada);
}

void sel(int selectorc){
    switch(selectorc){
        case 1:
            system ("pause");
            system("cls");
            cadiz();
            break;
        case 2:
            system("cls");
            puertoreal();
            break;
        case 3:
            system("cls");
            jerez();
            break;
        case 4:
            system("cls");
            chiclana();
            break;
        case 5:
            system("cls");
            sanlucar();
            break;
        case 6:
            system("cls");
            puerto();
            break;
        case 7:
            system("cls");
            sanfer();
            break;
        }
}
