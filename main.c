#include <stdio.h>
#include <string.h>
#include "Kids/RegisterKids.h"
#include "Elfs/RegisterElfs.h"
#include "Toys/RegisterToys.h"
//created by chaitanya

void function(char *myString)
{
    printf("myString = %s\n",myString);
    for (size_t i = 0; i < strlen(myString); i++) {
        // Access each char in the string
        printf("myString[%lu] = %c\n", i, myString[i]);
    }
}



int main()
{
//ListsKids();
//EditKid("SIHAN",2,"EL-MOLESTO");
//ListsKids();
//    ListsElfs();
//EditElf("13",2,"ELLAESA");
//RegisterElf();
//  ListsElfs();

//RegisterElf();
//RegisterElf();
//RegisterElf();

    tpunteroa raiz;
    int dato, esCompleto=1, aux;
    raiz = NULL;

    /*
        Insertamos valores creando el siguiente Arbol:

                       4
                      / \
                     1   6
                        / \
                       5   9
    */

    insertarArbol (&raiz, 4);
    insertarArbol (&raiz, 1);
    insertarArbol (&raiz, 6);
    insertarArbol (&raiz, 9);
    insertarArbol (&raiz, 5);

    //Imprimimos el Arbol en orden
    printf ("Arbol impreso: ");
    imprimirArbol (raiz);
}