#include <stdio.h>

void report_count(void);
void accumulate(int);

int count = 0;

int main(void)
{
    int value;
    register int i;

    printf("Enter a positive integer: 0 to quit\n");

    while(scanf("%d", &value) == 1 && value>0)
    {
        ++count;
        for(i=value;i>=0;i--)
            accumulate(i);
        printf("Enter a positive integer: 0 to quit\n");
    }
    report_count();
}

void report_count(void)
{
    printf("\nLoop executed %d times\n", count);
}