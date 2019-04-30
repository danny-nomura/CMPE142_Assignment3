// A simple memory manager
// This program takes input from a file with three fields for a process
// Proccess_ID , ACTION , and PAGE
// We will simulate FIFO, LRU, and RANDOM swapping policies
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
// Predefined max array size
#define MAX_ARRAY_SIZE 50

// Function Declaration
int ReadFile(char *fileName);

// Structure for process objects, with fields for their ID, action, and page num
typedef struct Process
{
	int PROCESS_ID;
	char ACTION;
	int PAGE;
}Process;

// Instantiating an array of Process objects
Process myProcess[MAX_ARRAY_SIZE];

// Main Function
int main(){

}

int ReadFile(char *fileName)
{
    FILE *filePtr = NULL;
    int  i = 0;

    if ((filePtr = fopen(fileName, "r")) == NULL)
    {
        printf("Error : Unable to open %s for reading\n",fileName);
        exit(EXIT_FAILURE);
    }

    while (fscanf(filePtr, "%d%c%d", &myProcess[i].PROCESS_ID, &myProcess[i].ACTION, &myProcess[i].PAGE) != EOF)
    {
        i++;
    }

    fclose(filePtr);
    return i;
}
