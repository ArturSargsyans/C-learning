#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NAME 20
#define MAX_COLOR_NAME 10
char * s_gets(char * st, int n);

struct ciagerrete {
    char name[MAX_NAME];
    char color[MAX_COLOR_NAME];
    float nicotine;
    float price;
};

int main(void)
{
    struct ciagerrete my_cig;

    printf("Lets see what do you smoke\n");

    puts("Whats the name of your cigarrete");
    s_gets(my_cig.name, MAX_NAME);
    puts("Whats the color of its package");
    s_gets(my_cig.color, MAX_COLOR_NAME);
    puts("How much nicotine it has");
    scanf("%f", &my_cig.nicotine);
    puts("How much does it cost");
    scanf("%f", &my_cig.price);

    printf("You smoke %s, with %s color packaging, it has %f nicotine and costs %f drams", my_cig.name, my_cig.color, my_cig.nicotine, my_cig.price);

}

char * s_gets(char *st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}
