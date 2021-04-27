#include "Directory.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

/*typedef struct Name Name;*/
/*struct Name*/
/*{*/
/*char name[256];*/
/*Name* next;*/
/*};*/

bool inputAlias(DirMgt* root, Alias* aliasHead)
{
    char aliasName[256];
    scanf("%s", aliasName);

    DirMgt* cur = root;
    int ct = 0;

    while (true)
    {
        char str[260];
        scanf("%257[^/]s", str);

        if (strlen(str) == 257)
        {
            printf("Invalid Name\n");
            fflush(stdin);
            return 0;
        }

        if (!ct++)
        {
            if (strcmp(root->name, str))
            {
                printf("Directory does not exist\n");
                fflush(stdin);
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
                printf("Directory does not exist\n");
                fflush(stdin);
                return 0;
            }
        }
    }
}

DirMgt* findDir(char* dirName, DirMgt* parentDir)
{
    DirMgt* dir = parentDir->firstChild;

    while (dir && strcmp(dirName, dir->name))
        dir = dir->firstChild; 

    return dir;
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
    alias = alias->next;
    return 1;
}

/*void deleteName(Name** name)*/
/*{*/
/*Name* temp = *name;*/

/*while (temp)*/
/*{*/
/*Name* del = temp;*/
/*temp = temp->next;*/
/*free (del);*/
/*}*/
/**name = NULL;*/
/*}*/

/*Name* dirNames(char* absName)*/
/*{*/
/*Name* names = NULL;*/
/*Name* node = names;*/

/*int len = strlen(absName);*/
/*char str[260];*/
/*for (int i = 0, j = 0; i < len; ++i)*/
/*if (absName[i] != '/' && j < 255)*/
/*strcat(str, (char*)&absName[i]), ++j;*/
/*else if (j >= 254)*/
/*{*/
/*Name* temp = (Name*) malloc (sizeof (Name));*/
/*temp->next = NULL;*/
/*strcpy(temp->name, "");*/
/*deleteName(&names);*/
/*return temp;*/
/*}*/
/*else*/
/*{*/
/*Name* temp = (Name*) malloc (sizeof (Name));*/
/*strcpy(temp->name, str);*/

/*if (node == NULL)*/
/*names = node = temp;*/
/*else*/
/*node->next = temp, node = node->next;*/
/*}*/
/*return names;*/
/*}*/

Alias* createAlias(char* aliasName, DirMgt* dir)
{
    Alias* node = (Alias*) malloc (sizeof(Alias));
    assert(node != NULL);

    strcpy(node->name, aliasName);
    node->dir = dir;
    node->next = NULL;
    return node;
}

/*enum state addNewAlias(DirMgt* rootDir, Alias* aliasHead, char* name, char* absName)*/
/*{*/
/*Alias* node = aliasHead;*/
/*while (node->next)*/
/*if (strcmp(node->next->name, name) == 0)*/
/*return 1;*/

/*if (!DirExists(rootDir, absName))*/
/*return 2;*/

/*return 0;*/
/*}*/
