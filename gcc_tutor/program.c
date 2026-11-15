#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    puts("Random number generator");

    time_t t;
    srand((unsigned) time(&t));
    int rNum = rand();

    double sr = sqrt(rNum);
    printf("Square Root of %d, is %lf\n", rNum, sr);

    return 0;

}
