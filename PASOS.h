#ifndef PASOS_H
    #define PASOS_H
    typedef struct {
    int Id_viaje;         // numero identificatorio para el viaje
    char Poblacion[21];   // localizacion por donde va a pasar el conductor
    }estruct_pasos;

    void salida();
    void llegada();
    void recorrido();
    void reset_id();

#endif // PASOS_H
