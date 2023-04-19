#ifndef PASOS_H
#define PASOS_H

    typedef struct{
        char parada [200];
    }r_parada;

    typedef struct {
    int Id_viaje;           // numero identificatorio para el viaje
    r_parada v_parada[6];   // localizacion por donde va a pasar el conductor
    }estruct_pasos;

void menu_pasos();
int selector_camino();

#endif // PASOS_H
