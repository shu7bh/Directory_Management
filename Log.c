#include "Directory.h"

// Log.c file is to just print the messages and errors prettily
//
// The colour for an error is orange/red
// The colour for a message is light blue

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

// The main commands which get printed at the start and also when the user enters man
void mainCommands()
{
    printf("\nMain Commands\n");
    printf(" - Add\t\t\t\t<add>\n - Move\t\t\t\t<move>\n - Alias\t\t\t<alias>\n - Teleport\t\t\t<teleport>\n - Find\t\t\t\t<find>\n - Find All\t\t\t<findall>\n - List\t\t\t\t<ls>\n - Relative Directory\t\t<rd>\n - Clear\t\t\t<clear>\n");
    printf("\n\tTo get the man page\n\t$man\n");
    printf("\n\tTo get the man page for a specific command\n\t$man <Command Name>\n");
}

// The following are the man commands for the specific command

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

// The man command which gets called by the main function when man is typed
void man(int check)
{
    printf("\n\n-----------------------------------------Man Page----------------------------------------\n");
    if (!check)
        mainCommands();
    else
    {
        // To take the input if the user is typing a specific man command
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

        // To call the specific function which the user enters
        // And to handle the errors
        
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
