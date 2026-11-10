#include <stdio.h>

#define ROWS 3
#define COLS 5

void store(double (*)[COLS], int);
void print_array(double (*)[COLS], int);
double average(const double [], int);
double average_all(const double (*)[COLS], int);
double the_largest(const double (*)[COLS], int);

int main(void)
{
    double arr[ROWS][COLS];
    store(arr, ROWS);
    print_array(arr, ROWS);

    int set_num = 0;
    while(set_num<ROWS)
    {
        printf("\nThe average of set %d:\t %lf\n", set_num+1, average(arr[set_num], COLS));
        set_num++;
    }

    printf("\n The overall average is %.4lf", average_all(arr, ROWS));
    printf("\n The largest number entered is %.4lf", the_largest(arr, ROWS));

    return 0;
}

void store(double arr[][COLS], int rows)
{
    int r;
    int c;

    for(r=0;r<rows;r++)
    {
        printf("\nEnter 5 elements of the set %d", r+1);
        for(c=0;c<COLS;c++)
        {
            printf("\n Element %d ", c+1);
            scanf("%lf", *(arr+r)+c);
        }
    }
}

void print_array(double arr[][COLS], int rows)
{
    int r;
    int c;

    for(r=0;r<rows;r++)
    {
        for(c=0;c<COLS;c++)
        {
            printf("%.4lf\t", arr[r][c]);
        }
        printf("\n\n");
    }
}

double average(const double arr[], int size)
{
    int i;
    double total=0;
    for(i=0;i<size;i++)
        total+=arr[i];
    return total/size;
}

double average_all(const double arr[][COLS], int rows)
{
    int r;
    int c;
    double total = 0;

    for(r=0;r<rows;r++)
        for(c=0;c<COLS;c++)
            total+=arr[r][c];

    //printf("\nTotal sum %.4lf", total);

    return total/(COLS*rows);
}

double the_largest(const double arr[][COLS], int rows)
{
    int r;
    int c;
    double largest = arr[0][0];

    for(r=0;r<rows;r++)
        for(c=0;c<COLS;c++)
        {
            if(largest<arr[r][c])
                largest = arr[r][c];
        }
    
    return largest;
}