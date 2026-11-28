#include <stdio.h>
#include <stdlib.h>
#include "device.h"

int menu(void);

int main(void)
{
    DEVICE dev_array[MAX_DEVICES];
    int num_of_devices = 0;
    
    while(1)
    {
        int choice = menu();

        switch (choice){
            case 0:
                exit(EXIT_SUCCESS);
            case 1: 
                add_device(dev_array, &num_of_devices);
                break;
            case 2:
                display_devices(dev_array, num_of_devices);
                break;
        }

    }

    return 0;
}


int menu()
{
    puts("\n\n###DEVICE MANAGER###\n\n");
    puts("Choose among following options, enter 0 to exit");
    printf("1.Add device\n2.Display device");
    int choice;
    scanf("%d", &choice);

    return choice;
}