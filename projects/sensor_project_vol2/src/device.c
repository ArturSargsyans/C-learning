#include <stdio.h>
#include "device.h"
#include "input.h"


void add_ID(DEVICE * pdev)
{
    while(1)
    {
        puts("\nEnter device ID");
        if(scanf("%d", &pdev->dev_id) != 1)
            {
                int ch;
                while((ch = getchar()) != '\n' && ch != EOF)
                    ;
                puts("Invalid input");
                continue;
            }
        else
            {
                clear_buffer();
                break;
            }
    }
}

void add_Name(DEVICE * pdev)
{
    puts("Enter device name");
    s_gets(pdev->name, MAXSIZE);
}

void set_status(DEVICE * pdev, DEV_STATUS state)
{
    pdev->status = state;
}

void set_type(DEVICE * pdev)
{
    puts("Which of the following type it is\n\n1. TEMP_SENSOR,\n2. VOLT_SENSOR,\n3. DIG_OUTPUT\n(Enter corresponding integer)");
    int choice;
    while(1)
    {
        if(scanf("%d", &choice) != 1)
        {
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF)
                ;
            puts("Invalid input, Enter corresponding integer");
            continue;
        }
        else
        {
            if(choice >= 1 && choice <=3)
            {
                pdev->type = (DEV_TYPE)(choice - 1);
                break;
            } 
            else
                puts("Invalid input, Enter corresponding integer");
        }
    }

}

void configure(DEVICE * pdev)
{
    while(1)
    {
        switch(pdev->type){
            case TEMP_SENSOR:
                puts("Enter minimum temperature");
                if(scanf("%f", &pdev->temp_range[0]) != 1)
                {
                    input_validate();
                    continue;
                }
                puts("Enter max temperature");
                if(scanf("%f", &pdev->temp_range[1]) != 1)
                {
                    input_validate();
                    continue;
                }
                break;
            case VOLT_SENSOR:
                puts("Enter maximum voltage");
                if(scanf("%f", &pdev->max_volt) != 1)
                {
                    input_validate();
                    continue;
                }
                break;
            case DIG_OUTPUT:
                puts("Enter GPIO pin");
                int pin;
                if(scanf("%d", &pin) !=1)
                {
                    input_validate();
                    continue;
                }
                pdev->pin_num = pin;
                break;  
        }
        break;
    }
    
}

void add_device(DEVICE dev_array[], int *pnum)
{
    char choice;
    do
    {
        if(*pnum < MAX_DEVICES)
        {
            add_ID(&dev_array[*pnum]);
            add_Name(&dev_array[*pnum]);
            set_status(&dev_array[*pnum], OFFLINE);
            set_type(&dev_array[*pnum]);
            configure(&dev_array[*pnum]);
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