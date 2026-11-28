#include <stdio.h>
#include <string.h>
#include "input.h"


void clear_buffer(void)
{
    while (getchar() != '\n')
            continue;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            clear_buffer();
    }
    return ret_val;
}

void input_validate(void)
{
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF)
        ;
    puts("Invalid input, enter proper values");
}