// Driver program to test above functions

//
#include <stdio.h>
#include <string.h>
#include "Places/RegisterPlaces.h"
#include "Kids/RegisterKids.h"
#include "Elfs/RegisterElfs.h"
#include "Behavior/RegisterBehavior.h"
#include "Toys/RegisterToys.h"

void Menu(){
    int exit=0;
    tpunteroa raiz;
    raiz = NULL;
    rearmarArbol(&raiz);
    while (!exit){
        int opcion;
        printf("\n.Este es el Menu principal de NaviTEC,Tengo las siguientes opciones\n"
               "1.Registrar un niño\n"
               "2.Lista de los niños \n"
               "3.Registrar un Ayudante de Santa\n"
               "4.Lista de los Ayudante de Santa \n"
               "5.Registrar el comportamiento de un niño\n"
               "6.Listar los comportamientos de todos los niños\n"
               "7.Registrar un juguete\n"
               "8.Listar los jueguetes disponibles\n"
               "9.Salir del Programa\n");
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
            RegisterBehavior();
        }
        if(opcion==6){
            ListsBehavior();
        }
        if(opcion==7){
            registerToy(&raiz);
        }
        if(opcion==8){
            imprimirArbol(raiz);
        }
        if(opcion==9){
            exit=1;
            printf("Muchas gracias Regrese Luego");
        }

    }
}
int main()
{
//    Menu();
    ListsElfs();
//RegisterElf();
//RegisterElf();
    EditElf("40",2,"SIHAN");
    ListsElfs();
    return 0;
}