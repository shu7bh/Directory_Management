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

DirMgt *makeFile();
DirMgt *makeFolder();
void add(DirMgt *currentDir, char *nameF, int a);

#define SIZE 255

#endif
