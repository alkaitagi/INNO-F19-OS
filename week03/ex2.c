#include <stdio.h>

void bubble_sort(int *a, size_t n)
{
    for (int i = 1; i < n; i++)
        for (int j = i; j > 0; j--)
            if (a[j] < a[j - 1])
            {
                int b = a[j];
                a[j] = a[j - 1];
                a[j - 1] = b;
            }
}

void print_array(int *a, size_t n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\r\n");
}

int main()
{
    int a[] = {1, 6, 4, 8, 9, 5, 6, 3, 2};
    size_t n = sizeof(a) / sizeof(*a);

    bubble_sort(a, n);
    print_array(a, n);

    return 0;
}
