#ifndef DEVICE_H
#define DEVICE_H

#define MAXSIZE 20
#define MAX_DEVICES 5

typedef enum {
    TEMP_SENSOR,
    VOLT_SENSOR,
    DIG_OUTPUT
} DEV_TYPE;

typedef enum {
    OFFLINE,
    ONLINE,
} DEV_STATUS;


typedef struct {
    int dev_id;
    char name[MAXSIZE];
    DEV_TYPE type;
    DEV_STATUS status;
    union{
        float temp_range[2];
        float max_volt;
        int pin_num;
    };
} DEVICE;

void add_device(DEVICE [], int *);
void display_devices(DEVICE [], int);

#endif