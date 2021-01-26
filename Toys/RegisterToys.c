//
// Created by reds on 26/1/21.
//

#include "RegisterToys.h"

#include <string.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>
#include <stdio.h>

void registerToy(){
    int codigo;
    char name[20];
    char description[40];
    char category[20];
    char age[20];
    int  cost;
    // Input the Word
    printf("\nBienvenido al registro de Juguetes\nPor favor ingrese los datos que se le solicitan a continuacion\n");

    printf("1.Ingrese el codigo del  juguete (este tiene que ser un numero):\n");
    scanf("%d",codigo);

    printf("2.Ingrese el Nombre  del juguete\n");
    scanf("%s",&name);

    printf("3.Ingrese una descripcion  del juguete:\n");
    scanf("%s",&description);

    printf("4.Ingrese la categoria  del jueguete:\n");
    scanf("%s",&category);

    printf("5.Ingrese el rango de edad del juguete:\n");
    scanf("%s",&age);

    printf("6.Ingrese el coste para la fabricacion del juguete :\n");
    scanf("%d",cost);





//    saveElfFile(elf1);



}


//ARBOL-INSERTAR//
void insertarArbol (tpunteroa *raiz, int dato){
    if (*raiz == NULL){
        *raiz = malloc(sizeof(tnodoa));
        (*raiz)->valor = dato;
        (*raiz)->izq = NULL;
        (*raiz)->der = NULL;
    }else{
        if (dato <= (*raiz)->valor){
            insertarArbol (&(*raiz)->izq, dato);
        }else{
            insertarArbol (&(*raiz)->der, dato);
        }
    }
}



//ARBOL-IMPRIMIR//
void imprimirArbol (tpunteroa raiz){
    if (raiz != NULL){
        imprimirArbol (raiz->izq);
        printf("%d, ", raiz->valor);
        imprimirArbol (raiz->der);
    }
}



//ARBOL-BORRAR//
void borrarArbol (tpunteroa *raiz){
    if (*raiz != NULL){
        borrarArbol (&(*raiz)->izq);
        borrarArbol (&(*raiz)->der);
        free (*raiz);
        *raiz = NULL;
    }
}



//ARBOL-BUSCAR//
tpunteroa buscar (tpunteroa raiz, int dato){
    if (raiz == NULL){
        return NULL;
    }else{
        if (dato == raiz->valor){
            return raiz;
        }else{
            if (dato < raiz->valor){
                return buscar (raiz->izq, dato);
            }else{
                return buscar (raiz->der, dato);
            }
        }
    }
}



//ARBOL-COMPLETO//
//Dato en 0: No es - Dato en 1: Si, es
void arbolCompleto (tpunteroa *raiz, int *dato){
    if ((*raiz)->izq != NULL)
        arbolCompleto (&(*raiz)->izq, dato);
    if ((*raiz)->der != NULL)
        arbolCompleto (&(*raiz)->der, dato);
    if ((*dato) == 0)
        return;
    if ((*raiz)->der == NULL && (*raiz)->izq != NULL)
        *dato = 0;
    if ((*raiz)->der != NULL && (*raiz)->izq == NULL)
        *dato = 0;
}



//ARBOL-ALTURANODO//
int alturaArbolNodo (tpunteroa raiz, int dato){
    int altura=0;
    tpunteroa actual=raiz;
    while (actual!=NULL){
        if (dato == actual->valor){
            return altura;
        }else{
            altura++;
            if (dato < actual->valor){
                actual=actual->izq;
            }else{
                if (dato > actual->valor){
                    actual=actual->der;
                }
            }
        }
    }
    printf("\nNo existe ese valor en el nodo.\n");
    return 0;
}



//ARBOL-ESHOJA?//
//Devuelve 1 si es Hoja, 0 si no lo es
int esHoja(tpunteroa raiz){
    if (!raiz->der && !raiz->izq)
        return 1;
    else
        return 0;
}



//ARBOL-ALTURA//
void alturaArbol (tpunteroa raiz, int *altura){
    *altura=0;
    auxAltura(raiz, 0, altura);
}

void auxAltura (tpunteroa raiz, int a, int *altura){
    if(raiz->izq){
        auxAltura(raiz->izq, a+1, altura);
    }
    if(raiz->der){
        auxAltura(raiz->der, a+1, altura);
    }
    if(esHoja(raiz) && a>*altura){
        *altura=a;
    }
}