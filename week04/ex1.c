#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int n = 0;
    if (fork() == 0)
        printf("Hello from child [%d - %d]\r\n", getpid(), ++n);
    else
        printf("Hello from parent [%d - %d]\r\n", getpid(), ++n);
    return 0;
}
