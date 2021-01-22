#include <stdio.h>
#include <string.h>
#include "Kids/RegisterKids.h"
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
    RegisterKid();
    ListsKids();
//    char needs[50];
//    printf("7.Ingrese las necesidades especiales  del Niño/Niña, en caso no haber ninguna porfa escriba 'Ninguna' :\n");
//    scanf("%s", needs);
//    function(needs);




    return 0;

}