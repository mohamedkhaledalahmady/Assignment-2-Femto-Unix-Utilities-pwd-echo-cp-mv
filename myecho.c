#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define STDOUT 1
int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        for (int i = 1; i < argc; i++)
        {
            write(STDOUT, argv[i], strlen(argv[i]));
            write(STDOUT, " ", strlen(" "));
        }
        write(STDOUT, "\n", strlen("\n"));
    }
    else
        write(STDOUT, "nothing to echo\n", strlen("nothing to echo\n"));
    return 0;
}