#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int size = 256;
    char word[size];

    printf("Please, enter the string to reverse: ");

    fgets(word, size, stdin);
    size = strlen(word);

    printf("Result: ");

    for (int i = size - 1; i >= 0; i--)
        putchar(word[i]);

    return 0;
}
