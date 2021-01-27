#include <stdio.h>
#include <string.h>
#include "Kids/RegisterKids.h"
#include "Elfs/RegisterElfs.h"
#include "Toys/RegisterToys.h"
//created by chaitanya

#include <sys/stat.h>   // stat
#include <stdbool.h>    // bool type
#include <stdlib.h>


int main()
{

    tpunteroa raiz;

    raiz = NULL;

  registerToy(&raiz);
  registerToy(&raiz);
  imprimirArbol(raiz);

}


//ListsKids();
//EditKid("SIHAN",2,"EL-MOLESTO");
//ListsKids();
//    ListsElfs();
//EditElf("13",2,"ELLAESA");
//RegisterElf();
//  ListsElfs();

//RegisterElf();
//RegisterElf();
//RegisterElf();