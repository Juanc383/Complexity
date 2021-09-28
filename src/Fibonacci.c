#include <stdio.h>
#include <stdlib.h>

#include "../lib/Fibonacci.h"

long long recursiveFibonacci(long long index){
    if (index <= 1)return index;
    return recursiveFibonacci(index-1) + recursiveFibonacci(index-2);
}


long long sequentialFibonacci(long long index){
    long long  base = 0, base1 = 1, holder = 0, term = 0;
    if (index == 0)return base;
    for (term = 2; term <= index; term++){
        holder = base + base1;
        base = base1;
        base1 = holder;
    } 
    return base1;
}
