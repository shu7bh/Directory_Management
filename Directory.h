#ifndef __DIRECTORY_H
#define __DIRECTORY_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 255

typedef struct DirMgt DirMgt;
struct DirMgt
{
    char name[SIZE + 1];
    bool type;
    DirMgt* firstChild;
    DirMgt* sibling;
    DirMgt* parent;
};

DirMgt *makeFile();
DirMgt *makeFolder();
DirMgt* findDir(char* dirName, DirMgt* parentDir);
bool relativeDirectory(DirMgt** current);
void goToRoot(DirMgt* ptr);

void add(DirMgt *currentDir);
void list(DirMgt* cur);
bool move(DirMgt* root, DirMgt** current);
void find(DirMgt* cur, int showAll);
void man();

void printError(char str[100]);
void printMessage(char str[100]);

typedef struct Alias Alias;

struct Alias
{
    char name[SIZE + 1];
    DirMgt* dir;
    Alias* next;
};

bool inputAlias(DirMgt* root, Alias* aliasHead); // To input alias from the user
Alias* createAlias(char* aliasName, DirMgt* dir); // To create an empty node of the DirMgt structure
bool addAlias(Alias* aliasHead, char* aliasName, DirMgt* dir);
void Teleport(Alias* aliasHead, DirMgt** Current);

#endif
