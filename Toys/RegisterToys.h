//
// Created by reds on 26/1/21.
//

#ifndef NAVITEC_REGISTERTOYS_H
#define NAVITEC_REGISTERTOYS_H


#define MAX 100

typedef struct snodoa{
    int valor;
    char name[20];
    char description[40];
    char category[20];
    char age[20];
    int  cost;
    struct snodoa *izq, *der;
}tnodoa;

typedef tnodoa *tpunteroa;

void rearmarArbol(tpunteroa raiz);

void insertarArbolRepeat (tpunteroa *raiz,int dato,struct snodoa info);

void insertarArbol (tpunteroa *raiz,int dato);
void registerToy(tpunteroa raiz);
void imprimirArbol (tpunteroa raiz);
tpunteroa recorrerArbol (tpunteroa *raiz);
void borrarArbol (tpunteroa *raiz);
tpunteroa buscar (tpunteroa raiz, int dato);
int esHoja (tpunteroa raiz);
int alturaArbolNodo (tpunteroa raiz, int dato);
void alturaArbol (tpunteroa raiz, int *altura);
void auxAltura (tpunteroa raiz, int a, int *altura);

void saveToyFile (struct snodoa toy);

void registerToy();

#endif //NAVITEC_REGISTERTOYS_H
