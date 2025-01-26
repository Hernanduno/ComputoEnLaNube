//Importamos librerias
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
//Definimos variables
#define N 100000
#define chunk 10000
#define mostrar 20
//Funcion para imprimir los arreglos
void print(float *d);
void print(float *d)
{
    for (int x = 0; x < mostrar; x++)
    {
        printf("%f ", d[x]);
    }
    printf("\n");
}
int main()
{
     printf("Ejecutando con un tamaño de: %d \n", chunk);
    //Definimos los arreglos
    float A[N], B[N], Suma[N];
    int i;
    //Rellemos A y B con numeros aleatorios
    for (i = 0; i < N; i++)
    { A[i] = rand() % 101;  B[i] = rand() % 101; }
    //Tomamos la hora antes de empezar la suma
    clock_t T1 = clock();
    int size = chunk;
    //Configurarmos el for con openMP
    #pragma omp parallel for \
    shared(A, B, Suma, size) private(i) \
    schedule(static, size)
    //Sumamos A+B
    for (i = 0; i < N; i++)
    { Suma[i] = A[i] + B[i]; }
    //Tomamos la hora despues de terminar la suma
    clock_t T2 = clock();
    //Calculamos y mostrarmos el tiempo que tomo sumar A+B
    double time_taken = ((double)(T2 - T1)) / CLOCKS_PER_SEC;
    printf("La suma tomô: %f segundos\n", time_taken);
    // Mostramos los arreglos
    printf("Primeros %d valores del arreglo a: \n", mostrar);
    print(A);
    printf("Primeros %d valores del arreglo b: \n", mostrar);
    print(B);
    printf("Primeros %d valores del arreglo c: \n", mostrar);
    print(Suma);
    return 0;
}

