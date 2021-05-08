#include "Directory.h"

DirMgt* findDir(char* dirName, DirMgt* parentDir)
{
    DirMgt* dir = parentDir->firstChild;

    while (dir && strcmp(dirName, dir->name))
        dir = dir->sibling; 

    if (dir)
        return (dir->type)? dir : NULL;
    return NULL;
}

DirMgt *makeFile()
{
    DirMgt *A;
    A = malloc(sizeof(DirMgt));
    A->type = 0;
    A->firstChild = NULL;
    A->sibling = NULL;
    A->parent = NULL;
    return A;
}

DirMgt *makeFolder()
{
    DirMgt *A;
    A = malloc(sizeof(DirMgt));
    A->type = 1;
    A->firstChild = NULL;
    A->sibling = NULL;
    A->parent = NULL;
    return A;
}

void list(DirMgt* cur)
{
    DirMgt* temp = cur->firstChild;

    while (temp)
    {
        if (temp->type)
            printf("\033[0;35m");
        else
            printf("\033[0;32m");
        printf("%s   ", temp->name);
        printf("\033[0;37m");
        temp = temp->sibling;
    }
    printf("\n");
}
