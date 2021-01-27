//
// Created by reds on 26/1/21.
//

#include "RegisterToys.h"

#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "stddef.h"

#include <ctype.h>
#include <stdio.h>

#include <sys/stat.h>   // stat
#include <stdbool.h>    // bool type




bool file_exists (char *filename) {
    struct stat   buffer;
    return (stat (filename, &buffer) == 0);
}

void registerToy(tpunteroa raiz){
    int codigo;
    // Input the Word
    printf("\nBienvenido al registro de Juguetes\nPor favor ingrese los datos que se le solicitan a continuacion\n");

    printf("1.Ingrese el codigo del  juguete (este tiene que ser un numero):\n");
    scanf("%d",&codigo);
    insertarArbol(raiz,codigo);
}
//ARBOL-INSERTAR//
void insertarArbol (tpunteroa *raiz,int dato){
    if (*raiz == NULL){
        *raiz = malloc(sizeof(tnodoa));
//       (*raiz)->valor = dato;
        (*raiz)->izq = NULL;
        (*raiz)->der = NULL;


//    ESTOS SON LAS VARIABLES QUE TENDRAN LOS VALORES DE LAS DATOS SOLICITADOS

        char name[20];
        char description[40];
        char category[20];
        char age[20];
        int  cost;

//
////        Aqui solicitamos los demas datos
//

        printf("2.Ingrese el Nombre  del juguete\n");
        scanf("%s",&name);

        printf("3.Ingrese una descripcion  del juguete:\n");
        scanf("%s",&description);

        printf("4.Ingrese la categoria  del jueguete:\n");
        scanf("%s",&category);

        printf("5.Ingrese el rango de edad del juguete:\n");
        scanf("%s",&age);

        printf("6.Ingrese el coste para la fabricacion del juguete :\n");
        scanf("%d",&cost);
        (*raiz)->valor = dato;
        strcpy((*raiz)->name,name);
        strcpy((*raiz)->description,description);
        strcpy((*raiz)->category,category);
        strcpy((*raiz)->age,age);
        (*raiz)->cost = cost;

        struct snodoa toy;
        toy.valor = dato;
        strcpy(toy.name,name);
        strcpy(toy.description,name);
        strcpy(toy.category,category);
        strcpy(toy.age,age);
        toy.cost=cost;

        saveToyFile(toy);


    }else{
        if (dato <= (*raiz)->valor){
            insertarArbol (&(*raiz)->izq, dato);
        }else{
            insertarArbol (&(*raiz)->der, dato);
        }
    }
}


void saveToyFile (struct snodoa toy){
    printf("ESTE ES EL NOMBRE %s",toy.name);
    FILE *outfile;

    // open file for writing
    outfile = fopen ("toys.dat", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opend file\n");
        exit (1);
    }

    // write struct to file


    fwrite (&toy, sizeof(struct snodoa), 1, outfile);
//    fwrite (&kid1, sizeof(struct kid), 1, outfile);


    if(fwrite != 0){

    }
//        printf("EL AYUDANTE SE GUARDO EN EL SISTEMA CORRECTAMENTE!\n");
    else
        printf("error writing file !\n");

    // close file
    fclose (outfile);


}




//ARBOL-INSERTAR//
void insertarArbolRepeat (tpunteroa *raiz,int dato,struct snodoa info){
    if (*raiz == NULL){
        *raiz = malloc(sizeof(tnodoa));
//       (*raiz)->valor = dato;
        (*raiz)->izq = NULL;
        (*raiz)->der = NULL;

        (*raiz)->valor = dato;
        strcpy((*raiz)->name,info.name);
        strcpy((*raiz)->description,info.description);
        strcpy((*raiz)->category,info.category);
        strcpy((*raiz)->age,info.age);
        (*raiz)->cost = info.cost;




    }else{
        if (dato <= (*raiz)->valor){
            insertarArbolRepeat (&(*raiz)->izq, dato,info);
        }else{
            insertarArbolRepeat (&(*raiz)->der, dato,info);
        }
    }
}




void rearmarArbol (tpunteroa raiz){
    FILE *infile;
    struct snodoa input;

    // Open person.dat for reading
    infile = fopen ("toys.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    printf("\nEste es el listado de los Juguetes   \n");


    // read file contents till end of file
    while(fread(&input, sizeof(struct snodoa), 1, infile))
//        saveKidFile(input);
//        saveKidFile(input);
        insertarArbolRepeat(raiz,input.valor,input);
        printf (" ID %d Nombre = %s  Categoria= %s\n", input.valor,input.name,
                input.category);

    // close file
    fclose (infile);
}



void getToys(tpunteroa raiz){
    printf("EST ES EL CATALOGO DE JUGUETES");
    imprimirArbol(raiz);
}


//ARBOL-IMPRIMIR//
void imprimirArbol (tpunteroa raiz){

    if (raiz != NULL){
        imprimirArbol (raiz->izq);
        printf("**********************************\n");
        printf("Codigo Del Juguete:");
        printf("%d. \n", raiz->valor);
        printf("Nombre Del Juguete:");
        printf("%s. \n", raiz->name);
        printf("Descripcion Del Juguete:");
        printf("%s. \n", raiz->description);
        printf("Categoria Del Juguete:");
        printf("%s. \n", raiz->category);
        printf("Rango de Edad Del Juguete:");
        printf("%s. \n", raiz->age);
//        printf("**********************************\n");
        imprimirArbol (raiz->der);
    }
}

//ARBOL-IMPRIMIR//
tpunteroa recorrerArbol (tpunteroa *raiz){

    *raiz = malloc(sizeof(tnodoa));


    FILE *infile;
//        raiz=NUll;


    // Open person.dat for reading
    infile = fopen ("raiz.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    // read file contents till end of file
    while(fread(&raiz, sizeof(tnodoa), 1, infile)){
        tpunteroa raizReturn;
        *(&raizReturn) = malloc(sizeof(tnodoa));
        raizReturn->valor=(*raiz)->valor;
        raizReturn->der=(*raiz)->der;
        raizReturn->izq=(*raiz)->izq;

        return raizReturn;
        printf("Est es el valor  ES LA RAZON,  %d",(*raiz)->valor);
    }


    // close file
    fclose (infile);


//    if (raiz != NULL){
//        imprimirArbol (raiz->izq);
//        printf("%d, ", raiz->valor);
//        imprimirArbol (raiz->der);
//    }
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