#include "Directory.h"

// To add a file or a folder in the current directory
void add(DirMgt *currentDir)
{
    // To input the type name
    // fi for file
    // fo for folder
    
    char type[5];

    // initialising it to 0, since it could have garbage values
    type[0] = type[1] = type[2] = 0;
    scanf(" %2c", type);

    int a = 0;
    // a = 0 -> file
    // a = 1 -> folder
    // Checking the file type
    if (!strcmp(type, "fi"));
    else if (!strcmp(type, "fo"))
        a = 1;
 
    // Handling the errors
    else if (type[1] == '\n')
    {
        printError("Error: Give a valid type.");
        return;
    }
    else
    {
        printError("Error: Give a valid type.");
        while ((getchar()) != '\n');
        return;
    }

    // To input the file or folder name
    char nameF[SIZE + 5];
    int i = 0;
    char ch;

    ch = getchar();
    
    // Handling errors where the user does not input the name correctly
    if (ch == '\n')
    {
        printError("Error: Give a file/folder name.");
        return;
    }
    if (ch != ' ')
    {
        printError("Error: Give a valid type.");
        while ((getchar()) != '\n');
        return;
    }

    // Getting the input
    int flag = 0;
    while ((ch = getchar()))
    {
        if (ch == ' ')
        {
            flag = 1;
            break;
        }
        if (ch == '\n')
            break;
        else if (i > SIZE - 1)
        {
            flag = 2;
            break;
        }
        else
            nameF[i++] = ch;
    }

    // Handling more errors
    if (flag == 1)
    {
        printError("Error: Trailing whitespaces are not allowed.");
        while ((getchar()) != '\n');
        return;
    }
    else if (flag == 2)
    {
        printError("Error: Name exceeds 255 characters.");
        while ((getchar()) != '\n');
        return;
    }
    if (i == 0)
    {
        printError("Error: Give a file/folder name.");
        return;
    }

    nameF[i] = 0;

    DirMgt *A;
    DirMgt *temp = currentDir;

    // Checking if the directory is empty or not
    // Adding a file or folder depending on the type
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
        return;
    }
    if (currentDir != NULL)
    {
        while (currentDir->sibling != NULL) // Traversing the directory to the end, verifying if it is a unique name
        {
            currentDir = currentDir->sibling;
            if(strcmp(currentDir->name,nameF)==0)
            {
                printError("Error: Name already exists");
                return;
            }

        }
    }

    // Creating and adding depending on the type
    if (a == 1)
    {
        A = makeFolder();
    }

    if (a == 0)
    {
        A = makeFile();
    }

    // Initialising the siblings, name, and the parent directory
    currentDir->sibling = A;
    strcpy(A->name, nameF);
    A->parent = temp;
}
