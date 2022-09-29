#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Invalid number of argumants\n");
        return -1;
    }
    int remove_return = remove(argv[2]); // if file exist return 0 else -1
    // printf("remove_return: %d\n", remove_return);

    int FD1 = open(argv[1], O_RDONLY);
    int FD2 = open(argv[2], O_CREAT | O_WRONLY);
    char buf[100];
    int state = 0;
    if (FD1 == -1)
    {
        printf("doesn't exist file\n");
        return -1;
    }
    int count = 0;
    int count1 = 0;
    int sum = 0;
    do
    {
        count = read(FD1, buf, 100);
        sum += count;
        write(FD2, buf, count);
        count1++;
    } while (count != 0); // end of file
    printf("Copy done!\n");
    int remove_return2 = remove(argv[1]); // if file exist return 0 else -1
    // printf("remove_return2: %d\n", remove_return2);
    // close(FD1);
    close(FD2);
    return 0;
}
