#include "Directory.h"

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

void dfs(DirMgt* cur, char* str, int* flag, int showAll)
{
    if (!cur)
        return;

    if (showAll)
    {
        if (strstr(cur->name, str))
        {
            (*flag)++;
            goToRoot(cur);
            printf("\b \n");
        }
    }
    else
    {
        if (!strncmp(cur->name, str, strlen(str)))
        {
            (*flag)++;
            goToRoot(cur);
            printf("\b \n");
        }
    }

    dfs(cur->firstChild, str, flag, showAll);
    dfs(cur->sibling, str, flag, showAll);
}

void find(DirMgt* cur, int showAll)
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
    dfs(cur, str, &flag, showAll);

    if (!flag)
    {
        char message[300];
        sprintf(message, "No directories or files found with %s.", str);
        printMessage(message);
    }
}
