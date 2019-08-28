#include <stdio.h>

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int main(int argc, char const *argv[])
{
    int a, b;

    printf("Enter the first number: ");
    scanf("%d", &a);

    printf("Enter the second number: ");
    scanf("%d", &b);

    swap(&a, &b);
    printf("Swapped result: %d %d", a, b);
    return 0;
}
