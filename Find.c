#include "Directory.h"

// Helper function
// Traverses up the tree to go to the root directory
// The time complexity is O(h) where h is the height of the tree
void goToRoot(DirMgt* ptr)
{
    if (ptr->parent)
        goToRoot(ptr->parent);

    // Prints the files and folders in a different colour
    if (ptr->type)
        printf("\033[0;35m");
    else
        printf("\033[0;32m");
    printf("%s/", ptr->name);
    printf("\033[0;37m");
}

// A dfs type implementation for a tree
void dfs(DirMgt* cur, char* str, int* flag, int showAll)
{
    if (!cur)
        return;

    // A flag which basically tells whether to show all the possible matches
    // in the subdirectory or to just show the ones which match with the prefix
    if (showAll)
    {
        // To match all possible folder or files
        if (strstr(cur->name, str))
        {
            (*flag)++;
            goToRoot(cur);
            printf("\b \n");
        }
    }
    else
    {
        // To match only the prefix
        if (!strncmp(cur->name, str, strlen(str)))
        {
            (*flag)++;
            goToRoot(cur);
            printf("\b \n");
        }
    }

    dfs(cur->firstChild, str, flag, showAll); // To go to the first child
    dfs(cur->sibling, str, flag, showAll);    // To go the the next sibling
}

// Main function which is called when the find or the findall command is executed
void find(DirMgt* cur, int showAll)
{
    // The input of what it has to find
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

        // Handling error if the size is more than the possible file size
        if (i > SIZE)
        {
            printError("Error: No directories or files found.");
            while ((getchar()) != '\n');
            return;
        }
    }
    str[i] = 0;

    // Handling errors
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
    // Calls dfs to recursively search
    dfs(cur, str, &flag, showAll);

    // Pretty printing
    // To print a message if nothing is found with the string
    if (!flag)
    {
        char message[300];
        sprintf(message, "No directories or files found with %s.", str);
        printMessage(message);
    }
}
