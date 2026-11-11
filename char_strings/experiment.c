#include <stdio.h>

#define MAXSIZE 80
#define MSG "INCONSIDERATE BUSINESS"

int main()
{
    const char *message = MSG;

    char array[MAXSIZE] = "GOOD MORNING";



    printf("the massage says: %s\n", message);
    printf("the massage says: %s", array);

    array[0] = 'N';
    printf("\nthe massage says: %s", array);
    //*(message+1) = 'M'; // incorrect


}