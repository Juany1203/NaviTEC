//
// Created by reds on 21/1/21.
//

#include "RegisterElfs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void RegisterElf(){
    char id[20];
    char fullName[40];
    char job[20];
    char functions[40];
    char startDate[20];
    // Input the Word
    printf("\nBienvenido al registro de Ayudante de Santa\nPor favor ingrese los datos que se le solicitan a continuacion\n");

    printf("1.Ingrese la Identificacion del o la  Ayudante:\n");
    scanf("%s",&id);

    printf("2.Ingrese el Nombre Completo del o la  Ayudante:\n");
    scanf("%s",&fullName);

    printf("3.Ingrese la posicion  del o la  Ayudante:\n");
    scanf("%s",&job);

    printf("4.Ingrese las funciones  del o la  Ayudante:\n");
    scanf("%s",&functions);

    printf("5.Ingrese la fecha de ingreso  del o la  Ayudante:\n");
    scanf("%s",&startDate);



    struct elf elf1 ;
    strcpy(elf1.id,id);
    strcpy(elf1.fullName,fullName);
    strcpy(elf1.job,job);
    strcpy(elf1.functions,functions);
    strcpy(elf1.startDate,startDate);

    saveElfFile(elf1);



}



void saveElfFile (struct elf elf1){
    FILE *outfile;

    // open file for writing
    outfile = fopen ("elfs.dat", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opend file\n");
        exit (1);
    }

    // write struct to file


    fwrite (&elf1, sizeof(struct elf), 1, outfile);
//    fwrite (&kid1, sizeof(struct kid), 1, outfile);


    if(fwrite != 0)
        printf("EL AYUDANTE SE GUARDO EN EL SISTEMA CORRECTAMENTE!\n");
    else
        printf("error writing file !\n");

    // close file
    fclose (outfile);


}

void ListsElfs(){
    FILE *infile;
    struct elf input;

    // Open person.dat for reading
    infile = fopen ("elfs.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    printf("\nEste es el listado de los niños  y niñas en el sistema \n");


    // read file contents till end of file
    while(fread(&input, sizeof(struct elf), 1, infile))
//        saveKidFile(input);
//        saveKidFile(input);
        printf ("id = %s Nombre = %s  Trabajo= %s\n", input.id,
                input.fullName,input.job);

    // close file
    fclose (infile);

}



