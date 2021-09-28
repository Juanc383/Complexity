#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../lib/Fibonacci.h"
#include "../lib/Files.h"



#define FILENAME "data.db"
#define COLUMNS 3
#define ROWS 30

int main(void){

    FILE* myFile = NULL;
    long long data[ROWS][COLUMNS]={0};
    char* titles[] = {"Index\0", "Recursive\0", "Sequential\0" };


    myFile = newFile(FILENAME, "w");
    if(!myFile)return 1;

    for(int index = 0; index<ROWS; index++){
        data[index][0] = index;
        data[index][1] = recursiveFibonacci(index);
        data[index][2] = sequentialFibonacci(index);
        
    }
    puts("finished");
    printHeaders(myFile, 3, titles);
    csvFileWrite(myFile, COLUMNS, ROWS, data);

    closeFile(myFile);
}