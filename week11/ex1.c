#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    const char *text = "This is a nice day";
    int fd = open("ex1.txt", O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
    size_t textsize = strlen(text) + 1;

    lseek(fd, textsize - 1, SEEK_SET);
    write(fd, "", 1);

    char *map = mmap(0, textsize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    for (size_t i = 0; i < textsize; i++)
        map[i] = text[i];

    msync(map, textsize, MS_SYNC);
    munmap(map, textsize);
    close(fd);

    return 0;
}
