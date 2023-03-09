#ifndef Usersh
#define Usersh

int Users(text txt)

typedef struct{

    int Id_Users[5];
    char Name_User[21];
    char Place[21];
    bool User_Profile;
    char User[6];
    char Password[9];

}Users;

void User(char id);
void Admin(char id);
void Vehiculos(char id);
void Viajes(char id);


#endif 