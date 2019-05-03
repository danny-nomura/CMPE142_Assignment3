// A simple memory manager
// This program takes input from a file with three fields for a process
// Proccess_ID , ACTION , and PAGE
// We will simulate FIFO, LRU, and RANDOM swapping policies
#include <stdio.h>
#include <stdlib.h>
// Predefined max array size
#define MAX_ARRAY_SIZE 50

// Function Declaration
int ReadFile(char *fileName);
void FIFO(int);
void LRU(int);
void RANDOM(int);

// Structure for process objects, with fields for their ID, action, and page num
typedef struct Process
{
    int PROCESS_ID;
    char ACTION;
    int PAGE;
}Process;

// Instantiating an array of Process objects to hold them for interpreting
Process myProcess[MAX_ARRAY_SIZE];

// Instantiating our 20 pages of physical memory
Process physicalMemory[20];

// Main Function
int main(){
    char *fileName = "memory.dat";
    int totalActions = ReadFile(fileName);
    
    // To test that it works....
    printf("Number of actions in memory.dat:\t%s", totalActions);
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
    
    // Scan in the Process ID, Action, and Page to each process change
    while (fscanf(filePtr, "%d%c%d", &myProcess[i].PROCESS_ID, &myProcess[i].ACTION, &myProcess[i].PAGE) != EOF)
    {
        i++;
    }
    
    fclose(filePtr);
    // Return the number of actions required
    return i;
}
