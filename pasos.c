#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include "viajes_header.h"
#include "pasos.h"
#define N 100

void vaciar (char vector[]){  //Hecho

    //Declaración de datos
    int i;


    //Introduzco en valor '\0' en todas las celdas del vector para vaciarlo:
    for(i=0;i<N;i++){
        vector[i]='\0';
    }
}

int CREAR_VIAJE(int id){   //Selecctor si el camino es de ida o de vuelta al momento de crear viaje
    int selector;
    do{   //selecciona el tipo de viaje que quiere, si es de ida o de vuelta a la ESI
    printf("|||||||||||||||||||||||||||||||||||||||||\n");
    printf("|       Seleccione un tipo de viaje:    |\n");
    printf("|         1.VIAJE DE IDA(A LA ESI)      |\n");
    printf("|       2.VIAJE DE VUELTA(DE LA ESI)    |\n");
    printf("|||||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&selector);
    fflush(stdin);
    system("cls");
    }while (selector<1 || selector>2);

    if (selector==1)
        ida_recorrido(id);  //Si selecciona 1 te manda a la funcion de crear los pases de ida a la ESI
    else
        vuelta_recorrido(id);  //Si selecciona 2 te manda a la funcion de crear los pases de vuelta a la ESI

    return (selector);
}

void ida_recorrido(int id){  //Crea los pasos de los caminos que seleccione el usuario de las paradas
    //Abre el fichero
    FILE *pasos;
    pasos= fopen("pasos.txt", "a+");
    int a=0;
    char ubi1,ubi2,ubi3,ubi4,ubi5,ubi6;
    //Selecctor de la cuidad
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
        //Selecctor de las paradas de Cadiz
        system("cls");
        printf("Su lugar de salida es Cadiz\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        fprintf(pasos, "%d-", id);
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
        fprintf(pasos, "\n");
        break;


    case 2:
        //Selecctor de las paradas de Puerto real
        system("cls");
        printf("Su lugar de salida es Puerto Real\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        fprintf(pasos, "%d-", id);
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
        fprintf(pasos, "\n");
        break;


    case 3:
        //Selecctor de las paradas de Jerez
        system("cls");
        printf("Su lugar de salida es Jerez\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        fprintf(pasos, "%d-", id);
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
        fprintf(pasos, "\n");
        break;


    case 4:
        //Selecctor de las paradas de Chiclana
        system("cls");
        printf("Su lugar de salida es Chiclana\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        fprintf(pasos, "%d-", id);
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
            if (ubi4=='S'||ubi4=='s'){
                fprintf(pasos,"-I-Chiclana Gallos");
                a=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
        fprintf(pasos, "\n");
        break;


    case 5:
        //Selector de las paradas de Sanlucar de Barrameda
        system("cls");
        printf("Su lugar de salida es Sanlucar de Barrameda\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        fprintf(pasos, "%d-", id);
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
        fprintf(pasos, "\n");
        break;


    case 6:
        //Selecctor de las paradas del Puerto de Santa Maria
        system("cls");
        printf("Su lugar de salida es Puerto de Santa Maria\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        fprintf(pasos, "%d-", id);
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
        fprintf(pasos, "\n");
        break;


    case 7:
        //Selector de las paradas de San fernando
        system("cls");
        printf("Su lugar de salida es San Fernando\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        fprintf(pasos, "%d-", id);
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
        fprintf(pasos, "\n");
        break;

    }
}

void vuelta_recorrido(int id){   //Crea los pasos del camino del usuario de vuelta a la ESI, con paradas
    //Abre el fichero
    FILE *pasos;
    pasos= fopen("pasos.txt", "a+");
    int a=0;
    char ubi1,ubi2,ubi3,ubi4,ubi5,ubi6;
    //Selector de ciudad
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
        //Selecciona las paradas de Cadiz
        system("cls");
        printf("Su lugar de llegada es Cadiz\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        fprintf(pasos, "%d-", id);
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
        fprintf(pasos, "\n");
        break;


    case 2:
        //Selecciona las paradas de Puerto Real
        system("cls");
        printf("Su lugar de llegada es Puerto Real\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        fprintf(pasos, "%d-", id);
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
        fprintf(pasos, "\n");
        break;


    case 3:
        //Selecciona las paradas de Jerez
        system("cls");
        printf("Su lugar de llegada es Jerez\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        fprintf(pasos, "%d-", id);
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
        fprintf(pasos, "\n");
        break;


    case 4:
        //Selecciona las paradas de Chiclana
        system("cls");
        printf("Su lugar de llegada es Chiclana\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        fprintf(pasos, "%d-", id);
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
            if (ubi4=='S'||ubi4=='s'){
                fprintf(pasos,"-V-Chiclana Gallos");
                a=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
        fprintf(pasos, "\n");
        break;


    case 5:
        //Selecciona las paradas de Sanlucae de Barrameda
        system("cls");
        printf("Su lugar de llegada es Sanlucar de Barrameda\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        fprintf(pasos, "%d-", id);
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
        fprintf(pasos, "\n");
        break;


    case 6:
        //Selecciona las paradas del Puerto de Santa Maria
        system("cls");
        printf("Su lugar de llegada es Puerto de Santa Maria\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        fprintf(pasos, "%d-", id);
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
        fprintf(pasos, "\n");
        break;


    case 7:
        //Selecciona las paradas de San fernando
        system("cls");
        printf("Su lugar de llegada es San Fernando\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        fprintf(pasos, "%d-", id);
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
        fprintf(pasos, "\n");
        break;

    }
}

int selector_camino(){  //Selector si el camino es de ida o de vuelra al momento de selecionar un viaje
    int selector, aux;
    do{  //Seleccion del tipo de viaje que se desea
        printf("|||||||||||||||||||||||||||||||||||||\n");
        printf("|   Seleccione el tipo de viaje:    |\n");
        printf("|          1.IDA A LA ESI           |\n");
        printf("|          2.VUELTA A LA ESI        |\n");
        printf("|||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&selector);
        fflush(stdin);
        system("cls");
    }while (selector<1 || selector>2);
    if (selector==1){
        aux=selector_i();  //Si el viaje es de ida, el selector es 1, lo manda a la funcion selector_i
    }else{
        aux=selector_v();  //Si el viaje es de vuelta, el selector es, lo manda a la funcion selector_v
    }

    return mostrarviaje(aux);
}

int selector_i(){  //Selector de ciudades a la hora de ver viajes de ida
    int selectorc;
    do{
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
    }while (selectorc<1 || selectorc>7);   //Repite un bucle hasta que el usuario meta una opcion correcta
    return (selectorc);  //devuelve la ciudad selecionada
}

int selector_v(){  //Selector de ciudades a la hora de ver viajes de vuelta
    int selectorc;
    do{
        printf("|||||||||||||||||||||||||||||||||||||||\n");
        printf("|    Seleccione su lugar de VUELTA:   |\n");
        printf("|              8.CADIZ                |\n");
        printf("|           9.PUERTO REAL             |\n");
        printf("|             10.JEREZ                |\n");
        printf("|            11.CHICLANA              |\n");
        printf("|      12.SANLUCAR DE BARRAMEDA       |\n");
        printf("|      13.PUERTO DE SANTA MARIA       |\n");
        printf("|          14.SAN FERNANDO            |\n");
        printf("||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&selectorc);
        fflush(stdin);
        system("cls");
    }while (selectorc<8 || selectorc>14);  //Repite un bucle hasta que el usuario meta una opcion correcta
    return(selectorc);  //devuelve la ciudad selecionada
}

int mostrarviaje (int ciudad){  //Enseña los posibles viajes  MIRAR QUE FUNCIONAN TODOS LOS SWITCHS

    //Se abre el fichero de pasos
    FILE *pasos;
    char aux='0', vector[N];
    int i, id;

    pasos=fopen("pasos.txt","r+");
    if(pasos==NULL){
        error();
    }

    vaciar(vector);
    rewind(pasos);

    switch (ciudad){
        case 1:
        {  //este caso se refiere a los viajes de Cadiz de ida a la ESI
            do{
                for(i=0;aux!='-';i++){  //leo el id
                    vector[i]=aux;
                    aux=fgetc(pasos);
                }
                id=atoi(vector);  //creo el id
                for(i=0;i<2;i++){  //leo '-' que no me sirve
                    aux=fgetc(pasos);
                }

                if(aux=='I'){  //es de ida?
                    aux=fgetc(pasos);

                    vaciar(vector);
                    fgets(vector,6,pasos);

                    if(strcmp(vector,"Cadiz")==0){  //es de Cádiz??
                        printf("%d-%s", id, vector);
                        vaciar(vector);
                        fgets(vector,N,pasos);
                        printf("%s", vector);
                    }
                }else{
                    vaciar(vector);
                    fgets(vector,N,pasos);
                }

                aux=fgetc(pasos);
            }while(aux!=EOF);
        }
        break;

        case 2:  //este caso se refiere a los viajes de Puerto Real de ida a la ESI
            {
            do{
                for(i=0;aux!='-';i++){  //leo el id
                    vector[i]=aux;
                    aux=fgetc(pasos);
                }
                id=atoi(vector);  //creo el id
                for(i=0;i<2;i++){  //leo '-' que no me sirve
                    aux=fgetc(pasos);
                }

                if(aux=='I'){  //es de ida?
                    aux=fgetc(pasos);

                    vaciar(vector);
                    fgets(vector,12,pasos);

                    if(strcmp(vector,"Puerto Real")==0){  //es de Puerto Real??
                        printf("%d-%s", id, vector);
                        vaciar(vector);
                        fgets(vector,N,pasos);
                        printf("%s", vector);
                    }
                }else{
                    vaciar(vector);
                    fgets(vector,N,pasos);
                }

                aux=fgetc(pasos);
            }while(aux!=EOF);
        }
        break;

        case 3:   //este caso se refiere a los viajes de Jerez de ida a la ESI
            {
            do{
                for(i=0;aux!='-';i++){  //leo el id
                    vector[i]=aux;
                    aux=fgetc(pasos);
                }
                id=atoi(vector);  //creo el id
                for(i=0;i<2;i++){  //leo '-' que no me sirve
                    aux=fgetc(pasos);
                }

                if(aux=='I'){  //es de ida?
                    aux=fgetc(pasos);

                    vaciar(vector);
                    fgets(vector,6,pasos);

                    if(strcmp(vector,"Jerez")==0){  //es de Jerez??
                        printf("%d-%s", id, vector);
                        vaciar(vector);
                        fgets(vector,N,pasos);
                        printf("%s", vector);
                    }
                }else{
                    vaciar(vector);
                    fgets(vector,N,pasos);
                }

                aux=fgetc(pasos);
            }while(aux!=EOF);
        }
        break;

        case 4: //este caso se refiere a los viajes de Chiclana a la ESI
            {
            do{
                for(i=0;aux!='-';i++){  //leo el id
                    vector[i]=aux;
                    aux=fgetc(pasos);
                }
                id=atoi(vector);  //creo el id
                for(i=0;i<2;i++){  //leo '-' que no me sirve
                    aux=fgetc(pasos);
                }

                if(aux=='I'){  //es de ida?
                    aux=fgetc(pasos);

                    vaciar(vector);
                    fgets(vector,9,pasos);

                    if(strcmp(vector,"Chiclana")==0){  //es de Chiclana??
                        printf("%d-%s", id, vector);
                        vaciar(vector);
                        fgets(vector,N,pasos);
                        printf("%s", vector);
                    }
                }else{
                    vaciar(vector);
                    fgets(vector,N,pasos);
                }

                aux=fgetc(pasos);
            }while(aux!=EOF);
        }
        break;

        case 5:  //Este caso se refiere a los viajes de San Lucar a la ESI
              {
            do{
                for(i=0;aux!='-';i++){  //leo el id
                    vector[i]=aux;
                    aux=fgetc(pasos);
                }
                id=atoi(vector);  //creo el id
                for(i=0;i<2;i++){  //leo '-' que no me sirve
                    aux=fgetc(pasos);
                }

                if(aux=='I'){  //es de ida?
                    aux=fgetc(pasos);

                    vaciar(vector);
                    fgets(vector,9,pasos);

                    if(strcmp(vector,"SanLucar")==0){  //es de San Lucar??
                        printf("%d-%s", id, vector);
                        vaciar(vector);
                        fgets(vector,N,pasos);
                        printf("%s", vector);
                    }
                }else{
                    vaciar(vector);
                    fgets(vector,N,pasos);
                }

                aux=fgetc(pasos);
            }while(aux!=EOF);
        }
        break;

        case 6:   //Este caso se refiere a los viajes de Puerto Santa Maria a la ESI
              {
            do{
                for(i=0;aux!='-';i++){  //leo el id
                    vector[i]=aux;
                    aux=fgetc(pasos);
                }
                id=atoi(vector);  //creo el id
                for(i=0;i<2;i++){  //leo '-' que no me sirve
                    aux=fgetc(pasos);
                }

                if(aux=='I'){  //es de ida?
                    aux=fgetc(pasos);

                    vaciar(vector);
                    fgets(vector,7,pasos);

                    if(strcmp(vector,"Puerto")==0){  //es de Santa María??
                        printf("%d-%s", id, vector);
                        vaciar(vector);
                        fgets(vector,N,pasos);
                        printf("%s", vector);
                    }
                }else{
                    vaciar(vector);
                    fgets(vector,N,pasos);
                }

                aux=fgetc(pasos);
            }while(aux!=EOF);
        }
        break;


        case 7:  //Este caso se refiere a los viajes de San Fernando a la ESI
              {
            do{
                for(i=0;aux!='-';i++){  //leo el id
                    vector[i]=aux;
                    aux=fgetc(pasos);
                }
                id=atoi(vector);  //creo el id
                for(i=0;i<2;i++){  //leo '-' que no me sirve
                    aux=fgetc(pasos);
                }

                if(aux=='I'){  //es de ida?
                    aux=fgetc(pasos);

                    vaciar(vector);
                    fgets(vector,7,pasos);

                    if(strcmp(vector,"Sanfer")==0){  //es de San Fernando??
                        printf("%d-%s", id, vector);
                        vaciar(vector);
                        fgets(vector,N,pasos);
                        printf("%s", vector);
                    }
                }else{
                    vaciar(vector);
                    fgets(vector,N,pasos);
                }

                aux=fgetc(pasos);
            }while(aux!=EOF);
        }
        break;

        case 8:   //Este caso se refiere a los viajes de la ESI a Cadiz
            {
            do{
                for(i=0;aux!='-';i++){  //leo el id
                    vector[i]=aux;
                    aux=fgetc(pasos);
                }
                id=atoi(vector);  //creo el id
                for(i=0;i<2;i++){  //leo '-' que no me sirve
                    aux=fgetc(pasos);
                }

                if(aux=='V'){  //es de vuelta?
                    aux=fgetc(pasos);

                    vaciar(vector);
                    fgets(vector,6,pasos);

                    if(strcmp(vector,"Cadiz")==0){  //es de Cádiz??
                        printf("%d-%s", id, vector);
                        vaciar(vector);
                        fgets(vector,N,pasos);
                        printf("%s", vector);
                    }
                }else{
                    vaciar(vector);
                    fgets(vector,N,pasos);
                }

                aux=fgetc(pasos);
            }while(aux!=EOF);
        }
        break;

        case 9:   //Este caso se refiere a los viajes de la ESI a Puerto Real
            {
            do{
                for(i=0;aux!='-';i++){  //leo el id
                    vector[i]=aux;
                    aux=fgetc(pasos);
                }
                id=atoi(vector);  //creo el id
                for(i=0;i<2;i++){  //leo '-' que no me sirve
                    aux=fgetc(pasos);
                }

                if(aux=='V'){  //es de ida?
                    aux=fgetc(pasos);

                    vaciar(vector);
                    fgets(vector,12,pasos);

                    if(strcmp(vector,"Puerto Real")==0){  //es de Puerto Real??
                        printf("%d-%s", id, vector);
                        vaciar(vector);
                        fgets(vector,N,pasos);
                        printf("%s", vector);
                    }
                }else{
                    vaciar(vector);
                    fgets(vector,N,pasos);
                }

                aux=fgetc(pasos);
            }while(aux!=EOF);
        }
        break;

        case 10:   //Este caso se refiere a los viajes de la ESI a Jerez
            {
            do{
                for(i=0;aux!='-';i++){  //leo el id
                    vector[i]=aux;
                    aux=fgetc(pasos);
                }
                id=atoi(vector);  //creo el id
                for(i=0;i<2;i++){  //leo '-' que no me sirve
                    aux=fgetc(pasos);
                }

                if(aux=='V'){  //es de ida?
                    aux=fgetc(pasos);

                    vaciar(vector);
                    fgets(vector,6,pasos);

                    if(strcmp(vector,"Jerez")==0){  //es de Jerez??
                        printf("%d-%s", id, vector);
                        vaciar(vector);
                        fgets(vector,N,pasos);
                        printf("%s", vector);
                    }
                }else{
                    vaciar(vector);
                    fgets(vector,N,pasos);
                }

                aux=fgetc(pasos);
            }while(aux!=EOF);
        }
        break;

        case 11:   //Este caso se refiere a los viajes de la ESI a Chiclana
            {
            do{
                for(i=0;aux!='-';i++){  //leo el id
                    vector[i]=aux;
                    aux=fgetc(pasos);
                }
                id=atoi(vector);  //creo el id
                for(i=0;i<2;i++){  //leo '-' que no me sirve
                    aux=fgetc(pasos);
                }

                if(aux=='V'){  //es de ida?
                    aux=fgetc(pasos);

                    vaciar(vector);
                    fgets(vector,9,pasos);

                    if(strcmp(vector,"Chiclana")==0){  //es de Chiclana??
                        printf("%d-%s", id, vector);
                        vaciar(vector);
                        fgets(vector,N,pasos);
                        printf("%s", vector);
                    }
                }else{
                    vaciar(vector);
                    fgets(vector,N,pasos);
                }

                aux=fgetc(pasos);
            }while(aux!=EOF);
        }
        break;

        case 12:   //Este caso se refiere a los viajes de la ESI a Sanlucar de Barrameda
            {
            do{
                for(i=0;aux!='-';i++){  //leo el id
                    vector[i]=aux;
                    aux=fgetc(pasos);
                }
                id=atoi(vector);  //creo el id
                for(i=0;i<2;i++){  //leo '-' que no me sirve
                    aux=fgetc(pasos);
                }

                if(aux=='V'){  //es de ida?
                    aux=fgetc(pasos);

                    vaciar(vector);
                    fgets(vector,9,pasos);

                    if(strcmp(vector,"SanLucar")==0){  //es de San Lucar??
                        printf("%d-%s", id, vector);
                        vaciar(vector);
                        fgets(vector,N,pasos);
                        printf("%s", vector);
                    }
                }else{
                    vaciar(vector);
                    fgets(vector,N,pasos);
                }

                aux=fgetc(pasos);
            }while(aux!=EOF);
        }
        break;

        case 13:   //Este caso se refiere a los viajes de la ESI a el Puerto de Santa Maria
            rewind(pasos);
            do{
                for(i=0;aux!='-';i++){
                    aux=fgetc(pasos);
                    vector[i]=aux;
                }
                id=atoi(vector);
                do{
                    aux=fgetc(pasos);
                }while(aux=='-');
                if(aux=='V'){
                    fgetc(pasos);
                    fgets(vector,6,pasos);
                    if(strcmp(vector,"Puerto")==0){
                        fgets(vector,50,pasos);
                        printf("%d-%s", id, vector);   //Se imprimen los viajes disponibles por panatalla
                    }
                }
            }while(!feof(pasos));
            break;

        case 14:   //Este caso se refiere a los viajes de la ESI a San Fernando
             {
            do{
                for(i=0;aux!='-';i++){  //leo el id
                    vector[i]=aux;
                    aux=fgetc(pasos);
                }
                id=atoi(vector);  //creo el id
                for(i=0;i<2;i++){  //leo '-' que no me sirve
                    aux=fgetc(pasos);
                }

                if(aux=='V'){  //es de ida?
                    aux=fgetc(pasos);

                    vaciar(vector);
                    fgets(vector,7,pasos);

                    if(strcmp(vector,"Sanfer")==0){  //es de San Fernando??
                        printf("%d-%s", id, vector);
                        vaciar(vector);
                        fgets(vector,N,pasos);
                        printf("%s", vector);
                    }
                }else{
                    vaciar(vector);
                    fgets(vector,N,pasos);
                }

                aux=fgetc(pasos);
            }while(aux!=EOF);
        }
    }

    fclose(pasos);

    int id_aux=0;
    printf("\nIntroduzca el ID del viaje que le interese: ");   //Se lee la id del viaje que el usuario quiera, y se seleciona dicha clase.
    scanf("%d", &id_aux);

    return id_aux;
}
