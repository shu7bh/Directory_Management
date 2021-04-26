#include "Directory.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Name Name;
struct Name
{
    char name[255];
    Name* next;
};

char** dirNames(char* absName)
{
    Name* names = (Name*) malloc (sizeof (Name));
    names->next = NULL;

    Name* node = names;

    int len = strlen(absName);
    char str[260];
    for (int i = 0; i < len; ++i)
        if (absName[i] != '/')
            strcat(str, (char*)&absName[i]);
        else
        {
            node->next = (Name*) malloc (sizeof (Name));
            strcpy(node->next->name, str);
        }
}

Alias* createAlias()
{
    Alias* node = (Alias*) malloc (sizeof(Alias));
    assert(node != NULL);
    
    node->dir = NULL;
    node->next = NULL;
    return node;
}

enum state addNewAlias(DirMgt* rootDir, Alias* aliasHead, char* name, char* absName)
{
    Alias* node = aliasHead;
    while (node->next)
        if (strcmp(node->next->name, name) == 0)
            return 1;
    
   if (!DirExists(rootDir, absName))
       return 2;

   return 0;
}
