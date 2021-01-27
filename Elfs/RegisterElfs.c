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


    if(fwrite != 0){

    }
//        printf("EL AYUDANTE SE GUARDO EN EL SISTEMA CORRECTAMENTE!\n");
    else
        printf("error writing file !\n");

    // close file
    fclose (outfile);


}

void ListsElfs(){
    FILE *infile;
    struct elf input;

    // Open person.dat for reading
    infile = fopen ("elfs-tmp.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    printf("\nEste es el listado de los Ayudantes  de Santa  el sistema \n");


    // read file contents till end of file
    while(fread(&input, sizeof(struct elf), 1, infile))
//        saveKidFile(input);
//        saveKidFile(input);
        printf ("id = %s Nombre = %s  Trabajo= %s\n", input.id,
                input.fullName,input.job);

    // close file
    fclose (infile);

}

void EditElf(char *id ,int option,char *newValue){
    FILE *infile;
    FILE *file;
    struct elf input;

    // Open person.dat for reading
    infile = fopen ("elfs.dat", "r+");

    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    file = fopen("elfs-tmp.dat", "w");

    if (file == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }



    struct elf arr_elf[CountElfs()];
    int amountElfs=CountElfs();
    int cont=0;
    int flag=0;


    // read file contents till end of file
    while(fread(&input, sizeof(struct elf), 1, infile)){
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
                strcpy(input.job,newValue);
            }
            if(option==4){
                strcpy(input.functions,newValue);
            }
            if(option==5){
                strcpy(input.startDate,newValue);
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
    fwrite (&input, sizeof(struct elf), 1, file);
        cont++;
    }

//        saveKidFile(input);
//        saveKidFile(input);
//    fclose (infile);
    fclose(infile);
    fclose(file);
    remove("elf.dat");
    rename("elf-tmp.dat","elf.dat");
    if(flag){
//        fclose(fopen("elfs.dat", "w"));
        printf("\nELIMINE EL ARCHIVO");
        file = fopen("elfs-tmp.dat", "w");
        if (infile == NULL) {
            fprintf(stderr, "\nError opening file\n");
            exit(1);
        }
        for (int i=0;i<(amountElfs);i++) {
            printf("VAMOS A VOLVER A GREGAR UN ELFO AL SISTEMA");
            saveElfFile(arr_elf[i]);
           fwrite(&arr_elf[i], sizeof(struct elf), 1, file);
        }

//        remove("")
    }



//        fclose (infile);

    // close files


}



int ExistElf(char *id){
    FILE *infile;
    struct elf input;

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
    while(fread(&input, sizeof(struct elf), 1, infile))
        if (strcmp(input.id,id)==0){
            return 1;
        }

//        saveKidFile(input);
//        saveKidFile(input);
    printf ("id = %s Nombre = %s  Trabajo= %s\n", input.id,
            input.fullName,input.job);

    // close file
    fclose (infile);
    return 0;

}

int CountElfs(){
    FILE *infile;
    struct elf input;
    int amount=0;

    // Open person.dat for reading
    infile = fopen ("elfs.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    // read file contents till end of file
    while(fread(&input, sizeof(struct elf), 1, infile))
        amount++;

    // close file
    fclose (infile);

    printf("\nTHE AMOUNT OF ELFS ARE: %d",amount);

    return amount;
}



