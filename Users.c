#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "users.h"

//void login();
void sign_up();

void User_Menu(){

    FILE *fuser;
    fuser = fopen("user_database.txt", "a+");
    if(fuser == NULL){
        printf("No es possible abrir user_database.txt");
        exit(1);
    }
    
    puts("Bienvenid@!");

    int num;   

    do{

        puts("Ponga 1 para hacer login o 2 para hacer Sign-up?");
        
        scanf("%d", &num);

    }while(num != 1 && num != 2);

    switch(num){

       //case 1: login();
       //break;

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

    FILE *fuser;
    fuser = fopen("user_database.txt", "a+");
    if(fuser == NULL){

        printf("No es possible abrir user_database.txt");
        exit(1);
    }

    user user1;

    do{
        printf("Introduzca el usuario que quieras utilizar (maximo 5 caracteres):\n");
        fflush(stdin);

        fgets(user1.User, sizeof(user1.User), stdin);

        if (strlen(user1.User) > 6) {
            printf("El usuario debe tener 5 caracteres o menos. Intentalo de nuevo.\n");
        }
        
    }while(strlen(user1.User) > 6);

    fflush(stdin);
    
    char line[100];
    int i = 0;

    while (fgets(line, sizeof(line), fuser)) {
        if (strstr(line, user1.User) != NULL) {
            i = 1;
        }
    }

    if(i == 0){
        fseek(fuser, 0, SEEK_END);
        fputs(user1.User, fuser);
        printf("Tu usuario es: %s\n", user1.User);
    }else{
        printf("Usuario ya utilizado\n");
    }

    fseek(fuser, 0, SEEK_END);
    int num_newlines = 0;
    long int pos = ftell(fuser);  
    char c;
    char str[5];

    while (pos > 0) {
        pos--;
        fseek(fuser, pos, SEEK_SET);
        c = fgetc(fuser);

        if (c == '\n') {
            num_newlines++;

            if (num_newlines == 5) {

                
                fread(str, sizeof(char), 4, fuser);
                str[5] = '\0';

                break;
            }
        }
    }

    int id = atoi(str);
    id++;

    sprintf(str, "%04d", id);
    strcat(str, "-");
    fseek(fuser, 0, SEEK_END);
    num_newlines = 0;
    pos = ftell(fuser);

    while (pos > 0) {
        pos--;
        fseek(fuser, pos, SEEK_SET);
        c = fgetc(fuser);
        printf("%c", c);

        if (c == '\n') {
            num_newlines++;

            if (num_newlines == 3) {
                fprintf(fuser, "%s", str);
                break;
            }
        }
    }

    fclose(fuser);

}


/*void login(){

    char *line;

    puts("Ponga su usuario:");
    char usuario_imput[6];
    scanf("%s", usuario_imput);

    FILE *fuser;
    fuser = fopen("user_database.txt", "r");
    if(fuser == NULL){
        printf("No es possible abrir user_database.txt");
        exit(1);
    }

    while (fgets(line, ***, fuser) != NULL) {
        if (strstr(line, usuario_imput) != NULL) {
            printf("%s", line);
        }
        else{
            puts("Usuario no encontrado.");
        }
    }


    fclose(fuser);
}*/


