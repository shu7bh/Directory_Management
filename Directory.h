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

#endif
