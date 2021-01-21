//
// Created by reds on 21/1/21.
//

#include "RegisterKids.h"



// C program for writing
// struct to file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a struct to read and write


void RegisterKid(){
    int node;
    char id[20];
    char fullName[40];
    char username[20];
    char email[20];
    char birthday[20];
    char age[20];
    char needs[50];
    // Input the Word
    printf("\nBienvenido al registro de Niños y Niñas\nPor favor ingrese los datos que se le solicitan a continuacion\n");

    printf("1.Ingrese la Identificacion del Niño/Niña:\n");
    scanf("%s",&id);

    printf("2.Ingrese el Nombre Completo del Niño/Niña:\n");
    scanf("%s",&fullName);

    printf("3.Ingrese el nombre del usuario del Niño/Niña:\n");
    scanf("%s",&username);

    printf("4.Ingrese el email del Niño/Niña:\n");
    scanf("%s",&email);

    printf("5.Ingrese el cumpleaños del Niño/Niña:\n");
    scanf("%s",&birthday);

    printf("6.Ingrese la edad del Niño/Niña:\n");
    scanf("%s",&age);

    printf("7.Ingrese las necesidades especiales  del Niño/Niña, en caso no haber ninguna porfa escriba 'Ninguna' :\n");
    scanf("%s", needs);
        // Output the Word
    struct kid kid1 = {1,  id,fullName,username,email,birthday,age,needs};
    saveKidFile(kid1);
}


void saveKidFile (struct kid kid1)
{
    FILE *outfile;

    // open file for writing
    outfile = fopen ("person.dat", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opend file\n");
        exit (1);
    }

//    struct kid input1 = {1, "rohan", "sharma"};
//    struct kid input2 = {2, "mahendra", "dhoni"};
//    struct kid input3 = {1, "Sahid", "Rick"};
    // write struct to file
    fwrite (&kid1, sizeof(struct kid), 1, outfile);


    if(fwrite != 0)
        printf("EL NIÑO SE GUARDO EN EL SISTEMA CORRECTAMENTE!\n");
    else
        printf("error writing file !\n");

    // close file
    fclose (outfile);


}


int read ()
{
//    FILE *infile;
//    struct person input;
//
//    // Open person.dat for reading
//    infile = fopen ("person.dat", "r");
//    if (infile == NULL)
//    {
//        fprintf(stderr, "\nError opening file\n");
//        exit (1);
//    }
//
//    // read file contents till end of file
//    while(fread(&input, sizeof(struct person), 1, infile))
//        printf ("id = %d name = %s %s\n", input.id,
//                input.fname, input.lname);
//
//    // close file
//    fclose (infile);
//
   return 0;
}


