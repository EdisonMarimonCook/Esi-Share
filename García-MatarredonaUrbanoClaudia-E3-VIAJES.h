#ifndef VIAJES_h
    #define VIAJES_h
    typedef struct{
        int Id_viaje/*6 dígitos*/, Plazas_libre/*1 dígito*/, Importe, Estado/*1=Abierto, 2=Cerrado, 3=Iniciado, 4=Finalizado, 5=Anulado*/;
        char Id_mat[8], F_inic[11], H_inic[6], H_fin[6];
    }estruct_viajes;

    void menu_viajes();

#endif
