//============================================================================
// Name    	: Assignment3_142.cpp
// Author  	:
// Version 	:
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// A simple memory manager
// This program takes input from a file with three fields for a process
// Proccess_ID , ACTION , and PAGE
// We will simulate FIFO, LRU, and RANDOM swapping policies
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
int ReadFile(string fileName);
void FIFO(int);
void LRU(int);
void RANDOM(int);

// Structure for process objects, with fields for their ID, action, and page num
typedef struct pageTable
{
	int PROCESS_ID;
	string ACTION;
	int PAGE;
}pageTable;

// Instantiating an array of Process objects to hold them for interpreting
pageTable myPageTable[MAX_ARRAY_SIZE];

// Instantiating our 20 pages of physical memory
pageTable physicalMemory[20];

// Intstantiate an array for swapping
pageTable swapping[20];

// Main Function
int main(){

	string fileName = "memory.dat";
	int totalActions = ReadFile(fileName);
	int i = 0;
	FIFO(totalActions);
	// while(i < totalActions){
	// 	cout << myPageTable[i].PROCESS_ID <<": ";
	// 	cout << myPageTable[i].ACTION << "\t";
	// 	cout << myPageTable[i].PAGE << "\n";
	// 	i++;
	// }
	// To test that it works....
	cout << "Number of actions in memory.dat:\t " << totalActions << "\n";
}

int ReadFile(string fileName)
{
	ifstream infile(fileName); // connect file to stream

	//assert(!infile.fail());// make sure it is not a failure

	int i = 0; // counter

	// Loop until we reach the end of the file
	// Each loop, we set process id, action, and page for current line
	// Outside loop, we increment counter

	while(!infile.eof()){
    	bool check = true;
    	while(check) // get the whole line, place in temp
    	{
        	// Parse string, place individual items in proper position
        	infile >> myPageTable[i].PROCESS_ID >> myPageTable[i].ACTION;

        	if((myPageTable[i].ACTION == "C")||(myPageTable[i].ACTION == "T"))
        	{
            	myPageTable[i].PAGE = 0;
        	}

        	else
        	{
            	infile >> myPageTable[i].PAGE;
        	}
        	cout << myPageTable[i].PROCESS_ID <<": "<< myPageTable[i].ACTION << ": "<< myPageTable[i].PAGE << endl;
        	i++;
        	check = false;
    	}
    	// Exit while loop after a line, increment i
	}

	// Close the file
	infile.close();

	// Function returns the number of actions each file gives us
	return i;
}

void FIFO(int actions){
	int i = 0;
	typedef struct page_table{
	int PID;
	int PA;
	int VA;
	int dirty;
	int AT;
	}page_table;
	page_table physical_page[20];
	page_table swapping[80];
	int active[100];
	int time, j = 0;
	while (i < (actions + 1)){
    	//loop through myPageTable doing the actions
    	if(myPageTable[i].ACTION == "C"){//create
        	//add to active process array
        	active[i] = myPageTable[i].PROCESS_ID;
    	}
    	if(myPageTable[i].ACTION == "T"){//terminate
        	//process terminated
        	//process cleaned from page table
    	}
    	if(myPageTable[i].ACTION == "A"){//allocate
        	//allocate page for an active process
        	//check for free pages to allocate
        	for(j = 0; j < 20; j++){
            	if(physical_page[j].PID == NULL){
                	physical_page[j].PID = myPageTable[i].PROCESS_ID;
                	physical_page[j].PA = j;
                	physical_page[j].VA = myPageTable[i].PAGE;
                	physical_page[j].dirty = 0;
                	physical_page[j].AT = time;
            	}
        	}
        	//swap FIFO to allocate
        	for(j = 0; j < 20; j++){
            	//find min arrival time (AT)
            	//swap
        	}

    	}
    	if(myPageTable[i].ACTION == "R"){//read
        	//check page table
        	for(j = 0; j < 20; j++){
            	if(myPageTable[i].PROCESS_ID == physical_page[j].PID){
                	if(myPageTable[i].PAGE == physical_page[j].VA){
                    	physical_page[j].AT = time;
                	}
            	}
        	}
        	//check in swap
        	for(j = 0 ; j< 20; j++){
            	//find min arival time(AT)
            	//swap
        	}
        	//accessed time increment
    	}
    	if(myPageTable[i].ACTION == "W"){//write
        	//look at page table for allocated processes with pages
        	for(j = 0; j < 20; j++){
            	if(myPageTable[i].PROCESS_ID == physical_page[j].PID){
                	if(myPageTable[i].PAGE == physical_page[j].VA){
                    	physical_page[j].dirty = 1;
                    	physical_page[j].AT = time;
                	}
            	}
        	}
        	//check in swap

        	//mark dirty // accesed time increment
    	}
    	if(myPageTable[i].ACTION == "F"){//free
        	//page freed
    	}
    	i++;
    	time++;
	}
}

void LRU(int)
{

}

void RANDOM(int)
{

}
