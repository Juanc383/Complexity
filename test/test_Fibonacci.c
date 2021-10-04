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

void test_fibonacciInit(void){
    puts("Testing fibonacci Function");
    fibonacci test_sec = NULL;
    fibonacci test_rec = NULL;
    test_sec = newfibonacciSec();
    test_rec = newfibonacciRec();
    s = newfibonacciSec();
    r = newfibonacciRec();
    TEST_ASSERT_NOT_NULL(test_sec);
    TEST_ASSERT_NOT_NULL(test_rec);
    freeComplexNumber(test_sec);
    freeComplexNumber(test_rec);
}


void test_fibonacciSecSet(void){
    puts("Testing fibonacci Set Function");
    Fibonacci test_fibonacci = NULL;
    SERIES_RESULTS;
    test_fibonacci = newfibonacciSec();
    test_fibonacci2 = newfibonacciRec();

    fibonacci = setFibonacci(test_fibonacci, SERIES_RESULTS);

    // TEST CODE
    TEST_ASSERT_FLOAT_WITHIN(SERIES_RESULTS, fibonacciRecursiva, data);
    TEST_ASSERT_FLOAT_WITHIN(SERIES_RESULTS, fibonacciSecuencial, data);
    freeFibonacci(test_fibonacci);

}


void test_Fibonacci(void){
    puts("Testing Fibonacci Get Function");
    Fibonacci test_fibonacci = newfibonacciSec();
    Fibonacci test_fibonacci2 = newfibonacciRec();
    SERIES_RESULTS, TEST_INDECES;

    test_fibonacci->secuencial = time.secuencial;
    test_fibonacci->recursiva = time.recursiva;

    getFibonacci(test_fibonacci, &secuencial, &recursiva);

    TEST_ASSERT_FLOAT_WITHIN(SERIES_RESULTS, INDECES, fibonacciSecuencial);
    TEST_ASSERT_FLOAT_WITHIN(SERIES_RESULTS, INDECES, fibonacciRecursiva);
    freeFibonacci(test_fibonacci);

    Fibonacci test_fibonacci = newfibonacciRec();
    Fibonacci test_fibonacci2 = newfibonacciSec();

    test_Fibonacci = freeFibonacci(test_Fibonacci);

    TEST_ASSERT_NULL(test_fibonacci);
}
