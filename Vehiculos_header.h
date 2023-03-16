//CABECERA VEH�CULOS "ESI-SHARE"
#ifndef VEHICULOS_H
#define VEHICULOS_H                         //Si "VEHICULOS_H" no est� definido, definirlo
typedef struct                              //Se define la estructura "estruct_vehiculos"
{
    char Id_mat[8], Desc_veh[51];           //Se definen las cadenas para la matr�cula y la descripci�n de cada veh�culo
    int Id_usuario, Num_plazas;             //Se definen las variables del n�mero identificador de usuario (4 d�gitos) y n�mero de plazas del veh�culo (1 d�gito)
} estruct_vehiculos;

void menu_vehiculos();
#endif

