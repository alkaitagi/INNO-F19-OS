#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = __INT_MAX__;
    float f = __FLT_MAX__;
    double d = __DBL_MAX__;

    printf("int - size: %lu | value: %d\r\n", sizeof(i), i);
    printf("float - size: %lu | value: %f\r\n", sizeof(f), f);
    printf("double - size: %lu | value: %f\r\n", sizeof(d), d);

    return 0;
}
