#include <stdio.h>

int main()
{
    int a[10];

    for(int i=0;i<10;i++)
    {
        a[i] = i;
    }

    for(int i=0;i<10;i++)
    {
        printf("0x%08x - %d\n", &a[i], a[i]);
    }

    printf("\npointers ...\n");
    int *p = &a;

    for(int i=0;i<10;i++)
    {
        printf("0x%08x - %d\n",p, *p);

        p++;
    }

    printf("\nAfter the array\n");
    printf("0x%08x - %d\n",p, *p);


    printf("Hello, World!\n");
    return 0;
}