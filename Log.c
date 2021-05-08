#include "Directory.h"

void printError(char str[100])
{
    printf("\033[0;31m");
    printf("%s\n", str);
    printf("\033[0;37m");
}

void printMessage(char str[100])
{
    printf("\033[0;36m");
    printf("%s\n", str);
    printf("\033[0;37m");
}

void man()
{
    printf("\n\n-----------------------------------------Man Page----------------------------------------\n\n");
    printf("Main Commands\n");
    printf(" - Add\n - Move\n - Alias\n - Teleport\n - Find\n - List\n - Help\n");
    printf("\n\nAdd\n");
    printf("\tTo add a file in the current directory\n\t$add fi <File Name>\n");
    printf("\n\tTo add a folder in the current directory\n\t$add fo <Folder Name>\n");
    printf("\nNote: File and Folder names should not have spaces\n");
    printf("\n\nMove\n");
    printf("\tTo move to a directory, give the complete path name to that directory\n");
    printf("\t$move <Complete Path Name>\n");
    printf("\n\nAlias\n");
    printf("\tYou can add an alias to a directory in the following way\n");
    printf("\t$alias <Alias Name> <Complete Path Name>\n");
    printf("\n\nTeleport\n");
    printf("\tUsed to move to a directory which has an alias");
    printf("\t$teleport <Alias Name>\n");
    printf("\n\nFind\n");
    printf("\tTo Find through all the files and folders in a directory\n");
    printf("\t$find <String To Find>\n");
    printf("\n\nList\n");
    printf("\tTo print all the files and folders in the current directory\n");
    printf("\t$ls");
    printf("\n\nHelp\n");
    printf("\tHelp to run commands\n");
    printf("\t$man\n");
    printf("\n-----------------------------------------End of Man Page-----------------------------------------\n");
}
