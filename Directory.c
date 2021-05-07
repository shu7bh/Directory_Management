#include "Directory.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

bool inputAlias(DirMgt* root, Alias* aliasHead)
{
    char aliasName[260];

    char input;
    int i = 0;
    while ((input = getchar()))
    {
        if (input == ' ')
            break;
        
        aliasName[i++] = input;

        if (i > 255)
        {
            printf("Error: Invalid Alias Name.\n");
            while ((getchar()) != '\n');
            return 0;
        }
    }

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
            else
                str[i++] = input;
            if (i > 255)
            {
                printf("Error: Invalid Name.\n");
                while ((getchar()) != '\n');
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
                    while ((getchar()) != '\n');
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
                    while ((getchar()) != '\n');
                return 0;
            }
        }
    }
    if (addAlias(aliasHead, aliasName, cur))
        printf("\nAdded Alias\n");
    else
    {
        printf("Error: Alias already exists.\n");
        return 0;
    }
    return 1;
}

DirMgt* findDir(char* dirName, DirMgt* parentDir)
{
    DirMgt* dir = parentDir->firstChild;

    while (dir && strcmp(dirName, dir->name))
        dir = dir->firstChild; 

    if (dir)
        return (dir->type)? dir : NULL;
    return NULL;
}

bool addAlias(Alias* aliasHead, char* aliasName, DirMgt* dir)
{
    Alias* alias = aliasHead;

    while (alias->next)
    {
        if (strcmp(alias->name, aliasName) == 0)
            return 0;
        alias = alias->next;
    }

    alias->next = createAlias(aliasName, dir);
    return 1;
}

Alias* createAlias(char* aliasName, DirMgt* dir)
{
    Alias* node = (Alias*) malloc (sizeof(Alias));
    assert(node != NULL);

    strcpy(node->name, aliasName);
    node->dir = dir;
    node->next = NULL;
    return node;
}
