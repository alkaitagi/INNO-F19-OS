#include <stdio.h>
#include <stdlib.h>

// print new line
void pnl()
{
    putchar('\r');
    putchar('\n');
}

void printTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - i; j > 0; j--)
            putchar(' ');

        for (int j = i * 2 + 1; j > 0; j--)
            putchar('*');

        pnl();
    }
}

void printSquare(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            putchar('*');

        pnl();
    }
}

void printPythagor(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
            putchar('*');

        pnl();
    }
}

void printPyramid(int n)
{
    int h = n / 2;

    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j <= i; j++)
            putchar('*');

        pnl();
    }

    for (int i = h - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
            putchar('*');

        pnl();
    }
}

int main(int argc, char const *argv[])
{
    // the first number is n - size,
    // and the second number is print type:
    // 1 - triangle,
    // 2 - square triangle,
    // 3 - pyramid,
    // 4 - square

    int n = atoi(argv[1]);
    int t = atoi(argv[2]);

    if (t == 0)
        printTriangle(n);
    else if (t == 1)
        printPythagor(n);
    else if (t == 2)
        printPyramid(n);
    else if (t == 3)
        printSquare(n);
    else
        printf("Wrong type specified.");

    return 0;
}
