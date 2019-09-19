#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread(void *arg)
{
    printf("Thread #%d\r\n", *(int *)arg);
    return NULL;
}

int main()
{
    pthread_t thread_id;
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&thread_id, NULL, thread, &i);
        pthread_join(thread_id, NULL);
    }
    exit(0);
}
