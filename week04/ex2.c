#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int j = 0;
    for (int i = 0; i < 3; i++)
    {
        fork();
        j++;
    }
    printf("+");
    sleep(3);
    return 0;
}

// in the end there will be 8 '+' output,
// because calling fork() 3 times gives 2^3 = 8 threads
