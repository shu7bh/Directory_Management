#include "Directory.h"

// Finds if a directory is present as the immediate subdirectory of the parent directory
// The finding is done through a simple name search since the names are distinct in a given directory
DirMgt* findDir(char* dirName, DirMgt* parentDir)
{
    DirMgt* dir = parentDir->firstChild;

    while (dir && strcmp(dirName, dir->name))
        dir = dir->sibling; 

    if (dir)
        return (dir->type)? dir : NULL;
    return NULL;
}

// Makes a file
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

// Makes a folder
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

// Lists all the files and directories present in a directory
// It is colour coded. Purple represents folders, green represents files
void list(DirMgt* cur)
{
    DirMgt* temp = cur->firstChild;

    while (temp) // Used to iterate through all the siblings
    {
        if (temp->type)
            printf("\033[0;35m"); // This printf function is used to change the colours
        else
            printf("\033[0;32m");
        printf("%s   ", temp->name);
        printf("\033[0;37m");
        temp = temp->sibling;
    }
    printf("\n");
}
