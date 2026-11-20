#include <stdio.h>
#include <stdlib.h>

#define MAX_MEASURE 10

void load_data(float [], float [], float [], int []);
int display_menu(void);
void display_measurements(float [], float [], float [], int []);
int choose_sensor(void);
void add_measurement_to_sensor(float [], int *, const char *);

int main(void)
{   
    float temp_m[MAX_MEASURE];
    float volt_m[MAX_MEASURE];
    float lux_m[MAX_MEASURE];

    int count_of_each[3];

    load_data(temp_m, volt_m, lux_m, count_of_each);

    while(1)
    {
        switch(display_menu())
        {
            case 0:
                exit(EXIT_SUCCESS);
            case 1:
                switch (choose_sensor())
                {
                case 1:
                    add_measurement_to_sensor(temp_m, &count_of_each[0], "Temperature");
                    break;
                case 2:
                    add_measurement_to_sensor(volt_m, &count_of_each[1], "Voltage");
                    break;
                case 3:
                    add_measurement_to_sensor(lux_m, &count_of_each[2], "Lux");
                    break;
                default:
                    puts("Invalid parameter");
                    break;
                }
                break;
            case 2:
                display_measurements(temp_m, volt_m, lux_m, count_of_each);
                break;
            case 3:
                //code
                break;
            case -1:
                puts("please enter a valid parameter");
        }
    }
    return 0;
   
}

void add_measurement_to_sensor(float sensor[], int * count, const char sens_name[])
{
    printf("\n%s sensor last measurements: ", sens_name);
    int i;
    for(i=0;i<*count;i++)
        printf("%f\t", sensor[i]);
    float measurement;
    int yes_no;
    while(1)
    {
        if(*count < MAX_MEASURE)
        {
        puts("Do you want to add a new measurement (1 for yes/0 for no)");
        if(scanf("%d", &yes_no) != 1)
        {
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF)
                ;

            puts("Invalid input");
            continue;
        }
        if(yes_no == 0)
        {
            puts("Finished adding measurements, go to save option in main menu to save changes\n\n");
            break;
        }
        else if(yes_no == 1)
        {
            printf("\nValue: ");
            if(scanf("%f", &measurement) != 1)
            {
                int ch;
                while((ch = getchar()) != '\n' && ch != EOF)
                    ;
                puts("Invalid input");
                continue;
            }
            else
            {
                sensor[*count] = measurement;
                (*count)++;
                puts("\nMeasurement successfully added, New measurement list:\n");
                for(i=0;i<*count;i++)
                    printf("%f\t", sensor[i]);
            }
        }
        else
            puts("Invalid input");
        }
        else
        {
            puts("\n\n!!!!You have reached maximum amount of measurements\n");
            break;
        }
    }

}


int choose_sensor()
{
    printf("Choose the type of measurement\n1. Temperature\n2.Voltage\n3.Light intensity\n\nYour choice: ");
    int choice;
    if((scanf("%d", &choice)) != 1)
        {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            return -1;
        }
    else if(choice < 1 || choice > 3)
        {
            puts("invalid input, try again");
            return -1;
        }
    else
        return choice;
}

void display_measurements(float temp_m[], float volt_m[], float lux_m[], int count_of_each[])
{
    int i;
    printf("\nTemp sensor: ");
    for(i=0;i<count_of_each[0];i++)
        printf("%f\t", temp_m[i]);

    printf("\nVolt sensor: ");
    for(i=0;i<count_of_each[1];i++)
        printf("%f\t", volt_m[i]);

    printf("\nLux sensor: ");
    for(i=0;i<count_of_each[2];i++)
        printf("%f\t", lux_m[i]);
}

void load_data(float temp_m[], float volt_m[], float lux_m[], int count_of_each[])
{
    FILE *fp;
    if((fp = fopen("sensor_data.txt", "r")) == NULL)
    {
        fprintf(stderr, "Failure to open %s file\n", "sensor_data.txt");
        exit(EXIT_FAILURE);
    }
    int num_of_meas;    
    int loop = 1;
    int i;
    while(loop < 4)
    {
        
        if(fscanf(fp,"%d", &num_of_meas) != 1)
        {
            puts("error reading the text document");
            exit(EXIT_FAILURE);
        }
        if(num_of_meas<0 || num_of_meas>MAX_MEASURE)
        {
            puts("Cant store values in array");
            exit(EXIT_FAILURE);
        }
        for(i = 0; i<num_of_meas;i++)
            if(loop == 1)
            {
                if(fscanf(fp, "%f", &temp_m[i]) != 1)
                {
                    puts("error reading the text document");
                    exit(EXIT_FAILURE);
                }
            }
            else if(loop == 2)
            {
                if(fscanf(fp, "%f", &volt_m[i]) != 1)
                {
                    puts("error reading the text document");
                    exit(EXIT_FAILURE);
                }
            }
            else if(loop == 3)
            {
                if(fscanf(fp, "%f", &lux_m[i]) != 1)
                {
                    puts("error reading the text document");
                    exit(EXIT_FAILURE);
                }
            }
        count_of_each[loop-1] = num_of_meas;
        loop++;
    }

    fclose(fp);
}

int display_menu(void)
{
    printf("\n++++++++++++++++++++++++++++++++++++++++++++"
        "\n\nSENSOR DATA MEASUREMENT AND ANALYSIS PROGRAM\n\n"
        "++++++++++++++++++++++++++++++++++++++++++++++\n\n\n"
    "1.Add new measurement\n"
    "2. Display all measurements\n"
    "3. Calculate statistics\n"
    "4. Search measurements\n"
    "5. Sort measurements\n"
    "6. Delete measurement\n"
    "7. Save data to file\n"
    "8. Load data from file\n"
    "9. Generate report\n"
    "0. Exit\n\n"
    "Your choice:   \n");
    
    int choice;

    if((scanf("%d", &choice)) != 1)
        {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;

            return -1;
        }
    if(choice < 0 || choice > 9)
        {
            puts("invalid input, try again");
            return -1;
        }
    else    
        return choice;
}
