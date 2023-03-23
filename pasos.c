#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "PASOS.h"

int main(){
    FILE *pasos = {"pasos.txt", "w"};

    selector();
    fclose(pasos);
}
void ida_recorrido(){
    FILE *pasos = {"pasos.txt", "a+"};
    int a=0,i_plazaespana=1,i_victoria=1,i_RioSanPedro=1,i_Casem=1,i_Plaza=1,i_BahiaSur=1,i_HornosPunicos=1,i_Ardila=1,i_ParqueHuerta=1,i_calzada=1, i_hipodromo=1,i_Polila=1,i_bajoguia=1,i_Marquesado=1,i_pinarfranceses=1,i_Rana=1,i_Novo=1,i_Rotonda1=1,i_Minotauro=1,i_TrenesJerz=1,i_PuertoSantMaria=1,i_TrenesPuerto=1,i_Valdelagrana=1,i_Sudamerica=1,i_Plazatoros=1;
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
            printf("1.Plaza España(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                i_plazaespana=0;
                a=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Hotel Victoria(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                i_victoria=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Barriada Rio San Pedro(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                i_RioSanPedro=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Casem(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                i_Casem=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
        break;


    case 2:
        printf("Su lugar de salida es Puerto Real");
        break;


    case 3:
       system("cls");
        printf("Su lugar de salida es Jerez\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        do{
            printf("1.Rotonda 1(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                i_Rotonda1=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Minotauro(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                i_Minotauro=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Estacion de trenes(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                i_TrenesJerz=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Puerto Sant Maria(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                i_PuertoSantMaria=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
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
            if (ubi1=='N'||ubi1!='n'){
                i_Marquesado=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Pinar de los franceses(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                i_pinarfranceses=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.El Novo(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                i_Novo=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.La Rana Verde/Los Gallos(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                i_Rana=0;
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
            printf("1.Calzada(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                i_calzada=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Bajo Guia(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                i_bajoguia=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Hipodromo(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                i_hipodromo=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Barriada La Polila(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                i_Polila=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
        do{
            printf("5.Puerto Sant Maria(S/N)\n");
            scanf("%c",&ubi5);
            fflush(stdin);
            if (ubi5=='N'||ubi5=='n'){
                i_PuertoSantMaria=0;
                break;
        }
        if(ubi5!='N'&&ubi5!='S')
           system("cls");
        }while(ubi5!='N'&&ubi5!='S');
        system("cls");
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
            if (ubi1=='N'||ubi1!='n'){
                i_TrenesPuerto=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Valdelagrana(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                i_Valdelagrana=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Sudamerica(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                i_Sudamerica=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Plaza de toros(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                i_Plazatoros=0;
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
            printf("1.Plaza(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1=='n'){
                i_Plaza=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Bahia Sur(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                i_BahiaSur=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Hornos Punicos(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                i_HornosPunicos=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Ardila(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                i_Ardila=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');

        do{
            printf("5.Parque de la Huerta(S/N)\n");
            scanf("%c",&ubi5);
            fflush(stdin);
            if (ubi5=='N'||ubi5=='n'){
                i_ParqueHuerta=0;
                break;
        }
        if(ubi5!='N'&&ubi5!='S')
           system("cls");
        }while(ubi5!='N'&&ubi5!='S');
        break;

    }
}

void vuelta_recorrido(){
    int a=0,v_puentenuevo=1,v_puenteviejo=1,v_RioSanPedro=1,v_Casem=1,v_Plaza=1,v_BahiaSur=1,v_HornosPunicos=1,v_Ardila=1,v_ParqueHuerta=1,v_calzada=1,v_hipodromo=1,v_Polila=1,v_bajoguia=1,v_Marquesado=1,v_pinarfranceses=1,v_Rana=1,v_Novo=1,v_Rotonda1=1,v_Minotauro=1,v_TrenesJerz=1,v_PuertoSantMaria=1,v_TrenesPuerto=1,v_Valdelagrana=1,v_Sudamerica=1,v_Plazatoros=1;
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
            printf("1.Puente Nuevo(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                v_puentenuevo=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Puente Viejo(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
               v_puenteviejo=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Barriada Rio San Pedro(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                v_RioSanPedro=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Casem(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                v_Casem=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
        break;


    case 2:
        printf("Su lugar de llegada es Puerto Real");
        break;


    case 3:
       system("cls");
        printf("Su lugar de llegada es Jerez\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        do{
            printf("1.Rotonda 1(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                v_Rotonda1=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Minotauro(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                v_Minotauro=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Estacion de trenes(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                v_TrenesJerz=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Puerto Sant Maria(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                v_PuertoSantMaria=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
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
            if (ubi1=='N'||ubi1!='n'){
                v_Marquesado=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Pinar de los franceses(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                v_pinarfranceses=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.El Novo(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                v_Novo=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.La Rana Verde/Los Gallos(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                v_Rana=0;
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
            printf("1.Calzada(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                v_calzada=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Bajo Guia(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                v_bajoguia=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Hipodromo(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                v_hipodromo=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Barriada La Polila(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                v_Polila=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
        do{
            printf("5.Puerto Sant Maria(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                v_PuertoSantMaria=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");
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
            if (ubi1=='N'||ubi1!='n'){
                v_TrenesPuerto=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Valdelagrana(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                v_Valdelagrana=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Sudamerica(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                v_Sudamerica=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Plaza de toros(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                v_Plazatoros=0;
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
            printf("1.Plaza(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1=='n'){
                v_Plaza=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Bahia Sur(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                v_BahiaSur=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Hornos Punicos(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                v_HornosPunicos=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Ardila(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                v_Ardila=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');

        do{
            printf("5.Parque de la Huerta(S/N)\n");
            scanf("%c",&ubi5);
            fflush(stdin);
            if (ubi5=='N'||ubi5=='n'){
                v_ParqueHuerta=0;
                break;
        }
        if(ubi5!='N'&&ubi5!='S')
           system("cls");
        }while(ubi5!='N'&&ubi5!='S');
        break;

    }
}

void selector_camino(){
    void selecionar_t(){
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
}

void selector_i(){
    int selectorc;
    printf("|||||||||||||||||||||||||||||||||||||\n");
    printf("|   Seleccione su lugar de SALIDA:  |\n");
    printf("|              1.CADIZ              |\n");
    printf("|           2.PUERTO REAL           |\n");
    printf("|             3.JEREZ               |\n");
    printf("|            4.CHICLANA             |\n");
    printf("|     5.SAN LUCAR DE BARRAMEDA      |\n");
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
            printf("|     5.SAN LUCAR DE BARRAMEDA      |\n");
            printf("|      6.PUERTO DE SANTA MARIA      |\n");
            printf("|          7.SAN FERNANDO           |\n");
            printf("|||||||||||||||||||||||||||||||||||||\n");
            scanf("%d",&selectorc);
            fflush(stdin);
            system("cls");
    }
    switch(selectorc){
    case 1:
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

void selector_v(){
    int selectorc;
    printf("|||||||||||||||||||||||||||||||||||||\n");
    printf("|   Seleccione su lugar de VUELTA:  |\n");
    printf("|              1.CADIZ              |\n");
    printf("|           2.PUERTO REAL           |\n");
    printf("|             3.JEREZ               |\n");
    printf("|            4.CHICLANA             |\n");
    printf("|     5.SAN LUCAR DE BARRAMEDA      |\n");
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
        printf("|     5.SAN LUCAR DE BARRAMEDA       |\n");
        printf("|      6.PUERTO DE SANTA MARIA       |\n");
        printf("|          7.SAN FERNANDO            |\n");
        printf("||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&selectorc);
        fflush(stdin);
        system("cls");
    }
    switch(selectorc){
    case 1:
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

void cadiz(){
    int selectorc;
    printf("|||||||||||||||||||||||||||||||||||||||||\n");
    printf("|                 CADIZ                 |\n");
    printf("|     Seleccione la parada deseada:     |\n");
    printf("|            1.PLAZA ESPAÑA             |\n");
    printf("|              2.HOSPITAL               |\n");
    printf("|        3.BARRIADA RIO SAN PEDRO       |\n");
    printf("|                4.CASEM                |\n");
    printf("|||||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&selectorc);
    fflush(stdin);
    while (selectorc<1 || selectorc>4){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("|||||||||||||||||||||||||||||||||||||||||\n");
        printf("|                 CADIZ                 |\n");
        printf("|     Seleccione la parada deseada:     |\n");
        printf("|            1.PLAZA ESPAÑA             |\n");
        printf("|              2.HOSPITAL               |\n");
        printf("|        3.BARRIADA RIO SAN PEDRO       |\n");
        printf("|                4.CASEM                |\n");
        printf("|||||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&selectorc);
        fflush(stdin);
        system("cls");
    }
}

void puertoreal(){
    int selectorc;
    printf("||||||||||||||||||||||||||||||||||||||||\n");
    printf("|             PUERTO REAL              |\n");
    printf("|     Seleccione la parada deseada:    |\n");
    printf("|         1.ESTACION DE TRENES         |\n");
    printf("|           2.BURGER KING              |\n");
    printf("|        3.LAGUNA DE LA MARROQUIA      |\n");
    printf("|              4.CASEM                 |\n");
    printf("||||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&selectorc);
    fflush(stdin);
    while (selectorc<1 || selectorc>4){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("||||||||||||||||||||||||||||||||||||||||\n");
        printf("|             PUERTO REAL              |\n");
        printf("|     Seleccione la parada deseada:    |\n");
        printf("|         1.ESTACION DE TRENES         |\n");
        printf("|           2.BURGER KING              |\n");
        printf("|        3.LAGUNA DE LA MARROQUIA      |\n");
        printf("|              4.CASEM                 |\n");
        printf("||||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&selectorc);
        fflush(stdin);
        system("cls");
    }
}

void jerez(){
    int selectorc;
    printf("|||||||||||||||||||||||||||||||||||||||||\n");
    printf("|                  JEREZ                |\n");
    printf("|     Seleccione la parada deseada:     |\n");
    printf("|              1.MINOTAURO              |\n");
    printf("|               2.ROTONDA               |\n");
    printf("|          3.ESTACION DE TRENES         |\n");
    printf("|         4.PUERTO DE SANTA MARIA       |\n");
    printf("|||||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&selectorc);
    fflush(stdin);
    while (selectorc<1 || selectorc>4){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("|||||||||||||||||||||||||||||||||||||||||\n");
        printf("|                 JEREZ                 |\n");
        printf("|     Seleccione la parada deseada:     |\n");
        printf("|              1.MINOTAURO              |\n");
        printf("|               2.ROTONDA               |\n");
        printf("|          3.ESTACION DE TRENES         |\n");
        printf("|         4.PUERTO DE SANTA MARIA       |\n");
        printf("|||||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&selectorc);
        fflush(stdin);
        system("cls");
    }
}

void chiclana(){
    int selectorc;
    printf("||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|               CHICLANA                 |\n");
    printf("|    Seleccione la parada deseada:       |\n");
    printf("|             1.MARQUESADO               |\n");
    printf("|               2.EL NOVO                |\n");
    printf("|              3.FRANCESES               |\n");
    printf("|             4.LOS GALLOS               |\n");
    printf("||||||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&selectorc);
    fflush(stdin);
    while (selectorc<1 || selectorc>4){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|               CHICLANA                 |\n");
        printf("|    Seleccione la parada deseada:       |\n");
        printf("|             1.MARQUESADO               |\n");
        printf("|               2.EL NOVO                |\n");
        printf("|              3.FRANCESES               |\n");
        printf("|             4.LOS GALLOS               |\n");
        printf("||||||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&selectorc);
        fflush(stdin);
        system("cls");
    }
}

void sanlucar(){
    int selectorc;
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|             SAN LUCAR DE BARRAMEDA              |\n");
    printf("|          Seleccione la parada deseada:          |\n");
    printf("|                   1.EL PALMAR                   |\n");
    printf("|                  2.5ºCENTENARIO                 |\n");
    printf("|                3.ROTONDA DEL TREN               |\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&selectorc);
    fflush(stdin);
    while (selectorc<1 || selectorc>3){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|             SAN LUCAR DE BARRAMEDA              |\n");
        printf("|          Seleccione la parada deseada:          |\n");
        printf("|                   1.EL PALMAR                   |\n");
        printf("|              2.AVENIDA 5ºCENTENARIO             |\n");
        printf("|                3.ROTONDA DEL TREN               |\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&selectorc);
        fflush(stdin);
        system("cls");
    }
}

void puerto(){
    int selectorc;
    printf("||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|               PUERTO REAL              |\n");
    printf("|     Seleccione la parada deseada:      |\n");
    printf("|         1.ESTACION DE TRENES           |\n");
    printf("|            2.VALDELAGRANA              |\n");
    printf("|             3.SUDAMERICA               |\n");
    printf("|            4.PLAZA DE TOROS            |\n");
    printf("||||||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&selectorc);
    fflush(stdin);
    while (selectorc<1 || selectorc>4){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|               PUERTO REAL              |\n");
        printf("|     Seleccione la parada deseada:      |\n");
        printf("|         1.ESTACION DE TRENES           |\n");
        printf("|            2.VALDELAGRANA              |\n");
        printf("|             3.SUDAMERICA               |\n");
        printf("|            4.PLAZA DE TOROS            |\n");
        printf("||||||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&selectorc);
        fflush(stdin);
        system("cls");
    }
}

void sanfer(){
    int selectorc;
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|                    SAN FERNANDO                  |\n");
    printf("|          Seleccione la parada deseada:           |\n");
    printf("|                 1.PARQUE LA HUERTA               |\n");
    printf("|                     2.ARDILA                     |\n");
    printf("|                 3.HIRNOS PUNICOS                 |\n");
    printf("|                    4.BAHIA SUR                   |\n");
    printf("|                      5.PLAZA                     |\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    scanf("%d",&selectorc);
    fflush(stdin);
    while (selectorc<1 || selectorc>5){
        printf("Introduzca una opcion correcta\n\n\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|                    SAN FERNANDO                  |\n");
        printf("|          Seleccione la parada deseada:           |\n");
        printf("|                 1.PARQUE LA HUERTA               |\n");
        printf("|                     2.ARDILA                     |\n");
        printf("|                 3.HIRNOS PUNICOS                 |\n");
        printf("|                    4.BAHIA SUR                   |\n");
        printf("|                      5.PLAZA                     |\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        scanf("%d",&selectorc);
        fflush(stdin);
        system("cls");
    }
}
