#ifndef USERS_H
#define USERS_H


typedef struct {

    int Id_Users[5];
    char Name_User[21];
    char Place[21];
    char User_Profile[14];
    char User[10];
    char Password[9];

}user;

void User_Menu();
void Admin();
void Vehiculos();
void Viajes();


#endif 