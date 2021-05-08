#include <stdio.h>
#include <string.h>
#include "Directory.h"

int main()
{
    Alias* aliasHead = createAlias("Dummy", NULL);
    DirMgt* root = makeFolder();
    strcpy(root->name, "root");

    printf("\033[0;37m");
    DirMgt* cur = root;

    man();

    char input[10];
    while (true)
    {
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

        if (flag == 1 && strcmp(input, "ls") && strcmp(input, "quit") && strcmp(input, "man"))
        {
            printError("Error: Multi-line commands are not allowed.");
            continue;
        }
        if (flag == 2)
        {
            printError("Error: Invalid command.");
            while ((getchar()) != '\n');
            continue;
        }
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
            find(cur);
        else if (!strcmp(input, "man"))
            man();
        else if (!strcmp(input, "rd"))
            relativeDirectory(&cur);
        else if (!strcmp(input, "quit"))
            break;
        else
        {
            printError("Error: Invalid Command.");
            while ((getchar()) != '\n');
        }
    }
    return 0;
}
