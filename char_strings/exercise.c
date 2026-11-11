#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main(void)
{
    char first_name[20];
    char last_name[20];
    char full_name[40];

    puts("Enter your first name:");
    scanf("%19s", first_name);
    puts("Enter your last name:");
    scanf("%19s", last_name);
    first_name[0] = toupper(first_name[0]);
    last_name[0] = toupper(last_name[0]);

    strcpy(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);

    printf("Your full name is %s", full_name);

    printf("\nName length is %zu\n", strlen(full_name));

    if(strcmp(first_name, "Varazdat") == 0)
        puts("Your name is Varazdat");
    else
        puts("Your name is not Varazdat");

}