#include "Directory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Teleport(char alias[], Alias* aliasHead, DirMgt** Current)
{
    while(aliasHead != NULL && strcmp(aliasHead->name, alias) != 0)
    {
        aliasHead = aliasHead->next;
    }

    if(aliasHead == NULL)
    {
        printf("The alias that you entered does not exist");
        return;
    }

    *Current = aliasHead->location;
}