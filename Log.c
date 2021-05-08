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

void mainCommands()
{
    printf("\nMain Commands\n");
    printf(" - Add\n - Move\n - Alias\n - Teleport\n - Find\n - Find All\n - List\n - Relative Directory\n - Clear\n - Help\n");
    printf("\n\tMan pages are available for each command. They can be run as\n\t$man <Command Name>\n");
}

void logAdd()
{
    printf("\nAdd\n");
    printf("\tTo add a file in the current directory\n\t$add fi <File Name>\n");
    printf("\n\tTo add a folder in the current directory\n\t$add fo <Folder Name>\n");
    printf("\nNote: File and Folder names should not have spaces\n");
}

void logMove()
{
    printf("\nMove\n");
    printf("\tTo move to a directory, give the complete path name to that directory\n");
    printf("\t$move <Complete Path Name>\n");
}

void logAlias()
{
    printf("\nAlias\n");
    printf("\tYou can add an alias to a directory in the following way\n");
    printf("\t$alias <Alias Name> <Complete Path Name>\n");
}

void logTeleport()
{
    printf("\nTeleport\n");
    printf("\tUsed to move to a directory which has an alias");
    printf("\t$teleport <Alias Name>\n");
}

void logFind()
{
    printf("\nFind\n");
    printf("\tTo Find through all the files and folders in a directory\n");
    printf("\t$find <String To Find>\n");
    printf("\nNote: Strings cannot have spaces in them\n");
}

void logFindAll()
{
    printf("\nFind All\n");
    printf("\tTo Find through all the files and folders in a directory which have \n\tany substring of theirs matching the string used to search it\n");
    printf("\t$findall <String To Find>\n");
    printf("\nNote: Strings cannot have spaces in them\n");
}

void logList()
{
    printf("\nList\n");
    printf("\tTo print all the files and folders in the current directory\n");
    printf("\t$ls\n");
}

void logRelativeDirectory()
{
    printf("\nRelative Directory\n");
    printf("\n\tTo change the directory using the relative path to the new directory\n");
    printf("\t$rd <Path Name>\n");
    printf("\nNote: '..' refers to the parent directory and '.' refers to the current directory path\n");
}

void logClear()
{
    printf("\nClear\n");
    printf("\tTo clear the terminal\n");
    printf("\t$clear\n");
}

void man(int check)
{
    printf("\n\n-----------------------------------------Man Page----------------------------------------\n");
    if (!check)
        mainCommands();
    else
    {
        char input[10];
        char ch;
        int flag = 0;
        int i = 0;

        while ((ch = getchar()))
        {
            if (ch == ' ')
            {
                flag = 1;
                break;
            }
            if (ch == '\n')
                break;
            else if (i > 8)
            {
                flag = 2;
                break;
            }
            else
                input[i++] = ch;
        }
        input[i] = 0;

        if (flag)
            printError("Error: Invalid man command.");
        else if (!strcmp(input, "add"))
            logAdd();
        else if (!strcmp(input, "move"))
            logMove();
        else if (!strcmp(input, "alias"))
            logAlias();
        else if (!strcmp(input, "teleport"))
            logTeleport();
        else if (!strcmp(input, "find"))
            logFind();
        else if (!strcmp(input, "findall"))
            logFindAll();
        else if (!strcmp(input, "ls"))
            logList();
        else if (!strcmp(input, "rd"))
            logRelativeDirectory();
        else if (!strcmp(input, "clear"))
            logClear();
        else
            printError("\nError: Man Commands does not exist");
    }
    printf("\n-------------------------------------End of Man Page-------------------------------------\n");
}
