
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#include "Users.h"

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
    if((f=fopen("user_database.txt","r"))==NULL){
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

void reserva_memoria(user **u, int lineas){

    //Declaración de datos:
    FILE *f;


    //Abrir fichero:
    if((f=fopen("user_database.txt","r"))==NULL){
        //Error dado en el caso de no poder abrir el fichero:
        error();
    }


    //Volver al principio del fichero:
    rewind(f);


    //Crear vector dinámico dependiente del número de líneas de estruct_viajes:
    *u=(user*)calloc(lineas,sizeof(user));
    if(*u==NULL){
        printf("No se ha podido reservar memoria\n");
        exit(1);
    }

    fclose(f);
}

void subir_a_fichero_users(user *u){

    //Definición de datos:
    FILE *f;
    int j;
    char vector[N], aux;


    //Abrir fichero:
    if((f=fopen("user_database.txt","r"))==NULL){
        //Error dado en el caso de no poder abrir el fichero:
        error();
    }


    //LLenar en cada estructura del vector:
    for(j=0;!feof(f);j++){

        leer(vector, f);
        u[j].Id_Users=atoi(vector);  //Id_Users

        leer(vector, f);
        strcpy(u[j].Name_User, vector);  //Name_User

        leer(vector, f);
        strcpy(u[j].Place, vector);  //Place

        leer(vector, f);
        strcpy(u[j].User_Profile, vector);  //User_Profile

        leer(vector, f);
        strcpy(u[j].User, vector);  //User

        leer(vector, f);
        strcpy(u[j].Password,vector);  //Password
    }
}

void cargar_users(){

    //Declaración de datos:
    int lineas;
    user *us;

    //Contar longitud del fichero:
    lineas=contar();


    //Reservar memoria:
    reserva_memoria(&us, lineas);


    //Cargar datos a estructura:
    subir_a_fichero_users(us);
}

int main(){
    cargar_users();
    return 0;
}
