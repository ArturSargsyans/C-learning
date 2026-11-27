#include <stdio.h>

#define LEN 20

struct names{
    char first[LEN];
    char last[LEN];
};

struct guy{
    struct names handle;
    char fav_food[LEN];
    char job[LEN];
    float income;
};


int main()
{
    struct guy fellow[2] = {
        {
            {"Tyler", "Durden"},
            "Tolma",
            "Embedded engineer",
            200000
        },
        {
            {"Marla", "Singer"},
            "Jingialov hac",
            "Svarchik",
            50000
        }
    };



    struct guy * him;
    struct guy *her;
    printf("The address of first and second struct %p\t%p\n", &fellow[0], &fellow[1]);
    him = &fellow[0];
    her = him+1;
    printf("The value of pointers %p\t%p\n", him, her);
    printf("%p\t%p\n", fellow, fellow+1);
    printf("%s\t%s\t%s\n", fellow[0].handle.first, him->handle.first, fellow->handle.first);

}