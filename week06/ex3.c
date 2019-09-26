#include <stdio.h>
#include <signal.h>

int catched = 0;

void sigint(int sig_num)
{
    catched = 1;
    printf("\nPressed Ctrl+C. Terminating...\n");
}

int main()
{
    signal(SIGINT, sigint);
    while (!catched)
        ;
    return 0;
}
