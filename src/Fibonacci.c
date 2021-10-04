#include "../lib/Fibonacci.h"


int main(void)
{
  int n;
  TIME sec, rec;
  FILE *fp;


  fp = fopen("data.db", "rt");
  time.begin = clock();

  time.resultado=fibonacciRecursiva(n);
  //time.resultado=recursiveFibonacci(index);

  time.end = clock();
  time.count += (float)(time.end - time.begin);

  time.begin = clock();

  time.resultado=fibonacciSecuencial(n);
  //time.resultado=sequentialFibonacci(index);

  time.end = clock();
  time.count += (double)(time.end - time.begin);
  fclose(fp);

  mostrarTiempos(i, timeRec, mostrarRec, timeSec, mostrarSec);
  guardarArchivo(n, timeRec, timeSec);


}
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

void fibonacciRecursiva(int n)
{
  int n;
 printf ("Ingresa un numero para calcular su valor en la serie de Fibonacci:\n");
 scanf ("%d",&n);
 printf ("Fibonacci de %d = %d\n",n,Fibonacci (n));
}

int Fibonacci (int n){
 if (n>1)
     return Fibonacci(n-1)+Fibonacci(n-2);
 else
   if(n==1)
     return 1;
 else
   return 0;
}

void fibonacciSecuencial(int n)
{

  int a = 1, b = 0, i;

  for(i = 0; i < 10; i++){
    printf("%d\n",b);
    printf("%d\n",a);
    b = b + a;
    a = a + b;
  }
  return 0;

}

void mostrarTiempos(int i, float timeRec, int mostrarRec, float timeSec, int mostrarSec){
  printf("Tiempo  de la funcion Secuencial: %f segundos\n", tiempoSecuencial);
  printf("Tiempo  de la funcion Recursiva: %f segundos\n", tiempoRecursivo);
  printf ("Fibonacci Secuencial de %d = %d\n",i,resultadoSecuencial);
  printf ("Fibonacci Recursivo de %d = %d\n",i,resultadoRecursivo);
}

void guardarArchivo(int n, float timeRec, float timeSec){
  FILE *fp;
  fp=fopen("Fibonacci.txt","at");
  fprintf(fp, "%d,",n);
  fprintf(fp, "%f,",timeSec);
  fprintf(fp, "%f\n",timeRec);
  fclose(fp);
}
