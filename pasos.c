#include <stdio.h>
#include "PASOS.h"

typedef struct {
    int Id_viaje;         // numero identificatorio para el viaje
    char Poblacion[21];   // localizacion por donde va a pasar el conductor
}estruct_pasos;

void ida_recorrido();
void vuelta_recorrido();
void reset_id();

int main{




}

void ida_recorrido(){
    int a,puentenuevo=1,puenteviejo=1,RioSanPedro=1,Casem=1,Plaza=1,BahiaSur=1,HornosPunicos=1,Ardila=1,ParqueHuerta=1,calzada=1;
    char ubi1,ubi2,ubi3,ubi4,ubi5,ubi6;
    printf ("Selecione la su lugar de salida: \n");
    printf ("1.Cadiz\n2.Puerto Real\n3.Jerez\n4.Chiclana\n5.San Lucar de Barrameda\n6.Puerto Santa Maria\n7.San Fernando\n");
    printf ("Sus respuestas solo se actaran si son mayusculas\n");
    scanf("%d",&a);
    fflush(stdin);
    switch(a){
    case 1:
        system("cls");
        printf("Su lugar de salida es Cadiz\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        do{
            printf("1.Puente Nuevo(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                puentenuevo=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Puente Viejo(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                puenteviejo=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Barriada Rio San Pedro(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                RioSanPedro=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Casem(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                Casem=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");


    case 2:
        printf("Su lugar de salida es Puerto Real");
        break;


    case 3:
       system("cls");
        printf("Su lugar de salida es Jerez\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        do{
            printf("1.Puente Nuevo(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                puentenuevo=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Puente Viejo(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                puenteviejo=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Barriada Rio San Pedro(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                RioSanPedro=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Casem(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                Casem=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");


    case 4:
        system("cls");
        printf("Su lugar de salida es Cadiz\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        do{
            printf("1.Puente Nuevo(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                puentenuevo=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Puente Viejo(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                puenteviejo=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Barriada Rio San Pedro(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                RioSanPedro=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Casem(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                Casem=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");


    case 5:
        system("cls");
        printf("Su lugar de salida es San Lucar de Barrameda\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        do{
            printf("1.Calzada(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                calzada=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Puente Viejo(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                puenteviejo=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Barriada Rio San Pedro(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                RioSanPedro=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Casem(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                Casem=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");


    case 6:
        system("cls");
        printf("Su lugar de salida es Cadiz\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        do{
            printf("1.Puente Nuevo(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                puentenuevo=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Puente Viejo(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                puenteviejo=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Barriada Rio San Pedro(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                RioSanPedro=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Casem(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                Casem=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");


    case 7:
        system("cls");
        printf("Su lugar de salida es San Fernando\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        do{
            printf("1.Plaza(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1=='n'){
                Plaza=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Bahia Sur(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                BahiaSur=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Hornos Punicos(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                HornosPunicos=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Ardila(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                Ardila=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');

        do{
            printf("4.Parque de la Huerta(S/N)\n");
            scanf("%c",&ubi5);
            fflush(stdin);
            if (ubi5=='N'||ubi5=='n'){
                ParqueHuerta=0;
                break;
        }
        if(ubi5!='N'&&ubi5!='S')
           system("cls");
        }while(ubi5!='N'&&ubi5!='S');

    }
}
void vuelta_recorrido(){
int a,puentenuevo=1,puenteviejo=1,RioSanPedro=1,Casem=1,Plaza=1,BahiaSur=1,HornosPunicos=1,Ardila=1,ParqueHuerta=1,calzada=1;
    char ubi1,ubi2,ubi3,ubi4,ubi5,ubi6;
    printf ("Selecione la su lugar de llegada: \n");
    printf ("1.Cadiz\n2.Puerto Real\n3.Jerez\n4.Chiclana\n5.San Lucar de Barrameda\n6.Puerto Santa Maria\n7.San Fernando\n");
    printf ("Sus respuestas solo se actaran si son mayusculas\n");
    scanf("%d",&a);
    fflush(stdin);
    switch(a){
    case 1:
        system("cls");
        printf("Su lugar de llegada es Cadiz\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        do{
            printf("1.Puente Nuevo(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                puentenuevo=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Puente Viejo(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                puenteviejo=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Barriada Rio San Pedro(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                RioSanPedro=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Casem(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                Casem=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");


    case 2:
        printf("Su lugar de llegada es Puerto Real");
        break;


    case 3:
       system("cls");
        printf("Su lugar de llegada es Jerez\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        do{
            printf("1.Puente Nuevo(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                puentenuevo=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Puente Viejo(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                puenteviejo=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Barriada Rio San Pedro(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                RioSanPedro=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Casem(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                Casem=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");


    case 4:
        system("cls");
        printf("Su lugar de salida es Cadiz\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        do{
            printf("1.Puente Nuevo(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                puentenuevo=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Puente Viejo(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                puenteviejo=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Barriada Rio San Pedro(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                RioSanPedro=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Casem(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                Casem=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");


    case 5:
        system("cls");
        printf("Su lugar de llegada es San Lucar de Barrameda\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        do{
            printf("1.Calzada(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                calzada=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Puente Viejo(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                puenteviejo=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Barriada Rio San Pedro(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                RioSanPedro=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Casem(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                Casem=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");


    case 6:
 system("cls");
        printf("Su lugar de salida es Cadiz\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        do{
            printf("1.Puente Nuevo(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                puentenuevo=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Puente Viejo(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                puenteviejo=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Barriada Rio San Pedro(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                RioSanPedro=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Casem(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                Casem=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");


    case 7:
        system("cls");
        printf("Su lugar de salida es San Fernando\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        do{
            printf("1.Plaza(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1=='n'){
                Plaza=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Bahia Sur(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                BahiaSur=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Hornos Punicos(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                HornosPunicos=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.Ardila(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                Ardila=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');

        do{
            printf("4.Parque de la Huerta(S/N)\n");
            scanf("%c",&ubi5);
            fflush(stdin);
            if (ubi5=='N'||ubi5=='n'){
                ParqueHuerta=0;
                break;
        }
        if(ubi5!='N'&&ubi5!='S')
           system("cls");
        }while(ubi5!='N'&&ubi5!='S');

    }
}
