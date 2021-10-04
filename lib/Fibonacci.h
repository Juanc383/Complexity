/**
 * @Author Jazmin Villegas
 * @Author Juan C. Rosales
 * @Date 27 Sep 2021
 * @Name fibonacci.h
 * @Copyright TDA 2021
 */

// SOLID Convention

#ifndef Fibonacci_H
#define Fibonacci_H

// Bibliotecas Standard

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// User Libraries
// Data Types

typedef struct time{
  clock_t begin;
  clock_t end;
  int mostrar;
  float time;
} TIME;

void fibonacciSecuencial(int n);
void fibonacciRecursiva(int n);
void mostrarTiempos(int i, float timeRec, int mostrarRec, float timeSec, int mostrarSec);
void guardarArchivo(int n, float timeRec, float timeSec);
long long recursiveFibonacci(long long index);
long long sequentialFibonacci(long long index);


# endif
