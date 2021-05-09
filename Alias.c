#include "Directory.h"

// Takes the input for the alias name and the complete path to the directory it has to point to
// Calls addAlias() to add the alias if the above values are consistent
bool inputAlias(DirMgt* root, Alias* aliasHead)
{
    char aliasName[SIZE + 5];

    // To input the Alias name and handle the errors
    char input;
    int i = 0;
    int error = 0;

    while ((input = getchar())) // We take the input character by character
    {
        if (input == ' ')
        {
            if (i == 0)
                error = 1; // Alias name cannot start with a space
            break;
        }
        else if (input == '/')
        {
            error = 2; // Alias names cannot have a /
            break;
        }
        
        aliasName[i++] = input;

        if (i > SIZE) // To check if the name is within constraints
        {
            printError("Error: Invalid Alias Name.");
            while ((getchar()) != '\n'); // To clean the input buffer
            return 0;
        }
    }

    aliasName[i] = 0;

    // Handling the errors
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
    while (flag) // To take in the input for the path directory
    {
        char str[SIZE];
        char input;
        int i = 0;
        while ((input = getchar())) // The input is taken for each directory one by one
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

        if (!str[0]) // To handle the possibility of users adding a '/' after the path name
            break;

        // Handling the errors
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
            DirMgt* nextDir = findDir(str, cur); // To find if the directory exists in its subdirectory
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
    if (addAlias(aliasHead, aliasName, cur)) // To add the alias to the linked list
        printMessage("Added Alias");
    else // The alias already exists
    {
        printError("Error: Alias already exists.");
        return 0;
    }
    return 1;
}

bool addAlias(Alias* aliasHead, char* aliasName, DirMgt* dir) // To add the alias to the aliasHead linked list if it does not exist
{
    Alias* alias = aliasHead;

    while (alias->next) // Traversing the linked list
    {
        if (!strcmp(alias->next->name, aliasName))
            return 0;
        alias = alias->next;
    }

    alias->next = createAlias(aliasName, dir); // Creating the alias since it does not exist
    return 1;
}

Alias* createAlias(char* aliasName, DirMgt* dir) // Creates memory for the alias and initialises it
{
    Alias* node = (Alias*) malloc (sizeof(Alias));

    strcpy(node->name, aliasName);
    node->dir = dir; // Pointing the alias directly to the directory to which it has to change to 
    node->next = NULL;
    return node;
}
