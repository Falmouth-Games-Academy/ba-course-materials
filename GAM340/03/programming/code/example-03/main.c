#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

char* convert_string_to_as(char *str)
{
    char *p = str;

    while(*p != NULL)
    {
        *p = 'a';
        p++;
    }

    return str;
}

int main()
{
    //http://www.cplusplus.com/reference/cctype/?kw=ctype.h
    //http://www.cplusplus.com/reference/cstring/?kw=string.h

    if(FALSE)
    {
        convert_string_to_as("my name is adam");
    }

    if(FALSE)
    {
        char *myString = "my name is adam";

        char *p = myString;

        while (*p != NULL)
        {
            *p = 'a';
            p++;
        }

        printf("%s\n", myString);
    }


    {
        char myString[] = "my name is adam";

        char *p = myString;

        while (*p != NULL)
        {
            *p = 'a';
            p++;
        }

        printf("%s\n", myString);
    }

    {
        char *myString = "my name is adam";

        char myOtherString[255];

        strcpy(myOtherString, myString);

        char *p = myOtherString;

        while (*p != NULL)
        {
            *p = 'a';
            p++;
        }

        printf("%s\n", myOtherString);
    }

    {
        char *myString = "my name is adam";

        char *myOtherString = malloc(sizeof(char) * (strlen(myString) + 1));

        strcpy(myOtherString, myString);

        char *p = myOtherString;

        while (*p != NULL)
        {
            *p = 'a';
            p++;
        }

        printf("%s\n", myOtherString);

        free(myOtherString);
    }

    return 0;
}