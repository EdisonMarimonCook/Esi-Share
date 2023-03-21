#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "viajes_header.h"

void subir_viaje(){
    estruct_viajes Id_m;
    printf("�Bienvenido al creador de viajes de ESI Share!\n\nIntroduzca la matr�cula del coche que vaya a utilizar: ");
    /*fflush(stdin);
    fgets(v.Id_mat, sizeof(char), stdin); PROBLEMA. No te pide escribir la cadena de caracteres*/
}

int power (int base, int exp){
    int i, res=1;
    for(i=exp;i>0;i--){
        res*=base;
    }
    return res;
}

void crear_vector(int n, int *vector){
    //Declaraci�n de datos:
    int i, j=0;
    //Crea el vector. Intoduce d�gito a d�gito el ID en cada celda:
    for(i=5;i>=0;i--){
        *(vector+j)=n/power(10,i);
        n=n%power(10,i);
        j++;
    }
}

void escribir_vector (int *vector){
    int i;
    for(i=0;i<6;i++){
        printf("%d", *(vector+i));
    }
}

int contar (int n){     //arreglar que no cuenta 000001 como 6 d�gitos
    int res=0;
    while(n>0){
        n/=10;
        res++;
    }
    return res;
}

void eliminar_viaje(FILE *viajes_file){
    //Declaraci�n de datos:
    char c, vector_aux[6], vector_aux_grande[100];
    int id, vector_id[6], vector_fichero[6], i, cont=0, lineas_total=0, lineas_aux, lineas_cont=1, encontrado=0;
    //Ense�a por pantalla todos los viajes guardados en el fichero:
    printf("�Qu� viaje desea eliminar?\n\n");
    do{
        c=fgetc(viajes_file);
        printf("%c", c);
    }while(c!=EOF);
    //Crea un vector con cada d�gito del ID en sus 6 celdas:
    printf("\nIntroduzca el ID del viaje a borrar: ");
    scanf("%d", &id);
    /*//Comprobaci�n de que el ID dado es v�lido en n�mero de d�gitos: ##################NO FUNCIONA BN, EJ:000001==1#################
    while(contar(id)!=6){
        printf("ID inv�lido, el ID debe de contener 6 d�gitos, por favor int�ntelo de nuevo: ");
        scanf("%d", &id);
    }*/
    crear_vector(id, vector_id);
    escribir_vector(vector_id);
    //#############################PROBLEMAS#########################################
    //Crear vector de fichero:
    printf("\n");
    for(i=0;i<5;i++){
        vector_fichero[i]=fgetc(viajes_file);
    }
    escribir_vector(vector_fichero);
    /*//Comparaci�n:
    do{
        i=0;
        while(i<6||cont==0){
            if(vector_fichero[i]!=vector_id[i]){
                cont++;
            }
            i++;
        }
        if(cont==0){
            printf("\nEL VIAJE EXISTE");
            encontrado=1;
        }else{
            lineas_aux=0;
            while(lineas_aux!=lineas_cont){
                while(c!='\n'){
                    c=fgetc(viajes_file);
                }
                lineas_aux++;
            }
            lineas_cont++;
            printf("\n");
            fgets(vector_aux,6,viajes_file);
            id=atoi(vector_aux);
            crear_vector(id, vector_fichero);
        }
    }while(lineas_cont!=lineas_total||encontrado==0);
    //Borrar:*/
}

void modificar_viaje(){
    printf("�Qu� viaje desea modificar?");
}

void menu_viajes(){
    //Declaraci�n de datos:
    int elect, cont_menu=0;
    FILE *viajes_file;
    char res;
    //Men� gr�fico:
    do{
        printf("##       ##   ##      ###       ########  ######   ######\n");
        printf(" ##     ##    ##     ## ##         ##     ##      ##\n");
        printf("  ##   ##     ##    ##   ##        ##     ######   ######\n");
        printf("   ## ##      ##   #########   ##  ##     ##            ##\n");
        printf("    ###       ##  ##       ##   ####      ######   ######\n");
        printf("\n #######################");
        printf("\n |�Qu� desea hacer?    |");
        printf("\n |                     |");
        printf("\n |1. A�adir un viaje   |\n |2. Eliminar un viaje |\n |3. Modificar un viaje|\n");
        printf(" #######################\n\n");
        scanf("%d", &elect);
        //Comprobaci�n de elecci�n de men� v�lida:
        while(elect<1||elect>3){
            printf("VALOR INV�LIDO: Introduzca '1', '2' o '3' para seleccionar la opci�n deseada\n");
            scanf("%d", &elect);
        }
        system ("cls"); //Sirve para limpiar la pantalla
        //Abro el fichero viajes_file.txt antes de elegir qu� hacer con �l para no tener que abrirlo en cada funci�n:
        viajes_file=fopen("viajes_file.txt", "a+");
        if(viajes_file!=NULL){
            switch (elect){
                case 1: subir_viaje();
                break;
                case 2: eliminar_viaje(viajes_file);
                break;
                case 3: modificar_viaje();
            }
        }else{
            //Error dado en el caso de no poder abrir el fichero:
            printf("######################################################################\n");
            printf("|Ha ocurrido un error a la hora de abrir el fichero <viajes_file.txt>|\n|    Por favor, int�ntelo m�s tarde o consulte con mantenimiento     |\n");
            printf("######################################################################\n\n");
        }
        fclose(viajes_file);
        //Continuaci�n del bucle??:
        printf("\n\n�Desea continuar modificando sus viajes?\n(s/n)\n");
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
}

int main(){
    setlocale(LC_ALL, "spanish");
    menu_viajes();
    return 0;
}
