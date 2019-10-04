#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    printf("\nStandard type sizes\n");

    //http://www.cplusplus.com/reference/cstdio/printf/
    //http://www.cplusplus.com/doc/tutorial/variables/
    printf("char: %d\n",sizeof(char));
    printf("short: %d\n",sizeof(short));
    printf("int: %d\n",sizeof(int));
    printf("long: %d\n",sizeof(long));
    printf("float: %d\n",sizeof(float));
    printf("double: %d\n",sizeof(double));

    //be aware of signed and unsigned variable types:
    unsigned char c = UCHAR_MAX;
    signed char d= UCHAR_MAX;

    printf("\nsigned /unsigned issues\n");
    printf("unsgined: %d, signed: %d\n", c, d);

    printf("\nSimple for loop\n");

    //a for loop
    for(int i=0;i<10;i++)
    {
        printf("Hello, World! %d\n",i);
    }

    printf("\nfor loop with if/else\n");
    // if else
    for(int i=1;i<101;i++)
    {
        if(i%10 == 0)
        {
            printf("Hello, World! %d\n",i);
        }
        else
        {
            printf(".",i);
        }
    }

    printf("\nfor loop with conditional break\n");
    //break-ing out of for loops
    for(int i=0;i<101;i++)
    {
        if (i > 3)
        {
            break;
        }
        printf("Hello, World! %d\n", i);
    }

    printf("\nwhile loop\n");
    //while .. do
    int counter = 10;
    while(counter > 0)
    {
        printf("Counter1 value: %d\n",counter);
        counter--;
    }

    printf("\ndo while loop\n");
    counter = 10;
    do
    {
        printf("Counter2 value: %d\n",counter);
        counter--;
    }while(counter != 0);

    printf("\nswitch & rand\n");
    for(int i=0;i<10;i++)
    {
        int result = rand()%4; // random number from 0 to 3

        printf("value: %d ..",result);

        switch(result)
        {
            case 0:
                printf("case 0\n");
                break;

            case 1:
                printf("case 1\n");
                //the lack of a break here will make control drop into the next case statement ...
            case 2:
                printf("case 2\n");
                break;
            default:
                printf("value: %d not handled in case\n",result);
        }
    }

    return 0;
}