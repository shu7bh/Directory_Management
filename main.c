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

        if (flag == 1 && strcmp(input, "ls") && strcmp(input, "quit"))
        {
            printError("Error: Multi-line commands are not allowe");
            continue;
        }
        if (flag == 2)
        {
            printError("Error: Invalid command");
            while ((getchar()) != '\n');
            continue;
        }
        if (!strcmp(input, "add"))
        {
            char type[5];
            scanf(" %2c", type);

            int a = 0;
            if (!strcmp(type, "fi"));
            else if (!strcmp(type, "fo"))
                a = 1;
            else if (type[1] == '\n')
            {
                printError("Error: Give a valid type.");
                continue;
            }
            else
            {
                printError("Error: Give a valid type.");
                while ((getchar()) != '\n');
                continue;
            }

            char fileN[SIZE + 5];
            int i = 0;
            char ch;

            ch = getchar();
            if (ch == '\n')
            {
                printError("Error: Give a file/folder name.");
                continue;
            }
            if (ch != ' ')
            {
                printError("Error: Give a valid type.");
                while ((getchar()) != '\n');
                continue;
            }

            int flag = 0;
            while ((ch = getchar()))
            {
                if (ch == ' ')
                {
                    flag = 1;
                    break;
                }
                if (ch == '\n')
                    break;
                else if (i > SIZE - 1)
                {
                    flag = 2;
                    break;
                }
                else
                    fileN[i++] = ch;
            }

            if (flag == 1)
            {
                printError("Error: Trailing whitespaces are not allowed.");
                while ((getchar()) != '\n');
                continue;
            }
            else if (flag == 2)
            {
                printError("Error: Name exceeds 255 characters.");
                while ((getchar()) != '\n');
                continue;
            }
            if (i == 0)
            {
                printError("Error: Give a file/folder name.");
                continue;
            }
            fileN[i] = 0;
            add(cur, fileN, a);
        }
        else if (!strcmp(input, "move"))
        {
            move(root, &cur);
        }
        else if (!strcmp(input, "ls"))
        {
            list(cur);
        }
        else if (!strcmp(input, "teleport"))
        {
            Teleport(aliasHead, &cur);
        }
        else if (!strcmp(input, "alias"))
        {
            inputAlias(root, aliasHead);
        }
        else if (!strcmp(input, "find"))
        {
            find(cur);
        }
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
