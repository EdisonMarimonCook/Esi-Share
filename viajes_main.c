#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Vehiculos_header.h"
#include "viajes_header.h"
#include "PASOS.h"
#define N 100

void error(){  //Hecho
    printf("######################################################################\n");
    printf("|Ha ocurrido un error a la hora de abrir el fichero <viajes_file.txt>|\n|    Por favor, int�ntelo m�s tarde o consulte con mantenimiento     |\n");
    printf("######################################################################\n\n");
    exit(1);
}

int validez_fecha(char fecha_nueva[]){  //Hecho
    //Declaraci�n de datos:
    char aux, anos[5], meses[3], dias[3];
    int i, validez=0, ano, mes, dia, j;

    //Validez del a�o
    j=0;
    for(i=6;i<10;i++){
        anos[j]=fecha_nueva[i];
        j++;
    }
    ano=atoi(anos);
    if(ano<0){
        validez++;
    }

    //Validez de segundo '/'
    aux=fecha_nueva[5];
    if(aux!='/'){
        validez++;
    }

    //Validez del mes:
    j=0;
    for(i=3;i<5;i++){  //Validez del mes
        meses[j]=fecha_nueva[i];
        j++;
    }
    mes=atoi(meses);
    if(mes<1||mes>12){
        validez++;
    }

    //Validez del primer '/'
    aux=fecha_nueva[2];
    if(aux!='/'){
        validez++;
    }

    //Validez del dia
    j=0;
    for(i=0;i<2;i++){  //Validez del d�a
        dias[j]=fecha_nueva[i];
        j++;
    }
    dia=atoi(dias);

    switch(mes){
        case 1: case 3: case 5: case 7: case 10: case 12:
            if(dia<1||dia>31){
                validez++;
            }
        break;
        case 4: case 6: case 9: case 11:
            if(dia<1||dia>30){
                validez++;
            }
        break;
        case 2:
            if(ano%4==0&&ano%100!=0){
                if(dia<1||dia>29){
                    validez++;
                }
            }else{
                if(dia<1||dia>28){
                    validez++;
                }
            }
    }
    return validez;
}

void poner_ceros(estruct_viajes *v, FILE *viajes_file, int pos){  //Hecho
    int aux, cont=0, i;
    aux=v[pos].Id_viaje;
    while(aux>0){
        aux/=10;
        cont++;
    }
    for(i=6;i>cont;i--){
        fputc('0',viajes_file);
    }
}

void guardar_datos(int lineas, estruct_viajes *v){  //Hecho

    FILE *viajes_file;
    int i;

    //Abro el fichero viajes_file.txt:
    viajes_file=fopen("viajes_file.txt", "w+");
    if(viajes_file==NULL){
        //Error dado en el caso de no poder abrir el fichero:
        error();
    }

    for(i=0;i<(lineas-1);i++){

        poner_ceros(v,viajes_file,i);  //Rellena de 0s Id_viaje pa q escriba 000001, en vez de: 1
        fprintf(viajes_file, "%d-", v[i].Id_viaje);  //Escribir ID

        fputs(v[i].Id_mat,viajes_file);  //Escribir matr�cula
        fputc('-', viajes_file);

        fputs(v[i].F_inic,viajes_file);  //Escribir fecha inicial
        fputc('-', viajes_file);

        fputs(v[i].H_inic,viajes_file);  //Escribir hora de inicio
        fputc('-', viajes_file);

        fputs(v[i].H_fin,viajes_file);  //Escribir hora final
        fputc('-', viajes_file);

        fprintf(viajes_file, "%d-", v[i].Plazas_libre);  //Escribir plazas libres

        fprintf(viajes_file, "%d-", v[i].Importe);  //Escribir importe

        fputs(v[i].Estado,viajes_file);  //Escribir estado
        fputc('\n', viajes_file);
    }

    poner_ceros(v,viajes_file,(lineas-1));  //Rellena de 0s Id_viaje pa q escriba 000001, en vez de: 1
    fprintf(viajes_file, "%d-", v[lineas-1].Id_viaje);  //Escribir ID

    fputs(v[lineas-1].Id_mat,viajes_file);  //Escribir matr�cula
    fputc('-', viajes_file);

    fputs(v[lineas-1].F_inic,viajes_file);  //Escribir fecha inicial
    fputc('-', viajes_file);

    fputs(v[lineas-1].H_inic,viajes_file);  //Escribir hora de inicio
    fputc('-', viajes_file);

    fputs(v[lineas-1].H_fin,viajes_file);  //Escribir hora final
    fputc('-', viajes_file);

    fprintf(viajes_file, "%d-", v[lineas-1].Plazas_libre);  //Escribir plazas libres

    fprintf(viajes_file, "%d-", v[lineas-1].Importe);  //Escribir importe

    fputs(v[lineas-1].Estado,viajes_file);  //Escribir estado

    fclose(viajes_file);
}

void buscar_viaje(estruct_viajes *v, int lineas){  //FALTA

    //Declaraci�n de datos:
    FILE *f;
    int i, encontrado=0, id, bucle=0;
    char vector[N], aux;

    //Abrir fichero:
    f=fopen("viajes_file.txt","r");
    if(f==NULL){
        error();
    }

    //Buscador de viajes por localidad:
    id=selector_camino();

    //Escribir datos del viaje seleccionado en pasos:
    while(bucle==0){
        for(i=0;i<lineas&&encontrado==0;i++){
            if(id==v[i].Id_viaje){
                encontrado++;
                fgets(vector,N,f);
                printf("%s", vector);
            }
        }

        if(encontrado==0){
            printf("Este viaje no existe, por favor vuelva a intentarlo.\n");
            id=selector_camino();
        }else{
            //Existe, pero est� disponible?:
            if(strcmp(v[i].Estado,"ABIERTO")==0){

               printf("\n�Te gusta este viaje? �Quieres hacerlo?\n(s/n): ");
                scanf(" %c", &aux);
                //Lo haces?
                if(aux=='S'||aux=='s'){
                    v[i].Plazas_libre--;
                    if(v[i].Plazas_libre==0){
                        strcpy(v[i].Estado,"LLENO");
                    }
                    guardar_datos(lineas,v);
                    printf("\nElecci�n exitosa, pr�ximamente se le har� un cargo de %d$\nGracias por usar ESI-SHARE\n\n", v[i].Importe);
                    bucle++;
                }else{
                    id=selector_camino();
                }
            }else{
                printf("El viaje no est� disponible.\n");
                id=selector_camino();
            }
        }
    }
    fclose(f);
}

void subir_viaje(estruct_viajes *v, int lineas, estruct_vehiculos *vec, int l){  //FALTA

    //Declaraci�n de datos:
    char vector[N];
    int encontrado=0, k, i, id_generado=0;

    //Generar ID de viaje nueva:
    id_generado++;
    //Existe?
    for(i=0;encontrado==0&&i<lineas;i++){
        if(id_generado==v[i].Id_viaje){
            encontrado++;
        }
    }
    while(encontrado!=0){
        encontrado=0;
       //Generar ID de viaje nueva:
        id_generado++;
        //Existe?
        for(i=0;encontrado==0&&i<lineas;i++){
            if(id_generado==v[i].Id_viaje){
                encontrado++;
            }
        }
    }

    FILE *f;

    f=fopen("viajes_file.txt","a+");
    if(f==NULL){
        error();
    }

    system("cls");

    //Obtener MATR�CULA:
    printf("Introduzca la matr�cula del coche que va a utilizar: ");
    fflush(stdin);
    fgets(vector,8,stdin);
    for(k=0;k<l&&encontrado==0;k++){
        if(strcmp(vector,vec[k].Id_mat)==0){
            encontrado++;
        }
    }
    if(encontrado==0){
        printf("\nEl coche introducido no est� registrado, por favor reg�strelo e int�ntelo de nuevo.\n");
    }else{
        fprintf(f,"\n");
        int a, cont=0;
        a=id_generado;
        while(a>0){
            a/=10;
            cont++;
        }
        for(i=6;i>cont;i--){
            fputc('0',f);
        }
        fprintf(f, "%d-", id_generado);
        fputs(vector,f);
        fputc('-',f);

        //Obtener FECHA:
        printf("\nIntroduzca la fecha de salida (dd/mm/aaaa): ");
        fflush(stdin);
        fgets(vector,11,stdin);
        //Validez de la fecha:
        while((validez_fecha(vector))!=0){
            printf("Fecha no v�lida, por favor introd�zcala de nuevo\n(Recuerde que debe seguir el formato (dd/mm/aaaa): ");
            fflush(stdin);
            fgets(vector,11,stdin);
        }
        fputs(vector,f);
        fputc('-',f);

        char hora_nueva[6], aux, horas[3], minutos[3];
        int j, validez=0, hora, minuto, hora_aux, minuto_aux;

        //Obtener HORAS.
        printf("\nIntroduzca la hora de salida (hh:mm)-> ");
        fflush(stdin);
        fgets(hora_nueva,6,stdin);


        //Ver hora:
        j=0;
        for(i=0;i<2;i++){
            horas[j]=hora_nueva[i];
            j++;
        }
        hora=atoi(horas);
        if(hora<0||hora>23){
            validez++;
        }

        //Ver ':'
        aux=hora_nueva[2];
        if(aux!=':'){
            validez++;
        }

        //Ver minutos:
        j=0;
        for(i=3;i<5;i++){
            minutos[j]=hora_nueva[i];
            j++;
        }
        minuto=atoi(minutos);
        if(minuto<0||minuto>59){
            validez++;
        }
        while(validez!=0){
                validez=0;
            printf("\nHora no v�lida, por favor introd�zcala de nuevo\n(Recuerde que debe seguir el formato (hh:mm)-> ");
            fflush(stdin);
            fgets(hora_nueva,6,stdin);
            //Ver hora:
            j=0;
            for(i=0;i<2;i++){
                horas[j]=hora_nueva[i];
                j++;
            }
            hora=atoi(horas);
            if(hora<0||hora>23){
                validez++;
            }

            //Ver ':'
            aux=hora_nueva[2];
            if(aux!=':'){
                validez++;
            }

            //Ver minutos:
            j=0;
            for(i=3;i<5;i++){
                minutos[j]=hora_nueva[i];
                j++;
            }
            minuto=atoi(minutos);
            if(minuto<0||minuto>59){
                validez++;
            }
        }
        fputs(hora_nueva,f);
        fputc('-',f);
        //Guardar valores antiguos para comparar:
        hora_aux=hora;
        minuto_aux=minuto;

        printf("\nIntroduzca la hora de llegada (hh:mm)-> ");
        fflush(stdin);
        fgets(hora_nueva,6,stdin);

        //Ver hora:
        j=0;
        for(i=0;i<2;i++){
            horas[j]=hora_nueva[i];
            j++;
        }
        hora=atoi(horas);
        if(hora<0||hora>23){
            validez++;
        }

        //Ver ':'
        aux=hora_nueva[2];
        if(aux!=':'){
            validez++;
        }

        //Ver minutos:
        j=0;
        for(i=3;i<5;i++){
            minutos[j]=hora_nueva[i];
            j++;
        }
        minuto=atoi(minutos);
        if(minuto<0||minuto>59){
            validez++;
        }

        //Cuando s� que la hora existe miro la compatibilidad con la hora de inicio:
        if(hora<hora_aux){
            validez++;
        }else if(hora==hora_aux&&minuto<=minuto_aux){
            validez++;
        }
        while(validez!=0){
            validez=0;
            printf("\nHora no v�lida, por favor introd�zcala de nuevo\n(Recuerde que debe seguir el formato (hh:mm)-> ");
            fflush(stdin);
            fgets(hora_nueva,6,stdin);

            //Ver hora:
            j=0;
            for(i=0;i<2;i++){
                horas[j]=hora_nueva[i];
                j++;
            }
            hora=atoi(horas);
            if(hora<0||hora>23){
                validez++;
            }

            //Ver ':'
            aux=hora_nueva[2];
            if(aux!=':'){
                validez++;
            }

            //Ver minutos:
            j=0;
            for(i=3;i<5;i++){
                minutos[j]=hora_nueva[i];
                j++;
            }
            minuto=atoi(minutos);
            if(minuto<0||minuto>59){
                validez++;
            }

            //Cuando s� que la hora existe miro la compatibilidad con la hora de inicio:
            if(hora<hora_aux){
                validez++;
            }else if(hora==hora_aux&&minuto<=minuto_aux){
                validez++;
            }
        }
        fputs(hora_nueva,f);
        fputc('-',f);

        //Obtener PLAZAS:
        fprintf(f, "%d-", vec[--k].Num_plazas);
        //Obtener IMPORTE:
        int importe;
        printf("\nIntroduzca el importe deseado: ");
        scanf("%d", &importe);

        while(importe<=0){
            printf("Importe err�neo, por favor cobre al menos 1� para benificio de la aplicaci�n.\nVuelva a introducir el importe: ");
            scanf("%d", &importe);
        }
        fprintf(f, "%d-", importe);
        //Obtener ESTADO:
        fprintf(f, "ABIERTO");

        //Crea pasos:
        printf("\n");
        fclose(f);
        CREAR_VIAJE(id_generado);
        exit(1);
    }
}

void eliminar_viaje(estruct_viajes *v, int lineas){  //Hecho

    //Declaraci�n de datos:
    setlocale(LC_ALL, "spanish");
    FILE *viajes_file_aux, *viajes_file;
    char aux='0', vector_temporal[N];
    int id=0, id_aux=0, encontrado=0, cont=-1, oportunidades=3;


    //Abro el fichero viajes_file.txt:
    viajes_file=fopen("viajes_file.txt", "r");
    if(viajes_file==NULL){
        //Error dado en el caso de no poder abrir el fichero:
        error();
    }

    rewind(viajes_file);


    //Ense�a por pantalla todos los viajes guardados en el fichero:
    printf("�Qu� viaje desea eliminar?\n\n");
    printf("|| ID || MATR�CULA || FECHA || HORA SALIDA || HORA LLEGADA || PLAZAS LIBRES || IMPORTE || ESTADO ||\n\n");
    while(!feof(viajes_file)){
        fgets(vector_temporal,N,viajes_file);
        printf("%s", vector_temporal);
    }


    //Creo una variable para el ID:
    printf("\n\nIntroduzca el ID del viaje a borrar: ");
    scanf("%d", &id);


    //Comparaci�n:
    do{
        if(id==v[++cont].Id_viaje){
            encontrado=1;
        }
    }while(cont<lineas&&encontrado==0);

    if(encontrado==0){

        while(encontrado==0&&oportunidades>0){
            rewind(viajes_file);
            printf("\nEste viaje no existe, por favor int�ntelo de nuevo\n(Le quedan %d intentos)\n", oportunidades);
            scanf("%d", &id);
            cont=0;
            while(encontrado==0&&cont<lineas){
                if(id==v[++cont].Id_viaje){
                    encontrado++;
                }
            }
            if(encontrado==0){
                oportunidades--;
            }
            if(oportunidades==0){
                exit(1);
            }
        }
    }

    //Abrir un fichero auxiliar para introducir los datos:
    viajes_file_aux=fopen("viajes_file_aux.txt", "w+");
    if(viajes_file_aux==NULL){
        //Error dado en el caso de no poder abrir el fichero:
        error();
    }


    //Copiar contenido de viajes_file.txt en viajes_file_aux.txt menos la l�nea que se desea eliminar:
    rewind(viajes_file);
    while(!feof(viajes_file)){
        leer(vector_temporal,viajes_file);
        id_aux=atoi(vector_temporal);
        if(id!=id_aux){
            fputs(vector_temporal,viajes_file_aux);
            fputc('-', viajes_file_aux);
            fgets(vector_temporal,N,viajes_file);
            fputs(vector_temporal,viajes_file_aux);
        }else{
            while(aux!='\n'&&aux!=EOF){
                aux=fgetc(viajes_file);
            }
        }
    }
    //Esto es para evitar que me escriba el �ltimo viajes varias veces al borrarlo:
    if(aux==EOF){
        putc(aux,viajes_file_aux);
    }


    //Cierro los ficheros para editar nombres y borrar cosas:
    fclose(viajes_file_aux);
    fclose(viajes_file);


    //Borrar:
    system("rename viajes_file.txt borrador.txt");
    system("rename viajes_file_aux.txt viajes_file.txt");
    system("del borrador.txt");
    printf("\nEl viaje ha sido borrado con �xito\n\n");
    exit(1);
}

void cambiar_coche(estruct_viajes*v, estruct_vehiculos *vec, int pos, int lineas){  //Hecho

    //Declaraci�n de datos:
    char mat_nueva[8];
    int bucle=0, i, veces=0, encontrado;

    system("cls");

    //Nueva matr�cula:
    do{
        printf("Introduzca la nueva matr�cula: ");
        fflush(stdin);
        fgets(mat_nueva,8,stdin);

        /*//Ver validez de la matr�cula:
        for(i=0;i<4;i++){
            aux=mat_nueva[i]-48;  //Para transformar el valor char a int
            if(aux<0||aux>9){
                validez++;
            }
        }
        for(i=4;i<7;i++){
            aux=mat_nueva[i];
            if(aux<65||aux>90){
                validez++;
            }
        }*/

        encontrado=0;
        //Mirar que el coche est� registrado:
        for(i=0;i<lineas&&encontrado==0;i++){
            if(strcmp(mat_nueva,vec[i].Id_mat)==0){
                encontrado++;
            }
        }

        if(encontrado==0){
            printf("\nMatr�cula no registrada, int�ntelo de nuevo.");
            veces++;
            if(veces<=2){
                printf("\nPor favor, mirela bien\n\n");
            }else if(veces<4){
                printf("\nYo s� que t� puedes\n\n");
            }else if(veces<=5){
                printf("\n�Est�s bien?\n\n");
            }else{
                printf("\nNo puedo m�s, para.\n\n");
                exit(1);
            }
        }else{
            bucle++;
        }
    }while(bucle==0);


    //Poner en la estructura la nueva matr�cula:
    v[pos].Plazas_libre=vec[--i].Num_plazas;
    strcpy(v[pos].Estado,"ABIERTO");
    strcpy(v[pos].Id_mat,mat_nueva);
    printf("\nLa matr�cula ha sido cambiada con �xito\n\n");
}

void cambiar_fecha(estruct_viajes *v, int pos){  //Hecho
    //Declaraci�n de datos:
    char fecha_nueva[11];
    int bucle=0, validez, veces=0;

    system("cls");

    //Nueva fecha:
    do{
        validez=0;
        printf("Introduzca la nueva fecha (dd/mm/aaaa): ");
        fflush(stdin);
        fgets(fecha_nueva,11,stdin);

        validez=validez_fecha(fecha_nueva);

        if(validez!=0){
            printf("\nFecha inv�lida, int�ntelo de nuevo.");
            veces++;
            if(veces<=2){
                printf("\nPor favor, mire que la fecha existe\n\n");
            }else if(veces<5){
                printf("\nYo s� que t� puedes\n\n");
            }else if(veces<=7){
                printf("\n�Est�s bien?\n\n");
            }else{
                printf("\nPara ya por favor\n\n");
                exit(1);
            }
        }else{
            bucle++;
        }
    }while(bucle==0);


    //Poner en la estructura la nueva matr�cula:
    strcpy(v[pos].F_inic,fecha_nueva);
    printf("\nLa fecha ha sido cambiada con �xito\n\n");
}

void cambiar_hora(estruct_viajes *v, int pos){  //Mirar compatibilidad de horas y reloj
    //Declaraci�n de datos:
    char hora_nueva[6], aux, horas[3], minutos[3];
    int bucle=0, i, j, validez, veces=0, hora, minuto, hora_aux, minuto_aux;

    system("cls");

    do{
        validez=0;
        printf("Introduzca una nueva hora de inicio (hh:mm)-> ");
        fflush(stdin);
        fgets(hora_nueva,6,stdin);

        //Ver validez de la hora:

        //Ver hora:
        j=0;
        for(i=0;i<2;i++){
            horas[j]=hora_nueva[i];
            j++;
        }
        hora=atoi(horas);
        if(hora<0||hora>23){
            validez++;
        }

        //Ver ':'
        aux=hora_nueva[2];
        if(aux!=':'){
            validez++;
        }

        //Ver minutos:
        j=0;
        for(i=3;i<5;i++){
            minutos[j]=hora_nueva[i];
            j++;
        }
        minuto=atoi(minutos);
        if(minuto<0||minuto>59){
            validez++;
        }

        if(validez!=0){
            printf("\nHora inv�lida, int�ntelo de nuevo.");
            veces++;
            if(veces<=2){
                printf("\nPor favor, mire que sale en un instante de tiempo existente\n\n");
            }else if(veces<5){
                printf("\nYo s� que t� puedes\n\n");
            }else if(veces<=7){
                printf("\n�Est�s bien?\n\n");
            }else{
                printf("\nSuficiente alteraci�n temporal, fuera.\n\n");
                exit(1);
            }
        }else{
            bucle++;
        }
    }while(bucle==0);


    //Poner en la estructura la nueva h:
    strcpy(v[pos].H_inic,hora_nueva);
    printf("\nLa hora de inicio ha sido cambiada con �xito\n\n");

    //Guardar valores antiguos para comparar:
    hora_aux=hora;
    minuto_aux=minuto;

    //Nueva hora de llegada:
    veces=0;
    bucle=0;
    do{
        validez=0;
        printf("Introduzca una nueva hora de llegada (hh:mm)-> ");
        fflush(stdin);
        fgets(hora_nueva,6,stdin);

        //Ver validez de la matr�cula:

        //Ver hora:
        j=0;
        for(i=0;i<2;i++){
            horas[j]=hora_nueva[i];
            j++;
        }
        hora=atoi(horas);
        if(hora<0||hora>23){
            validez++;
        }

        //Ver ':'
        aux=hora_nueva[2];
        if(aux!=':'){
            validez++;
        }

        //Ver minutos:
        j=0;
        for(i=3;i<5;i++){
            minutos[j]=hora_nueva[i];
            j++;
        }
        minuto=atoi(minutos);
        if(minuto<0||minuto>59){
            validez++;
        }

        //Cuando s� que la hora existe miro la compatibilidad con la hora de inicio:
        if(hora<hora_aux){
            validez++;
        }else if(hora==hora_aux&&minuto<=minuto_aux){
            validez++;
        }

        if(validez!=0){
            printf("\nHora inv�lida, int�ntelo de nuevo.");
            veces++;
            if(veces<=2){
                printf("\nPor favor, mire que llega en un instante de tiempo existente\n\n");
            }else if(veces<5){
                printf("\nYo s� que t� puedes\n\n");
            }else if(veces<=7){
                printf("\n�Est�s bien?\n\n");
            }else{
                printf("\nSuficiente alteraci�n temporal, fuera.\n\n");
                exit(1);
            }
        }else{
            bucle++;
        }
    }while(bucle==0);


    //Poner en la estructura la nueva hora:
    strcpy(v[pos].H_fin,hora_nueva);
    printf("\nLa hora final ha sido cambiada con �xito\n\n");
}

void cambiar_plazas(estruct_viajes *v, int pos, estruct_vehiculos *vec, int lineas){  //Hecho
    //Declaraci�n de datos:
    int bucle=0, validez, veces=0, plazas_nueva, encontrado=0;

    system("cls");

    //Nuevo n�mero de plazas:
    do{
        validez=0;
        printf("Introduzca el nuevo n�mero de plazas disponibles: ");
        scanf("%d", &plazas_nueva);

        //Buscar matr�cula en veh�culos:
        int i=-1;
        while(encontrado==0&&i<lineas){
            if(strcmp(v[pos].Id_mat,vec[++i].Id_mat)==0){
                encontrado++;
            }
        }

        //Ver validez de las plazas:
        if(plazas_nueva<0||plazas_nueva>vec[i].Num_plazas){
            validez++;
        }

        if(validez!=0){
            printf("\nN�mero de plazas inv�lida, int�ntelo de nuevo.");
            veces++;
            if(veces<=2){
                printf("\nPor favor, cu�ntelas de nuevo\n\n");
            }else if(veces<5){
                printf("\nYo s� que t� puedes\n\n");
            }else if(veces<=7){
                printf("\n�Est�s bien?\n\n");
            }else{
                printf("\nNo sabes contar\n\n");
                exit(1);
            }
        }else{
            bucle++;
        }
    }while(bucle==0);


    //Poner en la estructura el nuevo n�mero de plazas:
    v[pos].Plazas_libre=plazas_nueva;
    printf("\nEl n�mero de plazas ha sido cambiado con �xito\n");

    //Cerrar el viaje si ya no hay plazas libres o abrirlo si se queda alguno libre:
    if(plazas_nueva==0){
        strcpy(v[pos].Estado,"LLENO");
    }else{
        strcpy(v[pos].Estado,"ABIERTO");
    }
}

void cambiar_importe(estruct_viajes *v, int pos){  //Hecho
    //Declaraci�n de datos:
    int bucle=0, validez, veces=0, importe_nueva;

    system("cls");

    //Nuevo importe:
    do{
        validez=0;
        printf("Introduzca el nuevo importe: ");
        scanf("%d", &importe_nueva);

        //Ver validez de la matr�cula:

        if(importe_nueva<1){
            validez++;
        }

        if(validez!=0){
            printf("\nImporte inv�lido, int�ntelo de nuevo.");
            veces++;
            if(veces<=2){
                printf("\nPor favor, no introduzca un importe nulo o negativo\n\n");
            }else if(veces<5){
                printf("\nDe d�nde vamos a coger dinero sino paras de poner el importe gratuito\n\n");
            }else if(veces<=7){
                printf("\n�Acaso te importamos los programadores que hemos sufrido para crear esta aplicaci�n?\n\n");
            }else{
                printf("\n#####\n\n");
                exit(1);
            }
        }else{
            bucle++;
        }
    }while(bucle==0);


    //Poner en la estructura el nuevo importe:
    v[pos].Importe=importe_nueva;
    printf("\nEl importe ha sido cambiado con �xito\n\n");
}

void cambiar_estado(estruct_viajes *v, int pos){  //Hecho
    //Declaraci�n de datos:
    int bucle=0, validez, veces=0, op;

    system("cls");

    //Nuevo estado:
    do{
        validez=0;
        printf("Elija un estado nuevo:\n1. ABIERTO\n2. CERRADO\n3. INICIADO\n4. FINALIZADO\n5. ANULADO\n");
        scanf("%d", &op);

        //Ver validez de la matr�cula:

        if(op<1||op>5){
            validez++;
        }

        if(validez!=0){
            printf("\nEstado inv�lido, int�ntelo de nuevo.");
            veces++;
            if(veces<=2){
                printf("\nPor favor, elija un estado v�lido\n\n");
            }else if(veces<5){
                printf("\nYo s� que t� puedes\n\n");
            }else if(veces<=7){
                printf("\n�Est�s bien?\n\n");
            }else{
                printf("\nPor favor aprende a leer\n\n");
                exit(1);
            }
        }else{
            bucle++;
        }
    }while(bucle==0);


    //Poner en la estructura el nuevo estado:
    switch(op){
        case 1: strcpy(v[pos].Estado,"ABIERTO");
        break;
        case 2: strcpy(v[pos].Estado,"CERRADO");
        break;
        case 3: strcpy(v[pos].Estado,"INICIADO");
        break;
        case 4: strcpy(v[pos].Estado,"FINALIZADO");
        break;
        case 5: strcpy(v[pos].Estado,"ANULADO");
    }
    printf("\nEl estado ha sido cambiado con �xito\n\n");
}

int modificar_viaje(estruct_viajes *v, int lineas, estruct_vehiculos *vec, int l){  //Hecho

    //Declaraci�n de datos:
    FILE *viajes_file;
    char vector[N], res;
    int i, encontrado=0, oportunidades=3, elect, cont_menu=0, pos, id=0;


    //Abro el fichero viajes_file.txt:
    viajes_file=fopen("viajes_file.txt", "r");
    if(viajes_file==NULL){
        //Error dado en el caso de no poder abrir el fichero:
        error();
    }


    //Ense�a por pantalla todos los viajes guardados en el fichero:
    printf("�Qu� viaje desea modificar?\n\n");
    printf("|| ID || MATR�CULA || FECHA || HORA SALIDA || HORA LLEGADA || PLAZAS LIBRES || IMPORTE || ESTADO ||\n\n");
    while(!feof(viajes_file)){
        fgets(vector,N,viajes_file);
        printf("%s", vector);
    }


    //Elegir viaje a editar:
    printf("\n\nIntroduzca el ID del viaje que desee editar: ");
    scanf("%d", &id);


    //Comprobar existencia de ID:
    i=-1;
    while(encontrado==0&&i<lineas){
        if(id==v[++i].Id_viaje){
            encontrado++;
            pos=i;
        }
    }
    if(encontrado==0){
        while(encontrado==0&&oportunidades>0){
            rewind(viajes_file);
            printf("\nEste viaje no existe, por favor int�ntelo de nuevo\n(Le quedan %d intentos)\n", oportunidades);
            scanf("%d", &id);
            i=0;
            while(encontrado==0&&i<lineas){
                if(id==v[++i].Id_viaje){
                    encontrado++;
                    pos=i;
                }
            }
            if(encontrado==0){
                oportunidades--;
            }
            if(oportunidades==0){
                exit(1);
            }
        }
    }


    //Cierro el fichero:
    fclose(viajes_file);


    //Men� de edici�n:
    system("cls");
    do{
        printf("\n########################");
        printf("\n|�Qu� desea editar?    |");
        printf("\n|                      |");
        printf("\n|1. Cambiar coche      |\n|2. Cambiar fecha      |\n|3. Cambiar hora       |\n|4. Cambiar n� plazas  |\n|5. Cambiar importe    |\n|6. Cambiar estado     |\n|7. Salir              |\n");
        printf("########################\n\n");
        scanf("%d", &elect);

        //Comprobaci�n de elecci�n de men� v�lida:
        while(elect<1||elect>7){
            printf("VALOR INV�LIDO: Introduzca '1', '2', '3', '4', '5', '6' o '7' para seleccionar la opci�n deseada\n");
            scanf("%d", &elect);
        }

        switch(elect){
            case 1: cambiar_coche(v,vec,pos,lineas);
            break;
            case 2: cambiar_fecha(v,pos);
            break;
            case 3: cambiar_hora(v,pos);
            break;
            case 4: cambiar_plazas(v,pos,vec,l);
            break;
            case 5: cambiar_importe(v,pos);
            break;
            case 6: cambiar_estado(v,pos);
            break;
            case 7: return 0;
        }

        guardar_datos(lineas,v);

        printf("�Desea continuar modificando este viaje?\n(s/n)\n");
        scanf(" %c", &res);
        while(res!='s'&&res!='n'&&res!='N'&&res!='S'){
            printf("VALOR INV�LIDO: Responda con 's' para continuar o 'n' para salir del men� viajes\n");
            scanf(" %c", &res);
        }
        system ("cls");
        if(res=='n'||res=='N'){
            cont_menu++;
        }

    }while(cont_menu==0);
    return 1;
}

void menu_viajes(int lineas, estruct_viajes *viaj, estruct_vehiculos *vec, int l){  //Hecho

    //Declaraci�n de datos:
    int elect, cont_menu=0;
    char res;

    system("cls");  //Sirve para limpiar la pantalla

    //Men� gr�fico:
    do{
        printf("##       ##   ##      ###       ########  ######   ######\n");
        printf(" ##     ##    ##     ## ##         ##     ##      ##\n");
        printf("  ##   ##     ##    ##   ##        ##     ######   ######\n");
        printf("   ## ##      ##   #########   ##  ##     ##            ##\n");
        printf("    ###       ##  ##       ##   ####      ######   ######\n");
        printf("\n ########################");
        printf("\n |�Qu� desea hacer?     |");
        printf("\n |                      |");
        printf("\n |1. Buscar un viaje    |\n |2. A�adir un viaje    |\n |3. Eliminar un viaje  |\n |4. Modificar un viaje |\n |5. Salir              |\n");
        printf(" ########################\n\n");
        scanf("%d", &elect);


        //Comprobaci�n de elecci�n de men� v�lida:
        while(elect<1||elect>5){
            printf("VALOR INV�LIDO: Introduzca '1', '2', '3', '4' o '5' para seleccionar la opci�n deseada\n");
            scanf("%d", &elect);
        }
        system("cls");


        //Elecci�n de funci�n:
        switch (elect){
            case 1: buscar_viaje(viaj,lineas);
            break;
            case 2: subir_viaje(viaj,lineas,vec,l);
            break;
            case 3: eliminar_viaje(viaj,lineas);
            break;
            case 4: modificar_viaje(viaj,lineas,vec,l);
            break;
            case 5: break;
        }


        //Elecci�n sobre continuaci�n del bucle:
        printf("�Desea seguir en viajes?\n(s/n)\n");
        scanf(" %c", &res);
        while(res!='s'&&res!='n'&&res!='N'&&res!='S'){
            printf("VALOR INV�LIDO: Responda con 's' para continuar o 'n' para salir del men� viajes\n");
            scanf(" %c", &res);
        }
        system("cls");
        if(res=='n'||res=='N'){
            cont_menu++;
        }
    }while(cont_menu==0);
}
