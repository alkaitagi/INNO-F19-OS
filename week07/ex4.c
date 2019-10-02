#include <stdio.h>
#include <stdlib.h>

void* my_realloc()
{
    
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        arr[i] = i;

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);

    return 0;
}
