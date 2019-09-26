#include <stdio.h>
#include <signal.h>

int catched = 0;

void sigkill(int sig_num)
{
    catched = 1;
    printf("\nCatched SIGKILL.\n");
}

void sigstop(int sig_num)
{
    catched = 1;
    printf("\nCatched SIGSTOP.\n");
}

void sigusr1(int sig_num)
{
    catched = 1;
    printf("\nCatched SIGUSR1.\n");
}

int main()
{
    signal(SIGKILL, sigkill);
    signal(SIGSTOP, sigstop);
    signal(SIGUSR1, sigusr1);

    while (!catched)
        ;

    return 0;
}

// There is no message on SIGKILL and SIGSTOP
// as those signals cannot be catched by design.
