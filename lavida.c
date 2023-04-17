#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include "PASOS.h"

int main(){
    void sel(int selectorc);
}

void sel(int selectorc){
    switch(selectorc){
        case 1:
            system("cls");
            cadiz();
            break;
        case 2:
            system("cls");
            puertoreal();
            break;
        case 3:
            system("cls");
            jerez();
            break;
        case 4:
            system("cls");
            chiclana();
            break;
        case 5:
            system("cls");
            sanlucar();
            break;
        case 6:
            system("cls");
            puerto();
            break;
        case 7:
            system("cls");
            sanfer();
            break;
        }
}

void mostrarviaje (id){
    int x;
    int n;
    int j;
    for (x=0, x<n, x+1){
        for (j=0, j<n, j+1){
            if (v_pasos[x].id_viaje[j]==id[j]){
                ciudad=selector_i;
                switch (ciudad){
                    case 1:
                        para=cadiz();
                        switch (para){
                            case 1:
                                if (strcmp (para,"-I-Cadiz PlazaEspaña")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 2:
                                if (strcmp (para,"-I-Cadiz Hospital")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 3:
                                if (strcmp (para,"-I-Cadiz Estadio")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 4:
                                if (strcmp (para,"-I-Cadiz PuertaTierra")==0)
                                    imprimir_p(id,parada);
                                break;
                        }
                        break;
                    case 2:
                        para=puertoreal();
                        switch (para){
                            case 1:
                                if (strcmp (para,"-I-Puerto Real Estaciontrenes")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 2:
                                if (strcmp (para,"-I-Puerto Real BK")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 3:
                                if (strcmp (para,"-I-Puerto Real LagunaMarroquia")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 4:
                                if (strcmp (para,"-I-Puerto Real Casem")==0)
                                    imprimir_p(id,parada);
                                break;
                        }
                    break;
                    case 3:
                        para=jerez();
                        switch (para){
                            case 1:
                                if (strcmp (para,"-I-Jerez Minotauro")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 2:
                                if (strcmp (para,"-I-Jerez Rotonda")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 3:
                                if (strcmp (para,"-I-Jerez EstacionTrenes")==0)
                                    imprimir_p(id,parada);
                                break;
                        }
                    break;
                    case 4:
                        para=chiclana();
                        switch (para){
                            case 1:
                                if (strcmp (para,"-I-Chiclana Marquesado")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 2:
                                if (strcmp (para,"-I-Chiclana Novo")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 3:
                                if (strcmp (para,"-I-Chiclana Franceses")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 4:
                                if (strcmp (para,"-I-Chiclana Gallos")==0)
                                    imprimir_p(id,parada);
                                break;
                        }
                    break;
                    case 5:
                        para=sanlucar();
                        switch (para){
                            case 1:
                                if (strcmp (para,"-I-SanLucar Palmar")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 2:
                                if (strcmp (para,"-I-SanLucar Centenario")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 3:
                                if (strcmp (para,"-I-SanLucar Rotonda")==0)
                                    imprimir_p(id,parada);
                                break;
                        }
                    break;
                    case 6:
                        para=puerto();
                        switch (para){
                            case 1:
                                if (strcmp (para,"-I-Puerto Estaciontrenes")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 2:
                                if (strcmp (para,"-I-Puerto Valdelagrana")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 3:
                                if (strcmp (para,"-I-Puerto Sudamerica")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 4:
                                if (strcmp (para,"-I-Puerto PlazaToros")==0)
                                    imprimir_p(id,parada);
                                break;
                        }
                    break;
                    case 7:
                        para=sanfer();
                        switch (para){
                            case 1:
                                if (strcmp (para,"-I-Sanfer ParqueHuerta")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 2:
                                if (strcmp (para,"-I-Sanfer Ardila")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 3:
                                if (strcmp (para,"-I-Sanfer HornosPunicos")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 4:
                                if (strcmp (para,"-I-Sanfer BahiaSur")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 5:
                                if (strcmp (para,"-I-Sanfer Plaza")==0)
                                    imprimir_p(id,parada);
                                break;
                        }
                    break;
                }

        }
            if (v_pasos[x].id_viaje[j]==id[j]){
                ciudad=selector_i;
                switch (ciudad){
                    case 1:
                        para=cadiz();
                        switch (para){
                            case 1:
                                if (strcmp (para,"-V-Cadiz PlazaEspaña")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 2:
                                if (strcmp (para,"-V-Cadiz Hospital")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 3:
                                if (strcmp (para,"-V-Cadiz Estadio")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 4:
                                if (strcmp (para,"-V-Cadiz PuertaTierra")==0)
                                    imprimir_p(id,parada);
                                break;
                        }
                        break;
                    case 2:
                        para=puertoreal();
                        switch (para){
                            case 1:
                                if (strcmp (para,"-V-Puerto Real Estaciontrenes")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 2:
                                if (strcmp (para,"-V-Puerto Real BK")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 3:
                                if (strcmp (para,"-V-Puerto Real LagunaMarroquia")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 4:
                                if (strcmp (para,"-V-Puerto Real Casem")==0)
                                    imprimir_p(id,parada);
                                break;
                        }
                    break;
                    case 3:
                        para=jerez();
                        switch (para){
                            case 1:
                                if (strcmp (para,"-V-Jerez Minotauro")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 2:
                                if (strcmp (para,"-V-Jerez Rotonda")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 3:
                                if (strcmp (para,"-V-Jerez EstacionTrenes")==0)
                                    imprimir_p(id,parada);
                                break;
                        }
                    break;
                    case 4:
                        para=chiclana();
                        switch (para){
                            case 1:
                                if (strcmp (para,"-V-Chiclana Marquesado")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 2:
                                if (strcmp (para,"-V-Chiclana Novo")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 3:
                                if (strcmp (para,"-V-Chiclana Franceses")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 4:
                                if (strcmp (para,"-V-Chiclana Gallos")==0)
                                    imprimir_p(id,parada);
                                break;
                        }
                    break;
                    case 5:
                        para=sanlucar();
                        switch (para){
                            case 1:
                                if (strcmp (para,"-V-SanLucar Palmar")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 2:
                                if (strcmp (para,"-V-SanLucar Centenario")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 3:
                                if (strcmp (para,"-V-SanLucar Rotonda")==0)
                                    imprimir_p(id,parada);
                                break;
                        }
                    break;
                    case 6:
                        para=puerto();
                        switch (para){
                            case 1:
                                if (strcmp (para,"-V-Puerto Estaciontrenes")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 2:
                                if (strcmp (para,"-V-Puerto Valdelagrana")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 3:
                                if (strcmp (para,"-V-Puerto Sudamerica")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 4:
                                if (strcmp (para,"-V-Puerto PlazaToros")==0)
                                    imprimir_p(id,parada);
                                break;
                        }
                    break;
                    case 7:
                        para=sanfer();
                        switch (para){
                            case 1:
                                if (strcmp (para,"-V-Sanfer ParqueHuerta")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 2:
                                if (strcmp (para,"-V-Sanfer Ardila")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 3:
                                if (strcmp (para,"-V-Sanfer HornosPunicos")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 4:
                                if (strcmp (para,"-V-Sanfer BahiaSur")==0)
                                    imprimir_p(id,parada);
                                break;
                            case 5:
                                if (strcmp (para,"-V-Sanfer Plaza")==0)
                                    imprimir_p(id,parada);
                                break;
                        }
                    break;
                }

        }
    }
}
}

strcat(estruct_pasos.v_parada)

void imprimir_p(id,parada){
    printf ("Numero de viaje %d, con parada en %s", id, parada)
}


