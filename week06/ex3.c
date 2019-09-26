#include <stdio.h>
#include <signal.h>

int catched = 0;

void sigintHandler(int sig_num)
{
    catched = 1;
    printf("\r\nPressed Ctrl+C. Terminating...\r\n");
}

int main()
{
    signal(SIGINT, sigintHandler);
    while (!catched)
        ;
    return 0;
}
