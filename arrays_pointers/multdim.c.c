#include <stdio.h>
#define ROWS 4
#define COLS 5

void sum_rows(int (*)[COLS], int);
void sum_cols(int [][COLS], int);
void sum_all(int (*ar)[COLS], int);

int main()
{
    int matrix[4][5] = {
        {1,2,3,4,5},
        {10,3,55,4},
        {2,2,2,2,2},
        {11,2,4,5,6}
    };

    sum_rows(matrix, ROWS);
    sum_cols(matrix, ROWS);
    sum_all(matrix, ROWS);
}

void sum_rows(int (*arr)[COLS], int rows)
{
    int r;
    int c;
    int total;

    for(r=0;r<rows;r++)
    {
        total = 0;
        for(c=0;c<COLS;c++)
            total = total + arr[r][c];
        printf("subtotal of row %d is %d\n", r, total);
    }
    printf("\n");
}

void sum_cols(int arr[][COLS], int rows)
{
    int r;
    int c;
    int total;

    for(c=0;c<COLS;c++)
    {
        total = 0;
        for(r=0;r<rows;r++)
            total = total + arr[r][c];
        printf("\nsubtotal of column %d is %d", c, total);
    }
}

void sum_all(int arr[][COLS], int rows)
{
    int r;
    int c;
    int total = 0;

    for(r=0;r<rows;r++)
    {
        for(c=0;c<COLS;c++)
            total+=arr[r][c];
    }
    printf("\nThe sum of all elements is    %d", total);
} 