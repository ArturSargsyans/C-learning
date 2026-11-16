#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 40

int main(void)
{
    FILE *fp;

    char words[MAX];

    if((fp = fopen("destination.txt", "a+")) == NULL)
    {
        fprintf(stdout, "Failure to open %s file\n", "destination.txt");
        exit(EXIT_FAILURE);
    }
    puts("Enter the words to be saved in the file,  # to quit");
    while(fscanf(stdin, "%40s", words) == 1 && (words[0] != '#'))
        fprintf(fp, "%s\n", words);

    if(fclose(fp) != 0)
        fprintf(stdout, "Error closing file\n");

    return 0;

}