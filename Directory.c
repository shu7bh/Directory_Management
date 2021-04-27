#include "Directory.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "string.h"

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

void add(DirMgt *currentDir, char *nameF, int a)
{
    DirMgt *A;
    DirMgt *temp = currentDir;

    currentDir = currentDir->firstChild;
    if(strcmp(currentDir->name,nameF)==0)
    {
        printf("ERROR: name already exists");
        return ;
    }
    if (currentDir != NULL)
    {
        while (currentDir->sibling != NULL)
        {
            currentDir = currentDir->sibling;
            if(strcmp(currentDir->name,nameF)==0)
            {
                printf("ERROR: name already exists");
                return ;
            }
            
        }
    }

    if (a == 1)
    {
        A = makeFolder();
    }

    if (a == 0)
    {
        A = makeFile();
    }

    currentDir->sibling = A;
    strcpy(A->name, nameF);
    A->parent = temp;
}
