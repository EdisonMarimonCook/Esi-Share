//CABECERA VEHÍCULOS "ESI-SHARE"
#ifndef VEHICULOS_H
#define VEHICULOS_H                         //Si "VEHICULOS_H" no está definido, definirlo
typedef struct                              //Se define la estructura "estruct_vehiculos"
{
    char Id_mat[8], Desc_veh[51];           //Se definen las cadenas para la matrícula y la descripción de cada vehículo
    int Id_usuario, Num_plazas;             //Se definen las variables del número identificador de usuario (4 dígitos) y número de plazas del vehículo (1 dígito)
} estruct_vehiculos;

void menu_vehiculos();						//Se define la función que contendrá el menú del módulo de "Vehículos"
void eliminar_vehiculo();
#endif
