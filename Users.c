#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "users.h"

//void login();
void sign_up();

int main(){
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
    return 0;
    
};

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
    
    if (fputs(user1.User, fuser) == EOF) {

            printf("Error writing to file.\n");
    }

    fflush(stdin);

    printf("Tu usuario es %s\n", user1.User);

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


