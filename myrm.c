#include <stdio.h>
int main(int argc, char *argv[])
{
    if (argc != 1)
        for (int i = 1; i < argc; i++)
        {
            if (remove(argv[i]) == -1)
                printf("%s Not Exist\n", argv[i]);
        }
    else
        printf("nothing to remove!\n");
    return 0;
}