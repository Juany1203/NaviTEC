// Driver program to test above functions

//
#include <stdio.h>
#include <string.h>
#include "Places/RegisterPlaces.h"
#include "Kids/RegisterKids.h"
#include "Elfs/RegisterElfs.h"
#include "Behavior/RegisterBehavior.h"
#include "Toys/RegisterToys.h"
#include "Letters/RegisterLetters.h"

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
               "3.Editar la informacion de los niños \n"
               "4.Registrar un Ayudante de Santa\n"
               "5.Lista de los Ayudante de Santa \n"
               "6.Editar a un  Ayudante de Santa \n"
               "7.Registrar el comportamiento de un niño\n"
               "8.Listar los comportamientos de todos los niños\n"
               "9.Registrar un juguete\n"
               "10.Listar los jueguetes disponibles\n"
               "11.Salir del Programa\n");
        printf(".Ingrese el numero de la opcion que desea:\n");
        scanf("%d",&opcion);
        if(opcion==1){
            RegisterKid();
        }
        if(opcion==2){
            ListsKids();
        }
        if(opcion==3){
            changeKid();
        }
        if(opcion==4){
            RegisterElf();
        }
        if(opcion==5){
            changeElf();
        }
        if(opcion==6){
            ListsElfs();
        }
        if(opcion==7){
            RegisterBehavior();
        }
        if(opcion==8){
            ListsBehavior();
        }
        if(opcion==9){
            registerToy(&raiz);
        }
        if(opcion==10){
            imprimirArbol(raiz);
        }
        if(opcion==11){
            exit=1;
            printf("Muchas gracias Regrese Luego");
        }

    }
}
int main()
{
//    tpunteroa raiz;
//    raiz = NULL;
//    rearmarArbol(&raiz);
//    RegisterLetter(raiz);
ListsLetter();

//    Menu();
//    ListsElfs();
//RegisterElf();
//ListsKids();
//changeKid();
//RegisterElf();
//changeElf();
//    EditElf("40",2,"SIHAN");
//    ListsElfs();
    return 0;
}