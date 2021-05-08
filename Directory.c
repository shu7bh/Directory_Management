#include "Directory.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

DirMgt* findDir(char* dirName, DirMgt* parentDir)
{
    DirMgt* dir = parentDir->firstChild;

    while (dir && strcmp(dirName, dir->name))
        dir = dir->sibling; 

    if (dir)
        return (dir->type)? dir : NULL;
    return NULL;
}

bool move(DirMgt* root, DirMgt** current)
{
    DirMgt* cur = root;
    int ct = 0;

    int flag = 1;
    while (flag)
    {
        char str[260];
        char input;
        int i = 0;
        while ((input = getchar()))
        {
            if (input == '/')
                break;
            else if (input == '\n')
            {
                flag = 0;
                break;
            }
            else if (input == ' ')
            {
                printf("Error: Invalid command - spaces are not allowed.\n");
                while (getchar() != '\n');
                return 0;
            }
            else
                str[i++] = input;
            if (i > 255)
            {
                printf("Error: Directory does not exist.\n");
                while (getchar() != '\n');
                return 0;
            }
        }
        str[i] = '\0';

        if (!ct++)
        {
            if (strcmp(root->name, str))
            {
                printf("Error: Directory does not exist.\n");
                if (flag)
                    while (getchar() != '\n');
                return 0;
            }
        }
        else
        {
            DirMgt* nextDir = findDir(str, cur);
            if (nextDir)
                cur = nextDir;
            else 
            {
                printf("Error: Directory does not exist.\n");
                if (flag)
                    while (getchar() != '\n');
                return 0;
            }
        }
    }

    *current = cur;
    return 1;
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
        printf("\033[0m");
        temp = temp->sibling;
    }
    printf("\n");
}

void add(DirMgt *currentDir, char *nameF, int a)
{
    DirMgt *A;
    DirMgt *temp = currentDir;

    if (!currentDir->firstChild)
    {
        if (a == 1)
        {
            currentDir->firstChild = makeFolder();
            strcpy(currentDir->firstChild->name, nameF);
            currentDir->firstChild->parent = currentDir;
        }

        if (a == 0)
        {
            currentDir->firstChild = makeFile();
            strcpy(currentDir->firstChild->name, nameF);
            currentDir->firstChild->parent = currentDir;
        }
        return;
    }

    currentDir = currentDir->firstChild;
    if(strcmp(currentDir->name,nameF)==0)
    {
        printf("Error: Name already exists\n");
        return ;
    }
    if (currentDir != NULL)
    {
        while (currentDir->sibling != NULL)
        {
            currentDir = currentDir->sibling;
            if(strcmp(currentDir->name,nameF)==0)
            {
                printf("Error: Name already exists\n");
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
