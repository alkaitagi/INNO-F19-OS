#include <stdlib.h>
#include <stdio.h>

#define LEN 256

int main()
{
    char line[LEN];
    while (1)
    {
        fgets(line, LEN, stdin);
        system(line);
    }
    return 0;
}
