#include "Directory.h"

// Teleports to a directory if the alias name is provided
// Checks through the alias linked list, and if found, changes the current directory to point to that directory
void Teleport(Alias* aliasHead, DirMgt** Current)
{
    Alias* tempAliasHead = aliasHead; // Temporary pointer to traverse through the alias linked list

    // To input the alias
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

        // Handling the error
        if (i > SIZE)
        {
            printError("Error: Invalid Alias Name.");
            while ((getchar()) != '\n');
            return;
        }
    }

    // Handling the error
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

    // If the alias is not present
    if(tempAliasHead == NULL)
    {
        printMessage("The alias that you entered does not exist");
        return;
    }

    // Changing the current directory to point to the alias' directory
    *Current = tempAliasHead->dir;
}
