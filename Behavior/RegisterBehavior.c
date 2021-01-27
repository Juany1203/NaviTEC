//
// Created by reds on 26/1/21.
//

#include "RegisterBehavior.h"


//
// Created by reds on 21/1/21.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void RegisterBehavior(){
    char parentName[20];
    char kidsId[20];
    char date[20];
    char description[40];
    char indications[20];
    // Input the Word
    printf("\nBienvenido al registro de Ayudante de Santa\nPor favor ingrese los datos que se le solicitan a continuacion\n");

    printf("1.Ingrese el nombre del padre o madre:\n");
    scanf("%s",&parentName);

    printf("2.Ingrese la identificacion del niño:\n");
    scanf("%s",&kidsId);

    printf("3.Ingrese la fecha del registro :\n");
    scanf("%s",&date);

    printf("4.Ingrese Una descripcion del comportamiento del joven :\n");
    scanf("%s",&description);

    printf("5.Ingrese si el joven es 'Bueno' o 'Malo' con ese formato porfa :\n");
    scanf("%s",&indications);



    struct behavior behavior1 ;
    strcpy(behavior1.parentName,parentName);
    strcpy(behavior1.kidsId,kidsId);
    strcpy(behavior1.date,date);
    strcpy(behavior1.description,description);
    strcpy(behavior1.indications,indications);

    saveBehaviorFile(behavior1);



}



void saveBehaviorFile (struct behavior behavior1){
    FILE *outfile;

    // open file for writing
    outfile = fopen ("behaviors.dat", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opend file\n");
        exit (1);
    }

    // write struct to file


    fwrite (&behavior1, sizeof(struct behavior), 1, outfile);
//    fwrite (&kid1, sizeof(struct kid), 1, outfile);


    if(fwrite != 0){

    }
//        printf("EL AYUDANTE SE GUARDO EN EL SISTEMA CORRECTAMENTE!\n");
    else
        printf("error writing file !\n");

    // close file
    fclose (outfile);


}

void ListsBehavior(){
    FILE *infile;
    struct behavior input;

    // Open person.dat for reading
    infile = fopen ("behaviors.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    printf("\nEste es el listado de los Comportamientos de los niños  y niñas \n");


    // read file contents till end of file
    while(fread(&input, sizeof(struct behavior), 1, infile))
//        saveKidFile(input);
//        saveKidFile(input);
        printf ("Nombre del Padre = %s, Identificacion del niño= %s,Comportamiento= %s\n", input.parentName,
                input.kidsId,input.indications);

    // close file
    fclose (infile);

}




int ExistBehavior(char *id){
    FILE *infile;
    struct behavior input;

    // Open person.dat for reading
    infile = fopen ("elfs.dat", "r+");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    printf("\nEste es el listado de los ayudantes en el sistema \n");
    printf("\nEste es el valior de la ID %s ",id);


    // read file contents till end of file
    while(fread(&input, sizeof(struct behavior), 1, infile))
//        if (strcmp(input.id,id)==0){
//            return 1;
//        }

//        saveKidFile(input);
//        saveKidFile(input);


    // close file
    fclose (infile);
    return 0;

}

int CountBehavior(){
    FILE *infile;
    struct behavior input;
    int amount=0;

    // Open person.dat for reading
    infile = fopen ("elfs.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    // read file contents till end of file
    while(fread(&input, sizeof(struct behavior), 1, infile))
        amount++;

    // close file
    fclose (infile);

    printf("\nTHE AMOUNT OF BEHAVIORS ARE: %d",amount);

    return amount;
}



