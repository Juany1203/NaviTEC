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


    struct kid kid1 ;
    kid1.node=1;
    strcpy(kid1.id,id);
    strcpy(kid1.fullName,fullName);
    strcpy(kid1.username,username);
    strcpy(kid1.email,email);
    strcpy(kid1.birthday,birthday);
    strcpy(kid1.age,age);
    strcpy(kid1.needs,needs);
    saveKidFile(kid1);



}


void saveKids(struct kid *kids){


}

void saveKidFile (struct kid kid1){
    FILE *outfile;

    // open file for writing
    outfile = fopen ("kids.dat", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opend file\n");
        exit (1);
    }

    // write struct to file

    printf ("NOMBRE = %d USERNAME = %s  EMAIL = %s\n", kid1.node,
            kid1.username,kid1.email);
    fwrite (&kid1, sizeof(struct kid), 1, outfile);
//    fwrite (&kid1, sizeof(struct kid), 1, outfile);


    if(fwrite != 0)
        printf("EL NIÑO SE GUARDO EN EL SISTEMA CORRECTAMENTE!\n");
    else
        printf("error writing file !\n");

    // close file
    fclose (outfile);


}

void ListsKids(){
    FILE *infile;
    struct kid input;

    // Open person.dat for reading
    infile = fopen ("kids.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    printf("\nEste es el listado de los niños  y niñas en el sistema \n");


    // read file contents till end of file
    while(fread(&input, sizeof(struct kid), 1, infile))
//        saveKidFile(input);
//        saveKidFile(input);
        printf ("id = %s fullname = %s %s\n", input.id,
                input.fullName,input.username);

    // close file
    fclose (infile);

}







void changeKid(){
    char newValue[20];
    int option;
    char id[20];


    printf("\n.Este es el menu para editar un Niño de Santa\n"
           "Estas son las opciones\n"
           "1.Editar la identificacion del Niño o Niña\n"
           "2.Editar el Nombre Completo del Niño o Niña\n"
           "3.Editar Nombre de usuario del Niño o Niña\n"
           "4.Editar el email del Niño o Niña\n"
           "5.Editar el cumpleaños del Niño o Niña\n"
           "6.Editar la edad del Niño o Niña\n"
           "7.Editar las necesidades  del Niño o Niña\n");

    printf(".Ahora ingrese la identificacion   del Niño o Niña que desea modificar:\n");
    scanf("%s",&id);

    printf("Ingrese  la opcion que desea cambiar:\n");
    scanf("%d",&option);

    printf("Ingrese el Nuevo valor ha ser cambiado:\n");
    scanf("%s",&newValue);
    EditKid(id,option,newValue);
}

void EditKid(char *id ,int option,char *newValue){
    FILE *infile;
    FILE *file;
    struct kid input;

    // Open person.dat for reading
    infile = fopen ("kids.dat", "r+");

    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    file = fopen("kids-tmp.dat", "w");

    if (file == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }



    struct kid arr_elf[CountKids()];
    int amountElfs=CountKids();
    int cont=0;
    int flag=0;


    // read file contents till end of file
    while(fread(&input, sizeof(struct kid), 1, infile)){
        printf("\nBUSCADO:%s SOLICITADO: %s",input.id,id);
        int comparacion=strcmp(input.id,id) ;
        printf("\nCOMPARACION %d",comparacion);
        if (comparacion==0){
            printf("\nSI LO ENCONTE");
            if(option==1){
                strcpy(input.id,newValue);
            }
            if(option==2){
                strcpy(input.fullName,newValue);
            }
            if(option==3){
                strcpy(input.username,newValue);
            }
            if(option==4){
                strcpy(input.email,newValue);
            }
            if(option==5){
                strcpy(input.birthday,newValue);
            }
            if(option==6){
                strcpy(input.age,newValue);
            }
            if(option==7){
                strcpy(input.needs,newValue);
            }
//            fwrite (&input, sizeof(struct elf), 1, file);
//            arr_elf[cont]=input;
//            flag=1;
        }
        else{
            printf("NO LO ENCONTRE");
//            fwrite (&input, sizeof(struct elf), 1, file);
//            arr_elf[cont]=input;
        }
        fwrite (&input, sizeof(struct kid), 1, file);
        cont++;
    }

//        saveKidFile(input);
//        saveKidFile(input);
//    fclose (infile);
    fclose(infile);
    fclose(file);
    remove("kids.dat");
    rename("kids-tmp.dat","kids.dat");




//        fclose (infile);

    // close files


}
 void eraseKid(){

     char id[20];




     printf(".Ahora ingrese la identificacion   del Niño o Niña que Eliminar\n");
     scanf("%s",&id);


     DeleteKid(id);
}

void DeleteKid(char *id){
    FILE *infile;
    FILE *file;
    struct kid input;

    // Open person.dat for reading
    infile = fopen ("kids.dat", "r+");

    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    file = fopen("kids-tmp.dat", "w");

    if (file == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }



//    int amountElfs=CountKids();
    int cont=0;
    int flag=0;


    // read file contents till end of file
    while(fread(&input, sizeof(struct kid), 1, infile)){
        printf("\nBUSCADO:%s SOLICITADO: %s",input.id,id);
        int comparacion=strcmp(input.id,id) ;
        printf("\nCOMPARACION %d",comparacion);
        if (comparacion==0){
            printf("\nSI LO ENCONTE");

        }
        else{
            printf("NO LO ENCONTRE");
            fwrite (&input, sizeof(struct kid), 1, file);
//            arr_elf[cont]=input;
        }
//        fwrite (&input, sizeof(struct kid), 1, file);
        cont++;
    }

    fclose(infile);
    fclose(file);
    remove("kids.dat");
    rename("kids-tmp.dat","kids.dat");




//        fclose (infile);

    // close files
}




int ExistKid(char *id){
    FILE *infile;
    struct kid input;

    // Open person.dat for reading
    infile = fopen ("kids.dat", "r+");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    printf("\nEste es el listado de los ayudantes en el sistema \n");
    printf("\nEste es el valior de la ID %s ",id);


    // read file contents till end of file
    while(fread(&input, sizeof(struct kid), 1, infile))
        if (strcmp(input.id,id)==0){
            return 1;
        }



    // close file
    fclose (infile);
    return 0;

}





int CountKids ()
{
    FILE *infile;
    struct kid input;
    int amount=0;

    // Open person.dat for reading
    infile = fopen ("kids.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    // read file contents till end of file
    while(fread(&input, sizeof(struct kid), 1, infile))
        amount++;

    // close file
    fclose (infile);

    printf("\nTHE AMOUNT OF KIDS ARE: %d",amount);

   return amount;
}


