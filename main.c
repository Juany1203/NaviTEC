// Driver program to test above functions

//
#include <stdio.h>
#include <string.h>
#include "Places/RegisterPlaces.h"
#include "Kids/RegisterKids.h"
#include "Elfs/RegisterElfs.h"
#include "Behavior/RegisterBehavior.h"
#include "Toys/RegisterToys.h"
// #include "Letters/RegisterLetters.h"

void Menu()
{
    int exit = 0;
    tpunteroa raiz;
    raiz = NULL;
    rearmarArbol(&raiz);
    while (!exit)
    {
        int opcion;
        printf("\n.Este es el Menu principal de NaviTEC,Tengo las siguientes opciones\n"
               "1.Registrar un niño\n"
               "2.Lista de los niños \n"
               "3.Editar la informacion de los niños \n"
               "4.Eliminar a un  niño del sistema \n"
               "5.Registrar un Ayudante de Santa\n"
               "6.Lista de los Ayudante de Santa \n"
               "7.Editar a un  Ayudante de Santa \n"
               "8.Eliminar a un  Ayudante de Santa del sistema \n"
               "9.Registrar el comportamiento de un niño\n"
               "10.Listar los comportamientos de todos los niños\n"
               "11.Registrar un juguete\n"
               "12.Listar los jueguetes disponibles\n"
               "13.Salir del Programa\n");
        printf(".Ingrese el numero de la opcion que desea:\n");
        scanf("%d", &opcion);
        if (opcion == 1)
        {
            RegisterKid();
        }
        if (opcion == 2)
        {
            ListsKids();
        }
        if (opcion == 3)
        {
            changeKid();
        }
        if (opcion == 4)
        {
            eraseKid();
        }
        if (opcion == 5)
        {
            RegisterElf();
        }
        if (opcion == 6)
        {
            changeElf();
        }
        if (opcion == 7)
        {
            eraseElf();
        }
        if (opcion == 8)
        {
            ListsElfs();
        }
        if (opcion == 9)
        {
            RegisterBehavior();
        }
        if (opcion == 10)
        {
            ListsBehavior();
        }
        if (opcion == 11)
        {
            registerToy(&raiz);
        }
        if (opcion == 12)
        {
            imprimirArbol(raiz);
        }
        if (opcion == 13)
        {
            exit = 1;
            printf("Muchas gracias Regrese Luego");
        }
    }
}
int main()
{
    Menu();
    return 0;
}