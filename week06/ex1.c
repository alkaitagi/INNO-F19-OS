#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEN 14

int main()
{
    char from[LEN] = "Hello, world!";
    char to[LEN];

    int p[2];

    if (pipe(p))
        exit(1);

    write(p[1], from, LEN);
    read(p[0], to, LEN);

    printf("%s\n", to);

    return 0;
}
