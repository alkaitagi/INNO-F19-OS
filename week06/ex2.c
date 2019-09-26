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
        write(p[1], from, LEN);
        wait(NULL);
    }
    else
    {
        while (read(p[0], to, LEN) <= 0)
            ;
        printf("%s\n", to);
    }

    return 0;
}
