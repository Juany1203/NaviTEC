//
// Created by reds on 27/1/21.
//

#include "Toys/RegisterToys.h";
#include "RegisterLetters.h"
#include "../Toys/RegisterToys.h"

//
// Created by reds on 26/1/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RegisterLetter(tpunteroa raiz)
{
    char kidsId[20];
    char year[20];
    int toysId[10];
    int wishList[20];
    char respuesta[20];
    int id = 40;
    int size = 0;
    int sizeWish = 0;
    char respuesta2[20];
    // Input the Word
    printf("\nBienvenido al registro de Cartas para  Santa\nPor favor ingrese los datos que se le solicitan a continuacion\n");

    printf("1.Ingrese el nombre del niño:\n");
    scanf("%s", &kidsId);

    printf("2.Ingrese el año de la tarjeta:\n");
    scanf("%s", &year);

    printf("3.¿Desea Buscar una Juguete?(Responda Si / No) :\n");
    scanf("%s", &respuesta);
    if (strcmp(respuesta, "Si") == 0)
    {
        while (id != 0)
        {
            printf("\n3.1.Ingrese el Id del juguete a Buscar:(Para salir digite 0)\n");
            scanf("%d", &id);
            tpunteroa result = buscar(raiz, id);
            if (result != NULL)
            {
                printf("\nESTE ES EL JUGUETE %s", result->name);
                printf("\n3.2.¿Desea Agregarlo a la Carta?(Responda Si/No )\n");
                scanf("%s", &respuesta2);
                if ((strcmp(respuesta, "Si") == 0) && size < 9)
                {
                    toysId[size] = result->valor;
                    printf("\nSE AGREGO EL JUGUETE %d", toysId[size]);
                    size++;
                }
                if (size > 9)
                {
                    printf("\n LO siento ya no se pueden agregar mas juguetes a tu Carta?");
                    printf("\n3.2.¿Desea Agregarlo a la Tu WishList?(Responda Si/No )\n");
                    scanf("%s", &respuesta2);
                    if ((strcmp(respuesta, "Si") == 0))
                    {
                        wishList[sizeWish] = result->valor;
                        printf("\nSE AGREGO EL JUGUETE %d la Lista de deseos", wishList[sizeWish]);
                        sizeWish++;
                    }
                }
            }
            if (id == 0)
            {
                break;
            }
        }
    }

    //    printf("4.Ingrese Una descripcion del comportamiento del joven :\n");
    //    scanf("%s",&description);
    //
    //    printf("5.Ingrese si el joven es 'Bueno' o 'Malo' con ese formato porfa :\n");
    //    scanf("%s",&indications);
    //
    //
    //
    struct letter letter1;
    strcpy(letter1.kidsId, kidsId);
    strcpy(letter1.year, year);

    /*
    * Copy all elements from source array to dest array
    */
    for (int i = 0; i < size; i++)
    {
        letter1.toysId[i] = toysId[i];
    }
    for (int i = 0; i < sizeWish; i++)
    {
        letter1.wishList[i] = wishList[i];
    }

    printf("TODO SALIO BIEN");

    saveLettersFile(letter1);
}

void saveLettersFile(struct letter letter1)
{
    FILE *outfile;

    // open file for writing
    outfile = fopen("letters.dat", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opend file\n");
        exit(1);
    }

    // write struct to file

    fwrite(&letter1, sizeof(struct letter), 1, outfile);
    //    fwrite (&kid1, sizeof(struct kid), 1, outfile);

    if (fwrite != 0)
    {
    }
        //        printf("EL AYUDANTE SE GUARDO EN EL SISTEMA CORRECTAMENTE!\n");
    else
        printf("error writing file !\n");

    // close file
    fclose(outfile);
}

void ListsLetter()
{
    FILE *infile;
    struct letter input;

    // Open person.dat for reading
    infile = fopen("letters.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }

    printf("\nEste es el listado de las Cartas de los niños  y niñas \n");

    // read file contents till end of file
    while (fread(&input, sizeof(struct letter), 1, infile))
        //        saveKidFile(input);
        //        saveKidFile(input);
        printf("Nombre del Niño = %s, Año de la Carta =%s\n", input.kidsId,
               input.year);

    // close file
    fclose(infile);
}

int ExistLetter(char *id)
{
    FILE *infile;
    struct letter input;

    // Open person.dat for reading
    infile = fopen("letters.dat", "r+");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }

    printf("\nEste es el listado de los ayudantes en el sistema \n");
    printf("\nEste es el valior de la ID %s ", id);

    // read file contents till end of file
    while (fread(&input, sizeof(struct letter), 1, infile))
        //        if (strcmp(input.id,id)==0){
        //            return 1;
        //        }

        //        saveKidFile(input);
        //        saveKidFile(input);

        // close file
        fclose(infile);
    return 0;
}

//int CountBehavior(){
//    FILE *infile;
//    struct behavior input;
//    int amount=0;
//
//    // Open person.dat for reading
//    infile = fopen ("elfs.dat", "r");
//    if (infile == NULL)
//    {
//        fprintf(stderr, "\nError opening file\n");
//        exit (1);
//    }
//
//    // read file contents till end of file
//    while(fread(&input, sizeof(struct behavior), 1, infile))
//        amount++;
//
//    // close file
//    fclose (infile);
//
//    printf("\nTHE AMOUNT OF BEHAVIORS ARE: %d",amount);
//
//    return amount;
//}
//
//
//
