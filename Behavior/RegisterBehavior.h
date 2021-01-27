//
// Created by reds on 26/1/21.
//

#ifndef NAVITEC_REGISTERBEHAVIOR_H
#define NAVITEC_REGISTERBEHAVIOR_H

struct behavior
{
//    int node;
    char parentName[20];
    char kidsId[20];
    char date[20];
    char description[40];
    char indications[20];

};

void saveBehaviorFile(struct behavior behavior1);
void ListsBehavior();
void RegisterBehavior();
void EditElf(char *id,int option,char *newValue);
int  CountBehavior();
int  ExistBehavior(char *id);

#endif //NAVITEC_REGISTERBEHAVIOR_H
