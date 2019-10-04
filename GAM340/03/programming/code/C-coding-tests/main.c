#include <stdio.h>

#define ARRAY_LENGTH(x) (sizeof(x)/sizeof(x[0]))

// print the biggest number in the array, it should be 32
void biggest_number_in_array()
{
    int list[] = {1,5,4,7,2,7,3,32,8,4};

    for(int i=0;i<ARRAY_LENGTH(list);i++)
    {
        printf("%d ",list[i]);
    }

    printf("%\n");
}

// print the second biggest number in the array, it should be 31
void second_biggest_number_in_array()
{
    int list[] = {31,5,4,7,2,7,3,32,8,4};
}

//Reverse the order of the characters using pointers
void string_reverse()
{
    char str[] = "abcdefghijklmnopqrstuvwxyz";
}

//Replace uppercase characters with their lowercase equivalents
void upper_to_lower_case()
{
    char str[] = "The Quick Brown Fox Jumps Over The Lazy Dog";
}

//Remove the uppercase characters from the string
void remove_upper_case()
{
    char str[] = "The Quick Brown Fox Jumps Over The Lazy Dog";
}

//find the most popular vowel in the string
void most_popular_vowel()
{
    char *str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
}

//print this string so that each word appears on a new line
void print_as_words()
{
    char *str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
}

//print this string so that each word appears on a new line, but each word is reversed
void print_as_reversed_words()
{
    char *str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
}

//see which of these test_cases are palidromes.
void is_palindrome()
{
    char *test_cases[] = {"aaa",
                        "aab",
                        "abba",
                        "Mr. Owl ate my metal worm",
                        "Do geese see God?",
                        "Was it a car or a cat I saw?",
                        "Murder for a jar of red rum",
                        "Go hang a salami, I'm a lasagna hog",
                        "Rats live on no evil star",
                        "Live on time, emit no evil",
                        "Step on no pets"};
    for(int i=0;i<ARRAY_LENGTH(test_cases);i++)
    {
        printf("%s\n",test_cases[i]);
    }

}


void main()
{
    biggest_number_in_array();
    second_biggest_number_in_array();
    string_reverse();
    upper_to_lower_case();
    remove_upper_case();
    most_popular_vowel();
    print_as_words();
    print_as_reversed_words();
    is_palindrome();
}

