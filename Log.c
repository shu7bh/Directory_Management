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
