#include "Directory.h"

// To move to the relative directory
// Complete path doesn't work with this feature
bool relativeDirectory(DirMgt** current)
{
    DirMgt* cur = *current;

    int flag = 1; // To check if user has completed entering the relative path for the directory
    while (flag)
    {
        // To input the relative directory one directory at a time
        char str[SIZE];
        char input;
        int i = 0;
        while ((input = getchar()))
        {
            if (input == '/')
                break;
            else if (input == '\n')
            {
                flag = 0;
                break;
            }
            else if (input == ' ')
            {
                printError("Error: Invalid command - spaces are not allowed.");
                while (getchar() != '\n');
                return 0;
            }
            else
                str[i++] = input;
            if (i > SIZE)
            {
                printError("Error: Directory does not exist.");
                while (getchar() != '\n');
                return 0;
            }
        }
        str[i] = '\0';

        if (!str[0]) // To handle if the user enters a / at the end of the path
            break;
        if (!strcmp(str, "..")) // To go the parent directory
        {
            if (cur->parent)
                cur = cur->parent;
            else // If you are already on the root directory
            {
                printError("Error: Directory does not exist.");
                if (flag)
                    while (getchar() != '\n');
                return 0;
            }
            continue;
        }
        else if (!strcmp(str, ".")) // Since we are already in the current directory, it does not do anything
            continue;
        DirMgt* nextDir = findDir(str, cur); // Checks if the directory is present
        if (nextDir)
            cur = nextDir;
        else  // The directory is not present
        {
            printError("Error: Directory does not exist.");
            if (flag)
                while (getchar() != '\n');
            return 0;
        }
    }

    *current = cur; // Changes where the directory points to
    return 1;
}
