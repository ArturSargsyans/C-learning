#include <stdio.h>
#include <stdlib.h>


struct sensor_data{
    int sensor_id;
    int count;
    float measurements[];
};

int main()
{
    struct sensor_data *ptr;

    ptr = malloc(sizeof(struct sensor_data) + 10*sizeof(float));
    if(ptr == NULL)
    {
        puts("Memory allocation failed");
        return 1;
    }
    ptr->sensor_id = 5;
    ptr->count = 10;
    ptr->measurements[0] = 12.5;
    ptr->measurements[9] = 24.7;

    printf("sensor id %d\ncount %d\n1st measurement %f\n10th measurement %f\n", 
    ptr->sensor_id, ptr->count, ptr->measurements[0],ptr->measurements[9]);

    free(ptr);

    return 0;
    
}