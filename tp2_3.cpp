#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 15

int f,c;
int vector[FILAS];

int main()
{
    //Para tener numeros aleatorios cada vez que ejecutamos
    time_t t;
    srand((unsigned) time(&t));

    //Definimos las columnas y generamos aleatoriamente la cantidad entre 5 y 15
    int columnas = 0;
    columnas = rand() % 11 + 5;

    int cont = 0;

    //Creamos la matriz
    int matriz[FILAS][columnas];

    for(f = 0; f < FILAS; f++)
    {
        for(c = 0; c < columnas; c++)
        {
            //Damos un valor random entre 100 y 999
            matriz[f][c] = rand() % 900 + 100;
            printf("%3d   ", matriz[f][c]);
        }
        printf("\n");
    }

    printf("\n");

    for(f = 0; f < FILAS; f++)
    {
        for(c = 0; c < columnas; c++)
        {
            //Contamos los valores pares
            if(matriz[f][c] % 2 == 0) cont++;
        }
        //Mostramos la cantidad de valores pares por fila
        printf("Pares fila [%d]: %d", f+1, cont);

        //Guardamos en el vector con la cantidad de pares
        vector[f] = cont;

        //Reseteamos el contador
        cont = 0;

        printf("\n");
    }

    printf("\nVector: ");
    for(f = 0; f < FILAS; f++)
    {
        //Mostramos el vector
        printf("%d   ", vector[f]);
    }

    getchar();
    return 0;
}