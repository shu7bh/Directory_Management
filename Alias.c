#include "Directory.h"

bool inputAlias(DirMgt* root, Alias* aliasHead)
{
    char aliasName[SIZE + 5];

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
        
        aliasName[i++] = input;

        if (i > SIZE)
        {
            printError("Error: Invalid Alias Name.");
            while ((getchar()) != '\n');
            return 0;
        }
    }

    aliasName[i] = 0;

    if (error == 1)
    {
        printError("Error: Alias name cannot start with a space.");
        while ((getchar()) != '\n');
        return 0;
    }
    else if (error == 2)
    {
        printError("Error: Alias name cannot have a /.");
        while ((getchar()) != '\n');
        return 0;
    }

    DirMgt* cur = root;
    int ct = 0;

    int flag = 1;
    while (flag)
    {
        char str[SIZE];
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
            if (i > SIZE)
            {
                printError("Error: Invalid Name.");
                while ((getchar()) != '\n');
                return 0;
            }
        }
        str[i] = '\0';

        if (!ct++)
        {
            if (strcmp(root->name, str))
            {
                printError("Error: Directory does not exist.");
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
                printError("Error: Directory does not exist.");
                if (flag)
                    while ((getchar()) != '\n');
                return 0;
            }
        }
    }
    if (addAlias(aliasHead, aliasName, cur))
        printMessage("Added Alias");
    else
    {
        printError("Error: Alias already exists.");
        return 0;
    }
    return 1;
}

bool addAlias(Alias* aliasHead, char* aliasName, DirMgt* dir)
{
    Alias* alias = aliasHead;

    while (alias->next)
    {
        if (!strcmp(alias->next->name, aliasName))
            return 0;
        alias = alias->next;
    }

    alias->next = createAlias(aliasName, dir);
    return 1;
}

Alias* createAlias(char* aliasName, DirMgt* dir)
{
    Alias* node = (Alias*) malloc (sizeof(Alias));

    strcpy(node->name, aliasName);
    node->dir = dir;
    node->next = NULL;
    return node;
}
