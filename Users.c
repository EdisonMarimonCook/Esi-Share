#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include "Users.h"
#include "viajes_header.h"
#include "Vehiculos_header.h"

void User_Menu_Opciones_Usu();
void Editar_Perfil();
void Admin();
void sign_up();
void login();

void User_Menu(){

    FILE *fuser;
    fuser = fopen("user_database.txt", "a+");
    if(fuser == NULL){
        printf("No es possible abrir user_database.txt");
        exit(1);
    }

    system("cls");
    
    puts("Bienvenid@!");

    int num;   
    
    puts("Pulse 1 para hacer login o 2 para hacer Sign-up");
        
    scanf("%d", &num);

    fflush(stdin);
    system("cls");

    while(num < 1 || num > 2){

        puts("Pulse 1 para hacer login o 2 para hacer Sign-up");
        
        scanf("%d", &num);

        fflush(stdin);

        system("cls");

    }

    switch(num){

        case 1: login();
        break;

        case 2: sign_up();
        break;
    }

    fclose(fuser);

}

int main(){
    
    setlocale(LC_ALL, "spanish");
    User_Menu();

    return 0;    
}

void sign_up(){

    system("cls");

    FILE *fuser;
    fuser = fopen("user_database.txt", "a+");
    if(fuser == NULL){

        printf("No es possible abrir user_database.txt");
        exit(1);
    }

    user user1;
    char fullstring[85];

    do{
        printf("Introduzca su nombre completo (maximo 20 caracteres):\n");
        fflush(stdin);

        fgets(user1.Name_User, sizeof(user1.Name_User), stdin);

        system("cls");

        if (strlen(user1.Name_User) > 21) {
            printf("El usuario debe tener 20 caracteres o menos. Intentalo de nuevo.\n");
        }
        
    }while(strlen(user1.Name_User) > 21);

    do{
        printf("Introduzca el usuario que quieras utilizar (maximo 5 caracteres):\n");
        fflush(stdin);

        fgets(user1.User, sizeof(user1.User), stdin);

        system("cls");

        if (strlen(user1.User) > 6) {
            printf("El usuario debe tener 5 caracteres o menos. Intentalo de nuevo.\n");
        }
        
    }while(strlen(user1.User) > 6);

    do{
        printf("Introduzca la contraseña que quieras utilizar (maximo 8 caracteres):\n");
        fflush(stdin);

        fgets(user1.Password, sizeof(user1.Password), stdin);

        system("cls");

        if (strlen(user1.Password) > 9) {
            printf("La contraseña debe tener 8 caracteres o menos. Intentalo de nuevo.\n"); 
        }
        
    }while(strlen(user1.Password) > 9);

    fflush(stdin);
    
    char user_check[] = "user";
    char admin_check[] = "admin";
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

        while (pos > 0) {
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

        int id = atoi(str);
        id++;

        fflush(stdin);

        fseek(fuser, 0, SEEK_END);        
        sprintf(str, "%04d", id);
        long long unsigned int j;

        for(j = 0; j <= strlen(user1.Name_User); j++){
            if(user1.Name_User[j] == '\n'){
                user1.Name_User[j] = '\0';
            }
        }

        for(j = 0; j <= strlen(user1.User); j++){
            if(user1.User[j] == '\n' || user1.User[j] == ' '){
                user1.User[j] = '\0';
            }
        }   
        
        system("cls");

        printf("Tu nombre completo es: %s\n", user1.Name_User);
        printf("Tu nombre de usuario es: %s\n", user1.User);

        strcpy(fullstring, str);
        strcat(fullstring, "-");
        strcat(fullstring, user1.Name_User);
        strcat(fullstring, "-");
        strcat(fullstring, "user");
        strcat(fullstring, "-");
        strcat(fullstring, user1.User);
        strcat(fullstring, "-");
        strcat(fullstring, user1.Password);
        fprintf(fuser, "%s", fullstring);

        fseek(fuser, -1, SEEK_END);
        c = fgetc(fuser);

        if(c != '\n'){
            fseek(fuser, 0, SEEK_END);
            fprintf(fuser, "\n");
        }

    }else{
        system("cls");
        printf("Usuario o nombre completo ya utilizado\n");

        User_Menu();
    }

    fclose(fuser);
}


void login(){

    FILE *fuser;
    fuser = fopen("user_database.txt", "r");
    if(fuser == NULL){
        printf("No es possible abrir user_database.txt");
        exit(1);
    }

    char line[85];
    char usuario_imput[10];
    char contraseña_imput[9];
    char nombre_entero[21];
    int check = 0;
    char c;
    int num_guion = 0;
    char newline[20];

    do{
        system("cls");

        puts("Ponga su usuario:");
        scanf("%s", usuario_imput);

            if(strlen(usuario_imput) > 5){
                puts("Escriba un nombre de usuario que sea menos o igual que 5 caracteres.");
            }

    }while(strlen(usuario_imput) > 5);

    fflush(stdin);

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

        if (strstr(newline, usuario_imput) != NULL) {
            check = 1;
            break;
        }
    }
    
    if(check == 0){
        system("cls");

        puts("Usuario no encontrado.");
        User_Menu();

    }else{
        
        do{
            puts("Ponga su contraseña: ");
            scanf("%s", contraseña_imput);

            system("cls");
                if(strlen(contraseña_imput) > 8){
                    puts("Escriba una contraseña que sea menos o igual que 8 caracteres.");
                }

        }while(strlen(contraseña_imput) > 8);

        for(int i = strlen(line); i >= 0; i--){
            newline[0] = '\0';
            c = line[i];
            if(c == '-'){    
                strcpy(newline, &line[i+1]);
                break; 
            }
        }

        check = 0;

        if (strstr(newline, contraseña_imput) != NULL) {
            
            for(long long unsigned int i = 0; i <= strlen(line); i++){
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
            while (fgets(line, sizeof(line), fuser) != NULL) {
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
         
            if(newline == check_user){

                User_Menu_Opciones_Usu(nombre_entero);

            }else{

                Admin();

            }

        }else{
            system("cls");
            puts("Contraseña incorrecta.");
            login();
        }
    }

    fclose(fuser);
}

void User_Menu_Opciones_Usu(char nombre_entero[]){
    int elec;
    system("cls");
    printf("Bienvenid@ %s", nombre_entero);

    puts("Que quiere hacer?");
    printf("\n");
    puts("Pulse 1 para entrar en el menu de seleccion de vehiculos");
    puts("Pulse 2 para entrar en el menu de seleccion de viajes"); 
    puts("Pulse 3 para editar su perfil");

    scanf("%d", &elec);
    system("cls");
    switch(elec){
        case 1: menu_vehiculos();
        break;

        case 2: menu_viajes();
        break;

        case 3: Editar_Perfil();
        break;
    }

}

void Admin(){
    system("cls");

    puts("Eres admin");

}

void Editar_Perfil(){
    puts("Aqui para editar tu perfil");

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

}