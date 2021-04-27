#ifndef __DIRECTORY_H
#define __DIRECTORY_H

#include <stdbool.h>

typedef struct DirMgt DirMgt;

struct DirMgt
{
    char name[256];
    bool type;
    DirMgt* firstChild;
    DirMgt* sibling;
    DirMgt* parent;
};

typedef DirMgt* HeadDir;

typedef struct Alias Alias;

struct Alias
{
    char name[256];
    DirMgt* dir;
    Alias* next;
};

//enum state
//{
    //added, alreadyExists, error
//};

bool inputAlias(DirMgt* root, Alias* aliasHead); // To input alias from the user

DirMgt* findDir(char* dirName, DirMgt* parentDir);
Alias* createAlias(char* aliasName, DirMgt* dir); // To create an empty node of the DirMgt structure
//enum state addNewAlias(DirMgt* rootDir, Alias* aliasHead, char* name, char* absName); // To add a new alias

bool addAlias(Alias* aliasHead, char* aliasName, DirMgt* dir);
//bool DirExists(DirMgt* rootDir, char* absName);

#endif
