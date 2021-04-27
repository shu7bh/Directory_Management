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

void add(DirMgt *current_dir, char *name_f, int a)
{
    DirMgt *A;
    DirMgt *temp = current_dir;

    current_dir = current_dir->firstChild;
    if(strcmp(current_dir->name,name_f)==0)
    {
        printf("ERROR: name already exists");
        return ;
    }
    if (current_dir != NULL)
    {
        while (current_dir->sibling != NULL)
        {
            current_dir = current_dir->sibling;
            if(strcmp(current_dir->name,name_f)==0)
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

    current_dir->sibling = A;
    strcpy(A->name, name_f);
    A->parent = temp;
}
