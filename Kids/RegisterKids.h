//
// Created by reds on 21/1/21.
//

#ifndef NAVITEC_REGISTERKIDS_H
#define NAVITEC_REGISTERKIDS_H
struct kid
{
    int node;
    char id[20];
    char fullName[40];
    char username[20];
    char email[20];
    char birthday[20];
    char age[20];
    char needs[40];
};
void saveKidFile(struct kid kid1);
void ListsKids();
int read();
void RegisterKid();

#endif //NAVITEC_REGISTERKIDS_H
