#include <stdio.h>
#include <stdlib.h>

#define MAX_MEASURE 10

void display_header(void);
int display_menu(void);
void display_sensor(float [], int *, const char []);
void display_all_measurements(float [], float [], float [], int []);

void load_data(float [], float [], float [], int []);
void save_data(float [], float [], float [], int []);

int choose_sensor(void);
void add_measurement_to_sensor(float [], int *, const char *);
void delete_measurement_from_sensor(float [], int *, const char *);
void statistics_for_sensor(float [], float [], int *, const char *);

void generate_report(float [], float [], float [], float [], float [], float [], int []);


int main(void)
{   
    float temp_m[MAX_MEASURE];
    float volt_m[MAX_MEASURE];
    float lux_m[MAX_MEASURE];

    float temp_stat[4];
    float volt_stat[4];
    float lux_stat[4];

    int count_of_each[3];



    load_data(temp_m, volt_m, lux_m, count_of_each);
    display_header();
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
                    puts("please enter a valid parameter");
                    break;
                }
                break;
            case 2:
                display_all_measurements(temp_m, volt_m, lux_m, count_of_each);
                break;
            case 3:
                save_data(temp_m, volt_m, lux_m, count_of_each);
                break;
            case 4:
                switch (choose_sensor())
                {
                case 1:
                    delete_measurement_from_sensor(temp_m, &count_of_each[0], "Temperature");
                    break;
                case 2:
                    delete_measurement_from_sensor(volt_m, &count_of_each[1], "Voltage");
                    break;
                case 3:
                    delete_measurement_from_sensor(lux_m, &count_of_each[2], "Lux");
                    break;
                default:
                    puts("please enter a valid parameter");
                    break;
                }
                break;
            case 5:
                switch(choose_sensor())
                {
                    case 1:
                        statistics_for_sensor(temp_m, temp_stat, &count_of_each[0], "Temperature");
                        break;
                    case 2:
                        statistics_for_sensor(volt_m, volt_stat, &count_of_each[1], "Voltage");
                        break;
                    case 3:
                        statistics_for_sensor(lux_m, lux_stat, &count_of_each[2], "Lux");
                        break;
                    default:
                        puts("please enter a valid parameter");
                        break;
                }
                break;
            case 6:
                statistics_for_sensor(temp_m, temp_stat, &count_of_each[0], "Temperature");
                statistics_for_sensor(volt_m, volt_stat, &count_of_each[1], "Voltage");
                statistics_for_sensor(lux_m, lux_stat, &count_of_each[2], "Lux");
                generate_report(temp_m, volt_m, lux_m, temp_stat, volt_stat, lux_stat, count_of_each);
                break;
            case -1:
                puts("please enter a valid parameter");
        }
    }
    return 0;  
}

void generate_report(float temp_m[], float volt_m[], float lux[], float temp_stat[], float volt_stat[], float lux_stat[], int count_of_each[])
{
    
    FILE *frp;
    if((frp = fopen("report.txt", "w")) == NULL)
    {
        fprintf(stderr, "Failure to open %s file\n", "report.txt");
        exit(EXIT_FAILURE);
    }
    int sum_of_counts = count_of_each[0]+count_of_each[1]+count_of_each[2];
    fprintf(frp, "1. General information\n\n"
        "- Overall %d measurements took place\n- %d Temperature measurements %d Voltage measurements %d Light measurements\n"
        "\n2.Temperature statistics\n-Sum %f\n-Average %f\n-Minimum %f\n-Maximum %f"
        "\n3.Voltage statistics\n-Sum %f\n-Average %f\n-Minimum %f\n-Maximum %f"
        "\n4.Light intensity statistics\n-Sum %f\n-Average %f\n-Minimum %f\n-Maximum %f",
        sum_of_counts, count_of_each[0], count_of_each[1], count_of_each[2], temp_stat[0], 
        temp_stat[1], temp_stat[2], temp_stat[3], volt_stat[0], volt_stat[1], volt_stat[2], volt_stat[3],
        lux_stat[0], lux_stat[1], lux_stat[2], lux_stat[3]);

    fclose(frp);

}

void statistics_for_sensor(float sensor[], float sens_stat[], int * count, const char sens_name[])
{

    display_sensor(sensor, count, sens_name);
    int i;
    sens_stat[0] = 0;
    for(i=0;i<*count;i++)
    {
        sens_stat[0] = sens_stat[0] + sensor[i];
    }
    sens_stat[1] = sens_stat[0]/(*count);

    sens_stat[2] = sensor[0];
    for(i=0;i<*count;i++)
    {
        if(sens_stat[2]>sensor[i])
            sens_stat[2] = sensor[i];
    }

    sens_stat[3] = sensor[0];
    for(i=0;i<*count;i++)
    {
        if(sens_stat[3]<sensor[i])
            sens_stat[3] = sensor[i];
    }


    printf("\n\n1. The sum of measurements: %f\n"
        "2. The average of measurmenets: %f\n"
        "3. The minimum value: %f\n"
        "4. The maximum value: %f\n", sens_stat[0], sens_stat[1], sens_stat[2], sens_stat[3]);

}

void delete_measurement_from_sensor(float sensor[], int * count, const char sens_name[])
{
    display_sensor(sensor, count, sens_name);
    int delete_index;
    int yes_no;
    while(1)
    {
        if(*count != 0)
        {
        puts("Do you want to delete a measurement(1 for yes, 0 for no)");
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
            puts("Finished deleting measurements, go to save option in main menu to save changes\n\n");
            break;
        }
        else if(yes_no == 1)
        {
            puts("which number of measurement do you want to delete");
            if(scanf("%d", &delete_index) != 1)
            {
                int ch;
                while((ch = getchar()) != '\n' && ch != EOF)
                    ;

                puts("Invalid input");
                continue;
            }
            if(delete_index < 1 || delete_index > *count)
                puts("No such measurement index, try again");
            else
            {
                int i;
                for(i=delete_index-1; i<(*count)-1; i++)
                    sensor[i] = sensor[i+1];
                (*count)--;
                puts("\nMeasurement successfully deleted, New measurement list:\n");
                display_sensor(sensor, count, sens_name);
            }
        }
        else
            puts("invalid input");
        }
        else
        {
            puts("There are no more measurements to delete");
            break;
        }
            
    }
}

void save_data(float temp_m[], float volt_m[], float lux_m[], int count_of_each[])
{
    FILE *ffp;
    if((ffp = fopen("sensor_data.txt", "w")) == NULL)
    {
        fprintf(stderr, "Failure to open %s file\n", "sensor_data.txt");
        exit(EXIT_FAILURE);
    }
    int i;
    int j;
    for(j=0;j<3;j++)
    {
        fprintf(ffp, "%d ", count_of_each[j]);
        for(i=0;i<count_of_each[j];i++)
            {
                if(j==0)
                    fprintf(ffp, "%f ", temp_m[i]);
                else if(j==1)
                    fprintf(ffp, "%f ", volt_m[i]);
                else if(j==2)
                    fprintf(ffp, "%f ", lux_m[i]);
            }
        fprintf(ffp, "\n");
    }
    fclose(ffp);
}

void add_measurement_to_sensor(float sensor[], int * count, const char sens_name[])
{
    display_sensor(sensor, count, sens_name);
    int i;
    float measurement;
    int yes_no;
    while(1)
    {
        if(*count < MAX_MEASURE)
        {
        puts("\n\nDo you want to add a new measurement (1 for yes/0 for no)");
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

void display_sensor(float sensor[], int *count, const char sens_name[])
{
    int i;
    printf("\n%s sensor last measurements: \n", sens_name);
    for(i=0;i<*count;i++)
        printf("%d. %f\n", i+1, sensor[i]);
}

void display_all_measurements(float temp_m[], float volt_m[], float lux_m[], int count_of_each[])
{
    display_sensor(temp_m, &count_of_each[0], "Temperature");
    display_sensor(volt_m, &count_of_each[1], "Voltage");
    display_sensor(lux_m, &count_of_each[2], "Lux");
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
    printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++\n\n"
    "1. Add new measurement\n"
    "2. Display all measurements\n"
    "3. Save data to file\n"
    "4. Delete measurement\n"
    "5. Calculate statistics\n"
    "6. Calculate all statistics and Generate report\n"
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
    if(choice < 0 || choice > 6)
        {
            puts("invalid input, try again");
            return -1;
        }
    else    
        return choice;
}

void display_header()
{
    puts("\n####################################################\n"
        "\n\n   SENSOR DATA MEASUREMENT AND ANALYSIS PROGRAM\n\n"
        "\n####################################################\n");

}