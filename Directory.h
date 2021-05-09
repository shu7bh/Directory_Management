#ifndef __DIRECTORY_H
#define __DIRECTORY_H

#include <stdbool.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

#define SIZE 255 // Maximum name of any given file or folder

// The main structure for the Directory management
typedef struct DirMgt DirMgt;
struct DirMgt
{
    char name[SIZE + 1]; // The name of the file or folder
    bool type;           // Whether it is a file or a folder
    DirMgt* firstChild;  // The pointer to the first child of a folder 
    DirMgt* sibling;     // The pointer to the sibling of the file or a folder to the other files or folders of the parent directory
    DirMgt* parent;      // The pointer to the parent folder
};

// Helper functions
DirMgt *makeFile();
DirMgt *makeFolder();
DirMgt* findDir(char* dirName, DirMgt* parentDir);
void goToRoot(DirMgt* ptr);

// Feature functions
void add(DirMgt *currentDir);
void list(DirMgt* cur);
bool move(DirMgt* root, DirMgt** current);
void find(DirMgt* cur, int showAll);
bool relativeDirectory(DirMgt** current);
void man(int check);

// Log functions
void printError(char str[100]);
void printMessage(char str[100]);

// The structure which stores the aliases
// Implemented it as a linked list
typedef struct Alias Alias;
struct Alias
{
    char name[SIZE + 1]; // The name of the alias
    DirMgt* dir;         // The directory the alias points to
    Alias* next;         // The pointer which points to the next alias
};

bool inputAlias(DirMgt* root, Alias* aliasHead); // To input alias from the user
Alias* createAlias(char* aliasName, DirMgt* dir); // To create an empty node of the DirMgt structure
bool addAlias(Alias* aliasHead, char* aliasName, DirMgt* dir); // Adds an alias if it is not already present
void Teleport(Alias* aliasHead, DirMgt** Current); // Teleports to the given alias

#endif
