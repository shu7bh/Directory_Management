#include <stdio.h>
#include <string.h>
#include "Directory.h"

int main()
{
    DirMgt* root = makeFolder();
    strcpy(root->name, "root");

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

        if (flag == 1)
        {
            printf("Error: Multi-line commands are not allowed.\n");
            continue;
        }
        if (flag == 2)
        {
            printf("Error: Invalid command\n");
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
                printf("Error: Give a valid type.\n");
                continue;
            }
            else
            {
                printf("Error: Give a valid type.\n");
                while ((getchar()) != '\n');
                continue;
            }

            char fileN[SIZE + 5];
            int i = 0;
            char ch;

            ch = getchar();
            if (ch == '\n')
            {
                printf("Error: Give a file/folder name.\n");
                continue;
            }
            if (ch != ' ')
            {
                printf("Error: Give a valid type.\n");
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
                printf("Error: Trailing whitespaces are not allowed.\n");
                while ((getchar()) != '\n');
                continue;
            }
            else if (flag == 2)
            {
                printf("Error: Name exceeds 255 characters.\n");
                while ((getchar()) != '\n');
                continue;
            }
            if (i == 0)
            {
                printf("Error: Give a file/folder name.\n");
                continue;
            }
            fileN[i] = 0;
            add(cur, fileN, a);
        }
        else if (!strcmp(input, "move"))
        {
            move(root, &cur);
        }
        else if (!strcmp(input, "teleport"));
        else if (!strcmp(input, "alias"));
        else if (!strcmp(input, "find"));
        else if (!strcmp(input, "quit"))
            break;
        else
        {
            printf("Error: Invalid Command.\n");
            while ((getchar()) != '\n');
        }
    }
    return 0;
}
