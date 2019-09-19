#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int const MAX_COUNT = 10;
int count = 0;

char prodWake = 1;
char consWake = 1;

void *producer()
{
    while (1)
        if (prodWake)
            if (count == MAX_COUNT)
                prodWake = 0;
            else if (++count == 1)
                consWake = 1;
}

void *consumer()
{
    while (1)
        if (consWake)
            if (!count)
                consWake = 0;
            else if (--count == MAX_COUNT - 1)
                prodWake = 1;
}

void *display()
{
    while (1)
        if (prodWake || consWake)
        {
            printf("Count: %d.\r\n", count);
            sleep(1);
        }
        else
        {
            printf("Deadlock!\r\n");
            return NULL;
        }
}

int main()
{
    pthread_t producer_id, consumer_id, display_id;

    pthread_create(&producer_id, NULL, producer, NULL);
    pthread_create(&consumer_id, NULL, consumer, NULL);
    pthread_create(&display_id, NULL, display, NULL);

    pthread_join(display_id, NULL);

    exit(0);
}
