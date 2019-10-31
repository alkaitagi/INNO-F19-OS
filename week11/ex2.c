#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    const int LEN = 5;
    const char *text = "Hello";

    for (int i = 0; i < LEN; i++)
    {
        printf("%c", text[i]);
        sleep(1);
    }
    return 0;
}
