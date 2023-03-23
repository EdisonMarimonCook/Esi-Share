#ifndef VIAJES_h

    #define VIAJES_h
    typedef struct{
        int Id_viaje/*6 dígitos*/, Plazas_libre/*1 dígito*/, Importe, F_inic, H_inic, H_fin;
        char Id_mat[8], Estado[15];
    }estruct_viajes;

    void menu_viajes();

#endif
