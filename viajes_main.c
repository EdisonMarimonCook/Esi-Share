#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "viajes_header.h"
#define N 100

void subir_viaje(FILE *viajes_file){
    estruct_viajes Id_m;
    printf("¡Bienvenido al creador de viajes de ESI Share!\n\nIntroduzca la matrícula del coche que vaya a utilizar: ");
    /*fflush(stdin);
    fgets(v.Id_mat, sizeof(char), stdin); PROBLEMA. No te pide escribir la cadena de caracteres*/
}


void vaciar_vector (char vector[]){

    //Declaración de datos
    int i;


    //Introduzco en valor '\0' en todas las celdas del vector para vaciarlo:
    for(i=0;i<100;i++){
        vector[i]='\0';
    }
}


void eliminar_viaje(FILE *viajes_file){

    //Declaración de datos:
    char aux, vector_temporal[N];
    int id=0, id_fichero=0, i, encontrado=0, lineas=1, lineas_total=0;


    //Enseña por pantalla todos los viajes guardados en el fichero:
    printf("¿Qué viaje desea eliminar?\n\n");
    while(!feof(viajes_file)){
        fgets(vector_temporal,N,viajes_file);
        printf("%s", vector_temporal);
        lineas_total++;
    }


    //Creo una variable para el ID:
    printf("\n\nIntroduzca el ID del viaje a borrar: ");
    scanf("%d", &id);


    //Crear ID obtenida del fichero:
    rewind(viajes_file); //Pone el puntero en la posición inicial del fichero
    vaciar_vector(vector_temporal);  //Quitamos la basura de este vector
    for(i=0;aux!='-';i++){
        aux=fgetc(viajes_file);
        vector_temporal[i]=aux;
    }
    id_fichero=atoi(vector_temporal);  //La función atoi transforma los valores char del vector en un entero


     //Comparación:
    do{
        if(id==id_fichero){
            encontrado=1;
        }else{
            while(aux!='\n'){
                aux=fgetc(viajes_file);
                printf("%c", aux);
            }
            vaciar_vector(vector_temporal);
            for(i=0;aux!='-';i++){
                aux=fgetc(viajes_file);
                vector_temporal[i]=aux;
            }
            printf("%s", vector_temporal);
            id_fichero=atoi(vector_temporal);
        }
        lineas++;
    }while(lineas<lineas_total&&encontrado==0);

    if(id==id_fichero){
        printf("\nEl viaje ha sido encontrado");
    }else{
        printf("\nNo se ha encontrado el viaje en la base de datos");
    }


    //Borrar:*/
}


void modificar_viaje(FILE *viajes_file){
    char c;
    printf("¿Qué viaje desea modificar?\n\n");
    //Enseña por pantalla todos los viajes guardados en el fichero:
    do{
        c=fgetc(viajes_file);
        printf("%c", c);
    }while(c!=EOF);
}


void menu_viajes(){

    //Declaración de datos:
    int elect, cont_menu=0;
    FILE *viajes_file;
    char res;


    //Menú gráfico:
    do{
        printf("##       ##   ##      ###       ########  ######   ######\n");
        printf(" ##     ##    ##     ## ##         ##     ##      ##\n");
        printf("  ##   ##     ##    ##   ##        ##     ######   ######\n");
        printf("   ## ##      ##   #########   ##  ##     ##            ##\n");
        printf("    ###       ##  ##       ##   ####      ######   ######\n");
        printf("\n ########################");
        printf("\n |¿Qué desea hacer?     |");
        printf("\n |                      |");
        printf("\n |1. Añadir un viaje    |\n |2. Eliminar un viaje  |\n |3. Modificar un viaje |\n |4. Salir              |\n");
        printf(" ########################\n\n");
        scanf("%d", &elect);


        //Comprobación de elección de menú válida:
        while(elect<1||elect>4){
            printf("VALOR INVÁLIDO: Introduzca '1', '2', '3' o '4' para seleccionar la opción deseada\n");
            scanf("%d", &elect);
        }
        system ("cls"); //Sirve para limpiar la pantalla


        //Abro el fichero viajes_file.txt antes de elegir qué hacer con él para no tener que abrirlo en cada función:
        viajes_file=fopen("viajes_file.txt", "a+");
        if(viajes_file!=NULL){
            switch (elect){
                case 1: subir_viaje(viajes_file);
                break;
                case 2: eliminar_viaje(viajes_file);
                break;
                case 3: modificar_viaje(viajes_file);
                break;
                case 4: exit(1);
            }
        }else{
            //Error dado en el caso de no poder abrir el fichero:
            printf("######################################################################\n");
            printf("|Ha ocurrido un error a la hora de abrir el fichero <viajes_file.txt>|\n|    Por favor, inténtelo más tarde o consulte con mantenimiento     |\n");
            printf("######################################################################\n\n");
            exit(1);
        }
        fclose(viajes_file);


        //Elección sobre continuación del bucle:
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
    setlocale(LC_ALL, "spanish");  //Función para poder escribir carácteres específicos del español
    menu_viajes();
    return 0;
}
