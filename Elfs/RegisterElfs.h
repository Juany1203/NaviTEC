//
// Created by reds on 21/1/21.
//

#ifndef NAVITEC_REGISTERELFS_H
#define NAVITEC_REGISTERELFS_H

struct elf
{
//    int node;
    char id[20];
    char fullName[40];
    char job[20];
    char functions[40];
    char startDate[20];
};

void saveElfFile(struct elf elf1);
void ListsElfs();
void RegisterElf();
void EditElf(char *id,int option,char *newValue);
int  CountElfs();
int  ExistElf(char *id);



#endif //NAVITEC_REGISTERELFS_H
