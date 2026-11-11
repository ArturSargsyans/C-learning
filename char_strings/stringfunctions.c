#include <stdio.h>
#include <string.h>

#define SIZE 20

int main(void)
{
    char name[SIZE] = "AAB";
    char surname[SIZE] = "AA";

    printf("The lenght of the string is %d", strlen(name));
    // printf("\nnew string %s", strncat(name, surname, 4));

    printf("\n%d", strcmp(name, surname));
}