#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char buff[100];
    char *current = NULL;
    char buff_size = 100;
    if (argc == 1)
    {
        current = getcwd(buff, buff_size);
        if ((current == buff) && (current != NULL))
        {
            printf("PWD: %s\n", buff);
        }
        else
        {
            printf("Falid\n");
        }
    }
    else
        return -1;
    return 0;
}
