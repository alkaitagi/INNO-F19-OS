#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(int argc, char const *argv[])
{
    const int N = 10;
    const int M = 10 * 1024 * 1024;
    int *arr[N];

    struct rusage usage;

    for (int i = 0; i < N; i++)
    {
        arr[i] = (int *)malloc(M);
        memset(arr[i], 0, M);

        getrusage(RUSAGE_SELF, &usage);
        printf("Memory usage: %ld\n", usage.ru_maxrss);
        sleep(1);
    }

    for (int i = 0; i < N; i++)
        free(arr[i]);

    return 0;
}
