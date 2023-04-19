#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "Users.h"
#include "Vehiculos_header.h"
#include "viajes_header.h"
#define N 100

void vaciar_vector (char vector[]){  //Hecho

    //Declaración de datos
    int i;


    //Introduzco en valor '\0' en todas las celdas del vector para vaciarlo:
    for(i=0;i<N;i++){
        vector[i]='\0';
    }
}

void leer(char vector[], FILE *f){  //Hecho

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

int contar_viajes(){  //Hecho

    //Declaración de datos:
    FILE *f;
    int lineas=0;
    char vector[N];


    //Abrir fichero:
    if((f=fopen("viajes_file.txt","r"))==NULL){
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

void reserva_memoria_viaj(estruct_viajes **v, int lineas){  //Hecho

    //Declaración de datos:
    FILE *f;


    //Abrir fichero:
    if((f=fopen("viajes_file.txt","r"))==NULL){
        //Error dado en el caso de no poder abrir el fichero:
        error();
    }


    //Volver al principio del fichero:
    rewind(f);


    //Crear vector dinámico dependiente del número de líneas de estruct_viajes:
    *v=(estruct_viajes*)calloc(lineas,sizeof(estruct_viajes));
    if(*v==NULL){
        printf("No se ha podido reservar memoria\n");
        exit(1);
    }

    fclose(f);
}

void subir_a_fichero_viajes(estruct_viajes *v, int lineas){  //Hecho

    //Definición de datos:
    FILE *f;
    int j;
    char vector[N];


    //Abrir fichero:
    if((f=fopen("viajes_file.txt","r"))==NULL){
        //Error dado en el caso de no poder abrir el fichero:
        error();
    }


    //LLenar en cada estructura del vector:
    for(j=0;j<lineas;j++){

        leer(vector, f);
        v[j].Id_viaje=atoi(vector);  //Id_viaje

        leer(vector, f);
        strcpy(v[j].Id_mat, vector);  //Id_mat

        leer(vector, f);
        strcpy(v[j].F_inic, vector);  //F_inic

        leer(vector, f);
        strcpy(v[j].H_inic, vector);  //H_inic

        leer(vector, f);
        strcpy(v[j].H_fin, vector);  //H_fin

        leer(vector, f);
        v[j].Plazas_libre=atoi(vector);  //Plazas_libre

        leer(vector, f);
        v[j].Importe=atoi(vector);  //Importe

        leer(vector, f);
        strcpy(v[j].Estado,vector);  //Estado
    }

    fclose(f);
}

int contar_vehiculo(){

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

void reserva_memoria_vec(estruct_vehiculos **v, int lineas){

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
    char vector[N];


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
    fclose(f);
}

int contar_user(){

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

void reserva_memoria_us(user **u, int lineas){

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
    char vector[N];


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
    fclose(f);
}

int main(){

    setlocale(LC_ALL, "spanish");  //Función para poder escribir carácteres específicos del español

    //Definición de datos:
    int lineas_viajes, lineas_vehiculos, lineas_users;
    estruct_viajes *viaj;
    estruct_vehiculos *vec;
    user *us;

    //Poner reloj:


    //###############################################################################################//

    //Cargar a memoria fichero VIAJES
    //Contar longitud del fichero:
    lineas_viajes=contar_viajes();

    //Reservar memoria:
    reserva_memoria_viaj(&viaj, lineas_viajes);

    //Cargar datos a estructura:
    subir_a_fichero_viajes(viaj, lineas_viajes);


    //Cargar a memoria fichero VEHICULOS
    //Contar longitud del vehiculo:
    lineas_vehiculos=contar_vehiculo();

    //Reservar memoria:
    reserva_memoria_vec(&vec, lineas_vehiculos);

    //Cargar datos a estructura:
    subir_a_fichero_vehiculos(vec);


    //Cargar a memoria fichero USUARIOS
    //Contar longitud del fichero:
    lineas_users=contar_user();

    //Reservar memoria:
    reserva_memoria_us(&us, lineas_users);

    //Cargar datos a estructura:
    subir_a_fichero_users(us);

    //###############################################################################################//

puts("###########################################################################################################################\n\n       $$$$$$$$$$$$$$$$$$$$$$$$$$            #######   #####    ####              #####   ##   ##    ##     ######   #######");
puts(" $$$$$$      $$$$$$$$$$$$$$$$$$$$$$$$$$       ##   #  ##   ##    ##              ##   ##  ##   ##   ####     ##  ##   ##   #");
puts("$$$$$$$      $$$$$$$$$$$$$$$$$$$$$$$$$$$      ## #    #          ##              #        ##   ##  ##  ##    ##  ##   ## #");
puts(" $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$      ####     #####     ##     ######    #####   #######  ##  ##    #####    ####");
puts("        $$$$$$$$$$     $$$$$        $$$$      ## #         ##    ##                   ##  ##   ##  ######    ## ##    ## #");
puts("       $$    $$$$$     $$$$$        $$$$      ##   #  ##   ##    ##              ##   ##  ##   ##  ##  ##    ##  ##   ##   #");
puts("      $      $$$$$     $$$$$        $$$$     #######   #####    ####              #####   ##   ##  ##  ##   #### ##  #######");
puts("    $$$$$$$$$$$$$$     $$$$$$$$$$$$$$$$$");
puts(" $$$$$$$$$$$$$$$$$     $$$$$$$$$$$$$$$$$     Hecho por: CLAUDIA GARCÍA-MATARREDONA URBANO");
puts("$$$$$$$$$$$$$$$$$$     $$$$$$$$$$$$$$$$$                YEDRA GARCÍA SÁNCHEZ");
puts("$$$$$ $$$$ $$$$$$$$$$$$$$$$ $$$$ $$$$$$$                EDISON MARIMON COOK");
puts(" $$$ $$$$$$ $$$$$$$$$$$$$$ $$$$$$ $$$$                  ÁLVARO FIUSA LÓPEZEO");
puts("      $$$$                  $$$$\n\n###########################################################################################################################\n\n");

    User_Menu(lineas_viajes, viaj, vec, lineas_vehiculos);

    return 0;
}
