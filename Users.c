#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include "Users.h"
#include "Vehiculos_header.h"
#include "viajes_header.h"

int getUserId();
void User_Menu_Opciones_Usu();
void Editar_Perfil();
void Admin();
void sign_up();
void login();
void Editar_Contrasenya();
void Editar_Rango();

void User_Menu(int lineas, estruct_viajes *viaj, estruct_vehiculos *vec, int l){

    FILE *fuser;
    fuser = fopen("user_database.txt", "a+");
    if(fuser == NULL){
        printf("No es posible abrir: <user_database.txt>");
        exit(1);
    }

    int num;

    puts("Elija una opción ('1' o '2'):\n\n");

    puts("  ***     ##      ##     ####    ##   ##   ##");
    puts(" * **     ##    ##  ##  ##       ##   ###  ##");
    puts("   **     ##    ##  ##  ##  ##   ##   ## # ##");
    puts("   **     ##    ##  ##  ##   #   ##   ##  ###");
    puts(" ******   #####   ##     ####    ##   ##   ##");

    printf("\n\n");

    puts(" ****     ####  ##   ####    ##   ##           ##   ##   #######");
    puts("*   **   ##     ##  ##       ###  ##           ##   ##   ##   ##");
    puts("   **    #####  ##  ##  ##   ## # ##    ####   ##   ##   #######");
    puts("  **         ## ##  ##   #   ##  ###           ##   ##   ##");
    puts(" *****   #####  ##   ####    ##   ##             ###     ##\n\n");

    scanf("%d", &num);

    fflush(stdin);
    system("cls");

    while(num < 1 || num > 2){

        puts("Pulse '1' para hacer <Login> o '2' para hacer <Sign-up>");

        scanf("%d", &num);

        fflush(stdin);

        system("cls");

    }

    switch(num){

        case 1: login(lineas, viaj, vec, l);
        break;

        case 2: sign_up();
        break;
    }

    fclose(fuser);
}

void sign_up(){  //ERROR SI SE INTRODUCE CONTRASEÑA INCORRECTA

    FILE *fuser;
    fuser = fopen("user_database.txt", "a+");
    if(fuser == NULL){

        printf("No es posible abrir: <user_database.txt>");
        exit(1);
    }

    user user1;
    char fullstring[85];

    do{
        printf("Introduzca su nombre completo (máximo 20 caracteres):\n");
        fflush(stdin);

        fgets(user1.Name_User, sizeof(user1.Name_User), stdin);

        system("cls");

        if (strlen(user1.Name_User) >= 20) {
            printf("El usuario debe tener 20 caracteres o menos. Inténtelo de nuevo.\n");
        }

    }while(strlen(user1.Name_User) >= 20);

    do{
        printf("Introduzca el usuario que quiera utilizar (máximo 5 caracteres):\n");
        fflush(stdin);

        fgets(user1.User, sizeof(user1.User), stdin);

        system("cls");

        if (strlen(user1.User) > 6) {
            printf("El usuario debe tener 5 caracteres o menos. Inténtelo de nuevo.\n");
        }

    }while(strlen(user1.User) > 6);

    do{
        printf("Introduzca la contraseña que quiera utilizar (máximo 8 caracteres):\n");
        fflush(stdin);

        scanf("%s", user1.Password);

        system("cls");

        if (strlen(user1.Password) >= 9) {
            printf("La contraseña debe tener 8 caracteres o menos. Inténtelo de nuevo.\n");
        }

    }while(strlen(user1.Password) >= 9);

    fflush(stdin);

    char user_check[] = "user";     //esto para que la contrasenya no pueda ser igual
    char admin_check[] = "admi";    // y esto tambien
    char line[85];
    int i = 0;

    while (fgets(line, sizeof(line), fuser)) {
        if (strstr(line, user1.User) != NULL && user1.User != user_check && user1.User != admin_check){
            i = 1;
        }
    }

    if(i == 0){
        fseek(fuser, 0, SEEK_END);
        int num_newlines = 0;
        long int pos = ftell(fuser);
        char c;
        char str[5];

        while (pos > 0) { //este while para obtener la ultima id que hay
            pos--;
            fseek(fuser, pos, SEEK_SET);
            c = fgetc(fuser);

            if (c == '\n' || SEEK_SET) {
                num_newlines++;

                if (num_newlines == 4) {

                    fread(str, sizeof(char), 4, fuser);
                    str[5] = '\0';

                    break;
                }
            }
        }

        int id = atoi(str); //convirtiendo la id obtenida en un entero para sumarle 1
        id++;

        fflush(stdin);

        fseek(fuser, 0, SEEK_END);
        sprintf(str, "%04d", id);   //convirtiendo la id de vuelta en cadena mientras siempre teniendo 4 digitos (rellenada de 0 los que no utiliza)
        long long unsigned int j;

        for(j = 0; j <= strlen(user1.Name_User); j++){  //todo estos for para quitar cualquier \n que haya
            if(user1.Name_User[j] == '\n'){
                user1.Name_User[j] = '\0';
            }
        }

        for(j = 0; j <= strlen(user1.User); j++){
            if(user1.User[j] == '\n' || user1.User[j] == ' '){
                user1.User[j] = '\0';
            }
        }

        for(j = 0; j <= strlen(user1.Password); j++){
            if(user1.Password[j] == '\n'){
                user1.Password[j] = '\0';
            }
        }

        system("cls");

        printf("Su nombre completo es: %s\n", user1.Name_User);
        printf("Su nombre de usuario es: %s\n", user1.User);

        strcpy(fullstring, str);
        strcat(fullstring, "-");
        strcat(fullstring, user1.Name_User);
        strcat(fullstring, "-");
        strcat(fullstring, "user");
        strcat(fullstring, "-");
        strcat(fullstring, user1.User);
        strcat(fullstring, "-");
        strcat(fullstring, user1.Password);
        strcat(fullstring, "         \n");
        fprintf(fuser, "%s", fullstring);   //montando el conjunto de datos obtenidos para añadirlos al fichero

    }else{
        system("cls");
        printf("Usuario o nombre completo ya utilizado\n");
    }

    fclose(fuser);
}

void login(int lineas, estruct_viajes *viaj, estruct_vehiculos *vec, int l){

    FILE *fuser;
    fuser = fopen("user_database.txt", "r");
    if(fuser == NULL){
        printf("No es posible abrir: <user_database.txt>");
        exit(1);
    }

    char line[85];
    char usuario_imput[10];
    char contrasena_imput[9];
    char nombre_entero[21];
    int check = 0;
    char c;
    int num_guion = 0;
    char newline[20];

    do{

        puts("Introduzca su usuario:");
        scanf("%s", usuario_imput);

            system("cls");

            if(strlen(usuario_imput) > 5){
                puts("Escriba un nombre de usuario que sea menor o igual que 5 caracteres.");
            }

    }while(strlen(usuario_imput) > 5);

    fflush(stdin);

    while (fgets(line, sizeof(line), fuser) != NULL) {  //este while para buscar el usuario en la base de datos, si lo encuentra se pone a 1
        num_guion = 0;
        for(int i = strlen(line); i >= 0; i--){
            c = line[i];
            if(c == '-'){
                num_guion++;
                if(num_guion == 2){
                    strcpy(newline, &line[i+1]);
                    for(long long unsigned int z = 0; z <= strlen(newline); z++){
                        c = newline[z];
                        if(c == '-'){
                            newline[z] = '\0';
                            break;
                        }
                    }
                }
            }
        }

        if (strcmp(usuario_imput, newline) == 0) {
            check = 1;
            break;
        }


    }

    if(check == 0){
        system("cls");

        puts("Usuario no encontrado.");

    }else{

        do{
            puts("Introduzca su contraseña: ");
            scanf("%s", contrasena_imput);

            system("cls");
                if(strlen(contrasena_imput) > 8){
                    puts("Escriba una contraseña que sea menor o igual que 8 caracteres.");
                }

        }while(strlen(contrasena_imput) > 8);

        for(int j = 0; j < strlen(contrasena_imput); j++){
            c = contrasena_imput[j];
            if(c == '\n'){
                contrasena_imput[j] = '\0';
            }
        }

        for(int i = strlen(line); i >= 0; i--){     //aqui cogiendo solo la parte de la contraseña de la linea de datos
            newline[0] = '\0';
            c = line[i];
            if(c == '-'){
                strcpy(newline, &line[i+1]);
                break;
            }
        }

        for(int i = 0; i < strlen(newline); i++){
            c = newline[i];
            if(c == ' '){
                newline[i] = '\0';
            }
        }

        for(int j = 0; j < strlen(newline); j++){
            c = newline[j];
            if(c == '\n'){
                newline[j] = '\0';
            }
        }

        check = 0;

        if (strcmp(newline, contrasena_imput) == 0) {

            for(long long unsigned int i = 0; i <= strlen(line); i++){      //este  for para obtener el nombre entero de la linea
                c = line[i];
                if(c == '-'){
                    strcpy(nombre_entero, &line[i+1]);
                    for(long long unsigned int z = 0; z <= strlen(nombre_entero); z++){
                        c = nombre_entero[z];
                        if(c == '-'){
                            nombre_entero[z] = '\0';
                            check = 1;
                            break;
                        }
                    }
                }
                if(check == 1){
                    break;
                }
            }

            newline[0] = '\0';
            char check_user[] = "user";
            while (fgets(line, sizeof(line), fuser) != NULL) {      //este while para saber si es user o admin
                num_guion = 0;
                for(int i = strlen(line); i >= 0; i--){
                    c = line[i];
                    if(c == '-'){
                        num_guion++;
                        if(num_guion == 3){
                            strcpy(newline, &line[i+1]);
                            for(long long unsigned int z = 0; z <= strlen(newline); z++){
                                c = newline[z];
                                if(c == '-'){
                                    newline[z] = '\0';
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            if(strstr(check_user, newline) != NULL){

                system("cls");
                User_Menu_Opciones_Usu(nombre_entero, usuario_imput, lineas, viaj, vec, l);       //entra en esta funcion si es un usuario

            }else{

                Admin(usuario_imput, lineas, viaj, vec, l);    //entra aqui si es admin

            }

        }else{
            system("cls");
            puts("Contraseña incorrecta.");
        }
    }

    fclose(fuser);
}

void User_Menu_Opciones_Usu(char nombre_entero[], char usuario_imput[], int lineas, estruct_viajes *viaj, estruct_vehiculos *vec, int l){
    int elec, bucle=0;
    system("cls");
    printf("Bienvenid@ %s\n", nombre_entero);


    do{
        puts("¿Qué desea hacer?");
        printf("\n");
        puts("Pulse '1' para entrar en el menú de vehiculos");
        puts("Pulse '2' para entrar en el menú de viajes");
        puts("Pulse '3' para editar su contraseña");
        puts("Pulse '4' para salir");

        scanf("%d", &elec);

        while(elec<1||elec>4){
            system("cls");
            puts("Opción inválida.");
            puts("Pulse '1' para entrar en el menú de vehiculos");
            puts("Pulse '2' para entrar en el menú de viajes");
            puts("Pulse '3' para editar su contraseña");
            puts("Pulse '4' para salir");

            scanf("%d", &elec);
        }

        switch(elec){
            case 1: menu_vehiculos(vec, l);
            break;
            case 2: menu_viajes(lineas, viaj, vec, l);
            break;
            case 3: Editar_Contrasenya(usuario_imput);
            break;
            case 4: bucle++;
            break;
        }
    }while(bucle==0);

}

void Admin(char usuario_imput[], int lineas, estruct_viajes *viaj, estruct_vehiculos *vec, int l){

    system("cls");

    int elec, bucle=0;

    while(bucle==0){
        puts("Eres admin.");

        puts("Puedes entrar en la base de datos para eliminar cualquier usuario.");

        do{
            puts("Pulse '1' para editar su contraseña.");
            puts("Pulse '2' para editar/eliminar usuarios");
            puts("Pulse '3' para eliminar viajes");
            puts("Pulse '4' para eliminar vehiculos");


            scanf("%d", &elec);
            system("cls");
        }while(elec < 1 || elec > 4);

        switch(elec){
            case 1: system("cls");
                    Editar_Contrasenya(usuario_imput);
            break;

            case 2: system("notepad user_database.txt");
            break;

            case 3: eliminar_viaje(viaj,lineas);
            break;

            case 4: eliminar_vehiculo(vec,l);
            break;
        }

        char op;

        printf("¿Desea continuar sembrando el caos?\n(s/n): ");
        scanf(" %c", &op);

        if(op=='s'||op=='S'){
            system("cls");
        }else{
            bucle++;
        }
    }
}

void Editar_Contrasenya(char usuario_imput[]){  //NO ACEPTA CONTRASEÑA MÁS PEQUEÑA

    FILE *fuser;
    fuser = fopen("user_database.txt", "r+");

    char nuev_contr[10];
    char line[85];
    int num_guion;
    char newline[20];

    do{
        puts("Introduzca la nueva contraseña:");

        scanf("%s", nuev_contr);

        system("cls");

        if (strlen(nuev_contr) > 8) {
            printf("La contraseña debe tener 8 caracteres o menos. Inténtelo de nuevo.\n");
        }

    }while(strlen(nuev_contr) > 8);

    long int position;
    char c;
    int check = 0;
    int pos_check;

    while (fgets(line, sizeof(line), fuser) != NULL) {      //este while para obtener la linea de datos utilizando el usuario
        num_guion = 0;
        position = ftell(fuser);    //utilizo la variable posicion para obtener la posicion en el fichero de la contrasenya para reemplazarlo luego
        pos_check = 1;
        for(int i = strlen(line); i >= 0; i--){
            c = line[i];
            if(pos_check == 1){
                position--;
            }
            if(c == '-'){
                pos_check = 0;
                num_guion++;
                if(num_guion == 2){
                    strcpy(newline, &line[i+1]);
                    position++;
                    for(long long unsigned int z = 0; z <= strlen(newline); z++){
                        c = newline[z];
                        printf("%c", c);
                        if(c == '-'){
                            newline[z] = '\0';
                            break;
                        }
                    }
                }
            }
        }

        if (strstr(newline, usuario_imput) != NULL) {
            check = 1;
            break;
        }
    }

    if(check == 0){
        system("cls");

        puts("Error editando contraseña");

    }else{

        strcat(nuev_contr, "       ");
        fseek(fuser, position, SEEK_SET);

        fwrite(nuev_contr, sizeof(char), strlen(nuev_contr), fuser);

        system("cls");

        printf("Contrasenya cambiada a %s correctamente.\n", nuev_contr);

    }

    fclose(fuser);
}

int getUserId(const char *usuario){

    FILE *fuser;
    fuser = fopen("user_database.txt", "r");

    char line[85];
    char user_id[10];
    int user_num;
    char newline[20];
    int num_guion;
    char c;
    int check = 0;

    while (fgets(line, sizeof(line), fuser) != NULL) {
        num_guion = 0;
        for(int i = strlen(line); i >= 0; i--){
            c = line[i];
            if(c == '-'){
                num_guion++;
                if(num_guion == 2){
                    strcpy(newline, &line[i+1]);
                    for(long long unsigned int z = 0; z <= strlen(newline); z++){
                        c = newline[z];
                        if(c == '-'){
                            newline[z] = '\0';
                            break;
                        }
                    }
                }
            }
        }

        if (strstr(newline, usuario) != NULL) {
            check = 1;
            break;
        }
    }

    if(check == 0){
        int stuff = 235;
        return stuff;

    }else{

        strcpy(user_id, line);

        user_id[5] = '\0';
        user_num = atoi(user_id);

        return user_num;

    }

    fclose(fuser);
}
