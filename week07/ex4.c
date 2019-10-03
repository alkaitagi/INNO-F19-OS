#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_realloc(void *ptr, size_t old_size, size_t new_size)
{
    if (ptr == NULL)
        return malloc(new_size);
    else if (!new_size)
    {
        free(ptr);
        return NULL;
    }
    else
    {
        int min_size = new_size < old_size ? new_size : old_size;
        void *buff = malloc(min_size);
        memcpy(buff, ptr, min_size);
        free(ptr);
        return buff;
    }
}

int main(int argc, char const *argv[])
{
    const int size = 5, new_size = 10;
    int *arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        arr[i] = i;

    arr = (int *)my_realloc(arr, size * sizeof(int), new_size * sizeof(int));

    for (int i = 0; i < new_size; i++)
        printf("%d: %d\n", i, arr[i]);

    free(arr);
    return 0;
}
