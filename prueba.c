#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(){
    int a=0,puentenuevo=1,puenteviejo=1,RioSanPedro=1,Casem=1,Plaza=1,BahiaSur=1,HornosPunicos=1,Ardila=1,ParqueHuerta=1,calzada=1,Marquesado=1,pinarfranceses=1,PacianoBarco=1,Campito=1;
    char ubi1,ubi2,ubi3,ubi4,ubi5,ubi6;
    printf ("Selecione la su lugar de salida: \n");
    printf ("1.Cadiz\n2.Puerto Real\n3.Jerez\n4.Chiclana\n5.Sanlucar de Barrameda\n6.Puerto Santa Maria\n7.San Fernando\n");
    scanf("%i",&a);
    fflush(stdin);

    switch(a){
    case 1:
        system("cls");
        printf("Su lugar de salida es Cadiz\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
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
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
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
        printf("Su lugar de salida es Chiclana\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
        do{
            printf("1.Marquesado(S/N)\n");
            scanf("%c",&ubi1);
            fflush(stdin);
            if (ubi1=='N'||ubi1!='n'){
                Marquesado=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Pinar de los franceses(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                pinarfranceses=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Paciano del Barco(S/N)\n");
            scanf("%c",&ubi3);
            fflush(stdin);
            if (ubi3=='N'||ubi3=='n'){
                PacianoBarco=0;
        }
        if(ubi3!='N'&&ubi3!='S')
           system("cls");
        }while(ubi3!='N'&&ubi3!='S');

        do{
            printf("4.El Campito(S/N)\n");
            scanf("%c",&ubi4);
            fflush(stdin);
            if (ubi4=='N'||ubi4=='n'){
                Campito=0;
                break;
        }
        if(ubi4!='N'&&ubi4!='S')
           system("cls");
        }while(ubi4!='N'&&ubi4!='S');
        system("cls");


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
                calzada=0;
        }
        if(ubi1!='N'&&ubi1!='S')
           system("cls");
        }while(ubi1!='N'&&ubi1!='S');

        do{
            printf("2.Bajo Gia(S/N)\n");
            scanf("%c",&ubi2);
            fflush(stdin);
            if (ubi2=='N'||ubi2=='n'){
                puenteviejo=0;
        }
        if(ubi2!='N'&&ubi2!='S')
           system("cls");
        }while(ubi2!='N'&&ubi2!='S');

        do{
            printf("3.Dopodromo(S/N)\n");
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
        printf("Su lugar de salida es Puerto de Santa Maria\n");
        printf("Introduzca los lugares por los que va a pasar\n");
        printf ("Sus respuestas solo se actaran si son mayusculas\n");
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
            printf("5.Parque de la Huerta(S/N)\n");
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
return 0;
}

