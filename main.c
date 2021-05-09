#include <stdio.h>
#include <string.h>
#include "Directory.h"

int main()
{
    system("clear");
    Alias* aliasHead = createAlias("Dummy", NULL); // To create the alias linked list
    DirMgt* root = makeFolder(); // To create the tree 
    strcpy(root->name, "root"); // To initialise the root directory with the name 'root'

    printf("\033[0;37m");
    DirMgt* cur = root;

    man(0); // To give the main man commands at the start

    char input[10];
    while (true)
    {
        // To print the absolute path for the user to easily see at which directory they are in
        goToRoot(cur);
        printf("\033[1;92m");
        printf("\b$ ");
        printf("\033[0;37m");
        
        // To input the command
        char ch;
        int flag = 0;
        int i = 0;

        while ((ch = getchar()))
        {
            if (ch == ' ')
                break;
            if (ch == '\n')
            {
                flag = 1;
                break;
            }
            else if (i > 8)
            {
                flag = 2;
                break;
            }
            else
                input[i++] = ch;
        }
        input[i] = 0;

        // To handle errors
        //
        // This if condition will only work if the user has entered a new line after giving a command which is not a single command
        if (flag == 1 && strcmp(input, "ls") && strcmp(input, "quit") && strcmp(input, "man") && strcmp(input, "clear"))
        {
            printError("Error: Multi-line commands are not allowed.");
            continue;
        }
        
        // A command is directly filtered out if it exceeds the maximum size
        if (flag == 2)
        {
            printError("Error: Invalid command.");
            while ((getchar()) != '\n');
            continue;
        }

        // To call the specific functions depending on the command

        if (!strcmp(input, "add"))
            add(cur);
        else if (!strcmp(input, "move"))
            move(root, &cur);
        else if (!strcmp(input, "ls"))
            list(cur);
        else if (!strcmp(input, "teleport"))
            Teleport(aliasHead, &cur);
        else if (!strcmp(input, "alias"))
            inputAlias(root, aliasHead);
        else if (!strcmp(input, "find"))
            find(cur, 0);
        else if (!strcmp(input, "findall"))
            find(cur, 1);
        else if (!strcmp(input, "man"))
            man(!flag); // The flag checks whether there is more input to be read
        else if (!strcmp(input, "rd"))
            relativeDirectory(&cur);
        else if (!strcmp(input, "quit"))
            break;
        else if (!strcmp(input, "clear")) // To clear the screen
            system("clear");
        else // To handle any invalid commmand
        {
            printError("Error: Invalid Command.");
            while ((getchar()) != '\n');
        }
    }
    return 0;
}
