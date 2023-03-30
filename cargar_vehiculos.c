#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#include "Vehiculos_header.h"

void error(){
    printf("######################################################################\n");
    printf("|Ha ocurrido un error a la hora de abrir el fichero <viajes_file.txt>|\n|    Por favor, inténtelo más tarde o consulte con mantenimiento     |\n");
    printf("######################################################################\n\n");
    exit(1);
}

void vaciar_vector (char vector[]){

    //Declaración de datos
    int i;


    //Introduzco en valor '\0' en todas las celdas del vector para vaciarlo:
    for(i=0;i<N;i++){
        vector[i]='\0';
    }
}

void leer(char vector[], FILE *f){

    //Declaración de datos:
    char aux;
    int i;

    //Leer vector hasta '-', '\n' o 'EOF':
    vaciar_vector(vector);
    aux='0';
    for(i=0;aux!='-'&&aux!='\n'&&aux!=EOF;i++){
        aux=fgetc(f);
        if(aux!='-'&&aux!='\n'&&aux!=EOF){
            vector[i]=aux;
        }
    }
}

int contar(){

    //Declaración de datos:
    FILE *f;
    int lineas=0;
    char vector[N];


    //Abrir fichero:
    if((f=fopen("Vehiculos_file.txt","r"))==NULL){
        //Error dado en el caso de no poder abrir el fichero:
        error();
    }


    //Contar líneas:
    while(!feof(f)){
        fgets(vector,N,f);
        lineas++;
    }

    fclose(f);
    return lineas;
}

void reserva_memoria(estruct_vehiculos **v, int lineas){

    //Declaración de datos:
    FILE *f;


    //Abrir fichero:
    if((f=fopen("Vehiculos_file.txt","r"))==NULL){
        //Error dado en el caso de no poder abrir el fichero:
        error();
    }


    //Volver al principio del fichero:
    rewind(f);


    //Crear vector dinámico dependiente del número de líneas de estruct_viajes:
    *v=(estruct_vehiculos*)calloc(lineas,sizeof(estruct_vehiculos));
    if(*v==NULL){
        printf("No se ha podido reservar memoria\n");
        exit(1);
    }

    fclose(f);
}

void subir_a_fichero_vehiculos(estruct_vehiculos *v){

    //Definición de datos:
    FILE *f;
    int j;
    char vector[N], aux;


    //Abrir fichero:
    if((f=fopen("Vehiculos_file.txt","r"))==NULL){
        //Error dado en el caso de no poder abrir el fichero:
        error();
    }


    //LLenar en cada estructura del vector:
    for(j=0;!feof(f);j++){

        leer(vector, f);
        strcpy(v[j].Id_mat, vector);  //Id_mat

        leer(vector, f);
        v[j].Id_usuario=atoi(vector);  //Id_usuario

        leer(vector, f);
        v[j].Num_plazas=atoi(vector);  //Num_plazas

        leer(vector, f);
        strcpy(v[j].Desc_veh,vector);  //Desc_veh
    }
}

void cargar_vehiculos(){

    //Declaración de datos:
    int lineas;
    estruct_vehiculos *vec;

    //Contar longitud del fichero:
    lineas=contar();


    //Reservar memoria:
    reserva_memoria(&vec, lineas);


    //Cargar datos a estructura:
    subir_a_fichero_vehiculos(vec);
}

int main(){
    cargar_vehiculos();
    return 0;
}

