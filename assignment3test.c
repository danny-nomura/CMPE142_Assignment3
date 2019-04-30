// A simple memory manager
// This program takes input from a file with three fields for a process
// Proccess_ID , ACTION , and PAGE
// We will simulate FIFO, LRU, and RANDOM swapping policies
#include <iostream>
#include <stdio.h>
// Predefined max array size
#define MAX_ARRAY_SIZE 50

// Structure for process objects, with fields for their ID, action, and page num
typedef struct Process
{
	int PROCESS_ID;
	char ACTION;
	int PAGE;
}Process;

// Instantiating an array of Process objects
Process myProcess[MAX_ARRAY_SIZE];


int main(){

}
