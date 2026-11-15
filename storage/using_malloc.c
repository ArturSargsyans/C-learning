#include <stdio.h>
#include <stdlib.h>

int ask_for_number(void);

int count_positives(const int *, int);
int count_negatives(const int *, int);
int count_zeros(const int *, int);
void sum(const int *, int);
void largest(const int *, int);
void smallest(const int *, int);

int main(void)
{   
    int num = ask_for_number();
    int i;
    int *integers = (int *)malloc(num*sizeof(int));

    if(integers == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    printf("\nnow enter the %d values\n", num);
    for(i=0;i<num;i++)
    {
        scanf("%d", integers+i);
    }

    int *data = (int *)calloc(3, sizeof(int));
    if (data == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    
    data[0] = count_positives(integers, num);
    data[1] = count_negatives(integers, num);
    data[2] = count_zeros(integers, num);

    printf("in your integers array you have\n%d positive integers,\n%d negative integers,\n%d zeros\n", data[0], data[1],data[2]);

    sum(integers, num);
    largest(integers, num);
    smallest(integers,num);

    free(integers);
    free(data);

    return 0;
}


int ask_for_number(void)
{
    int num;
    printf("Enter how many integers do you want to store\n");
    scanf("%d", &num);
    
    return num;
}

int count_positives(const int * integers, int num)
{
    int i;
    int total = 0;
    for(i=0;i<num;i++)
    {
        if(integers[i]>0)
            total++;
    }

    return total;
}

int count_negatives(const int * integers, int num)
{
    int i;
    int total = 0;
    for(i=0;i<num;i++)
    {
        if(integers[i]<0)
            total++;
    }

    return total;
}

int count_zeros(const int * integers, int num)
{
    int i;
    int total = 0;
    for(i=0;i<num;i++)
    {
        if(integers[i] == 0)
            total++;
    }

    return total;
}

void sum(const int * integers, int num)
{
    int i;
    int sum = 0;
    for(i=0;i<num;i++)
        sum+=integers[i];
    printf("\nThe sum of your numbers is %d", sum);
}

void largest(const int * integers, int num)
{
    int i;
    int largest = integers[0];
    for(i=0;i<num;i++)
    {
        if(largest<integers[i])
            largest = integers[i];
    }

    printf("\nThe largest number is %d", largest);
}

void smallest(const int * integers, int num)
{
    int i;
    int smallest = integers[0];
    for(i=0;i<num;i++)
    {
        if(smallest>integers[i])
            smallest = integers[i];
    }

    printf("\nThe smallest number is %d\n", smallest);
}