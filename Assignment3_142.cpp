//============================================================================
// Name        : Assignment3_142.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// A simple memory manager
// This program takes input from a file with three fields for a process
// Proccess_ID , ACTION , and PAGE
// We will simulate FIFO, LRU, and RANDOM swapping policies
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <assert.h>

using namespace std;

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
    string ACTION;
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
    cout << "Number of actions in memory.dat:\t " << totalActions;
}

int ReadFile(char *fileName)
{
	ifstream infile(fileName); // connect file to stream

	assert(!infile.fail());// make sure it is not a failure

	int i = 0; // counter
	// Loop until we reach the end of the file
	// Each loop, we set process id, action, and page for current line
	// Outside loop, we increment counter

	while(!infile.eof()){
		string temp; // string to hold current line input
		while(getline(infile, temp)) // get the whole line, place in temp
		{
			// Parse string, place individual items in proper position
			stringstream myLine(temp);
			myLine >> myProcess[i].PROCESS_ID >> myProcess[i].ACTION >> myProcess[i].PAGE;
		}
		// Exit while loop after a line, increment i
		i++;
	}

	// Close the file
	infile.close();

	// Function returns the number of actions each file gives us
	return i;
}

void FIFO(int)
{

}

void LRU(int)
{

}

void RANDOM(int)
{

}
