//
// Created by reds on 27/1/21.
//

#ifndef NAVITEC_REGISTERLETTERS_H
#define NAVITEC_REGISTERLETTERS_H


struct letter
{
//    int node;
    char kidsId[20];
    char year[20];
    int toysId[10];
    int wishList[20];
};

void saveLettersFile(struct letter letter1);
void ListsLetter();
void RegisterLetter();
void EditLetter(char *id,int option,char *newValue);
int  CountLetters();
int  ExistLetter(char *id);


#endif //NAVITEC_REGISTERLETTERS_H
