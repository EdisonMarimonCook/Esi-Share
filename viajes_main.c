#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Vehiculos_header.h"
#include "viajes_header.h"
#define N 100

void error(){  //Hecho
    printf("######################################################################\n");
    printf("|Ha ocurrido un error a la hora de abrir el fichero <viajes_file.txt>|\n|    Por favor, inténtelo más tarde o consulte con mantenimiento     |\n");
    printf("######################################################################\n\n");
    exit(1);
}

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

int contar(){  //Hecho

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

void reserva_memoria(estruct_viajes **v, int lineas){  //Hecho

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

void subir_a_fichero_viajes(estruct_viajes *v){  //Hecho

    //Definición de datos:
    FILE *f;
    int j;
    char vector[N], aux;


    //Abrir fichero:
    if((f=fopen("viajes_file.txt","r"))==NULL){
        //Error dado en el caso de no poder abrir el fichero:
        error();
    }


    //LLenar en cada estructura del vector:
    for(j=0;!feof(f);j++){

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
        strcpy(v[j].Estado,vector);  //Estado*/
    }

    fclose(f);
}

void subir_viaje(){  //Yedra
    char vector[N];
    printf("¡Bienvenido al creador de viajes de ESI Share!\n\nIntroduzca la matrícula del coche que vaya a utilizar: ");
    fflush(stdin);
    fgets(vector,N,stdin);
}

void eliminar_viaje(estruct_viajes *v, int lineas){  //Hecho

    //Declaración de datos:
    setlocale(LC_ALL, "spanish");
    FILE *viajes_file_aux, *viajes_file;
    char aux='0', vector_temporal[N];
    int id=0, id_aux=0, i, encontrado=0, cont=-1, oportunidades=3;


    //Abro el fichero viajes_file.txt:
    viajes_file=fopen("viajes_file.txt", "r");
    if(viajes_file==NULL){
        //Error dado en el caso de no poder abrir el fichero:
        error();
    }

    rewind(viajes_file);


    //Enseña por pantalla todos los viajes guardados en el fichero:
    printf("¿Qué viaje desea eliminar?\n\n");
    while(!feof(viajes_file)){
        fgets(vector_temporal,N,viajes_file);
        printf("%s", vector_temporal);
    }


    //Creo una variable para el ID:
    printf("\n\nIntroduzca el ID del viaje a borrar: ");
    scanf("%d", &id);


    //Comparación:
    do{
        if(id==v[++cont].Id_viaje){
            encontrado=1;
        }
    }while(cont<lineas&&encontrado==0);

    if(encontrado==0){

        while(encontrado==0&&oportunidades>0){
            rewind(viajes_file);
            printf("\nEste viaje no existe, por favor inténtelo de nuevo\n(Le quedan %d intentos)\n", oportunidades);
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


    //Copiar contenido de viajes_file.txt en viajes_file_aux.txt menos la línea que se desea eliminar:
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
    //Esto es para evitar que me escriba el último viajes varias veces al borrarlo:
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
    printf("\nEl viaje ha sido borrado con éxito\n\n");
}

void cambiar_coche(estruct_viajes *v, int pos){  //Hecho

    //Declaración de datos:
    char mat_nueva[8], aux;
    int bucle=0, i, validez, veces=0;

    system("cls");

    //Nueva matrícula:
    do{
        validez=0;
        printf("Introduzca la nueva matrícula: ");
        fflush(stdin);
        fgets(mat_nueva,8,stdin);

        //Ver validez de la matrícula:
        for(i=0;i<4;i++){
            aux=mat_nueva[i]-48;  //Para transformar el valor char a int
            if(aux<1||aux>9){
                validez++;
            }
        }
        for(i=4;i<7;i++){
            aux=mat_nueva[i];
            if(aux<65||aux>90){
                validez++;
            }
        }
        if(validez!=0){
            printf("\nMatrícula inválida, inténtelo de nuevo.");
            veces++;
            if(veces<=2){
                printf("\nPor favor, mirela bien\n\n");
            }else if(veces<5){
                printf("\nYo sé que tú puedes\n\n");
            }else if(veces<=7){
                printf("\n¿Estás bien?\n\n");
            }else{
                printf("\nNo puedo más, para.\n\n");
                exit(1);
            }
        }else{
            bucle++;
        }
    }while(bucle==0);


    //Poner en la estructura la nueva matrícula:
    strcpy(v[pos].Id_mat,mat_nueva);
    printf("\nLa matrícula ha sido cambiada con éxito\n\n");
}

void cambiar_fecha(estruct_viajes *v, int pos){  //Hecho
    //Declaración de datos:
    char fecha_nueva[11], aux, anos[5], meses[3], dias[3];
    int bucle=0, i, validez, veces=0, ano, mes, dia, j;

    system("cls");

    //Nueva fecha:
    do{
        validez=0;
        printf("Introduzca la nueva fecha (dd/mm/aaaa): ");
        fflush(stdin);
        fgets(fecha_nueva,11,stdin);

        //Ver validez de la fecha:

        //Validez del año
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
        for(i=0;i<2;i++){  //Validez del día
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

        if(validez!=0){
            printf("\nFecha inválida, inténtelo de nuevo.");
            veces++;
            if(veces<=2){
                printf("\nPor favor, mire que la fecha existe\n\n");
            }else if(veces<5){
                printf("\nYo sé que tú puedes\n\n");
            }else if(veces<=7){
                printf("\n¿Estás bien?\n\n");
            }else{
                printf("\nPara ya por favor\n\n");
                exit(1);
            }
        }else{
            bucle++;
        }
    }while(bucle==0);


    //Poner en la estructura la nueva matrícula:
    strcpy(v[pos].F_inic,fecha_nueva);
    printf("\nLa fecha ha sido cambiada con éxito\n\n");
}

void cambiar_hora(estruct_viajes *v, int pos){  //Mirar compatibilidad de horas y reloj
    //Declaración de datos:
    char hora_nueva[6], aux, horas[3], minutos[3];
    int bucle=0, i, j, validez, veces=0, hora, minuto, op, hora_aux, minuto_aux;

    system("cls");

    do{
        validez=0;
        printf("Introduzca una nueva hora de inicio (hh:mm)-> ");
        fflush(stdin);
        fgets(hora_nueva,6,stdin);

        //Ver validez de la matrícula:

        //Ver hora:
        j=0;
        for(i=0;i<2;i++){
            horas[j]=hora_nueva[i];
            j++;
        }
        hora=atoi(horas);
        if(hora<0||hora>59){
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
            printf("\nHora inválida, inténtelo de nuevo.");
            veces++;
            if(veces<=2){
                printf("\nPor favor, mire que sale en un instante de tiempo existente\n\n");
            }else if(veces<5){
                printf("\nYo sé que tú puedes\n\n");
            }else if(veces<=7){
                printf("\n¿Estás bien?\n\n");
            }else{
                printf("\nSuficiente alteración temporal, fuera.\n\n");
                exit(1);
            }
        }else{
            bucle++;
        }
    }while(bucle==0);


    //Poner en la estructura la nueva h:
    strcpy(v[pos].H_inic,hora_nueva);
    printf("\nLa hora de inicio ha sido cambiada con éxito\n\n");

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

        //Ver validez de la matrícula:

        //Ver hora:
        j=0;
        for(i=0;i<2;i++){
            horas[j]=hora_nueva[i];
            j++;
        }
        hora=atoi(horas);
        if(hora<0||hora>59){
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

        //Cuando sé que la hora existe miro la compatibilidad con la hora de inicio:
        if(hora<hora_aux){
            validez++;
        }else if(hora==hora_aux&&minuto<=minuto_aux){
            validez++;
        }

        if(validez!=0){
            printf("\nHora inválida, inténtelo de nuevo.");
            veces++;
            if(veces<=2){
                printf("\nPor favor, mire que llega en un instante de tiempo existente\n\n");
            }else if(veces<5){
                printf("\nYo sé que tú puedes\n\n");
            }else if(veces<=7){
                printf("\n¿Estás bien?\n\n");
            }else{
                printf("\nSuficiente alteración temporal, fuera.\n\n");
                exit(1);
            }
        }else{
            bucle++;
        }
    }while(bucle==0);


    //Poner en la estructura la nueva hora:
    strcpy(v[pos].H_fin,hora_nueva);
    printf("\nLa hora final ha sido cambiada con éxito\n\n");
}

void cambiar_plazas(estruct_viajes *v, int pos){  //Conectar con vehículos para acceder al nº de plazas max del coche
    //Declaración de datos:
    int bucle=0, i, validez, veces=0, plazas_nueva;

    system("cls");

    //Nuevo número de plazas:
    do{
        validez=0;
        printf("Introduzca el nuevo número de plazas disponibles: ");
        scanf("%d", &plazas_nueva);

        //Ver validez de las plazas:

        if(plazas_nueva<0/*||plazas_nueva>plazas máxima del vehículo*/){
            validez++;
        }

        if(validez!=0){
            printf("\nNúmero de plazas inválida, inténtelo de nuevo.");
            veces++;
            if(veces<=2){
                printf("\nPor favor, cuéntelas de nuevo\n\n");
            }else if(veces<5){
                printf("\nYo sé que tú puedes\n\n");
            }else if(veces<=7){
                printf("\n¿Estás bien?\n\n");
            }else{
                printf("\nNo sabes contar\n\n");
                exit(1);
            }
        }else{
            bucle++;
        }
    }while(bucle==0);


    //Poner en la estructura el nuevo número de plazas:
    v[pos].Plazas_libre=plazas_nueva;
    printf("\nEl número de plazas ha sido cambiado con éxito\n");
}

void cambiar_importe(estruct_viajes *v, int pos){  //Hecho
    //Declaración de datos:
    int bucle=0, i, validez, veces=0, importe_nueva;

    system("cls");

    //Nuevo importe:
    do{
        validez=0;
        printf("Introduzca el nuevo importe: ");
        scanf("%d", &importe_nueva);

        //Ver validez de la matrícula:

        if(importe_nueva<1){
            validez++;
        }

        if(validez!=0){
            printf("\nImporte inválido, inténtelo de nuevo.");
            veces++;
            if(veces<=2){
                printf("\nPor favor, no introduzca un importe nulo o negativo\n\n");
            }else if(veces<5){
                printf("\nDe dónde vamos a coger dinero sino paras de poner el importe gratuito\n\n");
            }else if(veces<=7){
                printf("\n¿Acaso te importamos los programadores que hemos sufrido crear esta aplicación?\n\n");
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
    printf("\nEl importe ha sido cambiado con éxito\n\n");
}

void cambiar_estado(estruct_viajes *v, int pos){  //Hecho
    //Declaración de datos:
    char estado_nueva[15];
    int bucle=0, i, validez, veces=0, op;

    system("cls");

    //Nuevo estado:
    do{
        validez=0;
        printf("Elija un estado nuevo:\n1. ABIERTO\n2. CERRADO\n3. INICIADO\n4. FINALIZADO\n5. ANULADO\n");
        scanf("%d", &op);

        //Ver validez de la matrícula:

        if(op<1||op>5){
            validez++;
        }

        if(validez!=0){
            printf("\nEstado inválido, inténtelo de nuevo.");
            veces++;
            if(veces<=2){
                printf("\nPor favor, elija un estado válido\n\n");
            }else if(veces<5){
                printf("\nYo sé que tú puedes\n\n");
            }else if(veces<=7){
                printf("\n¿Estás bien?\n\n");
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
    printf("\nEl estado ha sido cambiado con éxito\n\n");
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

int modificar_viaje(estruct_viajes *v, int lineas){  //Hecho

    //Declaración de datos:
    FILE *viajes_file;
    char c, vector[N], res;
    int i=0, encontrado=0, oportunidades=3, elect, cont_menu=0, pos, id=0;


    //Abro el fichero viajes_file.txt:
    viajes_file=fopen("viajes_file.txt", "r");
    if(viajes_file==NULL){
        //Error dado en el caso de no poder abrir el fichero:
        error();
    }


    //Enseña por pantalla todos los viajes guardados en el fichero:
    printf("¿Qué viaje desea modificar?\n\n");
    while(!feof(viajes_file)){
        fgets(vector,N,viajes_file);
        printf("%s", vector);
    }


    //Elegir viaje a editar:
    printf("\n\nIntroduzca el ID del viaje que desee editar: ");
    scanf("%d", &id);


    //Comprobar existencia de ID:
    while(encontrado==0&&i<lineas){
        if(id==v[++i].Id_viaje){
            encontrado++;
            pos=i;
        }
    }
    if(encontrado==0){
        while(encontrado==0&&oportunidades>0){
            rewind(viajes_file);
            printf("\nEste viaje no existe, por favor inténtelo de nuevo\n(Le quedan %d intentos)\n", oportunidades);
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


    //Menú de edición:
    system("cls");
    do{
        printf("\n########################");
        printf("\n|¿Qué desea editar?    |");
        printf("\n|                      |");
        printf("\n|1. Cambiar coche      |\n|2. Cambiar fecha      |\n|3. Cambiar hora       |\n|4. Cambiar nº plazas  |\n|5. Cambiar importe    |\n|6. Cambiar estado     |\n|7. Salir              |\n");
        printf("########################\n\n");
        scanf("%d", &elect);

        //Comprobación de elección de menú válida:
        while(elect<1||elect>7){
            printf("VALOR INVÁLIDO: Introduzca '1', '2', '3', '4', '5', '6' o '7' para seleccionar la opción deseada\n");
            scanf("%d", &elect);
        }

        switch(elect){
            case 1: cambiar_coche(v,pos);
            break;
            case 2: cambiar_fecha(v,pos);
            break;
            case 3: cambiar_hora(v,pos);
            break;
            case 4: cambiar_plazas(v,pos);
            break;
            case 5: cambiar_importe(v,pos);
            break;
            case 6: cambiar_estado(v,pos);
            break;
            case 7: return 0;
        }

        //Abro el fichero viajes_file.txt:
        viajes_file=fopen("viajes_file.txt", "w+");
        if(viajes_file==NULL){
            //Error dado en el caso de no poder abrir el fichero:
            error();
        }

        for(i=0;i<(lineas-1);i++){

            poner_ceros(v,viajes_file,i);  //Rellena de 0s Id_viaje pa q escriba 000001, en vez de: 1
            fprintf(viajes_file, "%d-", v[i].Id_viaje);  //Escribir ID

            fputs(v[i].Id_mat,viajes_file);  //Escribir matrícula
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

        fputs(v[lineas-1].Id_mat,viajes_file);  //Escribir matrícula
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

        printf("¿Desea continuar modificando este viaje?\n(s/n)\n");
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
    return 1;
}

void menu_viajes(){  //Hecho

    //Declaración de datos:
    setlocale(LC_ALL, "spanish");  //Función para poder escribir carácteres específicos del español
    int elect, cont_menu=0, j, lineas;
    estruct_viajes *viaj;
    char res;


    //Contar longitud del fichero:
    lineas=contar();


    //Reservar memoria:
    reserva_memoria(&viaj, lineas);


    //Cargar datos a estructura:
    subir_a_fichero_viajes(viaj);


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
        system("cls"); //Sirve para limpiar la pantalla


        //Elección de función:
        switch (elect){
            case 1: subir_viaje();
            break;
            case 2: eliminar_viaje(viaj,lineas);
            break;
            case 3: modificar_viaje(viaj,lineas);
            break;
            case 4: exit(1);
        }


        //Elección sobre continuación del bucle:
        printf("¿Desea continuar modificando sus viajes?\n(s/n)\n");
        scanf(" %c", &res);
        while(res!='s'&&res!='n'&&res!='N'&&res!='S'){
            printf("VALOR INVÁLIDO: Responda con 's' para continuar o 'n' para salir del menú viajes\n");
            scanf(" %c", &res);
        }
        system("cls");
        if(res=='n'||res=='N'){
            cont_menu++;
        }
    }while(cont_menu==0);
}
