#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define LEN 14

int main()
{
    char from[LEN] = "Hello, world!";
    char to[LEN];

    int p[2];

    if (pipe(p))
        exit(1);

    if (fork())
    {
        close(p[0]);
        write(p[1], from, LEN);
        close(p[1]);
    }
    else
    {
        close(p[1]);
        read(p[0], to, LEN);
        close(p[0]);
        printf("%s\n", to);
    }

    return 0;
}
