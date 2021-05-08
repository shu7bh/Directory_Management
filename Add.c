#include "Directory.h"

void add(DirMgt *currentDir)
{
    char type[5];
    scanf(" %2c", type);

    int a = 0;
    if (!strcmp(type, "fi"));
    else if (!strcmp(type, "fo"))
        a = 1;
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

    char nameF[SIZE + 5];
    int i = 0;
    char ch;

    ch = getchar();
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
        while (currentDir->sibling != NULL)
        {
            currentDir = currentDir->sibling;
            if(strcmp(currentDir->name,nameF)==0)
            {
                printError("Error: Name already exists");
                return;
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
