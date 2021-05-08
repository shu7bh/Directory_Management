#include "Directory.h"
#include <ctype.h>
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
            else if (input == ' ')
            {
                printError("Error: Invalid command - spaces are not allowed.");
                while (getchar() != '\n');
                return 0;
            }
            else
                str[i++] = input;
            if (i > SIZE)
            {
                printError("Error: Directory does not exist.");
                while (getchar() != '\n');
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
                printError("Error: Directory does not exist.");
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
        printf("\033[0;37m");
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
        printError("Error: Name already exists");
        return ;
    }
    if (currentDir != NULL)
    {
        while (currentDir->sibling != NULL)
        {
            currentDir = currentDir->sibling;
            if(strcmp(currentDir->name,nameF)==0)
            {
                printError("Error: Name already exists");
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
        printf("Added Alias\n");
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
    assert(node != NULL);

    strcpy(node->name, aliasName);
    node->dir = dir;
    node->next = NULL;
    return node;
}

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
        printf("The alias that you entered does not exist\n");
        return;
    }

    *Current = tempAliasHead->dir;
}

void goToRoot(DirMgt* ptr)
{
    if (ptr->parent)
        goToRoot(ptr->parent);
    if (ptr->type)
        printf("\033[0;35m");
    else
        printf("\033[0;32m");
    printf("%s/", ptr->name);
    printf("\033[0;37m");
}

void dfs(DirMgt* cur, char* str, int* flag)
{
    if (!cur)
        return;

    if (!strncmp(cur->name, str, strlen(str)))
    {
        (*flag)++;
        goToRoot(cur);
        printf("\b \n");
    }

    dfs(cur->firstChild, str, flag);
    dfs(cur->sibling, str, flag);
}

void find(DirMgt* cur)
{
    char str[SIZE + 5];
    char input;
    int i = 0;
    int error = 0;

    while ((input = getchar()))
    {
        if (input == ' ')
        {
            error = 1;
            break;
        }
        else if (input == '/')
        {
            error = 2;
            break;
        }

        else if(input == '\n')
            break;

        str[i++] = input;

        if (i > SIZE)
        {
            printError("Error: No directories or files found.");
            while ((getchar()) != '\n');
            return;
        }
    }
    str[i] = 0;
    if (error == 1)
    {
        printError("Error: No directories or files found.");
        while ((getchar()) != '\n');
        return;
    }
    else if (error == 2)
    {
        printError("Error: No directories or files found.");
        while ((getchar()) != '\n');
        return;
    }

    int flag = 0;
    dfs(cur, str, &flag);

    if (!flag)
        printf("No directories or files found with %s.\n", str);
}

void printError(char str[100])
{
    printf("\033[0;31m");
    printf("%s\n", str);
    printf("\033[0;37m");
}
