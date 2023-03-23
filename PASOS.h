#ifndef PASOS_H
#define PASOS_H
    typedef struct {
    int Id_viaje;         // numero identificatorio para el viaje
    char Poblacion[21];   // localizacion por donde va a pasar el conductor
    }estruct_pasos;

void ida_recorrido();
void vuelta_recorrido();
void selector_camino();

#endif // PASOS_H
