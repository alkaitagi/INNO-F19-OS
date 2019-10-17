#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int capacity;

int *storage;
unsigned int *usage;

int misses = 0;
int hits = 0;

int missing(int page)
{
    for (int i = 0; i < capacity; i++)
        if (storage[i] == page)
        {
            hits++;
            return 0;
        }

    misses++;
    return 1;
}

void update(int page)
{
    for (int i = 0; i < capacity; i++)
    {
        usage[i] >>= 1;
        if (storage[i] == page)
            usage[i] |= (1 << (sizeof(int) * 8 - 1));
    }
}

void replace(int page)
{
    int j = 0;
    for (int i = 1; i < capacity; i++)
    {
        if (storage[i] == -1)
        {
            j = i;
            break;
        }
        if (usage[i] < usage[j])
            j = i;
    }

    storage[j] = page;
    usage[j] = 0;
}

int main(int argc, char const *argv[])
{
    capacity = strtol(argv[1], NULL, 10);

    storage = calloc(capacity, sizeof(int));
    usage = calloc(capacity, sizeof(int));
    for (int i = 0; i < capacity; i++)
        storage[i] = -1;

    FILE *f = fopen("ex1.input", "r");
    int page;
    while (fscanf(f, "%d", &page) > 0)
    {
        if (missing(page))
            replace(page);
        update(page);
    }

    printf("total: %d\n", hits + misses);
    printf("hits: %d\n", hits);
    printf("faults: %d\n", misses);

    free(storage);
    free(usage);

    return 0;
}
