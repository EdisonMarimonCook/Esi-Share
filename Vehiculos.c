#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#include "Vehiculos_header.h"

void crear_vehiculo();
void modificar_vehiculo();
void eliminar_vehiculo();

int comprobar_matricula();
void lista_vehiculos();

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
    if((f=fopen("Vehiculos.txt","r"))==NULL){
        //Error dado en el caso de no poder abrir el fichero:
        printf("\n\nERROR: No se ha podido abrir el fichero. Por favor inténtelo más tarde.");
        exit(1);
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
    if((f=fopen("Vehiculos.txt","r"))==NULL){
        //Error dado en el caso de no poder abrir el fichero:
    	printf("\n\nERROR: No se ha podido abrir el fichero. Por favor, inténtelo más tarde.");
    	exit(1);
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
    if((f=fopen("Vehiculos.txt","r"))==NULL){
        //Error dado en el caso de no poder abrir el fichero:
        printf("\n\nERROR: No se ha podido abrir el fichero. Por favor, inténtelo más tarde.");
    	exit(1);
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
void cargar_vehiculos(){

    //Declaración de datos:
    int lineas;
    estruct_vehiculos *vehiculos;

    //Contar longitud del fichero:
    lineas=contar();


    //Reservar memoria:
    reserva_memoria(&vehiculos, lineas);


    //Cargar datos a estructura:
    subir_a_fichero_vehiculos(vehiculos);
}


void menu_vehiculos(){
estruct_vehiculos *vehiculos;
int select,lineas;
char res;

lineas=contar();
reserva_memoria(&vehiculos,lineas);
subir_a_fichero_vehiculos(vehiculos);

do{
printf("##       ##  ######  ##   ##  ##   #####  ##   ##  ##       ####     ######\n");
printf(" ##     ##   ##      ##   ##  ##  ##      ##   ##  ##     ##    ##  ##\n");
printf("  ##   ##    ######  #######  ##  ##      ##   ##  ##     ##    ##   ######\n");
printf("   ## ##     ##      ##   ##  ##  ##      ##   ##  ##     ##    ##        ##\n");
printf("    ###      ######  ##   ##  ##   #####   #####   #####    ####     ######\n\n");

printf("|| ########################################### ||\n");
printf("|| Seleccione una de las siguientes opciones:  ||\n");
printf("||                                             ||\n");
printf("|| 1. Añadir un vehículo                       ||\n");
printf("|| 2. Modificar un vehículo ya existente       ||\n");
printf("|| 3. Eliminar un vehículo                     ||\n");
printf("|| 4. Salir del menú                           ||\n");
printf("|| ########################################### ||\n\n");
scanf("%d",&select);

while(select<1||select>4){
    printf("\n\n====================================================================\n");
    printf("ERROR: Por favor, seleccione una opción válida (números entre 1 y 4)\n");
    printf("====================================================================\n\n");
    scanf("%d",&select);
}
system("cls");

	switch(select){
    	case 1:
   	    	crear_vehiculo(vehiculos);
   	    	break;
  	    case 2:
   	    	modificar_vehiculo(vehiculos, lineas);
  			break;
 	    case 3:
   	    	eliminar_vehiculo(vehiculos, lineas);
   	    	break;
   	    case 4:
   	    	exit(1);

   	}

printf("\n¿Desea continuar en el menú de vehículos? (pulse s para continuar)\n");
scanf(" %c",&res);

system("cls");
}while(res=='s'||res=='S');
}

int main(){
    setlocale(LC_ALL, "spanish");
    cargar_vehiculos();
	menu_vehiculos();
    return(0);
}

// ##### FUNCIONES PRINCIPALES #####
void crear_vehiculo(estruct_vehiculos vehiculos){			//Función para crear nuevos vehículos
	FILE *vehiculos_file;
	int encontrada;
	char v_aux[N];
	
}

void eliminar_vehiculo(estruct_vehiculos *vehiculos, int lineas){			//Función para eliminar vehículos ya existentes
	FILE *vehiculos_file, *vehiculos_aux;
	char aux='0',v_aux[N],mat[8],mat_aux[8];
	int i=0,encontrado=0;
	
	vehiculos_file=fopen("Vehiculos.txt","r");			
	if(vehiculos_file == NULL){
		printf("\n\nERROR: No se ha podido abrir el fichero de texto. Por favor, inténtelo más tarde.");
		exit(1);
	}
	
	rewind(vehiculos_file);
	
	printf("Lista de vehículos: ");
	printf("\n\n");
	while(!feof(vehiculos_file)){
		fgets(v_aux,N,vehiculos_file);
		printf("%s",v_aux);
	}
		
	printf("\n\nIntroduzca la matrícula del vehículo a borrar: ");
	fflush(stdin);
	fgets(mat,8,stdin);
	
	do{
		if(strcmp(mat,vehiculos[i].Id_mat)==0){
			encontrado=1;
		}
		i++;
	}while(i<lineas&&encontrado==0);
	
	vehiculos_aux=fopen("Vehiculos_aux.txt","w+");
	if(vehiculos_aux == NULL){
		printf("\n\nERROR: No se ha podido abrir el fichero de texto. Por favor, inténtelo más tarde.");
		exit(1);
	}
	
	rewind(vehiculos_file);
	while(!feof(vehiculos_file)){
		leer(v_aux,vehiculos_file);
		strcpy(mat_aux,v_aux);
		if(strcmp(mat,mat_aux)!=0){
			fputs(v_aux,vehiculos_aux);
			fputc('-',vehiculos_aux);
			fgets(v_aux,N,vehiculos_file);
			fputs(v_aux,vehiculos_aux);
		}else{
			while(aux!='\n'&&aux!=EOF){
				aux=fgetc(vehiculos_file);
			}
		}
	}
	
if(aux==EOF){
	putc(aux,vehiculos_aux);
}

fclose(vehiculos_aux);
fclose(vehiculos_file);

system("rename Vehiculos.txt Delete.txt");
system("rename Vehiculos_aux.txt Vehiculos.txt");
system("del Delete.txt");
}

void modificar_vehiculo(){			//Función para modificar campos de vehículos ya existentes
}

// ##### FUNCIONES SECUNDARIAS #####

int comprobar_matricula(estruct_vehiculos vehiculos){			//Función para comprobar si la matrícula sigue el formato de 4 dígitos y 3 letras
	int cont;
	if(strlen(vehiculos.Id_mat)!=7){
        return 0;
	}
	for(cont=0;cont<4;cont++){
		if(vehiculos.Id_mat[cont]<48||vehiculos.Id_mat[cont]>57){			//Se comprueba que las 4 primeras posiciones de Id_mat sean caracteres numéricos mediante comparación por su código ASCII respectivo (48='0'...57='9')
			return 0;														//Usaremos el valor '0' como "incorrecta" y el valor '1' como "válida"
		}
	}

	for(cont=4;cont<7;cont++){
		if(vehiculos.Id_mat[cont]<65||vehiculos.Id_mat[cont]>90){			//Hacemos lo mismo que en el bucle anterior, solo que con los códigos de las letras mayúsculas (A hasta Z)
			return 0;														//De nuevo, la matrícula sería incorrecta
		}
	}

	return 1;			//Si al pasar por los dos bucles, la info es correcta, la matrícula es válida
}
