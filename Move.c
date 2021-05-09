#include "Directory.h"

// The MOVE function takes the full path to a directory as input and moves the user from current directory to the directory provided by user
bool move(DirMgt* root, DirMgt** current)
{
    DirMgt* cur = root; //'cur' is the current temp directory location
    int ct = 0;

    int flag = 1;
    while (flag) //To take in the input of the path directory
    {
        char str[SIZE];
        char input;
        int i = 0;
        while ((input = getchar())) //Takes the input from user and checks for any errors
        {
            if (input == '/')
                break;
            else if (input == '\n')
            {
                flag = 0;
                break;
            }
            else if (input == ' ') //When user inputs more than required spaces in the input
            {
                printError("Error: Invalid command - spaces are not allowed.");
                while (getchar() != '\n');
                return 0;
            }
            else
                str[i++] = input;
            if (i > SIZE) //Directory name exceeds maximum size
            {
                printError("Error: Directory does not exist.");
                while (getchar() != '\n');
                return 0;
            }
        }
        str[i] = '\0';

        if (!str[0]) //To handle the case when user inputs '/' at the end of the directory
            break;
        if (!ct++)
        {
            if (strcmp(root->name, str)) //Invalid directory name as input
            {
                printError("Error: Directory does not exist.");
                if (flag)
                    while (getchar() != '\n');
                return 0;
            }
        }
        else
        {
            DirMgt* nextDir = findDir(str, cur); //Finds directory inputted by user
            if (nextDir)
                cur = nextDir; //Changes cur to the next directory
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
