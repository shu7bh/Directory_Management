#include "Directory.h"

void Teleport(Alias* aliasHead, DirMgt** Current)
{
    Alias* tempAliasHead = aliasHead;
    char aliasName[SIZE];
    char input;
    int i = 0;
    int error = 0;

    while ((input = getchar()))
    {
        if (input == ' ')
        {
            if (i == 0)
                error = 1;
            break;
        }
        else if (input == '/')
        {
            error = 2;
            break;
        }
        
        else if(input == '\n')
        {
            break;
        }
        aliasName[i++] = input;

        if (i > SIZE)
        {
            printError("Error: Invalid Alias Name.");
            while ((getchar()) != '\n');
            return;
        }
    }

    if (error == 1)
    {
        printError("Error: Alias name cannot start with a space.");
        while ((getchar()) != '\n');
        return;
    }
    else if (error == 2)
    {
        printError("Error: Alias name cannot have a /.");
        while ((getchar()) != '\n');
        return;
    }

    aliasName[i] = 0;
    // Searches in the linked list for the required alias name
    while(tempAliasHead != NULL && strcmp(tempAliasHead->name, aliasName) != 0)
    {
        tempAliasHead = tempAliasHead->next;
    }

    if(tempAliasHead == NULL)
    {
        printMessage("The alias that you entered does not exist");
        return;
    }

    *Current = tempAliasHead->dir;
}
