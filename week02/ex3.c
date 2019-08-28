#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n = atoi(argv[1]);

    for (int i = 0; i < n; i++)
    {
        for (int j = n - i; j > 0; j--)
            putchar(' ');

        for (int j = i * 2 + 1; j > 0; j--)
            putchar('*');

        putchar('\r');
        putchar('\n');
    }

    return 0;
}
