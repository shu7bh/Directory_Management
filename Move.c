#include "Directory.h"

bool move(DirMgt* root, DirMgt** current)
{
    DirMgt* cur = root;
    int ct = 0;

    int flag = 1;
    while (flag)
    {
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

        if (!ct++)
        {
            if (strcmp(root->name, str))
            {
                printError("Error: Directory does not exist.");
                if (flag)
                    while (getchar() != '\n');
                return 0;
            }
        }
        else
        {
            DirMgt* nextDir = findDir(str, cur);
            if (nextDir)
                cur = nextDir;
            else 
            {
                printError("Error: Directory does not exist.");
                if (flag)
                    while (getchar() != '\n');
                return 0;
            }
        }
    }

    *current = cur;
    return 1;
}
