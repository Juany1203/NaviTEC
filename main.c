// Driver program to test above functions

//
#include <stdio.h>
#include "Places/RegisterPlaces.h"
#include "Kids/RegisterKids.h"
#include "Elfs/RegisterElfs.h"

void Menu(){
    int exit=0;
    while (!exit){
        int opcion;
        printf(".Este es el Menu principal de NaviTEC,Tengo las siguientes opciones\n"
               "1.Registrar un niño\n"
               "2.Lista de los niños \n"
               "3.Registrar un Ayudante de Santa\n"
               "4.Lista de los Ayudante de Santa \n"
//               "3.Registrar un Juguete\n"
//               "4.Registrar un Lugar\n"
               "5.Registrar una Carta para Santa\n"
               "6.Salir del Programa\n");
        printf(".Ingrese el numero de la opcion que desea:\n");
        scanf("%d",&opcion);
        if(opcion==1){
            RegisterKid();
        }
        if(opcion==2){
            ListsKids();
        }
        if(opcion==3){
            RegisterElf();
        }
        if(opcion==4){
            ListsElfs();
        }
        if(opcion==5){
            exit=1;
            printf("Muchas gracias Regrese Luego");
        }
        if(opcion==6){
            exit=1;
            printf("Muchas gracias Regrese Luego");
        }

    }
}
int main()
{
    Menu();

    return 0;
}