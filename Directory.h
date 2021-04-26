#ifndef __DIRECTORY_H
#define __DIRECTORY_H

#include <stdbool.h>

typedef struct DirMgt DirMgt;

struct DirMgt
{
    char name[256];
    bool type;
    DirMgt* head;
    DirMgt* sibling;
    DirMgt* parent;
};

typedef DirMgt* HeadDir;

typedef struct Alias Alias;

struct Alias
{
    char name[255];
    DirMgt* dir;
    Alias* next;
};

enum state
{
    added, alreadyExists, error
};

Alias* createAlias(); // To create an empty node of the DirMgt structure
enum state addNewAlias(DirMgt* rootDir, Alias* aliasHead, char* name, char* absName); // To add a new alias

bool DirExists(DirMgt* rootDir, char* absName);

#endif
