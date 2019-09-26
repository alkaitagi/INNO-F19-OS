#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int catched = 0;

int main()
{
    int pid = 0;
    if (pid = fork())
    {
        sleep(10);
        kill(pid, SIGTERM);
    }
    else
        while (1)
        {
            printf("I'm alive\n");
            sleep(1);
        }

    return 0;
}
