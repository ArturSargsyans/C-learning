#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void check_argc(int);
void check_open_success(FILE *fp);
void check_error(FILE *fp);
unsigned long int count_chars(FILE *fp);
unsigned int count_alphas(FILE *fp);
unsigned int count_nums(FILE *fp);
unsigned int count_newlines(FILE *fp);

int main(int argc, char *argv[])
{
    FILE *fp, *ffp;
    long file_size;
    unsigned long int count;
    unsigned int alphas;
    unsigned int numerics;
    unsigned int newlines;


    check_argc(argc);
    fp = fopen(argv[1], "rb");
    check_open_success(fp);
    count = count_chars(fp);
    alphas = count_alphas(fp);
    numerics = count_nums(fp);
    newlines = count_newlines(fp);
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);


    ffp = fopen("record.txt", "w");
    check_open_success(ffp);
    fprintf(ffp, "FILE ANALYSIS REPORT\n------------------\n"
        "File name: %s\nFile size: %ld\nTotal characters: %lu\nAlphabetic characters: %u\nDigits: %u\n"
        "New line characters: %u\n", argv[1], file_size, count, alphas, numerics, newlines);

    fclose(fp);
    fclose(ffp);
}

unsigned int count_newlines(FILE *fp)
{
    int ch; 
    int count = 0;
    while ((ch = getc(fp)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    check_error(fp);
    rewind(fp);
    return count;
}


unsigned int count_nums(FILE *fp)
{
    int ch; 
    int count = 0;
    while ((ch = getc(fp)) != EOF) {
        if (isdigit(ch)) {
            count++;
        }
    }
    check_error(fp);
    rewind(fp);
    return count;
}

unsigned int count_alphas(FILE *fp)
{
    int ch; 
    int count = 0;
    while ((ch = getc(fp)) != EOF) {
        if (isalpha(ch)) {
            count++;
        }
    }
    check_error(fp);
    rewind(fp);
    return count;
}


unsigned long int count_chars(FILE *fp)
{
    unsigned long int count = 0;
    while(getc(fp) != EOF)
    {
        count++;
    }
    check_error(fp);
    rewind(fp);
    return count;
}

void check_argc(int argc)
{
    if(argc != 2)
    {
        puts("Usage should be ./ex file and textfile name");
        exit(EXIT_FAILURE);
    }
}

void check_open_success(FILE *fp)
{
    if(fp == NULL)
    {
        printf("Unable to open file\n");
        exit(EXIT_FAILURE);
    }
}

void check_error(FILE *fp)
{
    if(ferror(fp))
    {
        printf("Error reading the file\n");
        exit(EXIT_FAILURE);
    }
}