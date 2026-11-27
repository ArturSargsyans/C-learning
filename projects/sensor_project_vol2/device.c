#include <stdio.h>
#include "device.h"
#include "input.h"

void display_devices(DEVICE dev_array[], int num)
{
    int i;
    if(num == 0)
        puts("No devices");
    else
    {
        for(i=0; i<num; i++)
        {
            printf("\n\nDevice %d\nID %d\nName %s\n", i+1, dev_array[i].dev_id, dev_array[i].name);
            if(dev_array[i].status == 0)
                puts("Status: OFFLINE");
            else if(dev_array[i].status == 1)
                puts("Status: ONLINE");
            switch(dev_array[i].type){
                case TEMP_SENSOR:
                    puts("It is a temperature sensor");
                    printf("Temperature range from %f to %f\n", dev_array[i].temp_range[0], dev_array[i].temp_range[1]);
                    break;
                case VOLT_SENSOR:
                    puts("It is a voltage sensor");
                    printf("Maximum voltage  - %f\n", dev_array[i].max_volt);
                    break;
                case DIG_OUTPUT:
                    puts("It is a digital output");
                    printf("Pin number - %d\n", dev_array[i].pin_num);
                    break;
            }          
        }
    }
}

void add_device(DEVICE dev_array[], int *pnum)
{
    char choice;
    do
    {
        
        if(*pnum < MAX_DEVICES)
        {
            puts("Enter device id");
            scanf("%d", &dev_array[*pnum].dev_id);
            clear_buffer();
            puts("Enter device name");
            s_gets(dev_array[*pnum].name, MAXSIZE);

            int choice;
            puts("Is device 1. ONLINE\n or 2. OFFLINE");

            scanf("%d", &choice);
            
            if(choice == 1 || choice == 2)
                dev_array[*pnum].status = (DEV_STATUS)(choice - 1);
            else
                puts("Invalid input");

            puts("Which of the following type it is\n1. TEMP_SENSOR,\n2. VOLT_SENSOR,\n3. DIG_OUTPUT\n (Enter corresponding integer)");
            
            scanf("%d", &choice);
            if(choice >= 1 && choice <=3)
                dev_array[*pnum].type = (DEV_TYPE)(choice - 1);
            else
                puts("Invalid input");
            switch((DEV_TYPE)(choice-1)){
                case TEMP_SENSOR:
                    puts("Enter min temp");
                    scanf("%f", &dev_array[*pnum].temp_range[0]);
                    puts("Enter max temp\n");
                    scanf("%f", &dev_array[*pnum].temp_range[1]);
                    break;
                case VOLT_SENSOR:
                    puts("Enter max voltage");
                    scanf("%f", &dev_array[*pnum].max_volt);
                    break;
                case DIG_OUTPUT:
                    puts("Enter GPIO pin");
                    scanf("%d", &dev_array[*pnum].pin_num);                
            }
            
            

            clear_buffer();

            (*pnum)++;
        }

        else
        {
            puts("You cant add more than 5 devices");
            break;
        }

        puts("Do you want to add another device? (y/n)");
        scanf(" %c", &choice);
        clear_buffer();
    } while(choice == 'y');
}