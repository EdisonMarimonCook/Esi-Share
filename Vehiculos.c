#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#include "Vehiculos_header.h"

void menu_vehiculos(estruct_vehiculos *vec, int lineas){
int select;
char res;

system("cls");

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
   	    	crear_vehiculo(vec, lineas);
   	    	break;
  	    case 2:
   	    	modificar_vehiculo(vec, lineas);
  			break;
 	    case 3:
   	    	eliminar_vehiculo(vec, lineas);
   	    	break;
   	    case 4:
   	    	exit(1);

   	}

printf("\n¿Desea continuar en el menú de vehículos? (pulse 's' o 'S' para continuar)\n");
scanf(" %c",&res);

system("cls");
}while(res=='s'||res=='S');
}

// ##### FUNCIONES PRINCIPALES #####
void crear_vehiculo(estruct_vehiculos *vec, int lineas){			//FunciÃ³n para crear nuevos vehÃ­culos
	FILE *vehiculos_file;
	int encontrado=0,i=-1,plazas;
	char mat[8],desc[51];

	vehiculos_file=fopen("Vehiculos_file.txt","a+");
	if(vehiculos_file == NULL){
		printf("\n\nERROR: No se ha podido abrir el fichero. Por favor, inténtelo de nuevo.");
		exit(1);
	}

	do{
		printf("Introduzca una matrícula válida: ");
		fflush(stdin);
		fgets(mat,8,stdin);

		if(comprobar_matricula(mat)==0){
			printf("\n\nERROR: Por favor, introduzca una matrícula válida: ");
			system("pause");
			system("cls");
		}else{
			do{
				if(strcmp(mat,vec[++i].Id_mat)==0){
					encontrado=1;
				}
			}while(i<lineas&&encontrado==0);

		if(encontrado==1){
			printf("\n\nERROR: La matrícula introducida ya está siendo utilizada. Por favor, introduzca una matrícula válida");
			system("pause");
			system("cls");
		}
		}
	}while(encontrado==1||comprobar_matricula(mat)==0);

	//ID_USUARIO

	do{
		printf("Introduzca un número de plazas (entre 1 y 8): ");
		scanf("%d-",&plazas);

		if(plazas<1||plazas>8){
			printf("\n\nERROR: El número de plazas no es válido. Por favor, introduzca un número de plazas de nuevo");
			system("pause");
			system("cls");
		}
	}while(plazas<1||plazas>8);


	do{
		printf("Introduzca una descripción válida (50 caracteres máximo): ");
		fflush(stdin);
		fgets(desc,51,stdin);

		if(desc == '\0' || strlen(desc)>50){
			printf("\n\nERROR: La descripción no es válida. Por favor, introduzca una descripción de, como mucho, 50 caracteres");
			system("pause");
			system("cls");
		}
	}while(desc == '\0' || strlen(desc)>50);

	fprintf(vehiculos_file,"\n%s",mat);
	fputc('-',vehiculos_file);
	fprintf(vehiculos_file,"%d-",plazas);
	fputs(desc, vehiculos_file);

	fclose(vehiculos_file);
}

void eliminar_vehiculo(estruct_vehiculos *vec, int lineas){			//FunciÃ³n para eliminar vehÃ­culos ya existentes
	FILE *vehiculos_file, *vehiculos_aux;
	char aux='0',v_aux[N],mat[8],mat_aux[8];
	int i=-1,encontrado=0;

	vehiculos_file=fopen("Vehiculos_file.txt","r");
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

	printf("\n\nIntroduzca la matrícula del vehículo a eliminar: ");
	fflush(stdin);
	fgets(mat,8,stdin);

	do{
		if(strcmp(mat,vec[++i].Id_mat)==0){
			encontrado=1;
		}
	}while(i<lineas&&encontrado==0);

	vehiculos_aux=fopen("Vehiculos_aux.txt","w+");
	if(vehiculos_aux == NULL){
		printf("\n\nERROR: No se ha podido abrir el fichero de texto. Por favor, intÃ©ntelo mÃ¡s tarde.");
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

system("rename Vehiculos_file.txt Delete.txt");
system("rename Vehiculos_aux.txt Vehiculos_file.txt");
system("del Delete.txt");
printf("La matrícula ha sido eliminada correctamente.\n\n");
}

void modificar_vehiculo(estruct_vehiculos *vec, int lineas){			//FunciÃ³n para modificar campos de vehÃ­culos ya existentes
	FILE *vehiculos_file;
	char v[N], res_mod, mat[8];
	int encontrado=0, i=-1, select, pos;

	vehiculos_file=fopen("Vehiculos_file.txt","r");			//Abrimos el fichero "Vehiculos.txt"
	if(vehiculos_file == NULL){
		printf("\n\nERROR: No se ha podido abrir el fichero de texto. Por favor, inténtelo más tarde.");
		exit(1);
	}

	rewind(vehiculos_file);			//Vuelve al principio del fichero de texto

	printf("Lista de vehículos: ");
	printf("\n\n");
	while(!feof(vehiculos_file)){
		fgets(v,N,vehiculos_file);
		printf("%s",v);
	}

	printf("\n\nIntroduzca la matrícula del vehículo a editar: ");
	fflush(stdin);
	fgets(mat,8,stdin);

	do{
		if(strcmp(mat,vec[++i].Id_mat)==0){
			pos=i;
			encontrado=1;
		}
	}while(i<lineas&&encontrado==0);

	if(encontrado==0){
		while(encontrado==0){
			rewind(vehiculos_file);
			printf("\n\nERROR: Por favor, introduzca una matrícula válida: ");
			fgets(mat,8,stdin);


			i=-1;
			do{
				if(strcmp(mat,vec[++i].Id_mat)==0){
					encontrado=1;
					pos=i;
				}
			}while(i<lineas&&encontrado==0);
		}
	}

	fclose(vehiculos_file);

	system("pause");

	system("cls");

	do{
		printf("|| ########################################### ||\n");
		printf("|| Seleccione una de las siguientes opciones:  ||\n");
		printf("||                                             ||\n");
		printf("|| 1. Editar matrícula del vehículo            ||\n");
		printf("|| 2. Editar número de plazas del vehículo     ||\n");
		printf("|| 3. Editar descripción del vehículo          ||\n");
		printf("|| ########################################### ||\n\n");
		scanf("%d",&select);

		while(select<1||select>3){
    		printf("\n\n====================================================================\n");
   			printf("ERROR: Por favor, seleccione una opción válida (números entre 1 y 3)\n");
    		printf("====================================================================\n\n");
    		scanf("%d",&select);
    	}

    	system("cls");
    	switch(select){
    		case 1:
    			editar_matricula(vec,pos,lineas);
    			break;
    		case 2:
    			editar_plazas(vec,pos,lineas);
    			break;
    		case 3:
    			editar_desc(vec,pos,lineas);
		}

    guardar(vec,lineas);

    printf("Desea continuar en el menú de edición de vehículos? (Pulse 's' o 'S' para continuar)");
    scanf(" %c",&res_mod);
    system("cls");
	}while(res_mod=='s' || res_mod=='S');
}

// ##### FUNCIONES SECUNDARIAS #####

int comprobar_matricula(char matricula[8]){			//Función para comprobar si la matrícula sigue el formato de 4 dÃíitos y 3 letras
	int cont;
	if(strlen(matricula)!=7){
        return 0;
	}
	for(cont=0;cont<4;cont++){
		if(matricula[cont]<48||matricula[cont]>57){			//Se comprueba que las 4 primeras posiciones de Id_mat sean caracteres numÃ©ricos mediante comparaciÃ³n por su cÃ³digo ASCII respectivo (48='0'...57='9')
			return 0;														//Usaremos el valor '0' como "incorrecta" y el valor '1' como "vÃ¡lida"
		}
	}

	for(cont=4;cont<7;cont++){
		if(matricula[cont]<65||matricula[cont]>90){			//Hacemos lo mismo que en el bucle anterior, solo que con los cÃ³digos de las letras mayÃºsculas (A hasta Z)
			return 0;														//De nuevo, la matrÃ­cula serÃ­a incorrecta
		}
	}

	return 1;			//Si al pasar por los dos bucles, la info es correcta, la matrÃ­cula es vÃ¡lida
}

void guardar(estruct_vehiculos *vehiculos, int lineas){
	int cont;

	FILE *vehiculos_file;
    vehiculos_file=fopen("Vehiculos_file.txt","w+");
    if(vehiculos_file == NULL){
    	printf("\n\nERROR: No se ha podido abrir el fichero. Por favor, inténtelo más tarde.");
    	exit(1);
	}

	cont=0;
	while(cont<(lineas-1)){
		fputs(vehiculos[cont].Id_mat,vehiculos_file);
		fputc('-',vehiculos_file);

		fprintf(vehiculos_file,"%d-",vehiculos[cont].Num_plazas);

		fputs(vehiculos[cont].Desc_veh,vehiculos_file);
		fputc('\n',vehiculos_file);
		cont++;
	}

    fputs(vehiculos[cont].Id_mat,vehiculos_file);
	fputc('-',vehiculos_file);

	fprintf(vehiculos_file,"%d-",vehiculos[cont].Num_plazas);

	fputs(vehiculos[cont].Desc_veh,vehiculos_file);

    fclose(vehiculos_file);
}

void editar_matricula(estruct_vehiculos *vehiculos, int pos, int lineas){
	char nmat[8];
	int i=-1, encontrado;

	do{
		encontrado=0;
		printf("Introduzca la matrícula nueva: ");
		fflush(stdin);
		fgets(nmat,8,stdin);

		if(comprobar_matricula(nmat)==0){
			printf("\n\nERROR: Por favor, introduzca una matrícula válida: ");
			system("pause");
			system("cls");
		}else{

		do{
			if(strcmp(nmat,vehiculos[++i].Id_mat)==0){
			encontrado=1;
			}
		}while(encontrado==0&&i<lineas);

		if(encontrado==1){
			printf("\n\nERROR: La matrícula introducida ya está siendo utilizada. Por favor, introduzca una matrícula válida: ");
			system("pause");
			system("cls");
		}
		}
	}while(encontrado==1||comprobar_matricula(nmat)==0);

	strcpy(vehiculos[pos].Id_mat,nmat);
	printf("\n\nLa matrícula ha sido modificada.\n\n");
}

void editar_plazas(estruct_vehiculos *vehiculos, int pos, int lineas){
	int nplazas, encontrado,i;

	printf("Introduzca un nuevo número de plazas (Entre 0 y 8)");
	scanf("%d",&nplazas);


}

void editar_desc(estruct_vehiculos *vehiculos, int pos, int lineas){
}
